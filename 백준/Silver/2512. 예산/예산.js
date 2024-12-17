const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const N = input[0].split(' ').map(Number);
    const requests = input[1].split(' ').map(Number);
    const M = input[2].split(' ').map(Number);
    
    console.log(solution(N, requests, M));
});

function solution(N, requests, M) {
    requests.sort((a, b) => a - b);
    
    let l = 1;
    let r = requests[N - 1];
    
    while(l <= r) {
        const mid = Math.floor((l + r) / 2);
        
        const total = requests.reduce((acc, num) => acc += (num > mid ? mid : num), 0);
        
        if(total <= M) l = mid + 1;
        else r = mid - 1;
    }
    
    return r;
}
