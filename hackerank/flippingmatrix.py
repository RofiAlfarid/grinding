



def flippinmatrix(m):
    l = int(len(m)/2)
    ll = len(m) - 1
    maxx = 0

    for i in range(l):
        for j in range(l):
            m1 = 0
            m1 = max(m1,m[i][j])
            m1 = max(m1,m[i][ll-j])
            m1 = max(m1,m[ll-i][ll-j])
            m1 = max(m1,m[ll-i][j])

            maxx += m1


    return maxx




matrix = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
print(flippinmatrix(matrix))