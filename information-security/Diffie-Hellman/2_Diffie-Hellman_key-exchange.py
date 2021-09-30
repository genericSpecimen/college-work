import sympy
from random import randint
from sympy.ntheory.residue_ntheory import primitive_root

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
        # generate a random integer X < q.
        # This X is the private key PR
        self.PR = randint(2, self.q)
        
        # compute (alpha ^ X) mod q
        self.PU = pow(self.alpha, self.PR, self.q)
    
    def generate_shared_key(self, PU):
        # uses PU (Y) of the other user
        # and PR (X) of itself
        # computes K = (Y ^ X) mod q
        self.K = pow(PU, self.PR, self.q)

if __name__ == '__main__':
    # two users that wish to share a key
    alice = Participant()
    bob = Participant()
    
    # This time, Alice chooses q and alpha
    # and shares it with Bob
    q, alpha = alice.choose_q_alpha()
    alice.share_q_alpha(bob)
    
    print(f'Selecting and sharing q = {q} and alpha = {alpha}')
    
    # Alice generates a key pair
    alice.generate_key_pair()
    
    # Bob generates a key pair
    bob.generate_key_pair()
        
    print('\n--------------Generated Key Pairs--------------')
    print(f'Alice\'s key pair:\n\tPrivate: {alice.PR}\n\tPublic : {alice.PU}')
    print(f'Bob\'s key pair:\n\tPrivate: {bob.PR}\n\tPublic : {bob.PU}')
    print('-----------------------------------------------')
    
    # Both Alice and Bob generate the shared key
    # using the public key of each other
    alice.generate_shared_key(bob.PU)
    bob.generate_shared_key(alice.PU)

    
    # Now both Alice and Bob possess the same shared key
    print(f'\n------Secret Key sharing accomplished------')
    print(f'Alice has secret key: {alice.K}')
    print(f'Bob   has secret key: {bob.K}')
    print(f'\nBoth keys same  : {alice.K == bob.K}')
    print(f'-------------------------------------------')

    
    
    
