function solution(weights) {
    let answer = 0;
    const dict = new Map();
    const cals = [1, 1/2, 2/3, 3/4];
    
    weights.sort((a, b) => a - b);
    
    for(const weight of weights) {
        for(const cal of cals) {
            if(dict.has(weight * cal)) answer += dict.get(weight*cal);
        }
        dict.set(weight, (dict.get(weight) || 0) + 1);
    }

    return answer;
}