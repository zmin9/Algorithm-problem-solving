const fs = require('fs');

const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [N, M] = input.shift().trim().split(' ').map(Number);

// 입력된 타일 중 다른 위치의 타일을 표시할 diff 배열
const diff = Array.from(Array(N), () => Array(M).fill(0));

// 3x3 단위로 행렬을 뒤집음
// 기준점을 왼쪽 위로 잡은 것은 diff를 왼쪽 위에서부터 탐색해가면 이미 뒤집은 항목에 대해서는 다시 뒤집지 않게 됨
const reverse3x3 = (row, col) => {
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            diff[row + i][col + j] = (diff[row + i][col + j] === 1 ? 0 : 1);
        }
    }
};

// diff 배열에 다른 타일 입력
for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
        if (input[i].at(j) !== input[i + N].at(j)) diff[i][j] = 1;
    }
}

let result = 0;

// diff 를 돌며 다른 값(1) 뒤집어줌
for (let i = 0; i < N - 2; i++) {
    for (let j = 0; j < M - 2; j++) {
        if (diff[i][j] === 1) {
            result++;
            reverse3x3(i, j);
        }
    }
}

// 하나라도 1이 남아있다면, 바꿀 수 없는 행렬
diff.forEach(row => {
    if (row.includes(1)) result = -1;
});

console.log(result);