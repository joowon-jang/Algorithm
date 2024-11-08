function solution(n, t, m, p) {
    let answer = ""
    let i = 0
    let cnt = 0
    
    while (answer.length < t) {
        const nums = i.toString(n).toUpperCase().split("");
        for (const num of nums){
            if (cnt % m === p - 1 && answer.length < t) answer += num;
            cnt++
        }
        i++
    }
    return answer
}