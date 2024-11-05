function solution(phone_book) {
    phone_book.sort();
    const dict = new Set(phone_book);
    
    for(const phoneNumber of phone_book) {
        for(let i=1; i<phoneNumber.length; i++) {
            if(dict.has(phoneNumber.slice(0, i))) return false;
        }
    }
    
    return true;
}