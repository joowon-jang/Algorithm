function solution(n) {
    const len = n * (n + 1) / 2;
    const triangle = Array.from({ length: n }, () => []);
    
    triangle[0][0] = 1;
    let r = 0, c = 0;
    let num = 2;
    let cycle = n - 1;
    
    const dir = [[1, 0], [0, 1], [-1, -1]];
    let rotate = 0;
    
    while(num <= len) {
        const dirIdx = rotate % 3;
        for(let i = 0; i < cycle; i++) {
            r += dir[dirIdx][0];
            c += dir[dirIdx][1];
            triangle[r][c] = num;
            num++;
        }
        rotate++;
        if(rotate >= 2) cycle--;
    }
    
    let answer = [];
    for(const row of triangle) {
        answer.push(...row);
    }
    
    return answer;
}