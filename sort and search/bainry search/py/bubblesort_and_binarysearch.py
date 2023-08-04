def main():
    # Initialize an empty list and get the number of names to input
    my_list = []
    n = int(input("Enter the number of names: "))
    
    # Loop over the range of n to input each name and append it to the list
    for i in range(n):
        name = input(f"Enter name {i+1}: ")
        my_list.append(name)
    
    # Print the list before sorting
    print("The list before sorting:")
    print(*my_list, sep=" ")  # Use unpacking operator and sep to print list elements with a space separator

    # Sort the list using bubble sort
    bubblesort(my_list, n)

    # Print the list after sorting
    print("\nThe list after sorting:")
    print(*my_list, sep=" ")

    # Get the target name to search for
    target = input("Enter a name to search for: ")

    # Search for the target name using binary search
    index = binarysearch(my_list, 0, n-1, target)

    # Print the result of the search
    if index == -1:
        print(f"{target} is not found.")
    else:
        print(f"{target} is found at index {index}.")


def bubblesort(arr, n):
    # Implement bubble sort to sort the list
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


def binarysearch(arr, left, right, target):
    # Implement binary search to find the target name in the list
    if right >= left:
        mid = (right + left) // 2

        if arr[mid] == target:
            return mid

        elif arr[mid] > target:
            return binarysearch(arr, left, mid-1, target)

        else:
            return binarysearch(arr, mid+1, right, target)

    else:
        return -1


if __name__ == '__main__':
    main()
