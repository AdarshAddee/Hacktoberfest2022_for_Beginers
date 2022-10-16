// Github username: vishwasluhana
// Aim: create pattern to make a shape
// Date: 16-10-2022

'''
a b c d e f g f e d c b a
a b c d e f   f e d c b a
a b c d e       e d c b a
a b c d           d c b a
a b c               c b a
a b                   b a
a                       a
'''
characters = 'a b c d e f g f e d c b a'
print(characters)
for i in range(6):
    print(characters[:(int(len(characters)/2))-i*2-1],
          ' '*3 if i == 0 else ' '*(i*4+3),
          characters[(int(len(characters)/2))+2+i*2:], sep='')
