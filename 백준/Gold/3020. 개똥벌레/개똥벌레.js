const fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, H] = input[0].split(" ").map(Number);
const obstacles = input.slice(1).map(Number);

console.log(...solution(N, H, obstacles));

function solution(N, H, obstacles) {
  const bottom = Array.from({ length: H + 1 }, () => 0);
  const top = Array.from({ length: H + 1 }, () => 0);

  obstacles.forEach((height, index) => {
    if (index % 2 === 0) bottom[height]++;
    else top[H - height + 1]++;
  });

  for (let i = 1; i <= H; i++) {
    top[i] += top[i - 1];
    bottom[H - i] += bottom[H - i + 1];
  }

  const total = [];
  for (let i = 1; i <= H; i++) {
    total.push(top[i] + bottom[i]);
  }

  const min = Math.min(...total);
  const cnt = total.filter((num) => num === min).length;

  return [min, cnt];
}
