from cs50 import SQL
import csv
import sys

if len(sys.argv) != 2:
    print('Please provide correct number of arguments')
    exit()

file = open (sys.argv[1], 'r')
reader = csv.DictReader(file)
db = SQL('sqlite:///students.db')
id = 1

for row in reader:
    name = row ['name']
    house = row ['house']
    birth = int(row ['birth'])
    l_name = name.split()
    if len(l_name) == 3:
        first = l_name[0]
        middle = l_name[1]
        last = l_name[2]
    elif len(l_name) == 2:
        first = l_name[0]
        middle = None
        last = l_name[1]
    db.execute ('INSERT INTO students VALUES (?,?,?,?,?,?);', (id, first, middle, last, house, birth))
    id += 1