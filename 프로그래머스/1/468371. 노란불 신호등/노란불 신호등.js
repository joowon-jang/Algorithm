function getGCD(a, b) {
    return b === 0 ? a : getGCD(b, a % b);
}
function getLCM(a, b) {
    return a / getGCD(a, b) * b;
}

function solution(signals) {
    const cycles = signals.map(([G, Y, R]) => G + Y + R);
    const lcm = cycles.reduce((acc, curr) => getLCM(acc, curr), cycles[0]);
    
    let t = 1;
    while(t <= lcm) {
        let pass = true;
        
        for(const [G, Y, R] of signals) {
            const cycle = G + Y + R;
            if(!(G < t % cycle && t % cycle <= G + Y)) {
                pass = false;
                break;
            }
        }
        
        if(pass) return t;
        t++;
    }
    
    return -1;
}