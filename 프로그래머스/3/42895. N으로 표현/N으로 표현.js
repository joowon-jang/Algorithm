function solution(N, number) {
    if(N === number) return 1;
    const repeated = Array.from({ length : 9 }, () => new Set());
    
    for(let i = 1; i <= 8; i++) {
        repeated[i].add(Number(N.toString().repeat(i)));
    }
    
    for(let i = 1; i <= 8; i++) {
        for(let j = 1; j < i; j++) {
            for(const first of repeated[j]) {
                for(const second of repeated[i-j]) {
                    repeated[i].add(first + second);
                    repeated[i].add(first - second);
                    repeated[i].add(first * second);
                    repeated[i].add(first / second);
                }
            } 
        }

        if(repeated[i].has(number)) return i;
    }
    
    return -1;
}