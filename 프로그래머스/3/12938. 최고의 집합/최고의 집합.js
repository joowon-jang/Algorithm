function solution(n, s) {
    if(n > s) return [-1];
    
    const answer = Array.from({ length: n }, () => Math.floor(s / n));
    for(let i = 1; i <= s % n; i++) {
        answer[n - i]++;
    }
    
    return answer;
}