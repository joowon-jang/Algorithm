function solution(topping) {
    let answer = 0;
    
    let left = new Map();
    let right = new Map();
    
    for(const num of topping) {
        right.set(num, (right.get(num) || 0) + 1);
    }
    
    
    for(let i=0; i<topping.length; i++) {
        left.set(topping[i], (left[topping[i]] || 0) + 1);
        right.set(topping[i], right.get(topping[i]) - 1);
        if(right.get(topping[i]) === 0) right.delete(topping[i]);
        
        if(left.size === right.size) answer++;
    }
    
  
    return answer;
}