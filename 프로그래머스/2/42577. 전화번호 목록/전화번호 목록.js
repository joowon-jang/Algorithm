function solution(phone_book) {
    return !phone_book.sort().some((el, index, array) => {
        if(index === array.length - 1) return false;
        return array[index + 1].startsWith(array[index]);
    })
}