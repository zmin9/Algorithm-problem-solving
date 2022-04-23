const fs = require('fs');

// const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const input = fs.readFileSync('./input.txt').toString().split('\n');
const [N, M] = input[0].split(' ').map(num => parseInt(num));
const L = input[1].split(' ').map(num => parseInt(num));

let low = Math.max(...L);    // 가장 긴 트랙의 길이가 최솟값이 됨, 전개연산자 이용
let high = 1000000000;  // 블루레이 크기 최대 경우 -> 블루레이 1개에 9999분짜리 강의 100000개

// 각 블루레이의 크기를 저장할 result
let result = -1;

// 각 블루레이의 크기에 대해 이진탐색을 진행
while ( low <= high ){
    const mid = Math.floor((low + high)/2);
    let usedNum = 1;
    let cur = 0;
    for(let i = 0; i < N; i++){
        if(mid - cur < L[i]){
            cur = 0;
            usedNum++;
        }
        cur += L[i];
    }

    // 해당 크기일때 사용한 블루레이의 개수가 M보다 크면 블루레이 크기를 늘려야함
    if( usedNum > M ) {
        low = mid + 1;
    }
    // 개수가 M보다 작으거나 같으면 블루레이 크기를 조금씩 줄여가며 최소 크기를 찾아야함
    else {
        result = mid;
        high = mid - 1;
    }
}

console.log(result);