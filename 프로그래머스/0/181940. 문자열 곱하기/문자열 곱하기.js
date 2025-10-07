function solution(my_string, k) {
    return my_string.concat(...Array.from({ length: k - 1 }, () => my_string));
}