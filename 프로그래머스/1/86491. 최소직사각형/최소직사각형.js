function solution(sizes) {
    let long = 0;
    let short = 0;
    
    for(const size of sizes) {
        long = Math.max(long, Math.max(size[0], size[1]));
        short = Math.max(short, Math.min(size[0], size[1]));
    }
    
    return long * short
}