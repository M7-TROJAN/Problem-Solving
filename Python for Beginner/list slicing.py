

lst = [1,2,3,4,5,6,7,8,9,10]

print("=" * 40)

print("all elements")
for i in lst:
    print(i)

print("=" * 40)

print("from index 1 to index 3")
for i in lst[1:4]:
    print(i)

print("=" * 40)

print("from begin to index 5")
for i in lst[:6]:
    print(i)


print("=" * 40)

print("from index 3 to end of list")
for i in lst[3:]:
    print(i)

print("=" * 40)



names = ['Ahmed', 'Mohamed', 'Ali', 'Mahmoud', 'Khaled']

print(names[:-5])

