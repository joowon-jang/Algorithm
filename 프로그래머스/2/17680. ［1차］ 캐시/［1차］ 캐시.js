function solution(cacheSize, cities) {
    let answer = 0;
    let q = [];
    
    for(let i=0; i<cities.length; i++) {
        cities[i] = cities[i].toLowerCase();
    }
    
    if(cacheSize === 0) return cities.length * 5;
    
    for(let i=0; i<cities.length; i++) {
        if(q.includes(cities[i])) {
            q.splice(q.indexOf(cities[i]), 1);
            answer +=1;
        }
        else {
            answer += 5;
            if(cacheSize <= q.length) q.shift();
        }
        
        q.push(cities[i]);
    }
    
    return answer;
}