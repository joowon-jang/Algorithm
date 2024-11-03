function solution(numbers) {
    let answer = new Array(numbers.length).fill(-1);
    let stack = [];
    
    for(let i =0; i<numbers.length; i++){
        while(stack && numbers[stack.at(-1)] < numbers[i]){
            const top = stack.pop();
            answer[top] = numbers[i];
        }
        stack.push(i);
    }
    return answer;
}