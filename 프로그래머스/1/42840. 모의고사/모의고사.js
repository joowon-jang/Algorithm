function solution(answers) {
    const answer = [];
    const grades = [0, 0, 0];
    
    const first = [1, 2, 3, 4, 5];
    const second = [2, 1, 2, 3, 2, 4, 2, 5];
    const third = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    
    for(let i=0; i<answers.length; i++) {
        if(answers[i] === first[i%5]) grades[0]++;
        if(answers[i] === second[i%8]) grades[1]++;
        if(answers[i] === third[i%10]) grades[2]++;
    }
    
    const maxGrade = Math.max(...grades);
    for(let i=0; i<grades.length; i++) {
        if(grades[i] === maxGrade) answer.push(i+1);
    }
    
    return answer;
}