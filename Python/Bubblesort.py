# Github username: SaiAvinash2002
# Aim: Bubble Sort
# Date: 03/10/22

def bubbleSort(arr):
	n = len(arr)

	for i in range(n):

		for j in range(0, n-i-1):

			
			if arr[j] > arr[j+1]:
				arr[j], arr[j+1] = arr[j+1], arr[j]


# Driver code to test above
if __name__ == "__main__":
arr = [64, 34, 25, 12, 22, 11, 90]

bubbleSort(arr)

print("Sorted array is:")
for i in range(len(arr)):
	print("%d" % arr[i], end=" ")
