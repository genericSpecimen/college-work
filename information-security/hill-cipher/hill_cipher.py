import numpy as np

# multiplicative inverses of numbers mod 26
mul_inv_mod26 = {
    1 : 1,
    3 : 9,
    5 : 21,
    7 : 15,
    9 : 3,
    11 : 19,
    15 : 7,
    17 : 23,
    19 : 11,
    21 : 5,
    23 : 17
}

"""
The 'minor' function is used as a subroutine in
calculation of the inverse of the key matrix (mod 26)
"""
def minor(K, i, j):
    m = np.delete(K, i, 0) # delete ith row
    m = np.delete(m, j, 1) # delete jth column
    return m

"""
To decrypt the ciphertext, we need to compute the inverse
of the key K (mod 26).
The 'inverse_mod26' function calculates the inverse of
a matrix K performing mod 26 arithmetic at each step.
"""
def inverse_mod26(K):
    detK_mod26 = np.round(np.linalg.det(K)) % 26
    detKinv_mod26 = mul_inv_mod26[detK_mod26]
    
    order = K.shape[0]
    cofactorK = np.zeros(shape=(order, order))
    
    for i in range(order):
        for j in range(order):
            cofactorK[i][j] = ((-1) ** (i+j)) * np.round(np.linalg.det(minor(K, i, j)))
    
    adjK = np.transpose(cofactorK)
    adjK_mod26 = adjK % 26
    
    Kinv_mod26 = (detKinv_mod26 * adjK_mod26) % 26
    return Kinv_mod26.astype(int)

"""
The encryption function takes a key matrix K and
encrypts the plaintext using K. For a matrix of
order 3, three characters of the plaintext are
taken at one time and multiplied with K to get
the corresponding ciphertext characters.
"""
def E(K, P):
    # ciphertext to be returned
    C = ''
    order = K.shape[0]
    
    for i in range(0, len(P), order):
        # take the group of 'order' number of characters from the plaintext
        group = P[i : i+order]
        group_vec = [(ord(c) - ord('a')) for c in group]
        
        # multiply the vector with the matrix (dot product)
        encrypted_group_vec = np.dot(group_vec, K) % 26
        encrypted_group = [chr(x + ord('a')) for x in encrypted_group_vec]
        
        # append the encrypted characters to the complete ciphertext
        C += ''.join(encrypted_group)
        
    return C

"""
The decryption function takes a key matrix K and
decrypts the ciphertext using inverse_mod26(K).
For a matrix of order 3, three characters of the
ciphertext are taken at one time and multiplied
with inverse_mod26(K) to get the corresponding
plaintext characters.
"""
def D(K, C):
    # plaintext to be returned
    P = ''
    order = K.shape[0]
    
    # compute the (mod 26) inverse of key matrix K
    Kinv_mod26 = inverse_mod26(K).astype(int)
    
    for i in range(0, len(C), order):
        group = C[i : i+order]
        group_vec = [(ord(c) - ord('a')) for c in group]
        
        decrypted_group_vec = np.dot(group_vec, Kinv_mod26) % 26
        decrypted_group = [chr(x + ord('a')) for x in decrypted_group_vec]
        
        P += ''.join(decrypted_group)
        
    return P

if __name__ == '__main__':

    # plaintext
    P = 'paymoremoney'
    #P = 'attackatdawn'
    
    # key
    K = np.array([
        [17, 17, 5],
        [21, 18, 21],
        [2, 2, 19]
    ])

    #K = np.array([
    #    [2, 4, 5],
    #    [9, 2, 1],
    #    [3, 17, 7]
    #])

    print(f'Key:\n {K}\n')

    # Compute the ciphertext
    C = E(K, P)

    print(f'Plaintext (original) : {P}')
    print(f'Ciphertext           : {C}')
    
    # Compute the plaintext
    P = D(K, C)
    print(f'Plaintext (decrypted): {P}')
