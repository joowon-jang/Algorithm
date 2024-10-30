function solution(str1, str2) {
    let answer = 0;
    
    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();
    
    let group1 = [];
    let group2 = [];
    
    for(let i=0; i<str1.length-1; i++) {
        const el = str1.substring(i,i+2);
        if(!/^[a-z]+$/.test(el)) continue;
        group1.push(el);
    }
    for(let i=0; i<str2.length-1; i++) {
        const el = str2.substring(i,i+2);
        if(!/^[a-z]+$/.test(el)) continue;
        group2.push(el);
    }
    
    let intersection = 0;
    let union = 0;
    
    group1.forEach((el) => {
        if(group2.includes(el)) {
            group2.splice(group2.indexOf(el), 1);
            intersection++;
        }
    })
    union = group1.length + group2.length;
    
    if(intersection === 0 && union === 0) return 65536;
    
    answer = Math.floor(intersection / union * 65536);
    
    return answer;
}