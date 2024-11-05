function solution(participant, completion) {
    const mapCompletion = new Map();
    
    for(const person of completion) {
        mapCompletion.set(person, (mapCompletion.get(person) || 0) + 1);
    }
    
    for(const person of participant) {
        if(!mapCompletion.get(person)) return person;
        mapCompletion.set(person, mapCompletion.get(person) - 1);
        if(mapCompletion.get(person) === 0) mapCompletion.delete(person);
    }
}