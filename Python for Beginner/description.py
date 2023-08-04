
""" files in py """

# r   =>  only read                                    "cannot make the file if it not exist"
# w   =>  only write          "clear old data"         "it's make the file if it not exist"
# a   =>  only append         "save the old data"      "it's make the file if it not exist"

# r+  =>  read and write                               "cannot make the file if it not exist"
# w+  =>  write and read       "clear old data"        "it's make the file if it not exist"
# a+  =>  append and read      "save the old data"     "it's make the file if it not exist"


# "r" - Read - Default value. Opens a file for reading, error if the file does not exist

# "a" - Append - Opens a file for appending, creates the file if it does not exist

# "w" - Write - Opens a file for writing, creates the file if it does not exist

# "x" - Create - Creates the specified file, returns an error if the file exist


# In addition you can specify if the file should be handled as binary or text mode:

    # "t" - Text - Default value. Text mode

    # "b" - Binary - Binary mode (e.g. images)



# file seek

# Seek Operation Meaning:

# f.seek(0)	           Move file pointer to the beginning of a File
# f.seek(5)	           Move file pointer five characters ahead from the beginning of a file.
# f.seek(0, 2)	       Move file pointer to the end of a File
# f.seek(5, 1)	       Move file pointer five characters ahead from the current position.
# f.seek(-5, 1)	       Move file pointer five characters behind from the current position.
# f.seek(-5, 2)	       Move file pointer in the reverse direction. Move it to the 5th character from the end of the file






""" open files """

# method 1:

file = open("file path" , "mode" , encoding= "utf-8")

# do what you want her

file.close()


# method 2:

with open("file path" , "mode" , newline=""  ,encoding= "utf-8") as file:
    # do what you want her



