const fs = require('fs');
const input = (process.platform === 'linux' ? fs.readFileSync(0, 'utf-8') : fs.readFileSync('input.txt'))
  .toString()
  .trim()
  .split('\n');

// 입력
const K = Number(input[0]);
const [W, H] = input[1].split(' ').map(Number);
const field = input.slice(2, H + 2).map((row) => row.split(' ').map(Number));

// 출력
solution(K, W, H, field);

//풀이
function solution(K, W, H, field) {
  const visited = Array.from({ length: H }, () =>
    Array.from({ length: W }, () => Array.from({ length: K + 1 }, () => 0))
  );
  const dir = [
    [-2, -1],
    [-2, 1],
    [2, -1],
    [2, 1],
    [-1, -2],
    [-1, 2],
    [1, -2],
    [1, 2],

    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
  ];

  const isIn = (r, c) => r >= 0 && r < H && c >= 0 && c < W;

  const bfs = () => {
    const q = [{ r: 0, c: 0, horse: 0 }];

    while (q.length > 0) {
      const { r: cR, c: cC, horse: cHorse } = q.shift();

      if (cR === H - 1 && cC === W - 1) return visited[cR][cC][cHorse];

      for (let i = cHorse < K ? 0 : 8; i < dir.length; i++) {
        const nHorse = i < 8 ? cHorse + 1 : cHorse;
        const nR = cR + dir[i][0];
        const nC = cC + dir[i][1];

        if (!isIn(nR, nC)) continue;
        if (field[nR][nC] === 1) continue;
        if (visited[nR][nC][nHorse]) continue;

        visited[nR][nC][nHorse] = visited[cR][cC][cHorse] + 1;
        q.push({ r: nR, c: nC, horse: nHorse });
      }
    }

    return -1;
  };

  console.log(bfs());
}
