function checkTree(tree, a, b) {
    const visited = Array.from({ length : tree.length }, () => false);
    
    const q = [];
    let cntA = 0;
    let cntB = 0;
    
    q.push(a);
    visited[a] = true;
    
    while(q.length > 0) {
        const curr = q.shift();
        cntA++;
        
        tree[curr].forEach(node => {
            if(node === b) return;
            if(visited[node]) return;
            q.push(node);
            visited[node] = true;
        })
    }
    
    visited.fill(false);
    
    q.push(b);
    visited[b] = true;
    
    while(q.length > 0) {
        const curr = q.shift();
        cntB++;
        
        tree[curr].forEach(node => {
            if(node === a) return;
            if(visited[node]) return;
            q.push(node);
            visited[node] = true;
        })
    }
    
    return Math.abs(cntA - cntB);
}

function solution(n, wires) {
    let answer = Infinity;
    const tree = Array.from({ length : n + 1 }, () => []);
    
    wires.forEach(wire => {
        tree[wire[0]].push(wire[1]);
        tree[wire[1]].push(wire[0]);
    });
    
    wires.forEach(wire => {
        answer = Math.min(answer, checkTree(tree, wire[0], wire[1]));
        if(answer === 0) return;
    })
    
    return answer;
}