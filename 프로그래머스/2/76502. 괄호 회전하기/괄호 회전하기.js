function solution(s) {
    let answer = 0;
    let str = s + s;
    let stack = [];
    
    if(s.length % 2 === 1) return 0;
    
    for(let i = 0; i < s.length; i++) {
        for(let j = i; j < i + s.length; j++) {
            if(str[j] === '[' || str[j] === '(' || str[j] === '{') {
                stack.push(str[j]);
            }
            else if(stack.length === 0) break;
            else if(str[j] === ']' && stack.at(-1) === '[') {
                stack.pop();
            }
            else if(str[j] === ')' && stack.at(-1) === '(') {
                stack.pop();
            }
            else if(str[j] === '}' && stack.at(-1) === '{') {
                stack.pop();
            }
            if(j === i + s.length - 1 && stack.length === 0) answer++;
        }
    }
    
    return answer;
}