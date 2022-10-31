from time import sleep
from threading import Timer

def sleep_sort(val):
    arr = [] #stores slept elements
    def appen(v):
        arr.append(v) #Adds the element from sleeping to arr
    first = val[0] #first element in list
    for i in val:
        if first < i: #if element is less than
            first = i #then  it has sleep for so long as i
        Timer(i, appen, [i]).start() #start sleep for i
    sleep(first+1)
    return arr

arr1 = [2,7,1,6,3,2]#might take from 7-8 seconds
print("Initial Array")
print(arr1)

print("Array after sorting...")
arr2 = sleep_sort(arr1)#elements wake up according to order sleeping
print(arr2)
