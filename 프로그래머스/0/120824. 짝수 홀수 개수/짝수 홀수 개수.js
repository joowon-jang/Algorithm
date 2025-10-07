function solution(num_list) {
    return num_list.reduce((acc, curr) => curr % 2 === 0 ? [acc[0] + 1, acc[1]] : [acc[0], acc[1] + 1], [0, 0])
}