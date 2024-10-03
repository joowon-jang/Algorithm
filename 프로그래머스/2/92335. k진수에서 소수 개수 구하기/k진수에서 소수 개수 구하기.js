function isPrime(num) {
    if(num <= 1) return false;
    for(let i=2; i*i<=num; i++) {
        if(num % i === 0) return false;
    }
    return true;
}

function solution(n, k) {
    let answer = 0;
    
    let numbers = n.toString(k).split('0');
    
    numbers.forEach(num => {
        if(isPrime(num*1)) answer++;
    })
    
    return answer;
}