const fs = require("fs");
const input = (process.platform === "linux" ? fs.readFileSync(0, "utf-8") : fs.readFileSync("input.txt"))
  .toString()
  .trim()
  .split("\n");

// 입력
const n = Number(input[0]);
const confetties = input.slice(1, n + 1).map((confetti) => confetti.split(" ").map(Number));

// 출력
solution(n, confetties);

//풀이
function solution(n, confetties) {
  const paper = Array.from({ length: 100 }, () => Array.from({ length: 100 }, () => 0));

  for (const [x, y] of confetties) {
    for (let i = y; i < y + 10; i++) {
      for (let j = x; j < x + 10; j++) {
        paper[i][j] = 1;
      }
    }
  }

  console.log(paper.reduce((acc, row) => acc + row.reduce((acc, num) => acc + num, 0), 0));
}
