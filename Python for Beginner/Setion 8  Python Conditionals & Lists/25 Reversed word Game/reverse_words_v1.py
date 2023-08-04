import random
import time
# list of words
words = [
'have', 'that', 'they', 'with', 'this', 'from', 'which', 'would', 'will', 
'there',
'make', 'when', 'more', 'other', 'what', 'time', 'about', 'than', 'into', 
'could', 
'state', 'only', 'year', 'some', 'take', 'come', 'these', 'know', 'like', 
'then', 
'first', 'work', 'such', 'give', 'over', 'think', 'most', 'even', 'find', 
'also', 
'after', 'many', 'must', 'look', 'before', 'great', 'back', 'through', 
'long', 
'where', 'much', 'should', 'well', 'people', 'gouda', 'just', 'because', 
'good', 
'each', 'those', 'feel', 'seem', 'high', 'place', 'little', 'world', 
'very', 'still', 
'nation', 'hand', 'life', 'tell', 'write', 'become', 'here', 'show', 
'house', 'both', 
'between', 'need', 'mean', 'call', 'develop', 'under', 'last', 'right', 
'move', 'thing', 
'general', 'school', 'never', 'same', 'another', 'begin', 'while', 
'number', 'part', 
'turn', 'real', 'leave', 'might', 'want', 'point', 'form', 'child', 
'small', 'since', 
'against', 'late', 'home', 'interest', 'large', 'person', 'open', 
'public', 'follow', 
'during', 'present', 'without', 'again', 'hold', 'codezilla', 'govern', 
'around', 
'head', 'consider', 'word', 'program', 'problem', 'however', 'lead', 
'system', 
'order', 'plan', 'keep', 'face', 'group', 'play', 'stand', 'increase', 
'early', 'course', 'change', 'help', 'line', 'possible', 'fact', 'down'
]

# get a random index frow words list
random_index = random.randint(0,len(words)-1)
random_word = words[random_index]

# reverse the word
random_word = random_word[::-1]

print('Welcome to the Reserved Words Game!')
print('-'*20)
# record the start time
start_time = time.time()
print(f"The Reversed Word IS {random_word}")
print('-'*20)

# make the guess
guess = input("The Word Is: ").strip()

# record the end time
end_time = time.time()
print('-'*20)

# calculate the answer time
answer_time = end_time - start_time

# check the guess
if guess == words[random_index] and answer_time <= 6:
    print("You Win!")
else:
    if guess != words[random_index]:
        print('Wrong word!')
    if answer_time >= 5:
        print('You took too long!')
    print('You lost!')
