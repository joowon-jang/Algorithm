function isIn(r, c, n) {
    return (r >= 0 && c >= 0 && r < n && c < n);
}

function bfs(board, n) {
    const dir = [[0, -1], [0, 1], [-1, 0], [1, 0]];
    const q = [[0, 0, 0, 1], [0, 0, 0, 3]];
    const costs = Array.from({ length: n }, () => Array.from({ length: n }, () => Array.from({ length: 4}, () => Infinity)));
    
    while(q.length > 0) {
        const [cR, cC, cCost, moving] = q.shift();
        
        for(let i = 0; i < 4; i++) {
            const nR = cR + dir[i][0];
            const nC = cC + dir[i][1];
            
            if(!isIn(nR, nC, n)) continue;
            if(board[nR][nC] === 1) continue;
            
            const nCost = cCost + (moving === i ? 100 : 600);
            if(nCost < costs[nR][nC][i]) {
                costs[nR][nC][i] = nCost;
                q.push([nR, nC, nCost, i]);
            }
        }
    }
    
    return Math.min(...costs[n - 1][n - 1]);
}

function solution(board) {
    const n = board.length;
    
    return bfs(board, n);
}