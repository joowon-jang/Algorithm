function isIn(r, c, m, n) {
    return (r >= 0 && r < m && c >= 0 && c < n);
}

function solution(maps) {
    const m = maps.length;
    const n = maps[0].length;
    const dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    let answer = -1;
    let q = [[0,0,1]];
    
    while(q.length > 0) {
        const [cR, cC, cnt] = q.shift();
        if(cR === m-1 && cC === n-1) return cnt;
        
        for(i=0; i<4; i++) {
            const nR = cR + dir[i][0];
            const nC = cC + dir[i][1];
            
            if(!isIn(nR, nC, m, n)) continue;
            if(maps[nR][nC] === 0) continue;
            
            q.push([nR, nC, cnt + 1]);
            maps[nR][nC] = 0;
        }
    }
    
    return answer;
}