# bubble sort

def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


arr = [0, 64, 34, 20, 18, 90, 11, 14, 4]
print(arr)

bubble_sort(arr)
print(f"Sorted array: {arr}")