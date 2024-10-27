function solution(n, left, right) {
    let answer = [];
    
    for(let i=left; i<=right; i++) {
        answer.push(Math.max(parseInt(i/n + 1), i%n + 1));
    }
    
    return answer;
}