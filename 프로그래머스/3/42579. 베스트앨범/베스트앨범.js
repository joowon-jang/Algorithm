function solution(genres, plays) {
    const answer = [];
    const hashMap = new Map();
    
    for(let i=0; i<genres.length; i++) {
        const newArr = hashMap.get(genres[i]) || [];
        newArr.push(i);
        hashMap.set(genres[i], newArr);
    }
    
    const mapToArr = Array.from(hashMap);
    mapToArr.sort((a, b) => b[1].reduce((acc, curr) => acc + plays[curr], 0) - a[1].reduce((acc, curr) => acc + plays[curr], 0));
    
    for(let i=0; i<mapToArr.length; i++) {
        const arr = mapToArr[i][1];
        arr.sort((a, b) => plays[b] - plays[a]);
        answer.push(arr[0]);
        if(arr.length >= 2) answer.push(arr[1]);
        
    }
    
    
    
    return answer;
}