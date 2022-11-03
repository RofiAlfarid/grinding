# soal https://www.hackerrank.com/challenges/one-week-preparation-kit-grid-challenge/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-four

def gridChallenge(grid):
    # Write your code here
    grid[0] = sorted(grid[0])
    for i in range(1,len(grid)):
        grid[i] = sorted(grid[i])
        for l in range(len(grid[i])):
            if grid[i][l] < grid[i-1][l]:
                return 'NO'

    return 'YES'

        

input = ['ebacd', 'fghij', 'olmkn', 'trpqs', 'xywuv']
print(gridChallenge(input))