// 입력 처리
const fs = require('fs');
//const N = fs.readFileSync('./dev/stdin').toString() * 1;
const N = fs.readFileSync('./input.txt').toString() * 1;

// 각 자릿수 별로 0-9까지의 숫자가 나오는 가짓수를 저장
const dp = new Array(N+1);
dp[1] = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1];

// N === 1 이라면 바로 출력
if(N===1) console.log(dp[1].reduce((sum, currValue) => sum + currValue , 0) % 1000000000);
else {
    for (let i = 2; i <= N; i++){
        dp[i] = [];
        // 0과 9의 경우 이전 자릿수가 1 또는 8때의 가짓수가 그대로 전달
        dp[i][0] = dp[i-1][1] % 1000000000;
        dp[i][9] = dp[i-1][8] % 1000000000;
        // 다른 숫자의 경우 +1 -1 되는 두가지 경우로 연산되어질 수 있음
        for(let j = 1; j <= 8; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= 1000000000;
        }
    }
    // 전부 더한 값 출력
    console.log(dp[N].reduce((sum, currValue) => sum + currValue , 0) % 1000000000);
}


