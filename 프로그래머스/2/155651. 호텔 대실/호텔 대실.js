function toMinute(timeString) {
    const [hour, minute] = timeString.split(':');
    return Number(hour) * 60 + Number(minute);
}

function solution(book_time) {
    book_time.sort();
    const using = [];
    
    for(let [start, end] of book_time) {
        start = toMinute(start);
        end = toMinute(end) + 10;
        
        const idx = using.findIndex(room => room <= start);
        
        if(idx === -1) using.push(end);
        else using[idx] = end;
    }
    
    return using.length;
}