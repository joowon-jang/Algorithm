function solution(skill, skill_trees) {
    let cnt = 0;

    for (let tree of skill_trees) {
        let s = tree.split("").filter((ch) => skill.indexOf(ch) > -1).join("");
        if (skill.indexOf(s) === 0) cnt++;
    }

    return cnt;
}