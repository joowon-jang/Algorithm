const fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, d, k, c] = input[0].split(" ").map(Number);
const sushies = input.slice(1).map(Number);

// 결과 출력
console.log(solution(N, d, k, c, sushies));

// 풀이
function solution(N, d, k, c, sushies) {
  let answer = 0;

  const extendedSushies = sushies.concat(sushies.slice(0, k));

  const sushiMap = new Map();
  let kind = 0;

  for (let i = 0; i < k; i++) {
    sushiMap.set(extendedSushies[i], (sushiMap.get(extendedSushies[i]) || 0) + 1);
  }
  answer = sushiMap.size + (sushiMap.has(c) ? 0 : 1);

  for (let i = 0; i < N; i++) {
    const left = extendedSushies[i];
    const right = extendedSushies[i + k];

    sushiMap.set(left, sushiMap.get(left) - 1);
    if (sushiMap.get(left) === 0) sushiMap.delete(left);

    sushiMap.set(right, (sushiMap.get(right) || 0) + 1);

    answer = Math.max(answer, sushiMap.size + (sushiMap.has(c) ? 0 : 1));
  }

  return answer;
}