const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const [V, _] = input.shift().trim().split(' ').map(Number);
const K = Number(input.shift().trim());

const edges = input.map(i=>i.trim().split(' ').map(Number));

const cost = Array(V+1).fill(Infinity);
cost[K] = 0;

while(edges.length !== 0) {
    const l = edges.length;
    for (let i = 0; i < l; i++) {
        const temp = edges.shift();
        if (cost[temp[1]] > cost[temp[0]] + temp[2]) {
            cost[temp[1]] = cost[temp[0]] + temp[2];
            edges.push(temp);
        }
    }
}

for(let i = 1; i <= V; i++){
    cost[i]===Infinity? console.log('INF') : console.log(cost[i]);
}