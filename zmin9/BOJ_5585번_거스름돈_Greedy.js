const fs = require('fs');

// 입력 처리
//const N = parseInt(fs.readFileSync('/dev/stdin').toString());
const N = parseInt(fs.readFileSync('./input.txt').toString());

// 구해야하는 것이 '잔돈 개수'임에 유의할 것
let change = 1000 - N;
let result = 0;

// 가지고 있는 잔돈 종류
const coins = [500, 100, 50, 10, 5, 1];

// 큰 단위의 잔돈을 많이 쓸 수록 전체 잔돈의 개수가 적어지므로
// 가장 큰 단위의 잔돈부터 거슬러줄 수있는 최대값을 거슬러준다
coins.forEach((coin)=>{
    if(N<=0) return;
    result = result + Math.floor(change / coin);
    change %= coin;
});

console.log(result);