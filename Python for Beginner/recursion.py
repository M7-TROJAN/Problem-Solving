


def tri_recursion(k):
  if(k > 0):
    result = k + tri_recursion(k - 1)
    print(result)
  else:
    result = 0
  return result

print("\n\nRecursion Example Results")
tri_recursion(6)

# out put will be :
# 1
# 3
# 6
# 10
# 15
# 21

# explanation
#       21 = 1 + 2 + 3 + 4 + 5 + 6  هيساوي result اول لفة ال
# 
