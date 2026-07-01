# Hecho en 25 minutos

def digit_to_word(digit):
    return {0: "", 1:"one", 2:"two", 3:"three", 4:"four", 5:"five", 6:"six", 7:"seven", 8:"eight", 9:"nine"}[digit]    

def digit_to_word_x10(digit):
    return {0: "", 1:"teen", 2:"twenty", 3:"thirty", 4:"forty", 5:"fifty", 6:"sixty", 7:"seventy", 8:"eighty", 9:"ninety"}[digit]    



def three_digits_to_word(number):
    if number == 0:
        return ""
    elif number < 10:
        return digit_to_word(number)
    elif number == 10:
        return "ten"
    elif number == 11:
        return "eleven"
    elif number == 12:
        return "twelve"
    elif number == 13:
        return "thirteen"
    elif number == 15:
        return "fifteen"
    elif number < 20:
        return digit_to_word(number%10) + "" + digit_to_word_x10(int(number/10))
    elif number == 20:
        return "twenty"
    elif number < 100:
        return digit_to_word_x10(int(number/10)) + " " + digit_to_word(number%10) 
    elif number < 1000:
        return digit_to_word(int(number/100)) + " hundred " + three_digits_to_word(number%100)

def to_words(number):
    if number == 0:
        return "zero"
    elif number < 999:
        return three_digits_to_word(number)
    elif number < 999_999:
        return str(three_digits_to_word(int(number/1000))) + " thousend " + str(three_digits_to_word(number%1000)) 
    elif number < 999_999_999:
        return str(three_digits_to_word(int(number/1000000))) + " million " + str(three_digits_to_word(int((number%1000000)/1000))) + "" if number%1000 == 0 else " thousend " + str(three_digits_to_word(number%1000)) 

x = input("Ingese el numero: ")
print(to_words(int(x)))
