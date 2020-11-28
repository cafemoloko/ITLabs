# bubble sort
import random


def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


if __name__ == "__main__":

    # generating a list of ten random numbers in range 0-30
    unsorted_arr = (random.sample(range(0, 30), 10))
    print(f"Unsorted array: {unsorted_arr}")
    sorted_arr = (bubble_sort(unsorted_arr))
    print(f"Sorted array: {sorted_arr}")