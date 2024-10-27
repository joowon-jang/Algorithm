function solution(word) {
    let answer = 0;
    
    const vowel = {'A':0, 'E':1, 'I':2, 'O':3, 'U': 4};
    const counts = [781, 156, 31, 6, 1];
    
    for(let i=0; i<word.length; i++) {
        answer += vowel[word[i]] * counts[i] + 1;
    }
    
    return answer;
}