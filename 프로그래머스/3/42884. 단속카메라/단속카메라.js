function solution(routes) {
    let answer = 1;
    routes.sort((a, b) => a[0] - b[0]);
    
    let out = routes[0][1];
    
    for(const route of routes) {
        if(out < route[0]) {
            answer++;
            out = route[1];
        }
        if(out > route[1]) out = route[1];
    }
    
    return answer;
}