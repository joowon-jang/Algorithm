function solution(m, n, puddles) {
    const dp = Array.from({ length : n + 1}, () => Array.from({ length: m + 1}, () => 0));
    dp[1][1] = 1;
    
    for(const [x, y] of puddles) {
        dp[y][x] = -1;
    }
    
    for(let i=1; i<=n; i++) {
        for(let j=1; j<=m; j++) {
            if(i === 1 && j === 1) continue;
            if(dp[i][j] === -1) continue;
            
            if(dp[i-1][j] > 0) dp[i][j] += dp[i-1][j];
            if(dp[i][j-1] > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= 1000000007;
        }
    }
    
    return dp[n][m];
}