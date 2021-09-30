import sympy
from random import randint
from sympy.core.numbers import mod_inverse
from sympy.ntheory.residue_ntheory import primitive_root

def make_blocks(M):
    #block_size = 8 # bits
    M_blocks = [ord(c) for c in M]
    return M_blocks

def concat_blocks(blocks):
    M = ''
    x = [chr(b) for b in blocks]
    M = M.join(x)
    return M

class Participant:
    """
    A general class denoting a Participant in some communication.
    Each Participant can generate their own key pair.
    """
    def __init__(self):
        self.q = None
        self.alpha = None
        self.PR = None
        self.PU = None
        self.K = None

    def choose_q_alpha(self, q_len=1024):
        # q_len is in bits
        
        # choose a random prime number q with
        # size of q_len bits
        
        # q must be large enough to prevent brute force attacks
        # guideline suggests 1024 bits, but for a quick demonstration, let it be 128 bits.
        q_len = 128
        self.q = sympy.randprime(2 ** q_len, 2 ** (q_len+1))
        
        # choose a primitive root of q
        self.alpha = primitive_root(self.q)
        
        return (self.q, self.alpha)
    
    def share_q_alpha(self, P):
        # share the generated q and alpha with user P
        P.q = self.q
        P.alpha = self.alpha
    
    def generate_key_pair(self):
        # generate a random integer X < q - 1.
        # This X is the private key PR
        self.PR = randint(2, self.q - 1)
        
        # compute (alpha ^ X) mod q
        Y = pow(self.alpha, self.PR, self.q)
        
        # Public key consists of three components
        # q, alpha, and, Y
        self.PU = (self.q, self.alpha, Y)
        
    def encrypt(self, M, PU):
        # uses public key PU of the other user
        # to encrypt plaintext M
        
        M_blocks = make_blocks(M)
        C_blocks = []
        
        for M in M_blocks:
        
            # select random integer k between [1, q)
            k = randint(1, self.q)
            
            _, _, Y = PU
            # one time key for this message
            #K = (Y^k) mod q
            self.K = pow(Y, k, self.q)
            
            C1 = pow(self.alpha, k, q)
            C2 = (self.K * M) % self.q
            
            C = (C1, C2)
            
            C_blocks.append(C)
        
        return C_blocks
    
    def decrypt(self, C_blocks):
        # recover key from C1 sent by other user
        # using own private key PR
        
        M_blocks = []
        for C in C_blocks:
            C1, C2 = C
            self.K = pow(C1, self.PR, q)
            
            K_inv_mod_q = mod_inverse(self.K, self.q)
            M = (C2 * K_inv_mod_q) % self.q
            
            M_blocks.append(M)
        
        M_dec = concat_blocks(M_blocks)
        return M_dec

if __name__ == '__main__':
    # two users that wish to share confidential messages
    alice = Participant()
    bob = Participant()
    
    # This time, Alice chooses q and alpha
    # and shares it with Bob
    q, alpha = alice.choose_q_alpha()
    alice.share_q_alpha(bob)
    
    print(f'Selecting and sharing q = {q} and alpha = {alpha}')
    
    # Alice generates a key pair
    alice.generate_key_pair()
    
    print('\n--------------Generated Key Pair--------------')
    print(f'Alice\'s key pair:\n\tPrivate: {alice.PR}\n\tPublic : {alice.PU}')
    print('----------------------------------------------')
    
    M = 'Hello Alice, I am Bob!'
    print(f'\nOriginal Plaintext : {M}')
    
    # Bob encrypts a message M with Alice's Public Key
    C_blocks = bob.encrypt(M, alice.PU)
    print(f'\nCiphertext (encrypted by Bob)  : {C_blocks}')
    
    # Alice decrypts the Ciphertext with her own Private key
    M_dec = alice.decrypt(C_blocks)
    print(f'\nPlaintext (decrypted by Alice) : {M_dec}')
    
