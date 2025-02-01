const fs = require('fs');
const input = (process.platform === 'linux' ? fs.readFileSync(0, 'utf-8') : fs.readFileSync('input.txt'))
  .toString()
  .trim()
  .split('\n');

// 입력
const t = Number(input[0]);
const tCases = input.slice(1);

// 출력
for (let i = 0; i < t; i++) {
  const n = Number(tCases.shift());
  const locations = [];
  for (let j = 0; j < n + 2; j++) {
    const [x, y] = tCases.shift().split(' ').map(Number);
    locations.push({ x, y });
  }

  solution(n, locations);
}

//풀이
function solution(n, locations) {
  const visited = Array.from({ length: n + 2 }, () => false);

  const bfs = () => {
    visited[0] = true;
    const q = [{ x: locations[0].x, y: locations[0].y }];

    while (q.length > 0) {
      const { x: cX, y: cY } = q.shift();

      if (cX === locations[locations.length - 1].x && cY === locations[locations.length - 1].y) return 'happy';

      for (let i = 0; i < locations.length; i++) {
        if (visited[i]) continue;

        const nX = locations[i].x;
        const nY = locations[i].y;

        if (Math.abs(nX - cX) + Math.abs(nY - cY) <= 1000) {
          visited[i] = true;
          q.push({ x: nX, y: nY });
        }
      }
    }

    return 'sad';
  };

  console.log(bfs());
}
