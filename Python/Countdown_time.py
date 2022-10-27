# Github username: https://github.com/vishwjeet-ujgare
'''
Aim: In this example, you will learn to create a countdown timer.
       To understand this example, you should have the knowledge of the following Python programming topics:
              Python while Loop
              Python divmod()
              Python time Module
'''
#  Date: 10/27/2022

#coding
import time
def countdown(time_sec):
    while time_sec:
        mins, secs = divmod(time_sec, 60)
        timeformat = '{:02d}:{:02d}'.format(mins, secs)
        print(timeformat, end='\r')
        time.sleep(1)
        time_sec -= 1

    print("stop")

countdown(5)
