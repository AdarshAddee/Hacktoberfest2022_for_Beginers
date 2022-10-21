'''  Repeated more than once only one number ''' # return small duplicated number
''' Pigeonhole Principle'''


def findDyuplicate(nums):
    nums.sort()
    for i in range (1, len(nums)):
        if (nums [i]  == nums [i-1]):
            return nums[i]

print(findDyuplicate([1,2,3,3,4,4,6,8]))


'''DICTIONARY'''
# Program to find most frequent
# element in a list
 
def most_frequent(List):
    dict = {}
    count, itm = 0, ''
    for item in reversed(List):
        dict[item] = dict.get(item, 0) + 1
        if dict[item] >= count :
            count, itm = dict[item], item
    return(itm)
 
List = [1,2,3,3,4,4,6,8]
print(most_frequent(List))





 #most nearable duplicate number in an array
" TRIVAL METHOD "
def duplicate(numbers):

    tortoise = numbers[0]
    hare = numbers[0]
    while True:
        tortoise = numbers[tortoise]
        hare = numbers[numbers[hare]]
        if tortoise == hare:
            break

    ptr1 = numbers[0]
    ptr2 = tortoise
    while ptr1 != ptr2:
        ptr1 = numbers[ptr1]
        ptr2 = numbers[ptr2]

    return ptr2

print(duplicate([1,2,3,3,4,4,6,8]))
