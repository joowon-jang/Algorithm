function solution(k, tangerine) {
    let answer = 0;
    let dict = {};
    
    for(let i=0; i<tangerine.length; i++) {
        if(!dict[tangerine[i]]) dict[tangerine[i]] = 1;
        else dict[tangerine[i]]++;
    }
    
    const tArr = Object.values(dict).sort((a, b) => b - a);
    
    for(const num of tArr) {
        answer++;
        k -= num;
        if(k<=0) break;
    }
    
    return answer;
}