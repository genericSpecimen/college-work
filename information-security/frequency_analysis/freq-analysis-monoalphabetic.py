from pprint import pprint
from collections import Counter

# taken from William Stallings book
unigram_freq = {
    'E' : 0.12702,
    'T' : 0.09056,
    
    'A' : 0.08167,
    'O' : 0.07507,
    'I' : 0.06996,
    'N' : 0.06749,
    'S' : 0.06327,
    'H' : 0.06094,
    'R' : 0.05987,
    
    'D' : 0.04253,
    'L' : 0.04025,
    
    'C' : 0.02782,
    'U' : 0.02758,
    'M' : 0.02406,
    'W' : 0.02360,
    'F' : 0.02228,
    'G' : 0.02015,
    'Y' : 0.01974,
    'P' : 0.01929,
    
    'B' : 0.01492,
    'V' : 0.00978,
    'K' : 0.00772,
    'J' : 0.00153,
    'X' : 0.00150,
    'Q' : 0.00095,
    'Z' : 0.00074
}

unigram_freq_intervals = {
    'veryhigh'  : ['E', 'T'],
    'high'      : ['A', 'O', 'I', 'N', 'S', 'H', 'R'],
    'medium'    : ['D', 'L'],
    'low'       : ['C', 'U', 'M', 'W', 'F', 'G', 'Y', 'P'],
    'verylow'   : ['B', 'V', 'K', 'J', 'X', 'Q', 'Z']
}

# taken from https://en.wikipedia.org/wiki/Bigram
bigram_freq = {
    
    'TH' : 0.0152,
    'HE' : 0.0128,
    
    'IN' : 0.0094,
    'ER' : 0.0094,
    'AN' : 0.0082,
    
    'RE' : 0.0068,
    'ND' : 0.0063,
    'AT' : 0.0059,
    'ON' : 0.0057,
    'NT' : 0.0056,
    'HA' : 0.0056,
    'ES' : 0.0056,
    'ST' : 0.0055,
    'EN' : 0.0055,
    'ED' : 0.0053,
    'TO' : 0.0052,
    'IT' : 0.0050,
    'OU' : 0.0050,
    'EA' : 0.0047,
    'HI' : 0.0046,
    'IS' : 0.0046,
    'OR' : 0.0043,
    
    'TI' : 0.0034,
    'AS' : 0.0033,
    'TE' : 0.0027,
    'ET' : 0.0019,
    'NG' : 0.0018,
    'OF' : 0.0016,
    
    'AL' : 0.0009,
    'DE' : 0.0009,
    'SE' : 0.0008,
    'LE' : 0.0008,
    'SA' : 0.0006,
    'SI' : 0.0005,
    'AR' : 0.0004,
    'VE' : 0.0004,
    'RA' : 0.0004,
    'LD' : 0.0002,
    'UR' : 0.0002
    
}

bigram_freq_intervals = {
    'veryhigh'  : ['TH', 'HE'],
    'high'      : ['IN', 'ER', 'AN'],
    'medium'    : ['RE', 'ND', 'AT', 'ON', 'NT', 'HA', 'ES', 'ST', 'EN', 'ED', 'TO', 'IT', 'OU', 'EA', 'HI', 'IS', 'OR'],
    'low'       : ['TI', 'AS', 'TE', 'ET', 'NG', 'OF'],
    'verylow'   : ['AL', 'DE', 'SE', 'LE', 'SA', 'SI', 'AR', 'VE', 'RA', 'LD', 'UR']
}

# taken from https://en.wikipedia.org/wiki/Trigram
trigram_most_freq = {
    'THE' : 0.0181,
    'AND' : 0.0073,
    'THA' : 0.0033,
    'ENT' : 0.0042,
    'ING' : 0.0072,
    'ION' : 0.0042,
    'TIO' : 0.0031,
    'FOR' : 0.0034,
    'OFT' : 0.0022,
    'STH' : 0.0021
}

# taken from http://practicalcryptography.com/cryptanalysis/letter-frequencies-various-languages/english-letter-frequencies/
quadgram_most_freq = {
    'TION' : 0.0031,
    'THAT' : 0.0021,
    'THES' : 0.0018,
    'WITH' : 0.0018,
    'HERE' : 0.0013,
    'MENT' : 0.0012,
    'THEM' : 0.0012,
    'FROM' : 0.0010,
    'THIS' : 0.0010,
    'TING' : 0.0010,
    'IONS' : 0.0010,
    'HAVE' : 0.0010
}

def hamming_distance(P, attempt):
    d = sum(ci != cj for ci, cj in zip(P, attempt))
    return d

# computes relative frequencies and
# sorts the dictionary in reverse
def r_sort(d, total):
    total = len(C)
    for k, v in d.items():
        d[k] /= total
    d = sorted(d.items(), key=lambda item : item[1], reverse=True)
    #pprint(d)
    return d

def make_attempts(C, letter_map):
    attempts = dict()
    for key in letter_map:
        possible_subs = letter_map[key]
        #print(f'{key} : {possible_subs}')
        for sub in possible_subs:
            #print('----------')
            #print(f'{key} :')
            
            attempt = C
            for k1, s1 in zip(key, sub):
                #print(f'    => Replacing {k1} by {s1}')
                attempt = attempt.replace(k1, s1.lower())
            
            hd = hamming_distance(P.upper(), attempt.upper())
            #print(hd)
            attempts[hd] = attempt
            #print('----------')
    return attempts

def refine_attempts(attempts, mappings):
    prev_attempts = attempts.copy()
    
    for key in prev_attempts:
        attempt = prev_attempts[key]
        for c in attempt:
            if (c.isupper()):
                for s in mappings[c]:
                    attempt = attempt.replace(c, s.lower())
                    hd = hamming_distance(P.upper(), attempt.upper())
                    attempts[hd] = attempt
    return attempts

