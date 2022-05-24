const fs = require('fs');
// const [L, C, ...chars] = fs.readFileSync('./dev/stdin').toString().trim().split(/[ \n]/);
const [L, C, ...chars] = fs.readFileSync('./input.txt').toString().trim().split(/[ \n]/);

chars.sort();

const isUsed = Array((C*1));
const code = [];  // 코드를 저장할 변수

const backtracking = (depth, code, cur) => {
  if(depth===(L*1)){
    let count = 0;
    // 모음 개수 세기
    ['a', 'e', 'i', 'o', 'u'].forEach((char)=> {
      if(code.includes(char)) count++;
    })

    // 모음이 한 개 이상 사용된 모음의 개수를 제외한 남은 글자(자음)의 개수가 2개 이상일 경우에만 답 출력
    if(count >=1 && (L*1)-count>=2) console.log(code.join(''));
    return;
  }

  // sort 되어있는 character들에서 현재 문자 이후의 값에서 다시 push
  for(let i=cur+1; i<C*1;i++){
    if(!isUsed[i]){
      code.push(chars[i]);
      isUsed[i]=true;
      backtracking(depth+1, code, i);
      code.pop();
      isUsed[i]=false;
    }
  }
};

for(let i=0;i<C*1;i++){
  code.push(chars[i]);
  isUsed[i]=true;
  backtracking(1, code, i);
  code.pop();
  isUsed[i]=false;
}