function solution(nums) {
    let answer = 0;
    const dict = new Map();
    
    for(const num of nums) {
        dict.set(num, (dict.get(num) || 0) + 1);
    }
    
    if(nums.length / 2 >= dict.size) answer = dict.size;
    else answer = nums.length / 2;
    
    return answer;
}