const fs = require('fs');

//const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const input = fs.readFileSync('./input.txt').toString().split('\n');
const N = parseInt(input[0]);
const M = parseInt(input[2]);
const budgets = input[1].split(' ').map(budget => parseInt(budget));

budgets.sort(function (a,b){return b-a});

// 지역에 나눠주는 예산의 상한가는 최소 1원에서 요구되는 예산 중 가장 큰 액수(그니까 모든 지역이 원하는 예산을 전부 주는 경우)까지 가능
let low = 1;
let high = budgets[0];
let result;

while ( low <= high ){
    let mid = parseInt((low + high)/2);
    let sum = 0;
    budgets.forEach(budget => sum += budget < mid ? budget : mid);

    if(sum > M) high = mid - 1;
    else {  // 일반적인 이분탐색과 다른 것은 각 지역 예산의 총 합이 M보다 작거나 같을 때만 result가 될 수 있음
        low = mid + 1;
        result = mid;
    }
}

console.log(result);