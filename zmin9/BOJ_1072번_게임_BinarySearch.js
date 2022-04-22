// 알고리즘 적용하는 것보다는 실수 처리 방식(아마도..)때문에 애먹은 문제...

const fs = require('fs');

// const input = fs.readFileSync('/dev/stdin').toString().split(' ');
const input = fs.readFileSync('./input.txt').toString().split(' ');
const X = parseInt(input[0]); // 플레이 한 전체 게임 횟수
const Y = parseInt(input[1]); // 이긴 게임 횟수
const Z = Math.floor(100 * Y / X);    // 현재 승률

// 형택이는 지금부터 이기는 게임만 함
let low = 1;
let high = 1000000000;
let result = -1;

while ( low <= high ){
    let mid = Math.floor((low + high)/2);
    let newZ = Math.floor(100 * (Y+mid) / (X+mid));

    // 승률이 달라지는 경우 최소 값을 찾기 위해 범위를 낮게 잡음
    if(newZ !== Z ) {
        result = mid;
        high = mid - 1;
    }
    // 승률이 달라지지 않았다는 것은 더 많은 승리 횟수가 필요하다는 것을 의미
    else {
        low = mid + 1;
    }
}

console.log(result);


/* 이분 탐색을 사용하지 않는 방법
실수 처리 관련 연산이 약간 삐끗하는 것 같다..수정해서 정답은 나오는데 수정 전과 뭐가 다른지 잘 모르겠음

if(Z>=99){
    console.log(-1);
}
else{
    let result = (Z*X + X - 100*Y)/(99-Z);
    console.log(result===parseInt(result)?result:parseInt(result+1));
}
 */