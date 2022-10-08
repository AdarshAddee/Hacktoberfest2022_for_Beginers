# Github username: MuShaf-NMS
# Aim: Create a recursive merge sort in python
# Date: 08-10-2022

def merge(left, right):
  l_length, r_length = len(left), len(right)
  l_index, r_index = 0, 0
  result = []
  for i in range(l_length + r_length):
    if left[l_index] < right[r_index]:
      result.append(left[l_index])
      l_index += 1
    else:
      result.append(right[r_index])
      r_index += 1
    
    if l_index == l_length or r_index == r_length:
      result.extend(left[l_index:] or right[r_index:])
      break
  return result

def merge_sort(l):
  if len(l) < 2:
    return l
  
  middle = int(len(l)/2)
  left, right = merge_sort(l[:middle]), merge_sort(l[middle:])
  return merge(left, right)

l = [335, 755, 227, 725, 984, 799, 544, 277, 265, 603, 852, 288, 24, 802, 299, 163, 835]
print("before:", l)
res = merge_sort(l)
print("after:", res)