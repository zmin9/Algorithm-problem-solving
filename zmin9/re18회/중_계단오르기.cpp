// 백준 2579번
#include <iostream>
#include <vector>
using namespace std;

/*
* 
* <다이나믹 프로그래밍>
* 이전에 계산해둔 값을 저장해두었다가 필요할때 다시 계산하지 않고 다시 사용함 -> Memoization
* 재귀적 성질
* 부분문제 정의 -> 재귀적인 점화식이용
* 
* 시간복잡도 : n
*/

int solution(int n, vector<int>score) {
	// 각 계단의 최대 스코어를 저장할 벡터(dp)
	vector<int> score_sum(n + 1, 0);

	// 첫 번째 계단
	score_sum[1] = score[1];
	// 두 번째 계단 -> 최댓값을 저장하게 되므로 당연히 두 계단을 모두 밟는 것이 최댓값이 됨
	score_sum[2] = score[1] + score[2];

	// 세 번째 계단부터 n번째 계단까지 전부 계산
	for (int i = 3; i < n + 1; i++) {
		// 1) i-2 계단에서 두 칸 뛰어 올라오는 경우
		// 2) i-1 계단에서 한 칸 뛰어 올라오는 경우->세 칸 연속으로 밟으면 안되므로 이전에 밟은 칸은 i-3 계단이어야 함
		score_sum[i] = max(score_sum[i - 2], score_sum[i - 3] + score[i - 1]) + score[i];
	}

	return score_sum[n];
}

int main() {
	int n;
	cin >> n;
	
	vector<int> score(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}

	cout << solution(n, score) << endl;
}