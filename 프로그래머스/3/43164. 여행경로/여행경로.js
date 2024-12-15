function solution(tickets) {
    tickets.sort();
    const answer = [];
    const used = Array.from({ length: tickets.length }, () => false);

    function dfs(curr, cnt, routes) {
        if(cnt === tickets.length) {
            answer.push(routes);
            return;
        }
        for(let i = 0; i < tickets.length; i++) {
            if(used[i] || tickets[i][0] !== curr) continue;
            
            used[i] = true;
            
            const newRoutes = Array.from(routes);
            newRoutes.push(tickets[i][1]);
            dfs(tickets[i][1], cnt + 1, newRoutes);
            
            used[i] = false;
        }
    }
    
    dfs('ICN', 0, ['ICN']);
    
    return answer[0];
}