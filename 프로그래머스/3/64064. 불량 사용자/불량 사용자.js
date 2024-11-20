function solution(user_id, banned_id) {
    let answer = 0;
    const cases = new Set();
    
    const candidate = [];
    
    for(let i = 0; i < banned_id.length; i++) {
        const tmp = [];
        for(let j = 0; j < user_id.length; j++) {
            if(banned_id[i].length !== user_id[j].length) continue;
            for(let k=0; k<banned_id[i].length; k++) {
                if(banned_id[i][k] === '*') {
                    if(k === banned_id[i].length - 1) tmp.push(j);
                    continue;
                }
                if(banned_id[i][k] !== user_id[j][k]) break;
                if(k === banned_id[i].length - 1) tmp.push(j);
            }
        }
        if(tmp.length >= 1) candidate.push(tmp);
    }
    
    function getCases(index, caseArr) {
        if(index === candidate.length) {
            cases.add(caseArr.sort().join(''));
            return;
        }
        
        for(let i = 0; i < candidate[index].length; i++) {
            if(caseArr.includes(candidate[index][i])) continue;
            const nextCaseArr = [...caseArr];
            nextCaseArr.push(candidate[index][i]);
            getCases(index + 1, nextCaseArr);
        }
    }
    
    getCases(0, []);
    
    return cases.size;
}