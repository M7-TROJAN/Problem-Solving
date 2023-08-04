import csv

favLanguage = {
    "C" : 0,
    "Python": 0,
    "Scratch": 0
}
with open("favorites.csv" , "r" , encoding= "utf-8") as file:
    reader = csv.DictReader(file)
    for row in reader:
        favLanguage[row["language"]] +=1

for key , val in favLanguage.items():
    print(f"{key} : {val}")

# get the height value 
max_key = None
max_val = float("-inf")   # -inf means negative infinity

for key , val in favLanguage.items():
    if val > max_val:
        max_key = key
        max_val = val

print("the key with the highest value is:",max_key)
print("the highest value is:",max_val)