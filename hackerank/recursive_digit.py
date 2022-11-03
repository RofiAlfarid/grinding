# soal https://www.hackerrank.com/challenges/one-week-preparation-kit-recursive-digit-sum/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-four&h_r=next-challenge&h_v=zen

def superDigit(n, k):
    # Write your code here
    if len(n) == 1 and k == 1:
        return n
    else:
        t = 0
        for i in n:
            t += int(i)
        t *= k
        x = superDigit(str(t),1)
        return x

n = '1234'
k = 4
print(superDigit(n,k))