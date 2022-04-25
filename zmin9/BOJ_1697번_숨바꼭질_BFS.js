// 입력 처리
const fs = require('fs');

//const [N, K] = fs.readFileSync('./dev/stdin').toString().trim().split(' ').map(Number);
const [N, K] = fs.readFileSync('./input.txt').toString().trim().split(' ').map(Number);

let count = 0; // 첫 시작 부분의 시간은 0초이기 때문
let found = false;
const list = [N];

const isVisit = new Array(100001);
isVisit.fill(false);

// BFS를 이용하여 다음 시간에 존재할 수 있는 칸을 전부 list(queue)에 넣고
// 현재 시간에 존재할 수 있는 칸에 대한 탐색을 모두 진행한 뒤 다음 시간을 진행
while(!found){
    const len = list.length;
    // 현재 탐색 list에 남아있는 값에 대해서만 탐색 (현재 시간)
    for(let i=0; i<len;i++){
        const num = list.shift();
        if(num === K){
            console.log(count);
            found = true;
            break;
        }
        isVisit[num] = true;
        // 걸어서 이동하고 순간이동하는 위치가 범위 내라면 list에 추가 (다음 시간)
        if(num-1 >= 0 && !isVisit[num-1]) list.push(num-1);
        if(num+1 <= 100000 && !isVisit[num+1]) list.push(num+1);
        if(num*2 <= 100000 && !isVisit[num*2]) list.push(num*2);
    }
    count++;    // 시간 증가
}

