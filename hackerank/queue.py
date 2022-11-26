# https://www.hackerrank.com/challenges/one-week-preparation-kit-queue-using-two-stacks/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-five


loop = int(input())

stk = []

for i in range(loop):
    inputs = input()
    cmd = inputs.split(" ")[0]
    if cmd == "1":
        val = inputs.split(" ")[1]
    
    if cmd == "1":
        stk.append(val)
    if cmd == "2":
        stk = stk[1:]
    if cmd == "3":
        print(stk[0])

