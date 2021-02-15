import numpy as np
import time


# generates an array of n samples from zero to limit and draws a value to search for
def random_numbers(n, limit):
    random_arr = np.random.randint(low=0, high=limit, size=n)
    random_sample = np.random.choice(random_arr)
    return random_arr, random_sample


def timed(function):
    def wrapper(*args, **kwargs):
        start = time.time()
        finish = time.time()
        fname = function.__name__
        print(f"{fname} took {finish-start} s to execute.")

    return wrapper


@timed
def binary_search(arr, x):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high)//2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            high = mid - 1
        else:
            low = mid + 1

    return -1

@timed
def linear_search(arr, x): 
    for i in range(len(arr)): 
        if arr[i] == x: 
            return i 
  
    return -1


if __name__ == "__main__":
    n = 10000000                          # 10.000.000 samples
    lim = 45 ** 5                         # from 0 to 184.528.125

    arr, value = random_numbers(n, lim)    # array and searched value
    print(f"Looking for: {value}")
    arr.sort()

    binary_search(arr, value)
    linear_search(arr, value)
 
        
    

