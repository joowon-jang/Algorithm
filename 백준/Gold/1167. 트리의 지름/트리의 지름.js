const fs = require("fs");
const input = (process.platform === "linux" ? fs.readFileSync(0, "utf-8") : fs.readFileSync("input.txt"))
  .toString()
  .trim()
  .split("\n");

// 입력
const V = Number(input[0]);
const lines = input.slice(1).map((info) => info.split(" ").map(Number).slice(0, -1));

// 출력
console.log(solution(V, lines));

// 풀이
function solution(V, lines) {
  let answer = 0;
  let furthest = 1;
  const tree = Array.from({ length: V + 1 }, () => []);

  for (const [from, ...infos] of lines) {
    for (let i = 0; i < infos.length; i += 2) {
      tree[from].push([infos[i], infos[i + 1]]);
    }
  }

  const visited = Array.from({ length: tree.length }, () => false);

  function dfs(currNode, currDist) {
    if (visited[currNode]) return;

    if (answer < currDist) {
      answer = currDist;
      furthest = currNode;
    }
    visited[currNode] = true;

    for (let i = 0; i < tree[currNode].length; i++) {
      const [nextNode, nextDist] = tree[currNode][i];
      dfs(nextNode, currDist + nextDist);
    }
  }

  dfs(1, 0);
  visited.fill(false);
  dfs(furthest, 0);

  return answer;
}
