const fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, S] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);

console.log(solution(N, S, arr));

function solution(N, S, arr) {
  let answer = Infinity;
  const psum = [0];

  for (let i = 0; i < N; i++) {
    psum.push(psum[psum.length - 1] + arr[i]);
  }

  let left = 0;
  let right = 1;

  while (right <= N) {
    if (psum[right] - psum[left] >= S) {
      answer = Math.min(answer, right - left);
      left++;
    } else right++;
  }

  return answer === Infinity ? 0 : answer;
}
