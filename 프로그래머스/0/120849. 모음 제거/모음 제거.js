function solution(my_string) {
    return Array.from(my_string).filter(el => !['a', 'i', 'u', 'e', 'o'].includes(el)).join('');
}