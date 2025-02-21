function solution(d, budget) {
    let answer = 0;
    
    d.sort((a, b) => b - a);
    
    while(budget > 0 && d.length > 0) {
        answer++;
        budget -= d.pop();
    }
    
    if(budget < 0) return answer - 1;
    return answer;
}