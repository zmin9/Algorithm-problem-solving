const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [N, M]= input.shift().trim().split(' ').map(Number);

// 집합 S에 있는 단어들을 나타낼 객체(배열은 시간이 더 걸림)
const arr = {};

for(let i = 0; i < N; i++){
    arr[input.shift().trim()] = true;
}

let result = 0;

// 집합 S에 해당 단어가 있으면 result++, 없으면 아예 새롭게 프로퍼티가 undefined 로 추가 -> false
for(let i = 0; i < M; i++){
    if(arr[input.shift().trim()]) result++;
}

console.log(result);