const fs = require("fs");
const input = (process.platform === "linux" ? fs.readFileSync(0, "utf-8") : fs.readFileSync("input.txt"))
  .toString()
  .trim()
  .split("\n");

// 입력
const T = Number(input[0]);
const datas = input.slice(1, 1 + T).map((data) => data.split(" ").map(Number));

// 출력
solution(T, datas);

//풀이
function solution(T, datas) {
  const gcd = (a, b) => (a % b === 0 ? b : gcd(b, a % b));
  const lcm = (a, b) => (a * b) / gcd(a, b);

  for (let [M, N, x, y] of datas) {
    let k = x;
    while (k <= lcm(M, N)) {
      if ((k - x) % M === 0 && (k - y) % N === 0) {
        console.log(k);
        break;
      }
      k += M;
    }
    if (k > lcm(M, N)) console.log(-1);
  }
}
