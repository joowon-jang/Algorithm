const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    const [N, K] = input[0].split(' ').map(Number);
    const values = input[1].split(' ').map(Number);
    
    console.log(solution(N, K, values));
});

function solution(N, K, values) {
    let answer = -9999;

    const v = [0];
    for (let i = 0; i < N; i++) {
        v.push(v[v.length - 1] + values[i]);
    }

    for (let i = K; i <= N; i++) {
        answer = Math.max(answer, v[i] - v[i - K]);
    }

    return answer;
}