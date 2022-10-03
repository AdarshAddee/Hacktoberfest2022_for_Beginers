def selection_sort(numbers):

  print("Before Sorting:", numbers)  #size/length is = 5

  for i in range(len(numbers)-1): #0,1,2,3 (Iteration 4)

      #finding the minimum value from partition to rest of data
      #partition/index is moving to right
    
      for j in range(i+1, len(numbers)):
       
        #comparing the selected index value with its next index value

        if numbers[j] < numbers[i]:
          
          #swapping partition's left value with the right value

          numbers[i], numbers[j] =  numbers[j], numbers[i]

  print('After Sorting:', numbers)