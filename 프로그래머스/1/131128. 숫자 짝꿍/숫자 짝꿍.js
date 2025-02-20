function solution(X, Y) {
    let answer = '';
    
    const hash = {};
    const pair = [];
    
    for(let i = 0; i <= 9; i++) {
        hash[i] = 0;
    }
    
    for(let i = 0; i < X.length; i++) {
        hash[X[i]]++;
    }
    
    for(let i = 0; i < Y.length; i++) {
        if(hash[Y[i]] > 0) {
            hash[Y[i]]--;
            pair.push(Y[i]);
        }
    }
    
    pair.sort((a, b) => b - a);
    
    answer = pair.join('');
    
    if(answer === '') answer = "-1";
    else if(answer == 0) answer = "0";
    
    
    return answer;
}