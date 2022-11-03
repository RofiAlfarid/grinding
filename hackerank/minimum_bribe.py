# soal https://www.hackerrank.com/challenges/one-week-preparation-kit-new-year-chaos/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-four&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen


def minimumBribes(q):
    # Write your code here
    bribe = 0
    for i in range(1,len(q)+1):
        if q[i-1] == i:
            bribe += 0
        elif q[i-1] - i > 2:
            return 'Too chaotic'
        else:
            bribe += abs(q[i-1] - i)
    return int(bribe / 2)


s = [1,2,5,3,7,8,6,4]
print(minimumBribes(s))

# 12537864
# 12357864 1
# 12357648 2
# 12356478 2
# 12345678 2