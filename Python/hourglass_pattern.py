### Github Username - SanBuilds (https://github.com/SanBuilds)
### Hourglass pattern in python

rows = int(input("Enter the rows(height) of the hourglass: "))

for i in range(rows):
  for j in range(i):
    print('', end = ' ')
  for k in range(i,rows):
    print('*', end = ' ')
  print()

for i in range(rows,-1,-1):
  for j in range(i):
    print('', end = ' ')
  for k in range(i,rows):
    print('*', end = ' ')
  print()
