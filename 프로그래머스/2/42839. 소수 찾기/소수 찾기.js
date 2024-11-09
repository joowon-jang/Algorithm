function isPrime(num) {
    if(num <= 1) return false;
    for (let i = 2; i*i <= num; i++) {
        if (num % i === 0) return false;
    }
    return true;
}

function getPermutations(arr, selectNumber) {
    const results = [];
    if (selectNumber === 1) return arr.map((el) => el); 

    arr.forEach((fixed, index, origin) => {
        const rest = [...origin.slice(0, index), ...origin.slice(index+1)] 
        const permutations = getPermutations(rest, selectNumber - 1); 
        const attached = permutations.map((el) => fixed + el); 
        results.push(...attached); 
    });

    return results;
}

function solution(numbers) {
    let answer = 0;
    const numbersToString = numbers.split('');
    
    for(let i=1; i<=numbersToString.length; i++) {
        const permutation = getPermutations(numbersToString, i);
        const duplicationRemoved = new Set(permutation);
        duplicationRemoved.forEach(num =>  {
            if(num[0] !== '0' && isPrime(Number(num))) {
                answer++;
            }
        });
    }
    
    return answer;
}