const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = Number(input.shift());

// 주어진 테스트 케이스만큼 반복
for(let i = 0; i < N; i++){
    const M = Number(input.shift());
    // 옷 정보를 저장할 빈 객체 선언
    const clothes = {};
    for(let j = 0; j < M; j++){
        // 사실 이름이 겹치는 옷은 없다고 했기 때문에 cloth[0]의 값은 중요하지 않음
        const cloth = input.shift().trim().split(' ');
        // 옷의 종류가 clothes객체의 프로퍼티 키 값으로 존재하면 해당 프로퍼티 값을 하나 증가시켜주고
        // 아니면 1로 넣어줌
        if(clothes.hasOwnProperty(cloth[1])) clothes[cloth[1]]++;
        else clothes[cloth[1]] = 1;
    }
    let result = 1;
    // 각 옷 종류에 대해 선택할 수 있는 경우의 수는 1(안입기) + 옷 갯수
    for (let c in clothes) {
        result *= (clothes[c] + 1);
    }

    // 옷을 전부 안입게 되는 경우를 하나 뺌
    console.log(result - 1);
}