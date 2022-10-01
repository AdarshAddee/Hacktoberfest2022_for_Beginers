element = [int(input("Enter yout element: ")) for number in range(int(input("Number of elements: ")))]
# Traverse through all array elements 
for i in range(len(element)): 
    # Find the minimum element in remaining  
    # unsorted array 
    min_index = i 
    for j in range(i+1, len(element)): 
        if element[min_index] > element[j]: 
            min_index = j 
    # Swap the found minimum element with  
    # the first element         
    element[i], element[min_index] = element[min_index], element[i] 
# Driver Code
print ("\nSorted Array : ") 
for i in range(len(element)): 
    print("%d" %element[i]) 