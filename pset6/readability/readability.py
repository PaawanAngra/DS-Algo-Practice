import re
from cs50 import get_string
t = get_string("Text: ")
t = t + ' '
alpha = [chr(x) for x in range(ord('a'),ord('z')+1)]
l = 0
s = 0
w = 0
for i in t:
    if i.lower() in alpha:
        l+=1
    if i == ' ':
        w+=1
    if i in ['.','!','?']:
        s+=1
L = (l/w)*100
S = (s/w)*100
grade = round(0.0588 * L - 0.296 * S - 15.8)
if grade >= 16:
    print('Grade 16+')
elif grade <= 1:
    print('Before Grade 1')
else:
    print(f'Grade {grade}')
