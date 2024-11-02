function solution(msg) {
    let answer = [];
    let dict = new Map();
    
    for(let i=0; i<26; i++) {
        dict.set(String.fromCharCode(65+i), i+1);
    }
    
    for(let i=0; i<msg.length; i++) {
        let cut = 1;
        let longest = msg.slice(i, i+cut);
        
        while(dict.get(msg.slice(i, i+cut)) && i+cut <= msg.length) {
            longest = msg.slice(i, i+cut);
            cut++;
        }
        
        console.log(longest);
        answer.push(dict.get(longest));
        
        dict.set(msg.slice(i, i+cut), dict.size + 1);
        i += cut - 2;
    }
    
    
    return answer;
}