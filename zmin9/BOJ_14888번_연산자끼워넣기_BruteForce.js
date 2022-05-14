const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = Number(input.shift().trim());
const nums = input.shift().trim().split(' ').map(Number);
const operator = input.shift().trim().split(' ').map(Number);

// operator 인덱스에 따라 값을 계산하여 return
const operation = (operator, n, m) => {
    switch(operator){
        case 0:
            return n + m;
        case 1:
            return n - m;
        case 2:
            return n * m;
        case 3:
            return n > 0?
                Math.floor( n / m)
                : (-1) * Math.floor( (-1) * n / m) ;
    }
};

let max = -Infinity;
let min = Infinity;


const cal = (l, res) => {
    // l 이 N이 되면 모든 수를 연산한 것이므로 최대/최솟값 비교후 종료
    if(l === N) {
        if(max < res) max = res;
        if(min > res) min = res;
        return;
    }

    const operand = nums[l];
    
    // 현재 시점 존재하는 operator에 대해 모두 연산해봄
    for(let i = 0; i < 4; i++) {
        if(operator[i] !== 0){
            operator[i]--;
            // 계산한 결과를 이용하여 또 다음값을 계산
            cal(l+1, operation(i, res, operand));
            operator[i]++;
        }
    }
};

// 첫 숫자는 먼저 넣어줌
cal(1,nums[0]);

// 자바스크립트의 경우 -0, +0이 나눠 출력될 수 있으므로 이 경우도 처리해줘야 함
console.log(max ? max : 0);
console.log(min ? min : 0);