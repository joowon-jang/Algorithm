function checkTree(tree, a, b) {
    const visited = Array.from({ length : tree.length }, () => false);
    
    const q = [];
    let cntA = 0;
    
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
    
    return cntA;
}

function solution(n, wires) {
    let answer = Infinity;
    const tree = Array.from({ length : n + 1 }, () => []);
    
    wires.forEach(wire => {
        tree[wire[0]].push(wire[1]);
        tree[wire[1]].push(wire[0]);
    });
    
    wires.forEach(wire => {
        const cntA = checkTree(tree, wire[0], wire[1]);
        answer = Math.min(answer, Math.abs(cntA - (n - cntA)));
        if(answer === 0) return;
    })
    
    return answer;
}