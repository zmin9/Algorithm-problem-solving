// 입력 처리
const fs = require('fs');

//const [N, ...input] = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const [N, ...input] = fs.readFileSync('./input.txt').toString().trim().split('\n');
const picture = input.map(pixel=>pixel.trim().split(''));

// 상하좌우로 움직이기 위한 이동량
const di = [ 0, -1, 0, 1];
const dj = [ 1, 0, -1, 0];

const result = [0 ,0];
let rg = false;

const DFS = (i, j, color) => {
    if(picture[i][j] !== color){
        if((color === 'R' && picture[i][j] === 2) || (color === 'G' && picture[i][j] === 1)) {
            rg = true;
        }
        return;
    }

    if (color === 'R') picture[i][j] = 1;
    else if (color === 'G') picture[i][j] = 2;
    else picture[i][j] = 0;

    for( let n = 0; n < 4; n++){
        const nextI = i + di[n];
        const nextJ = j + dj[n];
        if(nextI >= 0 && nextI < N && nextJ >= 0 && nextJ < N) {
            DFS(nextI, nextJ, color);
        }
    }
};

for(let i=0; i<N; i++){
    for(let j=0; j<N; j++){
        if(!Number.isInteger(picture[i][j])){
            rg = false;
            DFS(i, j, picture[i][j]);
            result[0]++;
            if(picture[i][j] < 'C' || !rg) result[1]++;
        }
    }
}

console.log(picture);
console.log(result.join(' '));