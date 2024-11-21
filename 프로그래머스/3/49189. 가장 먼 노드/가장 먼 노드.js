function getDists(graph, start) {
    const visited = Array.from({ length : graph.length }, () => false);
    const dists = Array.from({ length : graph.length }, () => 0);
    const q = [[start, 0]];
    visited[start] = true;
    
    while(q.length > 0) {
        const [currNode, currDist] = q.shift();
        dists[currNode] = currDist;
        
        for(const nextNode of graph[currNode]) {
            if(visited[nextNode]) continue;
            q.push([nextNode, currDist + 1]);
            visited[nextNode] = true;
        }
    }
    
    return dists;
}

function solution(n, vertex) {
    const graph = Array.from({ length : n + 1 }, () => []);
    
    for(const [u, v] of vertex) {
        graph[u].push(v);
        graph[v].push(u);
    }
    
    const dists = getDists(graph, 1);
    
    return dists.filter(dist => dist === Math.max(...dists)).length;
}