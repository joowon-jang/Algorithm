function solution(maps) {
    let answer = 0;
    let leverR = 0;
    let leverC = 0;
    
    
    const rLen = maps.length;
    const cLen = maps[0].length;
    
    const dir = [ [-1, 0], [1, 0], [0, -1], [0, 1] ];
    
    const isIn = (r, c) => r >= 0 && r < rLen && c >= 0 && c < cLen;
    
    let visited = Array.from({ length: rLen }, () => Array.from({ length: cLen }, () => false));
    
    const bfs = (y, x, target) => {
        let q = [{ r: y, c: x, cnt: answer }];
        
        while(q.length > 0) {
            const { r: cR, c: cC, cnt: cCnt } = q.shift();
            
            if(maps[cR][cC] === target) {
                leverR = cR;
                leverC = cC;
                answer = cCnt;
                return;
            }
            
            for(let i = 0; i < dir.length; i++) {
                const nR = cR + dir[i][0];
                const nC = cC + dir[i][1];
                
                if(!isIn(nR, nC)) continue;
                if(maps[nR][nC] === 'X') continue;
                if(visited[nR][nC]) continue;
                
                visited[nR][nC] = true;
                q.push({ r: nR, c: nC, cnt: cCnt + 1 });
            }
        }
        
        answer = -1;
        return;
    }
    
    
    outerLoop:
    for(let i = 0; i < rLen; i++) {
        for(let j = 0; j < cLen; j++) {
            if(maps[i][j] === 'S') {
                bfs(i, j, 'L');
                break outerLoop;
            }
        }
    }
    
    if(answer === -1) return -1;

    visited = Array.from({ length: rLen }, () => Array.from({ length: cLen }, () => false));
    
    bfs(leverR, leverC, 'E');
    
    return answer;
}