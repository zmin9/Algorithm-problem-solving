// 입력 처리
const fs = require('fs');
let N = parseInt(fs.readFileSync('/dev/stdin').toString());
//let N = parseInt(fs.readFileSync('./input.txt').toString());

// 버튼 종류 5분=300초, 1분=60초,
const buttons = [300, 60, 10];
let result = '';

// 버튼 종류 적어서 반복문 없이도 처리 가능
if (N%10 === 0) {
    result = result + Math.floor(N / buttons[0]) + ' ';
    N %= buttons[0];
    result = result + Math.floor(N / buttons[1]) + ' ';
    N %= buttons[1];
    result = result + Math.floor(N / buttons[2]);
    N %= buttons[2];
    console.log(result);
}
// 나머지 있으면 10초로 해결할 수 없음
else { 
    console.log('-1');
}