// 입력 처리
const fs = require('fs');

// 아무리 봐도 알고리즘이 틀린게 없는데 틀렸대서 봤더니 입력 부분의 문제였던 것 같다..
// 주석 처리된 것처럼 해도 값도 잘 나오고 알고리즘에 들어가게 되는 변수의 구조도 동일해보이는데 왜 안됐던건지 잘 모르겠음
//let N = fs.readFileSync('./dev/stdin').toString().split('');
let [input] = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = input.split('');



// 30의 배수이려면 1의 자릿수가 0이어야하고 모든 자릿수를 더한 값이 3의 배수
if(!N.includes('0')) {
    console.log(-1);
}
else {
    let sum = 0;
    N.forEach(n=>{
        sum += parseInt(n) % 3;
    });
    if (sum % 3 !== 0){
        console.log('-1');
    }
    else {
        console.log(N.sort().reverse().join(''));
    }
}