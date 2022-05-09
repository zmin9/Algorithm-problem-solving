// 입력 처리
const fs = require('fs');
//let input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
let input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = Number(input.shift());
input = input.map(line => line.trim().split(' ').map(Number));

// 인덱스 값이 직원을 나타내고 요소값으로 팀을 나눔 (0/1)
const team = Array(N).fill(0);
let result = Infinity;

// DFS + 백트래킹
// 팀을 나눌 때 DFS를 사용하고
// 모든 팀원을 고른 뒤 차이값을 계산한 뒤에는 다시 분기점으로 돌아와서 다른 팀원을 선택하는 백트래킹 이용
const DFS = (curIdx, nMember) => {
    // 만약 팀이 나눠진 경우 능력치 계산
    if(nMember === N/2){
        const start = [];
        const link = [];

        // 팀들 나눠서 저장
        team.forEach((t,idx)=>(t===0? start.push(idx):link.push(idx)));

        let startSum = 0;
        let linkSum = 0;

        // 각 팀의 능력치 계산
        for(let i = 0; i < N/2; i++){
            for(let j = i + 1; j < N/2; j++){
                startSum += (input[start[i]][start[j]] + input[start[j]][start[i]]);
                linkSum += (input[link[i]][link[j]] + input[link[j]][link[i]]);
            }
        }

        if (Math.abs(startSum-linkSum) < result) result = Math.abs(startSum-linkSum);
        return;
    }

    // 팀원을 더 찾아야 하는 경우 중복탐색을 막기 위해 현재 추가된 멤버 뒷순서에서 새로운 멤버를 찾음
    for(let i = curIdx; i < N; i++){
        if(team[i] !== 1){
            team[i] = 1;
            DFS(i, nMember + 1)
            // 다음 탐색을 위해 다시 돌려둬야함
            team[i] = 0;
        }
    }
};

// 직원 0을 포함하는 경우만 탐색
// 직원을 두 팀으로 나누는 것이 중요, 팀이 어떤 이름을 가지는 지는 중요하지 않으며 오히려 중복 계산
DFS(0,0)

console.log(result);