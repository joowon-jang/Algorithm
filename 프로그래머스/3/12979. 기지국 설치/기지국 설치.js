function solution(n, stations, w) {
    let answer = Math.ceil((stations[0] - w - 1) / (2 * w + 1));
    for(let i = 1; i < stations.length; i++) {
        answer += Math.ceil((stations[i] - stations[i - 1] - (2 * w) - 1) / (2 * w + 1));
    }
    answer += Math.ceil((n - stations[stations.length - 1] - w) / (2 * w + 1));
    
    return answer;
}