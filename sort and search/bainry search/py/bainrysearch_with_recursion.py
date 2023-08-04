def binary_search(arr, left, right, target):
    """
    Search for a target value in a sorted array using binary search algorithm.
    Parameters:
        arr: list of integers
            The array to search in.
        left: int
            The left-most index of the sub array to search in.
        right: int1
            The right-most index of the sub array to search in.
        target: int
            The value to search for.
    Returns:
        int
            The index of the target value in the array, or -1 if not found.
    """
    # Base case: if left index exceeds right index, target is not found in array
    if left > right:
        return -1
    
    # Calculate the mid-point index
    mid = left + (right - left) // 2
    
    # If target is found at the mid-point index, return the index
    if arr[mid] == target:
        return mid
    
    # If target is greater than the mid-point value, search the right half of the array
    elif arr[mid] < target:
        return binary_search(arr, mid + 1, right, target)
    
    # If target is less than the mid-point value, search the left half of the array
    else:
        return binary_search(arr, left, mid - 1, target)
    

# Test the binary_search function
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
while True:
    try:
        target = int(input("Search for: "))
        break
    except ValueError:
        pass

index = binary_search(arr, 0, len(arr) - 1, target)

# Print the result of the binary search
if index < 0:
    print(f"{target} is not found.")
else:
    print(f"{target} is found at index {index}.")
