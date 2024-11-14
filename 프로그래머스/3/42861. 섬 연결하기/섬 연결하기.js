function getParent(parents, x) {
    if(parents[x] === x) return x;
    return parents[x] = getParent(parents, parents[x]);
}

function setParent(parents, a, b) {
    const parentA = getParent(parents, a);
    const parentB = getParent(parents, b);
    if(parentA < parentB) parents[parentB] = parentA;
    else parents[parentA] = parentB;
}

function solution(n, costs) {
    let answer = 0;
    
    const parents = [];
    for(let i = 0; i < n; i++) parents.push(i);
    
    costs.sort((a, b) => a[2] - b[2]);
    
    for(const cost of costs) {
        if(getParent(parents, cost[0]) !== getParent(parents, cost[1])) {
            answer += cost[2];
            setParent(parents, cost[0], cost[1]);
        }
    }
    
    return answer;
}