def top_K(attempts, K):
    attempts = sorted(attempts.items(), key=lambda item : item[0])
    topK_attempts = []
    for i in range(K):
        topK_attempts.append(attempts[i])
    return dict(topK_attempts)

#if __name__ == '__main__':

P = 'itwasdisclosedyesterdaythatseveralinformalbutdirectcontactshavebeenmadewithpoliticalrepresentativesofthevietconginmoscow'

C = 'UZQSOVUOHXMOPVGPOZPEVSGZWSZOPFPESXUDBMETSXAIZVUEPHZHMDZSHZOWSFPAPPDTSVPQUZWYMXUZUHSXEPYEPOPDZSZUFPOMBZWPFUPZHMDJUDTMOHMQ'

letter_map = dict()
attempts = dict()

# ----------- UNIGRAM FREQUENCY ANALYSIS -------------------
unigram_freq = dict(r_sort(Counter(C), len(C)))
#pprint(unigram_freq)

for c in unigram_freq:
    f = unigram_freq[c]
    if (f >= 0.08):
        letter_map[c] = unigram_freq_intervals['veryhigh']
    elif (f >= 0.05):
        letter_map[c] = unigram_freq_intervals['veryhigh'] + unigram_freq_intervals['high']
    elif (f >= 0.02):
        letter_map[c] = unigram_freq_intervals['medium'] + unigram_freq_intervals['low']
    else:
        letter_map[c] = unigram_freq_intervals['verylow'] 

#pprint(letter_map)

# ----------------------------------------------------------

# ----------- BIGRAM FREQUENCY ANALYSIS -------------------
bigrams = [C[i:i+2] for i in range(0,len(C))]
bigram_freq = dict(r_sort(Counter(bigrams), len(bigrams)))
#pprint(bigram_freq)

for c in bigram_freq:
    f = bigram_freq[c]
    if (f >= 0.01):
        letter_map[c] = bigram_freq_intervals['veryhigh']
    elif (f >= 0.008):
        letter_map[c] = bigram_freq_intervals['veryhigh'] + bigram_freq_intervals['high']
    elif (f >= 0.004):
        letter_map[c] = bigram_freq_intervals['veryhigh'] + bigram_freq_intervals['high'] + bigram_freq_intervals['medium']
    else:
        letter_map[c] = bigram_freq_intervals['veryhigh'] + bigram_freq_intervals['high'] + bigram_freq_intervals['medium'] + bigram_freq_intervals['low'] + bigram_freq_intervals['verylow']
#pprint(letter_map)

# ---------------------------------------------------------


# ----------- TRIGRAM FREQUENCY ANALYSIS -------------------
trigrams = [C[i:i+3] for i in range(0,len(C))]
trigram_freq = dict(r_sort(Counter(trigrams), len(trigrams)))
#pprint(trigram_freq)


for c in trigram_freq:
    #f = trigram_freq[c]
    letter_map[c] = list(trigram_most_freq.keys())

# ----------------------------------------------------------

# ----------- QUADGRAM FREQUENCY ANALYSIS -------------------
quadgrams = [C[i:i+4] for i in range(0,len(C))]
quadgram_freq = dict(r_sort(Counter(quadgrams), len(quadgrams)))
#pprint(quadgram_freq)


for c in quadgram_freq:
    #f = quadgram_freq[c]
    letter_map[c] = list(quadgram_most_freq.keys())

# -----------------------------------------------------------

attempts = make_attempts(C, letter_map)

topK_attempts = top_K(attempts, len(attempts))
#topK_attempts = attempts

mappings = dict()
for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
    mappings[c] = []

for key in topK_attempts:
    attempt = topK_attempts[key]
    for c1, c2 in zip(C, attempt):
        if c2.islower() and c2 not in mappings[c1]:
            mappings[c1].append(c2)

attempts = refine_attempts(topK_attempts, mappings)

K = 10
topK_attempts = top_K(attempts, 10)

print("Top K plaintexts: ")
print("----------------------")
pprint(topK_attempts)
print("----------------------")

# plausible mappings after looking at the generated plaintexts
mapping = {
    'U' : 'i',
    'Z' : 't',
    'Q' : 'w',
    'S' : 'a',
    'O' : 's',
    'W' : 'h',
    'P' : 'e',
}

attempt = C
for c in mapping:
    attempt = attempt.replace(c, mapping[c])

P_attempt = attempt

# now we look at the frequencies of each letter left undeciphered,
# and try to find a plausible mapping
possible_mappings = {
    'V' : ['d', 'l'],
    'E' : ['o', 'n', 'r'],
    'A' : ['v', 'b', 'p', 'y', 'g'],
    'D' : ['l', 'd', 'r', 'n'],
    'T' : ['c', 'u', 'm', 'w', 'f', 'g', 'y', 'p'],
    'X' : ['r', 'd', 'l'],
    'M' : ['o', 'n', 'r'],
    'G' : ['g', 'y', 'p', 'b'],
    'B' : ['c', 'u', 'm', 'w', 'f', 'g', 'y', 'p'],
}


attempts = make_attempts(P_attempt, possible_mappings)
topK_attempts = top_K(attempts, len(attempts))

attempts = refine_attempts(topK_attempts, mappings)

K = 10
topK_attempts = top_K(attempts, 10)

print(f'Top K = {K} plaintexts: (after trying a few more mappings)')
print("----------------------")
pprint(topK_attempts)
print("----------------------")


print(f' P :  {P}')
