const fs = require('fs');

//const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const input = fs.readFileSync('./input.txt').toString().split('\n');
const K = parseInt(input[0].split(' ')[0]);
const N = parseInt(input[0].split(' ')[1]);

let low = 1
let high = 1;

// 가장 긴 랜선보다 그 이상으로 잘려진 랜선의 길이를 정할 수는 없으므로
// 가장 긴 랜선을 최댓값으로 정함
for(let i = 1; i <= K; i++){
    input[i]=parseInt(input[i]);
    if(high < input[i]) high = input[i];
}

while(low <= high){
    // mid 계산
    let mid = parseInt((low + high) / 2);
    let numLine = 0;

    // 해당 길이로 랜선을 자를 때 나오는 랜선의 개수 계산
    for(let i = 1; i <= K; i++) {
        numLine += parseInt(input[i] / mid);
    }

    // 원하는 개수보다 많거나 같으면 더 길게해서 잘라보기 위해 low 이동
    if(numLine >= N){
        low = mid + 1;
    }
    // 원하는 개수보다 적다면 더 짧게해서 잘라보기 위해 high 이동
    else{
        high = mid - 1;
    }
}

// while문을 빠져 나오는 조건이 low가 high보다 커지는 경우이므로 high 값이 마지막 mid 값이 됨
console.log(high);