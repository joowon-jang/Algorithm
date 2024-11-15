function solution(hp) {
    const dp = [0, 1, 2, 1, 2, 1];
    
    for(let i=6; i<=hp; i++) {
        dp.push(Math.min(dp[i-5]+1, dp[i-3]+1, dp[i-1]+1));
    }
    
    return dp[hp];
}