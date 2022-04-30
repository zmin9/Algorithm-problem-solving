// 입력 처리
const fs = require('fs');
//const [N, K] = fs.readFileSync('./dev/stdin').toString().split('\n').map(line=>line.trim().split(' ').map(Number));
const input = fs.readFileSync('./input.txt').toString().split('\n').map(line=>line.trim().split(' ').map(Number));
const [N, K] = input.shift();

// node 방문 여부를 표시할 배열과 각 node와 연결된 edge저장할 배열 선언
const isVisited = new Array(N+1).fill(false);
const edges = Array.from(Array(N+1),()=>new Array());

// 방향이 없기 때문에 edge 양쪽 노드에 모두 추가
for(let i=0; i<K; i++){
    let [u, v] = input[i];
    edges[u].push(v);
    edges[v].push(u);
}

const DFS = (u) => {
    // 방문한 적이 있는 node라면 return
    if (isVisited[u])
        return;
    isVisited[u] = true;

    // 현재 node와 연결된 node에 대해 DFS
    edges[u].forEach( v => BFS(v) );
}

let result = 0;

for(let i=1; i<=N; i++){
    if(!isVisited[i]){
        result++;
        DFS(i);
    }
}

console.log(result);