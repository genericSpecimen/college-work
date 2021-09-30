"""
A variant of the shift cipher in which we shift right until
a specified position 'pos' is encountered. From that position,
we shift left until the end of the string.
"""

def E(K, P):
    C = ""
    for c in P:
        if not c.isspace():
            if c.isupper():
                C += chr(((ord(c) - ord('A') + K) % 26) + ord('A'))
            elif c.islower():
                C += chr(((ord(c) - ord('a') + K) % 26) + ord('a'))
            else:
                C += c
        else:
            C += c
    return C

def D(K, C):
   return E(26-K, C)

if __name__ == '__main__':
    
    # K1 = Shift right key
    K1 = 3
    # K2 = Shift left key
    K2 = 2
    
    # position (1 based) at which the shift direction is reversed
    pos = 4

    # plaintext
    P = 'Hello World'
    
    # ciphertext
    C = ''
    C += E(K1, P[ : pos-1])
    C += D(K2, P[pos-1 : ])
    
    print(f'K1: {K1}')
    print(f'K2: {K2}')
    print(f'Position: {pos} (1-based)')
    
    print(f'Plaintext : {P}')
    print(f'ciphertext: {C}')

