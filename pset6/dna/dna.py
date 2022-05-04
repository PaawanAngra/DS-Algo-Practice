import sys
import csv
import re
def match():
    data = open(sys.argv[1],'r')
    seq = open(sys.argv[2],'r')
    data_reader = csv.DictReader(data)
    fields = data_reader.fieldnames
    s = seq.read()
    list = []
    for i in range(1,len(fields)):
        list.append(count(s,fields[i]))
    for row in data_reader:
        c = 0
        l = 0
        for i in row:
            if i == 'name':
                continue
            if int(row[i]) != list [l]:
                c = 1
            l += 1
        if c == 0:
            print(row['name'])
            sys.exit()
    print('No match')

def count(seq,pattern):
    max = 0
    c = 0
    i = 0
    while i < len(seq)-len(pattern)-1:
        sub = seq[i:i+len(pattern)]
        if sub == pattern:
            c += 1
            i += len(pattern)
        else:
            if max < c:
                max = c
            c = 0
            i += 1
    return max

if __name__ == "__main__":
    if len (sys.argv) == 3:
        match()
    else:
        print("Usage: python dna.py data.csv sequence.txt")