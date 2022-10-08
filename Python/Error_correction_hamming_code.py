def calcRedundantBits(m):
    for i in range(m):
        if(2**i >= m + i + 1):
            return i

def posRedundantBits(data, r):
    j = 0
    k = 1
    m = len(data)
    res = ''
    for i in range(1, m + r+1):
        if(i == 2**j):
            res = res + '0'
            j += 1
        else:
            res = res + data[-1 * k]
            k += 1
    return res[::-1]

def calcParityBits(pos, r):
    n = len(pos)
    for i in range(r):
        val = 0
        for j in range(1, n + 1):
            if(j & (2**i) == (2**i)):
                val = val ^ int(pos[-1 * j])
        pos = pos[:n-(2**i)] + str(val) + pos[n-(2**i)+1:]
    return pos

def flipbit(pos, n):
    if pos[n]=='0':
        temp=pos[:n]+'1'+pos[n+1:]
    else:
        temp=pos[:n]+'0'+pos[n+1:]
    return temp

def detectError(pos, nr):
    n = len(pos)
    res = 0

    for i in range(nr):
        val = 0
        for j in range(1, n + 1):
            if(j & (2**i) == (2**i)):
                val = val ^ int(pos[-1 * j])
        res = res + val*(10**i)
    return (len(pos)-int(str(res), 2)+1)

def main():
    ch="Y"
    while(ch=="Y" or ch=="y"):
        print("\n\t*** ERROR CORRECTION HAMMING CODE ***\n")
        
        data=input("Enter the data bits to be transmitted: ")
        m = len(data)
        r = calcRedundantBits(m)
        pos = posRedundantBits(data, r)
        pos = calcParityBits(pos, r)
        print("Data transferred:" + pos)
        print("Generate error for detection and correction")
        n=int(input("Enter bit position to generate error: "))
        while n>len(pos) or n<0:
            print("Incorrect position!")
            n=int(input("Enter bit position to generate error: "))
        
        pos=flipbit(pos, n-1)
        print("Error Data is " + pos)
        correction = detectError(pos, r)
        print("The position of error is " + str(correction))
        pos=flipbit(pos,correction-1)
        print("Hamming code after correction:",pos)

        ch=input("\nDo you want to try again? {Y/N}: ")
        print("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*")

main()
