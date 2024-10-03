function solution(triangle) {
    triangle[1][0] += triangle[0][0];
    triangle[1][1] += triangle[0][0];
    
    for(i = 2; i < triangle.length; i++) {
        triangle[i][0] += triangle[i - 1][0];
        for(j = 1; j < triangle[i].length - 1; j++) {
            triangle[i][j] += Math.max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        triangle[i][j] += triangle[i - 1][j - 1];
    }
    
    return Math.max(...triangle.at(-1));
}