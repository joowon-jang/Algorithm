function solution(number, k) {
    let answer = '';
    
    let len = number.length;
    let cnt = 0;
    
    for(let i=0; i<len; i++) {
        if(answer.at(-1) < number[i]) {
            answer = answer.slice(0,-1);
            cnt++;
            i--;
            if(cnt >= k) {
                answer += number.slice(i+1, len)
                break;
            }
        }
        else answer += number[i];
    }
    if(cnt < k) {
        answer = answer.slice(0, answer.length - (k-cnt));
    }
    return answer;
}