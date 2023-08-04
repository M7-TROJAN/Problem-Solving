
#  write str
s = "mahmoud,01019060452\n"
with open("myfile.txt" , "a" , encoding="utf-8") as f:
    f.write(s)


# write lines -> list of data
li = ["mahmoud\n", "01019060452\n"]
with open("myfile.txt" , "a" , encoding="utf-8") as f:
    f.writelines(li)
