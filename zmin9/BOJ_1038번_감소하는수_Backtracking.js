// 입력 처리
const fs = require('fs');

// const N = Number(fs.readFileSync('./dev/stdin').toString().trim());
const N = Number(fs.readFileSync('./input.txt').toString().trim());

// 감소하는 수는 총 1023개 -> {0,1,2,3,4,5,6,7,8,9}의 공집합이 아닌 부분집합의 개수
// 하지만 최대 감소하는 수는 9876543210 으로 모든 수를 하나하나 증가시켜가며 검사하기엔 비효율적
// 역으로 감소하는 수를 그냥 먼저 찾고 sort

if( N > 1022 ) console.log(-1); // 인덱스를 벗어나는 값이면 바로 -1 출력
else {
  const decNum = [];  // 감소하는 수들이 담길 배열, length = 1023
  const num = Array(10).fill(0);
  
  const backtracking = (cur) => {
    let temp = 0;
    
    // 지금까지의 num의 포함상황을 10진수로 바꾸어서 decNum에 대입
    // 감소하는 수이므로 index=9부터 시작
    for(let idx = 9; idx >= 0; idx--){
      if(num[idx]===1){
        temp = temp * 10 + idx;
      }
    }
    decNum.push(temp);

    // 겹치지 않도록 지금 num 이후의 값 중 포함시킬 값 선정
    for(let i = cur + 1; i < 10; i++){
      num[i]=1;
      backtracking(i);
      num[i]=0;
    }
  };

  for(let i = 0; i < 10; i++){
    num[i]=1;
    backtracking(i);
    num[i]=0;
  }

  // 오름차순 정렬
  decNum.sort(function(a,b){return a-b;});

  console.log(decNum[N]);
}
