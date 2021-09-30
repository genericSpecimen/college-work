def E(K, P):
    """
    The encrypt function ignores spaces and special characters,
    and outputs them as it is. Only upper case and lower case
    alphabets get substituted.
    """
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

"""
decrypt can also be implemented as E(26-K, C),
because of the cyclic property of shift cipher
"""

#def D(K, C):
#    P = ""
#    for c in C:
#        if not c.isspace():
#            if c.isupper():
#               P += chr(((ord(c) - ord('A') - K) % 26) + ord('A'))
#           elif c.islower():
#               P += chr(((ord(c) - ord('a') - K) % 26) + ord('a'))
#           else:
#               P += c
#        else:
#           P += c
#    return P

def D(K, C):
   return E(26-K, C)

if __name__ == '__main__':
    K = 3 # key (shift) for caesar cipher
    
    # plaintext
    P = 'Hello World'
    
    # generate the ciphertext
    C = E(K, P)
    
    print(f'Key (shift): {K}')
    print(f'Plaintext  : {P}')
    print(f'Ciphertext : {C}')

    #C = 'abcd'
    
    # generate the plaintext
    P = D(K, C)
    print(f'Plaintext  : {P}  (decrypted from ciphertext)')

