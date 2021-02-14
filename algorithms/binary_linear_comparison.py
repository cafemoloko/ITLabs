import numpy as np
import time


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


def linear_search(arr, x): 
  
    for i in range(len(arr)): 
  
        if arr[i] == x: 
            return i 
  
    return -1

# generates an array of n samples from zero to limit and draws a value to search for
def random_numbers(n, limit):
    random_arr = np.random.randint(low=0, high=limit, size=n)
    random_sample = np.random.choice(random_arr)
    return random_arr, random_sample


if __name__ == "__main__":
    n = 10000000                          # 10.000.000 samples
    lim = 45 ** 5                         # from 0 to 184.528.125

    
    for i in range(5):
        arr, value = random_numbers(n, lim)    # array and searched value
        print(f"Looking for: {value}")
        arr.sort()

        binary_start = time.time()
        binary_result = binary_search(arr, value)
        binary_end = time.time()
        print(f"Binary search finished in: {binary_end - binary_start}s. Value found at index {binary_result}.")

        linear_start = time.time()
        linear_result = linear_search(arr, value)
        linear_end = time.time()
        print(f"Linear search finished in: {linear_end - linear_start} s. Value found at index {linear_result}.")
    

""" Looking for: 96613070
    Binary search finished in: 0.0002048015594482422s. Value found at index 5233331.
    Linear search finished in: 2.052222728729248 s. Value found at index 5233331.
    Looking for: 59751316
    Binary search finished in: 8.845329284667969e-05s. Value found at index 3237518.
    Linear search finished in: 1.2841665744781494 s. Value found at index 3237518.
    Looking for: 129553441
    Binary search finished in: 8.320808410644531e-05s. Value found at index 7020196.
    Linear search finished in: 2.743269443511963 s. Value found at index 7020196.
    Looking for: 69923640
    Binary search finished in: 8.916854858398438e-05s. Value found at index 3788910.
    Linear search finished in: 1.4806265830993652 s. Value found at index 3788910.
    Looking for: 8103925
    Binary search finished in: 9.036064147949219e-05s. Value found at index 438800.
    Linear search finished in: 0.17279767990112305 s. Value found at index 438800. """

