# AdrshCode
zero = int(False)
one = int(True)
hundred = int(f"{one}{zero}{zero}")


def shownum(i):
    if i <= hundred:
        print(i)
        shownum(i + one)


shownum(one)
    
    
