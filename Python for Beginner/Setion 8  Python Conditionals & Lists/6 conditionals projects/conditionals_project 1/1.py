
winners = ["mahmoud" , "mohamed" , "samaa" , "asmaa" , "layla" ,"rahma" , "nansy" , "ahmed" , "eslam", "ali"]

name = input("Enter your name: ").strip().lower()

if name in winners:
    print(f"Congratulation {name.title()} Is A Winner!!!")
else:
    print(f"Sorry {name.title()} Is Not A Winner")
