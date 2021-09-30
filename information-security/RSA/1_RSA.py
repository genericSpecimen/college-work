import sympy
from sympy.core.numbers import mod_inverse

def make_blocks(M):
    #block_size = 8 # bits
    M_blocks = [ord(c) for c in M]
    return M_blocks

def concat_blocks(blocks):
    M = ''
    x = [chr(b) for b in blocks]
    M = M.join(x)
    return M

def generate_key_pair(n_len=1024):
    # https://www.di-mgt.com.au/rsa_alg.html
    # length is in bits
    # by default, size of n = 1024 bits
    
    PU = None
    PR = None
    
    # e must be relatively prime to phi_n and e < phi_n
    # e = 65537 is the industry standard for various reasons
    # https://crypto.stackexchange.com/a/3113
    e = 65537
    
    # choose two prime numbers, p and q
    # of similar size
    
    p_len = n_len // 2
    q_len = n_len - p_len
    
    # just for initialization
    p = 1
    q = 1
    
    # calculate the Euler's totient function
    phi_n = (p - 1) * (q - 1)
    
    while (sympy.gcd(e, phi_n) != 1):
        p = sympy.randprime(2 ** p_len, 2 ** (p_len+1))
        q = sympy.randprime(2 ** q_len, 2 ** (q_len+1))
        phi_n = (p - 1) * (q - 1)
    
    n = p * q
    
    # determine d such that  de = 1 (mod n) and d < phi_n
    # this can be done using the Extended Euclid's algorithm
    # sympy's mod_inverse function implements this algorithm
    d = mod_inverse(e, phi_n)
    
    # resulting public and private keys
    PU = (e, n)
    PR = (d, n)
    
    return (p, q, PU, PR)

class Participant:
    """
    A general class denoting a Participant in some communication.
    Each Participant can generate their own key pair.
    """
    def __init__(self):
        self.p = None
        self.q = None
        self.PU = None
        self.PR = None
        self.d_p = None
        self.d_q = None
    
    def get_key_pair(self):
        self.p, self.q, self.PU, self.PR = generate_key_pair()
        # these values can be precomputed and will be useful
        # for fast decryption
        d, _ = self.PR
        self.d_p = d % (self.p - 1)
        self.d_q = d % (self.q - 1)
        
        e, n = self.PU
        print('----------------Values of e, d, n------------------')
        print('Note that out of these values, only d is secret.')
        print(f'\ne = {e}')
        print(f'\nd = {d}')
        print(f'\nn = {n}')
        print('---------------------------------------------------')
    
    def encrypt(self, PU, M):
        """Encrypt a message M with the
        public key of receiver, PU = {e, n}.
        The resulting ciphertext is C,
        C = M^e mod n
        """
        e, n = PU
        
        M_blocks = make_blocks(M)
        print(f'\nPlaintext blocks = {M_blocks}')
        
        # the built-in pow function does fast modular exponentiation,
        # when a third argument is passed to it, denoting the modulus
        
        C_blocks = [pow(M, e, n) for M in M_blocks]
        print(f'\nCiphertext blocks: C = {C_blocks} (encrypted and sent by Alice)')
        
        return C_blocks
    
    def decrypt(self, C_blocks):
        # uses self.PR
        """Decrypt a ciphertext C using the private key of receiver, PR = {d, n}.
        The resulting plaintext is M, where M = C^d mod n.
        
        To do this efficiently, we make use of the Chinese remainder theorem
        and Fermat's theorem.
        """
        d, n = self.PR
        
        M_blocks = []
        for C in C_blocks:
            V_p = pow(C, self.d_p, self.p)
            V_q = pow(C, self.d_q, self.q)
            
            X_p = self.q * mod_inverse(self.q, self.p)
            X_q = self.p * mod_inverse(self.p, self.q)
            
            M = (V_p * X_p + V_q * X_q) % n
            M_blocks.append(M)
            #print(M)
        
        print(f'\nPlaintext blocks: M = {M_blocks} (decrypted by Bob)')
        
        M_dec = concat_blocks(M_blocks)
        return M_dec

if __name__ == '__main__':    
    alice = Participant()
    
    bob = Participant()
    bob.get_key_pair()
    
    M = 'Hello Bob, I am Alice!'
    print(f'\nPlaintext:  M = {M}')
    
    # if Alice wants to send a confidential message M to Bob,
    # then alice encrypts M using Bob's public key
    
    C_blocks = alice.encrypt(bob.PU, M)
    
    # now Bob will decrypt this message using his own private key
    M_dec = bob.decrypt(C_blocks)
    
    print(f'\nPlaintext:  M = {M_dec} (decrypted by Bob)')
    
