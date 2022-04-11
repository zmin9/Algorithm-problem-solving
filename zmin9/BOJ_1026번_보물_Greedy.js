let fs = require('fs');

//let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let input = fs.readFileSync('./input.txt').toString().split('\n');

// 입력 처리
let N = parseInt(input[0]);
let A = input[1];
let B = input[2];
A = A.toString().split(' ');
A = A.map(n => n*1);
B = B.toString().split(' ');
B = B.map(n => n*1);

let result = 0;

/* Array.sort()를 이용하여 A의 가장 큰 수와 B의 가장 작은 수를 곱해 주는 방법도 있으나
    문제 조건에서 굳이 B를 재배열하지 말라고 했기 때문에
    하나하나 비교해가며 더해 나갈 것 (..을 했으나 그냥 sort 쓰는 것이 편할 듯)
 */

A.sort(function(a, b)  {
    return a - b;
});

let selectedIdx = [];   // B배열에서 한 번 선택됐던 인덱스를 저장할 배열

for(let i = 0; i < N; i++){
    let largeNum=-1;
    let index=-1;
    // B배열을 돌며 가장 큰 수를 찾는데 이전에 찾아졌던 수는 제외함
    for(let j = 0; j < N; j++){
        if((largeNum<B[j]) && selectedIdx.indexOf(j,0)===-1) {
            index = j;
            largeNum = B[j];
        }
    }
    selectedIdx.push(index);
    result = result + A[i] * largeNum;
}

console.log(result);