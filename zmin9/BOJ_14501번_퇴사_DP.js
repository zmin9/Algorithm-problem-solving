// 입력 처리
const fs = require('fs');
// const [N, ...input] = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const [N, ...input] = fs.readFileSync('./input.txt').toString().trim().split('\n');
const nums = input.map(num => num.trim().split(' ').map(Number));

// 해당 날짜를 포함하여 실행된 상담들의 최대 이익을 저장할 배열
const dp = Array(Number(N)).fill(0);

for (let i = 0; i < N ; i++){
    // 만약 오늘의 상담을 진행할 수 없다면 다른 처리 없이 다음날로 넘어감
    // 이때 dp에 저장되어 있는 것은 해당 날짜 이전에 끝난 상담들의 최대 이익
    if(i + nums[i][0] > N) continue;

    // 오늘 상담을 할 수 있다면 dp를 증가시키고
    dp[i] += nums[i][1];
    // 해당 상담이 끝나는 이후 날짜들의 dp를 업데이트
    for (let j = i + nums[i][0]; j < N; j++)
        dp[j] = Math.max(dp[i],dp[j]);
}

console.log(Math.max(...dp));