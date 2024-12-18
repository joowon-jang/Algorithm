const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [N, d, k ,c] = input[0].split(' ').map(Number);
    let sushies = [];
    for(let i = 1; i < input.length; i++) {
        sushies.push(Number(input[i]));
    }
    
    console.log(solution(N, d, k, c, sushies));
})

function solution(N, d, k, c, sushies) {
    let answer = 0;
    const originLen = sushies.length;
    sushies.push(...sushies);
    for(let i = 0; i < originLen; i++) {
        const s = new Set(sushies.slice(i, i + k));
        if(s.has(c)) answer = Math.max(s.size, answer);
        else answer = Math.max(s.size + 1, answer);
    }
    
    return answer;
}