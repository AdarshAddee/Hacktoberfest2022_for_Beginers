# Github username: RanaiKuruma 
# Aim: To implement merge sort using recursion 
# Date: 4th October 2022

def __merge(a1,a2,a):
    i = 0 
    j = 0 
    k = 0 
    #Transferring the elements of the small array's into the larger array 
    while(i < len(a1) and j < len(a2)):
        if(a1[i] < a2[j]):
            a[k] = a1[i] 
            k += 1 
            i += 1 
        else:
            a[k] = a2[j]            
            k += 1 
            j += 1 

    #Copying the elements of the first small array 
    while(i < len(a1)):
        a[k] = a1[i]            
        k += 1 
        i += 1 

    #Copying the elements of the second small array 
    while(j < len(a2)):
        a[k] = a2[j]        
        k += 1 
        j += 1 

def mergeSort(a):
    n = len(a)
    if(n == 0 or n == 1):
        return -1

    mid = (n) // 2 
    a1 = a[0:mid]        
    a2 = a[mid:]

    mergeSort(a1)
    mergeSort(a2)
    __merge(a1,a2,a)

arr = [int(ele) for ele in input().split()]    
mergeSort(arr)
print(arr)

