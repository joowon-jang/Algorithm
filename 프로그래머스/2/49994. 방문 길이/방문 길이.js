function solution(dirs) {
    let answer = 0;
    const visitedRow = Array.from({length:11}, () => Array.from({length:10}, () => false));
    const visitedCol = Array.from({length:11}, () => Array.from({length:10}, () => false));
    let currX = 5;
    let currY = 5;
    
    for(const dir of dirs) {
        switch(dir) {
            case 'U':
                if(currY !== 10) {
                    if(!visitedCol[currY][currX]) answer++;
                    visitedCol[currY][currX] = true;
                    currY++;
                }
                break;
            case 'D':
                if(currY !== 0) {
                    currY--;
                    if(!visitedCol[currY][currX]) answer++;
                    visitedCol[currY][currX] = true;
                }
                break;
            case 'R':
                if(currX !== 10) {
                    if(!visitedRow[currY][currX]) answer++;
                    visitedRow[currY][currX] = true;
                    currX++;
                }
                break;
            case 'L':
                if(currX !== 0) {
                    currX--;
                    if(!visitedRow[currY][currX]) answer++;
                    visitedRow[currY][currX] = true;
                }
                break;
        }
        
    }
    
    return answer;
}