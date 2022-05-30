const fs = require('fs');
// const N = Number(fs.readFileSync('./dev/stdin').toString().trim());
const N = Number(fs.readFileSync('./input.txt').toString().trim());

// N*N 체스판에 N개의 퀸이 서로를 공격할 수 없도록 자리해야하므로 한 row당 하나의 퀸이 있어야함
// row배열은 각 row(인덱스)에 위치하는 퀸의 col 값을 저장
// row와 col은 0~N-1
const row = Array(N).fill(-1);
let result = 0;

// 공격당할 위치인지 아닌지 판별
const isAttacked = (r, c) => {
  for(let i=0; i<r; i++){
    // 이전 row들에 c값이 존재한다면 그 c열은 공격 당할 수 있음
    if(c===row[i]) return true;
    // 대각선에도 위치하는지 보려면 행의 차와 열의 차가 같은지를 확인
    if(Math.abs(row[i]-c)===r-i) return true;
  }
  return false;
};

const NQueen = (r) => {
  if(r===N){
    result++;
    return;
  }

  // 모든 열에 대해 검사
  for(let i=0; i<N; i++){
    if(!isAttacked(r,i)){
      row[r]=i;
      // 다음 행에 대해 재귀호출
      NQueen(r+1);
    }
  }
};

NQueen(0);

console.log(result);