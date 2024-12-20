function solution(n, k) {
    const answer = [];
    let people = Array.from({ length: n }, (_, i) => i + 1);
    let caseNum = people.reduce((acc, person) => acc * person, 1);
    k--;
    
    while (answer.length < n) {
        caseNum = caseNum / people.length;
        const tmp = people[Math.floor(k / caseNum)];
        answer.push(tmp);
        k = k % caseNum;
        people = people.filter(person => person !== tmp);
    }

    return answer;
}