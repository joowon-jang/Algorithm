const fs = require('fs');
const input = (process.platform === 'linux' ? fs.readFileSync(0, 'utf-8') : fs.readFileSync('input.txt')).toString().trim().split('\n');

const N = Number(input[0]);
const nums = input[1].split(' ').map(Number);

function solution(N, nums) {
    const F = new Map();
    for(let i = 0; i < N; i++) {
        F.set(nums[i], (F.get(nums[i]) || 0) + 1);
    }
    
    const stack = [];
    const answer = [];
    for(let i = N - 1; i >= 0; i--) {
        while(F.get(stack[stack.length - 1]) <= F.get(nums[i])) {
            stack.pop();
        }
        if(stack.length === 0) {
            answer.push(-1);
        }
        else {
            answer.push(stack[stack.length - 1]);
        }
        stack.push(nums[i]);
    }
    
    console.log(...answer.reverse());
}

solution(N, nums);