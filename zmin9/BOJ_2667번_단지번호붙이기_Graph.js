const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const N = input.shift() * 1;

for (let i = 0; i < N; i++) {
  input[i] = input[i].trim().split('').map(Number);
}

// 결과 값을 저장할 배열
// 인덱스 0은 단지의 개수, 그 이후의 값들은 각 단지의 집 수
const result = [0];


// 같은 단지인 집을 찾기 위한 깊이 우선 탐색 -> 탐색 된 집은 0으로 바꿈
const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];
const DFS = (row, col) => {
  input[row][col] = 0;
  result[result[0]]++;
  for (let i = 0; i < 4; i++) {
    if (row + dr[i] >= 0 && row + dr[i] < N && col + dc[i] >= 0 && col + dc[i] < N && input[row + dr[i]][col + dc[i]] === 1)
      DFS(row + dr[i], col + dc[i]);
  }
};

// 입력받은 값을 순회하며 단지를 탐색
for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (input[i][j] === 1) {
      result[0]++;
      result[result[0]] = 0;
      DFS(i, j);
    }
  }
}

// 오름차순 정렬
result.splice(1, result.length, ...result.slice(1, result.length).sort(function (a, b) {
  return a - b
}));
console.log(result.join('\n'));