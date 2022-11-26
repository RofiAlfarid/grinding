# https://www.hackerrank.com/challenges/one-week-preparation-kit-simple-text-editor/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-six


n = input()
stk = []
tmp = ""
res = []
for i in range(int(n)):
    ins = input()
    ops = ins.split(" ")
    
    if ops[0] == "1":
        stk.append(tmp+ops[1])
        tmp += ops[1]
    elif ops[0] == "2":
        endi = len(stk[-1]) - int(ops[1])
        stk.append(stk[-1][:endi])
        tmp = tmp[:endi]
    elif ops[0] == "3":
        print(stk[-1][int(ops[1])-1])
        res.append(stk[-1][int(ops[1])-1])
    elif ops[0] == "4":
        stk.pop()
        if not stk:
            tmp = ""
        else:
            tmp = stk[-1]


# 10
# 1 lchbfcjtfpsmjrqsdgci
# 3 19
# 1 cpcvixlm
# 1 apdjgjydvpbpvyiy
# 2 29
# 4
# 4
# 3 9
# 4
# 4

# 50
# 1 zsfncpxdzl
# 3 4
# 3 6
# 2 1
# 3 7
# 3 2
# 4
# 2 4
# 2 6
# 4
# 4
# 1 l
# 1 hpe
# 3 6
# 2 7
# 4
# 3 6
# 4
# 3 6
# 1 zipsqagri
# 1 vuqxstnj
# 4
# 3 13
# 4
# 3 10
# 3 6
# 1 uzdpy
# 1 bupqp
# 1 kn
# 2 6
# 3 8
# 1 iiuvfbn
# 4
# 2 1
# 2 12
# 4
# 3 7
# 4
# 2 9
# 3 1
# 1 axbhx
# 1 wovbfyvt
# 3 11
# 3 7
# 3 2
# 4
# 1 tjmqp
# 4
# 2 6
# 3 4


# n
# p
# x
# s
# p
# p
# p
# i
# l
# p
# d
# x
# z
# b
# x
# s
# n