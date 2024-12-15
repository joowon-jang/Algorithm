function solution(N, road, K) {
    const graph = Array.from({ length: N + 1 }, () => []);
    const dists = Array.from({ length: N + 1 }, () => Infinity);
    dists[1] = 0;
    
    for(const [u, v, w] of road) {
        graph[u].push([v, w]);
        graph[v].push([u, w]);
    }
    
    const q = [1];
    
    while(q.length > 0) {
        const to = q.shift();
        
        for(const [v, w] of graph[to]) {
            if(dists[to] + w < dists[v]) {
                dists[v] = dists[to] + w;
                q.push(v);
            }
        }
    }
    
    return dists.filter(dist => dist <= K).length;
}