import numpy as np


"""
The encryption function creates 'K' rails
and assigns each character to a rail according
to the depth of the character.
Example:
K = 3
P = 'wearediscoveredfleeatonce'
     0121012101210121012101210
So, Rail 0 = ['w', 'e', 'c', 'r', 'l', 't', 'e'].
Similarly, characters are assigned to rails 1 and 2.

This is done using a 'step' and a depth parameter.
Whenever depth == 0, we increment the depth by step = 1.
But, as soon as depth == K-1, we need to decrement the
depth by step = -1.

The encrypted ciphertext is simply all the rails concatenated.
"""
def E(K, P):
    C = ''
    rails = [ [] for k in range(K) ]
    depth = 0
    step = 1
    for c in P:
        rails[depth] += c
        depth += step
        
        if(depth == 0):
            step = 1
        if(depth == K-1):
            step = -1
    
    for rail in rails:
        C += ''.join(rail)
    
    #print(rails)
    return C


"""
The decryption function is a bit complicated, and
uses the method mentioned at the Wikipedia article:
https://en.wikipedia.org/wiki/Rail_fence_cipher#Solution

Essentially, we need to calculate the number of
characters (units) in each rail. For that, we need
to find out the cycle length. The formula for that
is cycle_len = (number_of_rails * 2) - 2 = (K * 2) - 2.

Now, the number of complete cycles is floor(len(C) / cycle_len).
For the first and last rail, there is one character (unit)
per cycle. For other rails, there are two units per cycle.
Note that the first rail might have an additional character,
which starts the next partial cycle. This can be accounted for
using the ceiling function applied to (len(C) / cycle_len).
"""

def D(K, C):
    P = ''
    cycle_len = K*2 - 2
    num_cycles = np.floor(len(C) / cycle_len)
    
    rail_units = [0 for k in range(K)]
    for k in range(K):
        if (k == 0):
            # first rail - one unit in each cycle + one extra if applicable
            rail_units[k] = np.ceil(len(C) / cycle_len)
        elif (k == K-1):
            # last rail - one unit in each cycle
            rail_units[k] = num_cycles * 1
        else:
            # all other rails have two units per cycle
            rail_units[k] = num_cycles * 2
    
    rails = [ [] for k in range(K) ]
    start = 0
    for k in range(K):
        units = int(rail_units[k])
        rails[k] = C[start : start + units]
        start = start + units
    #print(rails)
    
    depth = 0
    step = 1
    P = ''
    for i in range(len(C)):
        c = rails[depth][0]
        rails[depth] = rails[depth][1:]
        P += c
        depth += step
        
        if(depth == 0):
            step = 1
        if(depth == K-1):
            step = -1
    
    return P

if __name__ == '__main__':
    #P = 'meetmeafterthetogaparty'
    
    K = 3
    P = 'wearediscoveredfleeatonce'
    
    # Compute the ciphertext
    C = E(K, P)
    
    print(f'Key (number of rails): {K}')
    print(f'Plaintext (original) : {P}')
    print(f'Ciphertext           : {C}')
    
    # Compute the plaintext
    P = D(K, C)
    print(f'Plaintext (decrypted): {P}')
