# https://www.hackerrank.com/challenges/one-week-preparation-kit-jesse-and-cookies/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-six

import heapq


def cookies(k, A):
    # Write your code here
    heapq.heapify(A)
    

    i = 0

    
    while A[0] < k:
        if A[0] < k and len(A)<=1:
            return -1
        i +=1
        n1 = heapq.heappop(A)
        n2 = heapq.heappop(A)
        newn = n1 + n2*2
        heapq.heappush(A,newn)
    
    return i


print(cookies(10,[1,1,1]))