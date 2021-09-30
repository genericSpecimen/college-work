import numpy as np

def E(K, P):
    ncols = len(K)
    nrows = int(len(P) / len(K))
 
    m = np.array(list(P)).reshape(nrows, ncols)
    
    assigned_idx = np.argsort(K)
    
    C = ''
    for k in assigned_idx:
        col = ''.join(m[:, k])
        C += col
        
    return C

def D(K, C):
    ncols = len(K)
    nrows = int(len(C) / ncols)
    m = np.array(list(C)).reshape(ncols, nrows)
    
    P = ''
    for row in np.transpose(m[K]):
        P += ''.join(row)
        
    return P

if __name__ == '__main__':
    K = np.array([4, 3, 1, 2, 5, 6, 7])
    P = 'attackpostponeduntiltwoamxyz'
    
    #K = np.array([6, 3, 2, 4, 1, 5])
    #P = 'wearediscoveredfleeatonceqkjeu'
    
    print(f'Key:\n {K}\n')
    
    K -= 1 # for 0 based indexing
    
    # Compute the ciphertext
    C = E(K, P)
    
    print(f'Plaintext (original) : {P}')
    print(f'Ciphertext           : {C}')
    
    # Compute the plaintext
    P = D(K, C)
    print(f'Plaintext (decrypted): {P}')
