#why-sid
#Aim: To find evolution in typing speed of the user.
#Date: 03/10/2022
#Create a program to help user type faster. Type speed counter
import matplotlib.pyplot as plt
import time as t
times=[]
mistakes=0
print('This program will help you type faster. Type the word "Programmer" as fast as you can for five times')
input("Press Enter to continue")
while(len(times)<5):
    start=t.time()
    word=input("Type the word")
    end=t.time()
    time_elapsed=end-start
    times.append(time_elapsed)
    if(word.lower()!='programmer'):
        mistakes=mistakes+1
print("You made "+str(mistakes)+" mistakes")
print("Now let'see your evolution")
t.sleep(3)
x=[1,2,3,4,5]
y=times
legend=['1','2','3','4','5']
plt.plot(x,y)
plt.xticks(x,legend)
plt.ylabel("Time in seconds")
plt.xlabel("Attempts")
plt.title("Your Typing Evolution")
plt.show()
