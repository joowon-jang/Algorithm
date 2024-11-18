function solution(n, works) {
    let answer = 0;
    
    if(works.reduce((a,b) => a+b) <= n) return 0;

    const sorted = works.sort((a,b) => a-b);
    const len = works.length;

    while(n > 0) {
        const max = sorted[len-1];

        for(let i = len-1; i >= 0; i--) {
            if(sorted[i] >= max) {
                sorted[i]--;
                n--;
            }
            if(n <= 0) break;
        }
    }
    
    for(const work of sorted) {
        answer += work*work;
    }

    return answer;
}