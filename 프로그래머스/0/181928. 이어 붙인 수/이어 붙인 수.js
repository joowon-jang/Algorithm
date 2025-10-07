function solution(num_list) {
    return num_list.reduce((acc, curr) => curr % 2 ? [acc[0]+curr, acc[1]] : [acc[0], acc[1]+curr] , ['', '']).reduce((acc, curr) => acc + Number(curr), 0);
}