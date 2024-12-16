function solution(n, times) {
    times.sort((a, b) => a - b);
    let l = 0;
    let r = times[times.length - 1] * n;
    
    let answer = r;
    
    while(l < r) {
        let mid = Math.floor((l + r) / 2);
        let cnt = 0;
        for(const time of times) {
            cnt += Math.floor(mid / time);
            if(cnt >= n) {
                answer = Math.min(mid, answer);
                break;
            }
        }
        if(cnt >= n) r = mid;
        else l = mid + 1;
    }
    
    return answer;
}