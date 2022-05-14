// 입력 처리
const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split(' ').map(Number);
const input = fs.readFileSync('./input.txt').toString().trim().split(' ').map(Number);

let round = 0;

// 둘이 만나는 것은 이후 배정받을 숫자가 같은 경우 -> 승자가 가지게 되는 번호
while (input[1]!==input[2]){
    round++;
    // 경기에서 이긴 뒤 배정받을 숫자는 현재 숫자를 2로 나눈 값을 올림한 값
    input[1] = Math.ceil(input[1]/2);
    input[2] = Math.ceil(input[2]/2);
}

console.log(round);