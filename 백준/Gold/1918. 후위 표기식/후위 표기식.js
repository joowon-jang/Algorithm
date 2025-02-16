const fs = require('fs');
const input = (process.platform === 'linux' ? fs.readFileSync(0, 'utf-8') : fs.readFileSync('input.txt')).toString().trim().split('\n');

const exp = input[0];

function solution(exp) {
    let answer = '';
    const stack = [];
    
    for(let i = 0; i < exp.length; i++) {
        if(exp[i] === '(') stack.push(exp[i]);
        else if(exp[i] === '*' || exp[i] === '/') {
            while(stack.length > 0 && (stack[stack.length - 1] === '*' || stack[stack.length - 1] === '/')) {
                answer += stack.pop();
            }
            stack.push(exp[i]);
        }
        else if(exp[i] === '+' || exp[i] === '-') {
            while(stack.length > 0 && stack[stack.length - 1] !== '(') {
                answer += stack.pop();
            }
            stack.push(exp[i]);
        }
        else if(exp[i] === ')') {
            while(stack.length > 0 && stack[stack.length - 1] !== '(') {
                answer += stack.pop();
            }
            stack.pop();
        }
        else {
            answer += exp[i];
        }
    }
    
    while(stack.length > 0) answer += stack.pop();
    
    console.log(answer);
}

solution(exp);