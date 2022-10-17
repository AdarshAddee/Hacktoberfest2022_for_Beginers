# miswaryousuf
# Calculate the angles of right-angled triangle using its sides
# Date: 18-10-2022

from math import *
print("Calculate the angles of right-angled triangle using its sides")
print("Enter the sides of the right-angled triangle:")
a, b = int(input()), int(input())
ang1 = degrees( atan(a/b) )
ang2 = 90 - ang1
print('The angles of right-angled triangle are', '{:.2f}'.format(ang1), 'and', '{:.2f}'.format(ang2))

