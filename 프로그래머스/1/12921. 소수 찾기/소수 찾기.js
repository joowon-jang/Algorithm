function solution(n) {
    const primes = new Set();
    primes.add(2);
    for(let i = 3; i <= n; i+=2) {
        primes.add(i);
    }
    
    for(let i = 3; i <= Math.sqrt(n); i += 2) {
        for(let j = i * 2; j <= n; j += i) primes.delete(j);
    }
    
    return primes.size;
}