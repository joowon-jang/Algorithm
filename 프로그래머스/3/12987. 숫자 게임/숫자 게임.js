function solution(A, B) {
    let answer = 0;
    
    A.sort((a, b) => b - a);
    B.sort((a, b) => a - b);
    
    for(const num of A) {
        if(num < B[B.length - 1]) {
            answer++;
            B.pop();
        }
    }
    
    return answer;
}