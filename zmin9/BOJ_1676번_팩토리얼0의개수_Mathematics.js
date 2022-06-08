const fs = require('fs');
//const N = Number(fs.readFileSync('/dev/stdin').toString());
const N = Number(fs.readFileSync('./input.txt').toString());

/*
 * 0 ≤ N ≤ 500
 * 곱셈에서 0이 생기는 경우는 10이 곱해졌을 때고 10은 2와 5로 이루어진 값
 * 따라서 해당 곱셈에서의 2와 5의 개수를 세면 됨
 * 이때 2와 5의 거듭제곱 고려
 */

// 5의 개수 - 5, 25, 125의 배수의 개수
let fiveNum = Math.floor(N / 5) + Math.floor(N / 25) + Math.floor(N / 125);

// 2의 개수 - 2^8(256)까지의 배수의 개수
let twoNum = 0;
let two = 1
for (let i = 0; i < 8; i++) {
  two *= 2;
  twoNum += Math.floor(N / two);
}

// 2와 5가 짝지어졌을 때 0이 하나 생기므로 두 개의 값 중 최솟값이 0의 개수
console.log(Math.min(fiveNum, twoNum));
