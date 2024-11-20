function compareNumber(a, b) {
    return parseInt(a) > parseInt(b) ? 1 : parseInt(a) < parseInt(b) ? -1 : 0
}

function compare(a, b) {
    const reg = /(\D*)([0-9]*)/i;
    const A = a.match(reg);
    const B = b.match(reg);
    const compareHead = A[1].toLowerCase().localeCompare(B[1].toLowerCase());
    
    return compareHead === 0 ? compareNumber(A[2], B[2]) : compareHead;
}

function solution(files) {
    return files.sort(compare);
}