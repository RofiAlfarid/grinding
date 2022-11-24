# https://www.hackerrank.com/challenges/one-week-preparation-kit-balanced-brackets/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-five


def is_balanced(s):
    Dict = {'}': '{', ']': '[', '>': '<'}

    stack = []
    for x in s:
        if stack and Dict.get(x) == stack[-1]:
            stack.pop()
        else:
            stack.append(x)
    print("NO" if stack else "YES")




s = "{(}"
print(is_balanced(s))