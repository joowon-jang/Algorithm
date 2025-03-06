function solution(picks, minerals) {
    let answer = 0;
    const cnt = Math.ceil(minerals.length / 5);

    let maxLen = picks.reduce((a, b) => a + b);
    if (maxLen === 0) return 0;

    minerals = minerals.splice(0, maxLen * 5);

    let arr = [];
    for(var i = 0; i < cnt; i++){
        const obj = {diamond: 0, iron: 0, stone: 0};

        minerals.splice(0, 5).map((element) => {
            obj[element]++;
        })
        arr.push([obj.diamond + obj.iron + obj.stone, obj.diamond * 5 + obj.iron + obj.stone, obj.diamond * 25 + obj.iron * 5 + obj.stone]);
    }
    
    arr = arr.sort((a, b) => b[2] - a[2]) 
    for(var i = 0; i < picks.length; i++){
        let pickCount = picks[i];
        while(pickCount--){
            if(arr.length === 0) return answer;
            answer += arr.shift()[i];
        }
    }
    
    return answer;
}