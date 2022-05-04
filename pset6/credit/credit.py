from cs50 import get_string

def checksum(num):
    sum = 0
    for i in range(-2,-len(num) - 1, -2):
        temp = str(int(num [i]) * 2)
        for c in temp:
            sum = sum + int(c)
    for i in range(-1,-len(num) - 1, -2):
        sum = sum + int(num [i])
    return sum

def main():
    num = get_string("Number: ")
    if(len(num) == 15 and num[0]+num[1] in ['34', '37']):
        sum = checksum(num)
        if (sum % 10 == 0):
            print("AMEX")
        else:
            print("INVALID")

    elif((len(num) == 13 or len(num) == 16) and num[0] == '4'):
        sum = checksum(num)
        if (sum % 10 == 0):
            print("VISA")
        else:
            print("INVALID")


    elif(len(num) == 16 and int(num[0]+num[1]) in range(51,56)):
        sum = checksum(num)
        if (sum % 10 == 0):
            print("MASTERCARD")
        else:
            print("INVALID")

    else:
        print("INVALID")

if __name__ == "__main__":
    main()






