

def checkpalindrome(s, start, end):
    while start < end and s[start] == s[end]:
        start += 1
        end -= 1

    return start >= end

def palindromeIndex(s):
    # Write your code here
    start = 0
    end = len(s)-1

    while start < end and s[start] == s[end]:
        start += 1
        end -= 1
    
    if start>= end:
        return -1
    
    if checkpalindrome(s,start+1, end):
        return start 
    else:
        return end




str = "aaab"
print(palindromeIndex(str))