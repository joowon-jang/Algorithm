import sys
input = sys.stdin.readline

n = int(input())

triangle = []

for i in range(0, n):
    row = list(map(int, input().split()))
    triangle.append(row)

# 입력된 삼각형 데이터 출력
#for row in triangle:
#    print(row)

dp = [[0] * n for _ in range(n)]

for i in range(0, n) :
    if i == 0 :
        dp[0][0] = triangle[0][0]
        continue
    for j in range(0, i+1) :
        if j == 0 :
            dp[i][j] = dp[i - 1][j] + triangle[i][j]
        elif j == i :
            dp[i][j] = dp[i - 1][j - 1] + triangle[i][j]
        else :
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]
        
print(max(dp[n - 1]))