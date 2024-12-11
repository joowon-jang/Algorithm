function gcd(a, b) {
    return b === 0 ? a : gcd(b, a % b);
}

function gcdArray(arr) {
    return arr.reduce((acc, num) => gcd(acc, num));
}

function solution(arrayA, arrayB) {
    let answer = 0;
    const gcdA = gcdArray(arrayA);
    const gcdB = gcdArray(arrayB);
    
    for(let i = 0; i < arrayA.length; i++) {
        if(arrayA[i] % gcdB === 0) break;
        if(i === arrayA.length - 1) answer = gcdB;
    }
    for(let i = 0; i < arrayB.length; i++) {
        if(arrayB[i] % gcdA === 0) break;
        if(i === arrayB.length - 1) answer = Math.max(answer, gcdA);
    }
    
    return answer;
}