function solution(storey) {
    let answer = 0;
    
    while(storey > 0) {
        if(storey % 10 < 5) {
            answer += storey % 10;
            storey = Math.floor(storey/10);
        }
        else if(storey % 10 === 5 && storey / 10 % 10 < 5) {
            answer += storey % 10;
            storey = Math.floor(storey/10);
        }
        else {
            answer += 10 - storey % 10;
            storey = Math.floor(storey/10);
            storey++;
        }
    }
    
    return answer;
}