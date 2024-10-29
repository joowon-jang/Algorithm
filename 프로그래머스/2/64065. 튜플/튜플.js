function solution(s) {
    let answer = [];
    
    let arr = s.split('},{');
    arr[0] = arr[0].slice(2);
    arr[arr.length - 1] = arr[arr.length - 1].slice(0,-2);
    
    for(let i=0; i<arr.length; i++) {
        arr[i] = arr[i].split(',');
    }
    
    arr.sort((a, b) => a.length < b.length ? -1 : a.length === b.length ? 0 : 1);
    
    for(let i=0; i<arr.length; i++) {
        filtered = arr[i].filter(el => !answer.includes(Number(el)));
        filtered.forEach(el => answer.push(Number(el)));
    }
    
    return answer;
}