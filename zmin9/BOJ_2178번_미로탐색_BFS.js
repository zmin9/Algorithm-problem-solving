// 입력 처리
const fs = require('fs');

//const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [N,M] = input.shift().trim().split(' ').map(Number);
const maze = input.map((num)=>num.trim().split('').map(Number));

// 상하좌우로 움직이기 위한 이동량
const di = [ 0, -1, 0, 1];
const dj = [ 1, 0, -1, 0];

// 탐색할 위치를 넣을 queue, 현재 위치에 대해 상하좌우의 위치값을 queue 뒤에 넣고 앞에서부터 탐색
const queue = [{ i:0, j:0 }];

while (queue.length>0){

    const cur = queue.shift();

    for( let n = 0; n < 4; n++){
        const nextI = cur.i + di[n];
        const nextJ = cur.j + dj[n];
        // 다음 이동할 칸 중에 미로를 벗어나지 않고 값이 1인 경우(아직 탐색하지 않고 이동가능한 경우)만 queue에 넣음
        if(nextI >= 0 && nextI < N && nextJ >= 0 && nextJ < M && maze[nextI][nextJ] === 1){
            maze[nextI][nextJ] = maze[cur.i][cur.j] + 1;
            queue.push({i: nextI, j:nextJ});
        }
    }
}

console.log(maze[N-1][M-1]);