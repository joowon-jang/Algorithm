function solution(name) {
    let answer = 0;
    let move = name.length - 1;
    
    [...name].forEach((ch, i, origin) => {
        answer += Math.min(ch.charCodeAt() - 65, 91 - ch.charCodeAt());
        
        let nextIndex = i + 1;
        while(nextIndex < name.length && name[nextIndex] === 'A') nextIndex++;
        
        move = Math.min(move, i*2 + name.length - nextIndex, i + (name.length - nextIndex) * 2 );
    })
    
    answer += move;
    return answer;
}