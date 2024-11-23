function replaceNumberSign(notes) {
    return notes.replace(/(\w)#/g, (_, p) => p.toLowerCase());
}

function calcTimeDiff(start, end) {
    const [startHour, startMin] = start.split(":").map(Number);
	const [endHour, endMin] = end.split(":").map(Number);
    
	return (endHour - startHour) * 60 + (endMin - startMin);
}

function solution(m, musicinfos) {
    m = replaceNumberSign(m);
    let result = { title: "(None)", playTime: 0 };
    
    for(const info of musicinfos) {
        let [start, end, title, notes] = info.split(',');
        const playTime = calcTimeDiff(start, end);
        notes = replaceNumberSign(notes);
        console.log(notes, m);
        
        const playedNotes = notes.repeat(Math.floor(playTime / notes.length)) + notes.slice(0, playTime % notes.length);

        if(playedNotes.includes(m)) {
            if(result.playTime < playTime) result = { title, playTime };
        }
    }
    
    return result.title;
}