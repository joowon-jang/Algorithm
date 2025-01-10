const fs = require('fs');
const input = (process.platform === 'linux' ? fs.readFileSync(0, 'utf-8') : fs.readFileSync('input.txt'))
  .toString()
  .trim()
  .split('\n');

// 입력
const [n, m] = input[0].split(' ').map(Number);
const field = input.slice(1, n + 1).map((row) => row.split(' ').map(Number));

// 출력
solution(n, m, field);

//풀이
function solution(n, m, field) {
  let answer = 0;
  const visited = Array.from({ length: n }, () => Array.from({ length: m }, () => false));
  const around = Array.from({ length: n }, () => Array.from({ length: m }, () => 0));
  const dir = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
  ];

  const bfs = (r, c) => {
    const q = [[r, c]];
    visited[r][c] = true;

    while (q.length > 0) {
      const [cR, cC] = q.shift();

      for (let i = 0; i < 4; i++) {
        const nR = cR + dir[i][0];
        const nC = cC + dir[i][1];

        if (field[nR][nC] <= 0) around[cR][cC]++;
        else {
          if (visited[nR][nC]) continue;
          visited[nR][nC] = true;
          q.push([nR, nC]);
        }
      }
    }
  };

  let cnt = 0;

  while (cnt <= 1) {
    cnt = 0;
    for (let i = 1; i < n - 1; i++) {
      for (let j = 1; j < m - 1; j++) {
        if (visited[i][j] === false && field[i][j] > 0) {
          bfs(i, j);
          cnt++;
        }
      }
    }

    if (cnt === 0) {
      answer = 0;
      break;
    } else if (cnt >= 2) break;

    for (let i = 1; i < n - 1; i++) {
      for (let j = 1; j < m - 1; j++) {
        field[i][j] -= around[i][j];
        around[i][j] = 0;
        visited[i][j] = false;
      }
    }

    answer++;
  }

  console.log(answer);
}
