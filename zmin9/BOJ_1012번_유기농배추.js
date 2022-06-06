const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const dx = [0, 1, 0, -1];
const dy = [1, 0, -1, 0];
const T = Number(input.shift());

const DFS = (i, j, graph, M, N) => {
  graph[i][j] = 0;

  for (let n = 0; n < 4; n++) {
    if (i + dx[n] < M && i + dx[n] >= 0 && j + dy[n] < N && j + dy[n] >= 0 && graph[i + dx[n]][j + dy[n]] == 1) {
      DFS(i + dx[n], j + dy[n], graph, M, N);
    }
  }
};

for (let test = 0; test < T; test++) {

  const [M, N, K] = input.shift().trim().split(' ').map(Number);

  const graph = Array.from(Array(M), () => Array(N).fill(0));

  for (let k = 0; k < K; k++) {
    const [x, y] = input.shift().trim().split(' ').map(Number);
    graph[x][y] = 1;
  }

  let result = 0;

  for (let i = 0; i < M; i++) {
    for (let j = 0; j < N; j++) {
      if (graph[i][j] === 1) {
        result++;
        DFS(i, j, graph, M, N);
      }
    }
  }

  console.log(result);
}