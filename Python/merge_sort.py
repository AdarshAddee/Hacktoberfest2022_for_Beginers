def merge_to_array(a, b):
    i = 0
    j = 0
    arr = []

    while i < len(a) and j < len(b):

        if a[i] < b[j]:
            arr.append(a[i])
            i += 1

        else:
            arr.append(b[j])
            j += 1

    if i == len(a):
        arr.extend(b[j:])
    else:
        arr.extend(a[i:])

    return arr


def merge_sort(input):

    if len(input) == 1:
        return input
        
    elif len(input) == 2:
        if input[0] > input[1]:
            input[1], input[0] = input[0], input[1]
        return input

    left = merge_sort(input[0: len(input) // 2])
    right = merge_sort(input[(len(input) // 2):])

    return merge_to_array(left, right)


print(merge_sort([2,1,3,5,6,7,4,7,9,11,10]))