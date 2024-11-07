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
        const indexes = mapToArr[i][1];

        let first = indexes[0];
        let second = -1;
        
        for(let j=1; j<indexes.length; j++) {
            if(plays[first] < plays[indexes[j]]) {
                second = first;
                first = indexes[j];
            } else if(second === -1 || plays[second] < plays[indexes[j]]) {
                second = indexes[j];
            }
        }
        
        answer.push(first);
        if(second !== -1) answer.push(second);
        
    }
    
    return answer;
}