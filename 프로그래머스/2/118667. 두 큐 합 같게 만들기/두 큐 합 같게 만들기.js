function solution(queue1, queue2) {
    const len = queue1.length + queue2.length;
    let answer = 0;
    let sum1 = queue1.reduce((acc, num) => acc + num);
    let sum2 = queue2.reduce((acc, num) => acc + num);
    let idx1 = 0;
    let idx2 = 0;
    
    while(sum1 !== sum2) {
        if(sum1 > sum2) {
            const tmp = queue1[idx1++];
            queue2.push(tmp);
            sum1 -= tmp;
            sum2 += tmp;
        }
        else {
            const tmp = queue2[idx2++];
            queue1.push(tmp);
            sum2 -= tmp;
            sum1 += tmp;
        }
        answer++;
        if(idx1 > len || idx2 > len) return -1;
    }
    
    return answer;
}