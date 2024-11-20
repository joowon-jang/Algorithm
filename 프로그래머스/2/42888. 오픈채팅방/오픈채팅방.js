function solution(record) {
    const result = [];
    const map = new Map();
    
    record.forEach((message, index) => {
        const [command, userId, nickName] = message.split(" ");
        if(command !== 'Leave') map.set(userId, nickName);
    });
    
    record.forEach((message, index) => {
        const [command, userId, nickName] = message.split(" ");
        
        switch(command) {
            case 'Enter':
                result.push(`${map.get(userId)}님이 들어왔습니다.`);
                break;
            case 'Leave':
                result.push(`${map.get(userId)}님이 나갔습니다.`);
                break;
        }
    })
    
    return result;
}