function solution(n, k) {
    const answer = [];
    const people = Array.from({ length: n }, (_, i) => i + 1);
    let caseNum = people.reduce((acc, person) => acc * person, 1);
    k--;
    
    while (answer.length < n) {
        caseNum = caseNum / people.length;
        answer.push(...people.splice(Math.floor(k / caseNum), 1));
        k = k % caseNum;
    }

    return answer;
}