# GitHub Username: saharshbhansali
# Aim: A Basic Implementation of RSA
# Date: 2020-10-10


"""
Quick Hacky Implementation of RSA
Credits: https://www.github.com/ACM-VIT/Codex-Cryptum
We can get varous values for e from: https://www.cs.drexel.edu/~jpopyack/IntroCS/HW/RSAWorksheet.html
"""

def ExtendedGCD(e: int):
    d = 1
    e2 = e
    top1 = phi
    top2 = phi

    # Extended Euclidean GCD
    while e2 != 1:
        k = top1 // e2
        # 192 // 5 = 38

        oldTop1 = top1
        oldTop2 = top2

        top1 = e2
        top2 = d

        e2 = oldTop1 - k * e2
        d  = oldTop2 - k * d

        if d < 0:
            d = d % phi
    
    return d

def encrypt(plaintext: str, publicKey, n: int):
    # str bytes hex int -> pow encrypt -> pow decrypt -> int hex bytes str
    # n is the block size. The constraint is that 16**(n+1) < e and d
    e = publicKey[0]
    N = publicKey[1]

    ciphertext = ''
    for i in range(0, len(plaintext), n):
        if len(plaintext[i:i+n]) < n:
            text = plaintext[i:i+n] + ' '*(n - len(plaintext[i:i+n]))
        else:
            text = plaintext[i:i+n]
        s_i = int(text.encode().hex(), 16)
        cipher = pow(s_i, e, N)
        ciphertext += str(cipher) + ' '
    return str(ciphertext)

def decrypt(ciphertext, privateKey):
    d = privateKey[0]
    N = privateKey[1]
    message = ''
    c = ''
    for i in ciphertext.split(' '):
        try: c = int(i)
        except: c = '0'
        try: decrypted = str(pow(c, d, N))
        except: return message
        decrypted = hex(int(decrypted))[2:]
        m = bytes.fromhex(decrypted).decode()
        message += str(m)
        c = ''
    return message

'''
P = long int(input("Enter P: "))
Q = long int(input("Enter Q: "))
e = long int(input("Enter e: "))
'''
n = int(input("Enter block size: "))
plaintext = input("Enter plaintext:\n>>> ")

# 1024 bit key
P = 170007611163882156467583070449223838584656753148867131633512190380283049593667937234054209916788376143894984910718820080485130228317492395177494053588704733242066260215738749826985323020318900966858054745093276666701971181051299894745771442097807356197274229456637808451705389506462483315002459525647
Q = 481643715591972638598218313298174701613643321254523884689569786332541775926781293302556117738302307356981609721753075739005830996780920022755885174107599088199228946117515541982018885577402946246815718309298010594221374531947169982607824253065171036917904012166986458504590468987728792073331236197449
e = 2**16 + 1

N   = P * Q 
phi = (P-1) * (Q-1)

d = ExtendedGCD(e)
ciphertext = encrypt(plaintext, [e,N], n)
message = decrypt(ciphertext, [d,N])

print("RSA Components")
print("P: ", P)
print("Q: ", Q)
print("N: ", N)
print("phi: ", phi)
print("e: ", e)
print("d: ", d)
print("n: ", n)
print()
print("Ciphertext:", ciphertext)
print()
print("Message: ", message)
