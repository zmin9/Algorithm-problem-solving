const fs = require('fs');
// ./dev/stdin
const N = Number(fs.readFileSync('./input.txt').toString().trim());
/* 아리스토테네스의 체를 사용하여 소수를 구하는 경우 -> 8자리까지 가면 쓸데없이 낭비되는 수가 많음
const primes = Array(10 ** N).fill(true);

for (let num = 2; num < 10 ** N; num++) {
    if (!primes[num]) continue;
    for (let mul = num * 2; mul < 10 ** N; mul += num) {
        primes[mul] = false;
    }
}

const queue = [2, 3, 5, 7];

while (queue.length !== 0) {
    const prime = queue.shift();
    if (prime > 10 ** (N - 1)) {
        console.log(prime);
        continue;
    }

    for(let n = prime*10+1;n<prime*10+10;n++){
        if(primes[n])
            queue.push(n);
    }
}
 */

// 소수뒤에 숫자를 붙여가며 계속해서 소수 판정
// queue에 찾아낸 소수들을 넣고 입력받은 자리수가 될 때까지 뒤에 수를 붙여서 push
// 빈 상태가 될 때까지 반복
const queue = [2, 3, 5, 7];

while (queue.length !== 0) {
    const prime = queue.shift();
    if (prime > 10 ** (N - 1)) {
        console.log(prime);
        continue;
    }

    // 짝수는 소수일 수 없으므로 제외
    // 결국 뒤에 붙는 수가 1,3,7,9 만 가능하기 때문에 이 값들을 직접적으로 붙이는게 더 가독성 있을 듯
    for (let n = prime * 10 + 1; n < prime * 10 + 10; n+=2) {
        let isPrime = true;
        for(let i = 2; i < Math.sqrt(n); i++)
            if(n % i === 0) {
                isPrime = false;
                break;
            }

        if(isPrime)
            queue.push(n);
    }
}
