function solution(num_list, n) {
    return num_list.reduce((acc, curr, i) => i % n ? acc : [...acc, curr], []);
}