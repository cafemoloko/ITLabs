# binary search

def binary_search(arr, x):

    # setting bounds
    low = 0
    high = len(arr) - 1

    while low <= high:
      
        mid = (low + high)//2   # looking for middle element (floor division)
       
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            high = mid - 1
        else:
            low = mid + 1

    return -1

  
if __name__ == "__main__":
   
    arr = [0, 2, 3, 4, 10, 29, 32, 40]  # sorted array
    x = 40                              # searched element 
    
    result = binary_search(arr, x) 
    
    if result != -1: 
        print(f"Element was found in the array at index {result}") 
    else: 
        print("Element is not present in the array") 
