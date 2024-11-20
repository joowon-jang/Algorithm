function getCases(candidate, index, caseArr, result) {
    if(index === candidate.length) {
        result.push(caseArr.sort().join(''));
        return;
    }

    for(let i = 0; i < candidate[index].length; i++) {
        if(caseArr.includes(candidate[index][i])) continue;
        const nextCaseArr = [...caseArr, candidate[index][i]];
        getCases(candidate, index + 1, nextCaseArr, result);
    }
    
    return result;
}

function solution(user_id, banned_id) {
    let answer = 0;
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
    
    const cases = new Set(getCases(candidate, 0, [], []));
    
    return cases.size;
}