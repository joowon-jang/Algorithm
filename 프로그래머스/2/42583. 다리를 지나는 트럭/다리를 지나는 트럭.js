function solution(bridge_length, weight, truck_weights) {
    let answer = bridge_length;
    let q = [];
    let totalWeight = 0;
    let i = 0;
    
    while(i < truck_weights.length) {
        answer++;
        if(answer - q[0] >= bridge_length) {
            totalWeight -= truck_weights[i - q.length];
            q.shift();
        }
        if(totalWeight + truck_weights[i] <= weight) {
            q.push(answer);
            totalWeight += truck_weights[i];
            i++;
        }
    }
    
    return answer;
}