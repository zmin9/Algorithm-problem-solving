const fs = require('fs');

//const N = Number(fs.readFileSync('./dev/stdin').toString().trim());
const N = Number(fs.readFileSync('./input.txt').toString().trim());

// 숫자가 쓰였는지 확인할 배열
const checkNum = Array(N+1).fill(0);


const dfs = (...arr) => {
    // arr의 길이가 N이 되면 arr를 출력하고 더이상 숫자를 추가하지않고 종료 
    if(arr.length === N) {
        console.log(arr.join(' '));
        return;
    }

    // 이미 쓰여진 숫자를 제외하고 가장 작은 숫자부터 arr에 넣음
    for(let i = 1; i <= N; i++) {
        if(checkNum[i] === 0){
            checkNum[i] = 1;
            dfs(...arr, i);
            checkNum[i] = 0;
        }
    }
};

// 1 ~ N 까지의 숫자로 시작하는 모든 순열 탐색
for(let i = 1; i <= N; i++) {
    checkNum[i] = 1;
    dfs(i);
    checkNum[i] = 0;
}