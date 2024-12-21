const fs = require("fs");
const input = (process.platform === "linux" ? fs.readFileSync(0, "utf-8") : fs.readFileSync("input.txt"))
  .toString()
  .trim()
  .split("\n");

const [n, m] = input[0].split(" ").map(Number);
const supervisors = input[1].split(" ").map(Number);
const praises = input.slice(2, 2 + m).map((praise) => praise.split(" ").map(Number));

console.log(...solution(n, m, supervisors, praises));

function solution(n, m, supervisors, praises) {
  const answer = Array.from({ length: n + 1 }, () => 0);
  const juniors = Array.from({ length: n + 1 }, () => []); // 트리

  for (let i = 0; i < n; i++) {
    const tmp = supervisors[i];
    if (tmp !== -1) juniors[tmp].push(i + 1);
  }

  for (const [i, w] of praises) {
    answer[i] += w;
  }

  function dfs(curr) {
    for (let i = 0; i < juniors[curr].length; i++) {
      const next = juniors[curr][i];
      answer[next] += answer[curr];
      dfs(next);
    }
  }

  dfs(1);

  return answer.slice(1);
}
