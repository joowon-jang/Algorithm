const fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, S] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);

console.log(solution(N, S, arr));

function solution(N, S, arr) {
  let answer = Infinity;

  let left = -1;
  let right = 0;
  let sum = arr[0];

  while (right < N && left < right) {
    if (sum >= S) {
      answer = Math.min(answer, right - left);
      left++;
      sum -= arr[left];
    } else {
      right++;
      sum += arr[right];
    }
  }

  return answer === Infinity ? 0 : answer;
}
