function solution(s) {
    let answer = [];
    
    let arr = s.slice(2, -2).split('},{');
    
    for(let i=0; i<arr.length; i++) {
        arr[i] = arr[i].split(',').map(el => Number(el));
    }
    
    arr.sort((a, b) => a.length < b.length ? -1 : a.length === b.length ? 0 : 1);
    
    for(let i=0; i<arr.length; i++) {
        filtered = arr[i].filter(el => !answer.includes(el));
        filtered.forEach(el => answer.push(el));
    }
    
    return answer;
}