/*
 백준 1535 안녕
 
 입력 받을 수
 1. 사람의 수 N (<= 20)
 2. 각 사람 별 잃는 체력 (0 or <= 100)
 3. 각 사람 별 잃는 기쁨 (")
 
 i(1~N)번 사람에게 인사하면:
 체력 = 세준체력(기본값 100) - L[i]
 기쁨 = 세준기쁨(기본값 0) + J[i]
 
 체력이 100에서 0 또는 음수가 될 때까지 얻을 수 있는 최대 기쁨?
 */

/*
 ? : 자료형 선언 시 비어있을 수도 있음을 표시.
  ㄴ ex) var n : String = nil (x), var n : String? = nil (o)
 
 optional : 런타임 시 발생할 수 있는 문제를 컴파일 시 알려줌. (잠재적인 에러 찾아줌)
  ㄴ 1. 값이 있는지 없는지 확인 2. 값이 있으면, 즉 nil이 아니라면 unwrapping
 
 ! : nil 확인 안 하고 강제 unwrapping
 
 readLine() : 어떤 입력을 받던지 간에 모두 문자열로 반환
  ㄴ 값 입력 확실 -> !, 불확실: optional 바인딩
 
 map : 축약된 for문 느낌..
  ㄴ compactMap : 컨테이너로 쌓여져 있으면 그 안의 값들로 작업 수행 후 다시 포장해 반환
 */

import Foundation

let N = Int(readLine()!)!

let L = [0] + readLine()!.split(separator: " ").map{Int(String($0))!}
let J = [0] + readLine()!.split(separator: " ").map{Int(String($0))!}

var strength = Array(repeating: Array(repeating: 0, count: N+1), count: 100)

for i in 1...N {
    let (l, j) = (L[i], J[i])
    for k in 0...99 {
        if l <= k {
            strength[k][i] = max(strength[k][i-1], strength[k-l][i-1]+j)
        }
        else {
            strength[k][i] = strength[k][i-1]
        }
    }
}
print(strength[99][N])
