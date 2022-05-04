// 입력 처리
const fs = require('fs');
//const wines = fs.readFileSync('./dev/stdin').toString().trim().split('\n').map(Number);
const wines = fs.readFileSync('./input.txt').toString().trim().split('\n').map(Number);
const N = wines[0];

// 만약 1인 경우 한 잔을 마시는 선택지 밖에 없음
if(N === 1){
    console.log(wines[1]);
}
else {
    const dp = Array(N + 1);
    dp[0] = 0;
    dp[1] = wines[1];
    dp[2] = wines[1] + wines[2];
    for (let i = 3; i <= N; i++) {
        // 이전 잔과 연속해서 마시는 경우, 한 잔 건너 뛰고 마시는 경우, 현재 잔을 아예 마시지 않는 경우
        // 중에 최댓값을 정하여 dp에 저장
        dp[i] = Math.max(dp[i-3] + wines[i-1] + wines[i], dp[i-2] + wines[i], dp[i-1]);
    }
    console.log(Math.max(...dp));
}