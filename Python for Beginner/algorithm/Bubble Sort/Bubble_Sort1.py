
def swap(a):
    swapped = True
    n = len(a)
    while swapped:
        swapped = False
        for i in range(n-1):
            if a[i] > a[i+1]:
                a[i] , a[i+1] = a[i+1] , a[i]
                swapped = True
        n -= 1
    return a




my_list = [10,9,8,7,6,5,4,3,2,1]

print("the list before sorting:")
print(my_list)

my_list = swap(my_list)

print("the list after sorting:")
print(my_list)

