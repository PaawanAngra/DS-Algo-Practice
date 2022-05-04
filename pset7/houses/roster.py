from cs50 import SQL
import sys

if len(sys.argv) != 2:
    print('Please provide correct number of arguments')
    exit()

db = SQL('sqlite:///students.db')
list = db.execute('SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first;', sys.argv[1])
for row in list:
    if row ['middle'] == None:
        print(f'{row ["first"]} {row ["last"]}, born {row ["birth"]}')
    else:
        print(f'{row ["first"]} {row ["middle"]} {row ["last"]}, born {row ["birth"]}')