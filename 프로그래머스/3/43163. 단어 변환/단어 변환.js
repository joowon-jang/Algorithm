function compareStr(a, b) {
    let diffCnt = 0;
    for(let i=0; i<a.length; i++) {
        if(a[i] !== b[i]) diffCnt++;
    }
    
    return diffCnt;
}

function solution(begin, target, words) {
    let answer = 0;
    
    function dfs(curr, cnt) {
        if(curr === target) {
            if(answer === 0 || answer > cnt) {
                answer = cnt;
            }
            return;
        }
        
        for(const word of words) {
            if(compareStr(curr, word) === 1) {
                words = words.filter(el => el !== word);
                dfs(word, cnt + 1);
                words.push(word);
            }
        }
    }
    
    dfs(begin, 0);
    
    return answer;
}