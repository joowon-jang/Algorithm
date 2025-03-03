function solution(stones, k) {
    let left = 1;
    let right = 200000000;
    
    while(left < right - 1) {
        const mid = Math.floor((left + right) / 2);
        
        let range = 0;
        for(let i = 0; i < stones.length; i++) {
            
            if(stones[i] < mid) range++;
            else range = 0;
            
            if(range >= k) {
                right = mid;
                break;
            }
            if(i === stones.length - 1) left = mid;
        }
    }
    
    return left;
}
