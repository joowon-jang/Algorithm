const fs = require('fs');
const input = (process.platform === 'linux' ? fs.readFileSync(0, 'utf-8') : fs.readFileSync('input.txt'))
  .toString()
  .trim()
  .split('\n');

// 입력
const [N, M] = input[0].split(' ').map(Number);
const field = input.slice(1, 1 + N).map((row) => row.split(' ').map((num) => (num == 1 ? -1 : Number(num))));

// 출력
solution(N, M, field);

//풀이
function solution(N, M, field) {
  const dir = [ [-1, 0], [1, 0], [0, -1], [0, 1], ];
  const isIn = (r, c) => r >= 0 && r < N && c >= 0 && c < N;

  const getCombinations = (total, pick) => {
    let result = [];
  
    const picker = (start, pickedArr) => {
      if (pickedArr.length === pick) {
        result.push([...pickedArr]);
        return;
      }
      for (let i = start; i < total; i++) {
        pickedArr.push(i);
        picker(i + 1, pickedArr);
        pickedArr.pop();
      }
    };
  
    picker(0, []);
  
    return result;
  }

  const puttable = [];
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (field[i][j] === 2) {
        field[i][j] = 0;
        puttable.push([i, j]);
      }
    }
  }

  const bfs = (combi, field) => {
    const newField = field.map(row => [...row]);
    const q = [];
    
    for (const index of combi) {
      const [r, c] = puttable[index];
      newField[r][c] = 1;
      q.push([r, c]);
    }

    while (q.length > 0) {
      const [cR, cC] = q.shift();

      for (let i = 0; i < 4; i++) {
        const nR = cR + dir[i][0];
        const nC = cC + dir[i][1];

        if (!isIn(nR, nC)) continue;
        if (newField[nR][nC] !== 0) continue;

        newField[nR][nC] = newField[cR][cC] + 1;
        q.push([nR, nC]);
      }
    }

    let time = 0;
    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (newField[i][j] === 0) return Infinity;
        time = Math.max(time, newField[i][j]);
      }
    }

    return time - 1;
  };



  let answer = Infinity;

  const combinations = getCombinations(puttable.length, M);

  for (let i = 0; i < combinations.length; i++) {
    const time = bfs(combinations[i], field);
    answer = Math.min(answer, time);
  }

  console.log(answer === Infinity ? -1 : answer);
}
