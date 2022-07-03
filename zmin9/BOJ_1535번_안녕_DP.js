const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const N = Number(input.shift());
const energy = input.shift().trim().split(' ').map(Number);
const pleasure = input.shift().trim().split(' ').map(Number);

// 배낭 문제, Knapsack 알고리즘

// 햇갈리면 안되는 것 energy와 pleasure은 인덱스 0부터, dp는 인덱스 1부터
const dp = Array.from(Array(N+1), () => Array(101).fill(0));

for (let num = 1; num <= N; num++) {
    for (let e = 1; e <= 100; e++) {
        // num번째의 친구까지 인사할 수 있다고 할 때 체력 e를 가지고 만들어낼 수 있는 기쁨의 최댓값 구하기
        if(energy[num-1] > e) {
            // num번째 친구와 인사 불가 -> num-1번째 친구 까지의 최댓값 그대로 사용
            dp[num][e] = dp[num - 1][e];
        }
        else{
            // num번째 친구와 인사 가능 -> 인사를 하지 않는 것과 하는 것 중에 최댓값 구하기
            // 인사 하지 않기 : 현재 체력으로 num - 1까지의 사람과 인사를 마쳤을 때의 최댓값
            // 인사 하기 : num번째 친구와 인사할 체력을 제외한 체력을 가지고 num-1번째 친구까지 인사할 수 있는 최댓값 + 현재 친구와 인사할 때의 기쁨
            dp[num][e]= Math.max( dp[num - 1][e], dp[num-1][e-energy[num-1]] + pleasure[num-1]);
        }
    }
}

console.log(dp[N][99]);