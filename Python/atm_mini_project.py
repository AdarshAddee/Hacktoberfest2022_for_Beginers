# ATM MINI PROJECT by Sarthak

import numpy as np
import time

user=np.array(['Sarthak','Pranit'])  #User id
pin=np.array([2284,2297])    #Passwords
bal=np.array([10000,20000])  #Account Balance
ac=np.array([357,378])   #A/C No
OTP=np.array([100,200])  #OTP




print("   Please Insert Your CARD...")
time.sleep(3)
print("\n   Please Enter your Login Credentials:\n")
u=input('Enter user id: ')
a=int(input('Enter Your A/C No: '))
p=int(input('Enter Your password: '))

print(" \n Wait for a second...")
time.sleep(3)

if u==user[0] and p==pin[0] and a==ac[0]:
    print("\n")
    print("***************************************")
    print("*                                     *")
    print("*****WELCOME SARTHAK TO ATM SYSTEM*****")                                    
    print("*                                     *")
    print("***************************************")
    print("\n   How can we Help You:")
    print("    1)Balance Enquiry\n    2)Cash Withdrawl\n    3)Forget Password\n    4)Logout")
    choice=int(input("\nEnter your Choice: "))
    if choice==1:
        print("Your Current Balance is RS",bal[0],"\nTHANKYOU!!! for Visiting us")
    elif choice==2:
        d=eval(input("Enter Amount You want to Withdraw: "))
        print("\n  Wait... Your transaction is being proceed")
        time.sleep(3)
        if d>bal[0]:
            print("You cannot Withdraw Amount more than Your current Balance")
        else:
            print("\nYour A/C is debited by RS",d)
            print("Your Current Balance is RS",bal[0]-d,"\n \nTHANKYOU!!!")
    elif choice==3:
        u=input('Enter user id: ')
        if u==user[0]:
            print("1)Mobile No\n2)Email id")
            choice=int(input("Please Enter Your Choice through which We can send your Password: "))
            if choice==1:
                mo=eval(input("Enter Your Mobile No: "))
                print("OTP has been sent to your Mobile No")
                o=int(input("Enter OTP: "))
                print(" \n Wait for a second...\n")
                time.sleep(2)
                if o==OTP[0]:
                    print("Password has been successfully!!! sent to your Mobile number, please Remember your Password for Future Reference\nPlease Login Again if you want to perform Another Task")
                else:
                    print("Incorrect OTP\nPlease Login Again")
            elif choice==2:
                e=input("Enter Your Email id: ")
                print("OTP has been sent to your Email id")
                o=int(input("Enter OTP: "))
                print("  Wait for a second...")
                time.sleep(2)
                if o==OTP[0]:
                    print("Password has been successfully!!! sent to your Email id, please Remember your Password for Future Reference\nPlease Login Again if you want to perform Another Task")   
                else:
                    print("Incorrect OTP\nPlease Login Again")
            else:
                print("You have Entered Incorrect Choice\nPlease Login Again")
            
        else:
            print("User id is Incorrect\nPlease Login Again")        
    elif choice==4:
        print("1)YES\n2)NO")
        choice=int(input("Are you Sure: "))
        if choice==1:
            print("Thankyou!! for transactions with Our ATM SYSTEM")
            print("Never share Your Password with Anyone, Bank will never ask For Your Password")
        elif choice==2:
            print("Sorry!! Your session has Expired You Need to Login again")
        else:
            print("You have Entered Incorrect Choice")
    else:
        print("Sorry You have Entered Incorrect Choice\nPlease Login Again")
elif u==user[1]and p==pin[1]and a==ac[1]:
    print("\n")
    print("**************************************")
    print("*                                    *")
    print("*****WELCOME PRANIT TO ATM SYSTEM*****")                                    
    print("*                                    *")
    print("**************************************")
    print("\n   How can we Help You:")
    print("    1)Balance Enquiry\n    2)Cash Withdrawl\n    3)Forget Password\n    4)Logout")
    choice=int(input("\nEnter your Choice: "))
    if choice==1:
        print("Your Current Balance is RS",bal[1],"\nTHANKYOU!!! for Visiting us")
    elif choice==2:
        d=eval(input("Enter Amount You want to Withdraw: "))
        print("\n Wait... Your transaction is being proceed")
        time.sleep(3)
        if d>bal[1]:
            print("You cannot Withdraw Amount more than Your current Balance")
        else:
            print("\nYour A/C is Debited by RS",d)
            print("Your Current Balance is RS",bal[1]-d,"\n\n  THANKYOU!!!")
    elif choice==3:
        u=input('Enter user id: ')
        if u==user[1]:
            print("1)Mobile No\n2)Email id")
            choice=int(input("\nPlease Enter Your Choice through which We can send your Password: "))
            if choice==1:
                mo=eval(input("Enter Your Mobile No: "))
                print("OTP has been sent to your Mobile No")
                o=int(input("Enter OTP: "))
                print("  Wait for a second...")
                time.sleep(2)
                if o==OTP[1]:
                    print("Password has been successfully!!! sent to your Mobile number, please Remember your Password for Future Reference\nPlease Login Again if you want to perform Another Task")
                else:
                    print("Incorrect OTP\nPlease Login Again")
            elif choice==2:
                e=input("Enter Your Email id: ")
                print("OTP has been sent to your Email id")
                o=int(input("Enter OTP: "))
                print(" \n Wait for a second...\n")
                time.sleep(2)
                if o==OTP[1]:
                    print("Password has been successfully!!! sent to your Email id, please Remember your Password for Future Reference\nPlease Login Again if you want to perform Another Task")   
                else:
                    print("Incorrect OTP")
            else:
                print("Sorry You have Entered Incorrect Choice\nPlease Login Again")
        else:
            print("User id is Incorrect\nPlease Login Again")
    elif choice==4:
        print("1)YES\n2)NO")
        choice=int(input("Are you Sure: "))
        if choice==1:
            print("Thankyou!! for transactions with Our ATM SYSTEM")
            print("Never share Your Password with Anyone, Bank will never ask your Password")
        elif choice==2:
            print("Sorry!! Your session has Expired You Need to Login again")
        else:
            print("You have Entered Incorrect Choice")
    else:
        print("You have Entered Incorrect Choice\nPlease Login Again")
else:
    print("\nOOPS! Incorrect Login details")