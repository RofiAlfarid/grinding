

def digits(num):
    res = 0
    while num > 1:
        num = num / 10
        res += 1
    return res


print(digits(-9996))


# 2. create a simple calculator that could calculate the following formula
# 	   “1 + 2 * ( ( (3 + 4) - 4 * 2) + 4)”


gls = ["+","*","-"]
def calc(str1):

    while "(" in str1:
        f1 = str1.rfind("(")
        l1 = str1.index(")")
        num = 0

        substr = str1[f1:l1+1]
        # serach perkalian
        if "*" in substr:
            ii = substr.index("*")
            
            n1kali = int(substr[ii-2])
            n2kali = int(substr[ii+2])
            num = n1kali * n2kali

        elif "+" in substr:
            ii = substr.index("+")
            n1kali = int(substr[ii-2])
            n2kali = int(substr[ii+2])
            
            num = n1kali + n2kali
            
        elif "-" in substr:
            ii = substr.index("+")
            n1kali = int(substr[ii-2])
            n2kali = int(substr[ii+2])
            num = n1kali - n2kali
            
        
        if ii > 3 :
            lstr = str1[:f1+ii-1]
            rstr = str1[l1+1:]
        
        lstr = str1[:f1-1]
        rstr = str1[l1+1:]

        str1 = lstr + str(num) + rstr


    return f1,l1


# print(calc("“1 + 2 *( ( (3 + 4) - 4 * 2) + 4)”"))