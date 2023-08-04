# print("hello")
# print('hello')
# print('hello' + ' mahmoud')
# print('hello','mahmoud')
# print(1+2)
# print(1,2)
# name = "mahmoud"
# age = 25
# print("hello " + name)
# print("hello",name,"your age is",age)
# print(f"hello {name} how are you your age is: {age}")

# name = input("enter your name: ")
# print(name)
# while True:
#     try:
#         age = int(input("enter your age: "))
#         break
#     except ValueError:
#         print("invalid input")
#         print("your age must be a number")
# print(age+10)


# while True:
#     user = input("user name: ")
#     if user in ['mahmoud', 'm7', "Mahmoud", 'M7', "mattar", 'Mattar']:
#         print("hello "+ user)
#         break
#     print("invalid input")


# i = 1
# while i < 20:
#     if i%2 == 0:
#         i+=1
#         continue
#     print('hi', i)
#     i+=1
# print(i)


# count = 0
# for i in "mahmoud mohamed abdalaziz mousa mesbah mattar":
#     print(i)
#     count+=1
# print(count)

# my_list = [1,2,3,"mahmoud","mattar",True,1.55547,[1,4,'mn'],(1,2,3)]
# print(my_list)
# for i in my_list:
#     print(i)

# print(my_list[8][0])
# print(my_list[8][1])
# print(my_list[8][2])
# try:
#     print(my_list[8][3])
# except IndexError:
#     print("there is no element in this index ")

# my_tuple = (1,2,3,"mahmoud",True,False,1.5)

# print(my_tuple)

# my_tuple[0] = 55 // error 'tuple' object does not support item assignment

# m_set = {1 , 2 , 3 , "mahmoud" , "mohamed" , False , 1.4569870}

# print(m_set)
# m_set[1] = 87


# age =25
# match age:
#     case 1:
#         print(1)
#     case 25:
#         print("allhamd lleh")


# my_dict = {
#     "name" : "mahmoud",
#     "age"  : 25,
#     "phone": "+20 1019060452",
#     'a'    : 25,
#     'a'    : 25,
#     'a'    : 25,
#     'a'    : 25,
#     'a'    : 25,
#     'a'    : 25,
#     'a'    : 25,
#     'a'    : 25,
#     'a'    : 25,
# }

# print(my_dict)
# my_dict["name"] = "khaled"
# print("name:",my_dict["name"])
# print("age:",my_dict["age"])
# print("phone:",my_dict["phone"])
# print("phone:",my_dict["a"])



def meow_fun(n):
    if n == 0:
        return
    print("meow")
    return meow_fun(n-1)

n = int(input("n: "))
meow_fun(n)























# # functions



# def Hello(name,age):
#     print(f"Hello, {name}")
#     print("hello,",name)
#     print("your age is:",age)
#     return True

# name = input("enter your name: ")
# while True:
#     try:
#         age = int(input("enter your age: "))
#         break
#     except ValueError:
#         print("invalid input. your age should be a numeric value ")

# Hello(name,age)

# def calc(a, b):
#     return a *b

# while True:
#     try:
#         x = float(input("x:"))
#         break
#     except ValueError:
#         print("x should ba a numeric value")

# while True:
#     try:
#         y = float(input("y:"))
#         break
#     except ValueError:
#         print("y should ba a numeric value")

# res = calc(x,y)
# print(res)
