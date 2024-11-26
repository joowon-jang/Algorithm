function solution(m, n, board) {
    board = board.map(row => row.split(''));
    let answer = 0;
    
    while(true) {
        const arr = [];
        
        for(let i = 1; i < m; i++) {
            for(let j = 1; j < n; j++) {
                if(board[i][j] !== 0 &&
                   board[i-1][j] === board[i][j] &&
                   board[i-1][j-1] === board[i][j] &&
                   board[i][j-1] === board[i][j]) {
                    arr.push([i, j]);
                }
            }
        }
        
        if(arr.length === 0) break;
        for(const [r, c] of arr) {
            board[r][c] = 0;
            board[r-1][c] = 0;
            board[r-1][c-1] = 0;
            board[r][c-1] = 0;
        }
        
        for(let i = m - 1; i > 0; i--) {
            for(let j = 0; j < n; j++) {
                if(board[i][j] === 0) {
                    for(let k = i - 1; k >= 0; k--) {
                        if (board[k][j] !== 0) {
                            board[i][j] = board[k][j];
                            board[k][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            if(board[i][j] === 0) answer++;
        }
    }
    
    return answer;
}