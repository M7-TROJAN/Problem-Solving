# type          brackets          ordered          mutable            duplicate          use

# list          []                yes              yes                yes                عام
# tuple         ()                yes              no                 yes                الأحداثيات
# set           {}                no               no                 no                 العمليات الرياضية
# dict          {}                yes              yes by access     yes for values      قواعد البيانات
#                                                  with key          no for keys


# first list []
print('\n.................. list ...........................\n')
my_list = [1, 'hello', True, 1.5, [5, 'semsem']]
print(my_list,"\n")                     # [1, 'hello', True, 1.5, [5, 'semsem']]
print("my_list[0]    = ",my_list[0])    # 1
print("my_list[1]    = ",my_list[1])    # hello
print("my_list[2]    = ",my_list[2])    # True
print("my_list[3]    = ",my_list[3])    # 1.5
print("my_list[4]    = ",my_list[4])    # [5, 'semsem']
print("my_list[4][0] = ",my_list[4][0]) # 5
print("my_list[4][1] = ",my_list[4][1]) # semsem
#............................................................................................................

# second tuple ()
print('\n.................. tuple ...........................\n')
my_tuple = (1, 'mahmoud', 1998, [1.5, False])
print(my_tuple,"\n")                       # (1, 'mahmoud', 1998, [1.5, False])
print("my_tuple[0]    = ",my_tuple[0])     # 1
print("my_tuple[1]    = ",my_tuple[1])     # mahmoud
print("my_tuple[2]    = ",my_tuple[2])     # 1998
print("my_tuple[3]    = ",my_tuple[3])     # [1.5, False]
print("my_tuple[3][0] = ",my_tuple[3][0])  # 1.5
print("my_tuple[3][1] = ",my_tuple[3][1])  # False
#............................................................................................................

# third set {}
print('\n.................. set ...........................\n')
my_set = {1, 1.5, False, 'ABC', (1,2,3)} 
print(my_set,'\n')
# print(my_set[0])  //Error TypeError: 'set' object is not subscriptable

my_set2 = {1 , 1 , 1 , 1 , 1 , 1 , 1 , 1}
print(my_set2,'\n') # / output -> {1}
#............................................................................................................

# 4th dict {}
print('\n.................. dict ...........................\n')

car = {
    "color" : "Red",
    "model" : 2022,
    "price" : 2000000
}
print(car)
print(car["color"])
print(car["model"])
print(car["price"])





# search for -> isinstance() function its important