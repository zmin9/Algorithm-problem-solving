// 입력 처리
const fs = require('fs');
//const [N, input] = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const [N, input] = fs.readFileSync('./input.txt').toString().trim().split('\n');
const nums = input.trim().split(' ').map(Number);

const dp = Array(Number(N)).fill(1);

// nums에서 index 0 부터 해당 숫자까지만 생각했을 때 만들수 있는 가장 긴 증가하는수열의 길이를 dp에 저장
// 자신보다 작은 수들이 가지는 길이에 +1
for(let i = 1; i < Number(N); i++){
    for(let j = 0; j < i; j++){
        if(nums[j] < nums[i]) {
            dp[i] = Math.max(dp[i], dp[j] + 1);
        }
    }
}

console.log(Math.max(...dp));