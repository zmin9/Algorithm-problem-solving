const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split(':');
const input = fs.readFileSync('./input.txt').toString().trim().split(':');

// input은 축약된 IPv6주소를 :를 기준으로 끊어서 입력받음

for(let i = 0 ; i < 8; i++){
  // 만약 ''(연속된 콜론)일 경우 한 개 이상의 0으로 이루어진 그룹이 축약된 것
  if( input[i]==='' ){
    // i+1은 주소값이 오는 경우 축약된 0 그룹이 주소의 중간에 위치하는 것
    // 해당 칸만 부족한 길이만큼 0000으로 대체시켜 주면 됨
    if(input[i+1] !== '') {
      const addZero = Array(8 - input.length + 1).fill('0000');
      input.splice(i, 1, ...addZero);
    }
    // i+1 값도 ''인 경우 축약된 0 그룹이 가장 처음이나 끝에 위치하고 있는 것
    // 다음 '' 도 같이 지워줘야 함
    else {
      const addZero = Array(8 - input.length + 2).fill('0000');
      input.splice(i, 2, ...addZero);
    }
  }
  // 주소가 존재하는 그룹인데 길이가 4가 아닌 경우 그룹 앞 쪽의 0이 생략된 것
  else if(input[i].length !== 4) {
    input[i] = '0'.repeat(4 - input[i].length) + input[i];
  }
}

console.log(input.join(':'));