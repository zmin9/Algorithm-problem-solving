// 입력 처리
const fs = require('fs');

// const [N, ...input] = fs.readFileSync('./dev/stdin').toString().trim().split(/[\n ]/).map(Number);
const [N, ...input] = fs.readFileSync('./input.txt').toString().trim().split(/[\n ]/).map(Number);
const idx = Array(N).fill(0);
let result = 0;

/* 모든 경우의 수 계산
* pre : 이전 값, A[i-1]
* cur : 현재 값, A[i]
* depth : 더한 횟수 -> 최대는 N-1
* sum : 지금까지 더한 값
*/
const backtracking = (pre, cur, depth, sum) => {
  // 첫 시작값이 아니라면 pre, cur의 차이를 더함
  if(pre !== null){
    sum += Math.abs(pre-cur);
  }

  // 전부 계산한 경우 최댓값인 경우 대입
  if(depth===N-1){
    if(sum > result)
      result = sum;
    return;
  }

  // 선택되지 않은 수들에 대해 재귀 호출
  for(let i = 0; i < N; i++){
    if(idx[i]===0){
      idx[i]=1;
      backtracking(cur, input[i], depth+1, sum);
      idx[i]=0;
    }
  }

};

for(let i = 0; i < N; i++){
  idx[i]=1;
  backtracking(null, input[i], 0, 0);
  idx[i]=0;
}

console.log(result);