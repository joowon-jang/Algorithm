function solution(elements) {
    let newElements = elements.concat(elements);
    let arr = [];
    let len = elements.length;
    
    for(let i=0; i<len; i++) {
        let num = 0;
        for(let j=0; j<len; j++) {
            num += newElements[i + j];
            arr.push(num);
        }
    }
    
    const set = new Set(arr);

    const uniqueArr = [...set];
    
    return uniqueArr.length;
}