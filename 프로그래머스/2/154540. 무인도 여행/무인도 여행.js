function solution(maps) {
    maps = maps.map(row => row.split(''));
    const n = maps.length;
    const m = maps[0].length;
    
    const dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const isIn = (r, c) => (r >= 0 && r < n && c >= 0 && c < m);
    const answer = [];
    
    function bfs(r, c){
        const q = [[r, c]];
        let period = Number(maps[r][c]);
        maps[r][c] = 'X';
        
        while(q.length > 0) {
            const [cR, cC] = q.shift();
            
            for(let i = 0 ; i < 4; i++) {
                const nR = cR + dir[i][0];
                const nC = cC + dir[i][1];
                
                if(!isIn(nR, nC)) continue;
                if(maps[nR][nC] === 'X') continue;
                
                period += Number(maps[nR][nC]);
                maps[nR][nC] = 'X';
                q.push([nR, nC]);
            }
        }
        
        answer.push(period);
    }
    
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < m; j++) {
            if(maps[i][j] !== 'X') bfs(i, j);
        }
    }
    
    if(answer.length === 0) answer.push(-1);
    answer.sort((a, b) => a - b);
    
    return answer;
}