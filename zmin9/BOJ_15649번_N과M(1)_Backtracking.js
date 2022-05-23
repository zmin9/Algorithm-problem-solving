const fs = require('fs');
// const [N, M] = fs.readFileSync('./dev/stdin').toString().trim().split(' ').map(Number);
const [N, M] = fs.readFileSync('./input.txt').toString().trim().split(' ').map(Number);


const num = Array(N+1); // 사용한 숫자를 표시할 배열
const arrNum = [];      // 실제 수열을 저장할 배열

const backtracking = (depth, arr) => {
  // depth는 곧 수열의 길이를 나타냄
  if(depth===M){
    console.log(arr.join(' '));
    return;
  }

  // 사용하지 않은 숫자들에 대하여 재귀호출
  for(let i=1; i<=N;i++){
    if(!num[i]){
      // 실제 수열 뒤에 넣어주고 사용여부를 true로 변경
      arr.push(i);
      num[i]=true;
      backtracking(depth+1,arr);
      arr.pop();
      num[i]=false;
    }
  }
};

// 모든 숫자들에 대해 백트래킹 시작지점 잡아줌
for(let i=1;i<=N;i++){
  arrNum.push(i);
  num[i]=true;
  backtracking(1,arrNum);
  arrNum.pop();
  num[i]=false;
}