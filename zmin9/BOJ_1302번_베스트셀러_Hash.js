const fs = require('fs');
// const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = Number(input.shift());

const books = {};

// 만약 이전에 나왔던 책 제목이라면 판매량+1, 아니라면 새로 추가
for(let i = 0; i < N; i++){
  if(books.hasOwnProperty(input[i].trim())) books[input[i].trim()]++;
  else books[input[i].trim()] = 1;
}

// 책 제목들만 불러와서 사전순으로 정렬
const bookTitle = Object.keys(books).sort();
let result = bookTitle[bookTitle.length - 1];

// 판매된 책 이름을 사전 뒤쪽에서부터 순회하며 판매량이 많거나 같으면 베스트셀러 변경
for(let i = bookTitle.length - 2; i >= 0; i--){
  if(books[result] <= books[bookTitle[i]]) result = bookTitle[i];
}

console.log(result);