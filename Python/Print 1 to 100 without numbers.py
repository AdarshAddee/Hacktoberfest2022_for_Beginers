zero = int(False)
one = int(True)
hundred = int(f"{one}{zero}{zero}")

def shownum():
    for i in range (one, hundred+one):
        print(i)


shownum()
