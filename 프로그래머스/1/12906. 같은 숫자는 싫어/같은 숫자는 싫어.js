function solution(arr)
{
    let answer = [arr[0]];
    const len = arr.length;
    
    for(let i=1; i<len; i++) {
        if(arr[i-1] !== arr[i]) answer.push(arr[i]);
    }
    
    return answer;
}