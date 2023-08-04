
def binary_search(arr, target):
    """
    Perform binary search on a sorted list to find the index of a target value.

    Args:
        arr (list): A sorted list of integers.
        target (int): The value to search for in the list.

    Returns:
        int: The index of the target value in the list, or -1 if it is not found.
    """

    # Initialize left and right pointers to the first and last indices of the list, respectively.
    left = 0
    right = len(arr) - 1

    while left <= right:
        # Calculate the middle index of the sublist.
        mid = left + (right - left) // 2

        if arr[mid] == target:
            # If the middle element is the target, return its index.
            return mid
        elif arr[mid] < target:
            # If the middle element is less than the target, the target must be in the right half of the sublist.
            left = mid + 1
        else:
            # If the middle element is greater than the target, the target must be in the left half of the sublist.
            right = mid - 1

    # If the target is not found, return -1.
    return -1


def main():
    # Initialize a sorted list of integers.
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    # Prompt the user to input a search target.
    target = int(input("Enter a number to search for: "))

    # Call binary_search to find the index of the target value in the list.
    result = binary_search(arr, target)

    if result == -1:
        # If the target is not found, print a message indicating so.
        print(f"{target} is not found in the list.")
    else:
        # If the target is found, print its index in the list.
        print(f"{target} is found at index {result}.")


if __name__ == "__main__":
    main()
