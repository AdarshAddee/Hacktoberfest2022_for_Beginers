#Github username: nishanthamms
#Aim: find your age
#Date: 2022/10/4
from datetime import date
 
def calculateAge(birthDate):
    today = date.today()
    age = today.year - birthDate.year - ((today.month, today.day) < (birthDate.month, birthDate.day))
 
    return age
     
# Driver code
print(calculateAge(date(1997, 2, 3)), "years")