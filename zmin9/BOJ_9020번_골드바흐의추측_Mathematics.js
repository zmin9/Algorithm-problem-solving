const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
input.shift();

const primes = [];

{
  // 에라토스테네스의 체를 이용하여 10000까지의 소수를 구함
  const isPrime = Array(10001).fill(true);

  for (let i = 2; i <= 10000; i++) {
    if (!isPrime[i]) continue;
    primes.push(i);
    for (let j = i * 2; j <= 10000; j += i) {
      isPrime[j] = false;
    }
  }
}

// 입력값을 돌며 검사
while (input.length > 0) {
  const N = input.shift() * 1;
  let result;

  // primes에 저장된 10000까지의 소수에 대해 연산
  for (let i = 0; i < primes.length; i++) {
    // 만약 해당 소수가 N의 절반 이상이 되면 종료 -> 작은 수부터 출력해야하고 가장 작게 차이나는 값으로 출력해야 하기 때문
    if (primes[i] > N / 2) break;

    // N-현재소수 가 primes에 포함되어있으면(소수이면) result에 값 저장
    if (primes.includes(N - primes[i])) result = primes[i];
  }
  console.log(result + ' ' + (N - result));
}