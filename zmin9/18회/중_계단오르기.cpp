// 백준 2579번

#include <iostream>
#include <vector>

using namespace std;

// 재귀함수 선언
int stair(int n, vector<int>& dp, vector<int>& score) {
	/* 이전에 해당 값을 계산한 적이 있는 경우 바로 해당 값을 반환하고
	   그렇지 않은 경우 계산하여 저장한 뒤 반환한다 */
	if (dp[n] == -1)
		dp[n] = max(stair(n - 3, dp, score) + score[n - 1], stair(n - 2, dp, score)) + score[n];

	return dp[n];
}

// solution 함수로 return값 낼 수 있도록 작성
int solution(vector<int>& score, int n) {
	// 각 계단까지의 최댓값을 저장할 dp 벡터 선언 및 초기화
	vector<int> dp(301, -1);
	dp[0] = 0;
	dp[1] = score[1];
	dp[2] = score[2] + dp[1];

	return stair(n, dp, score);
}


int main() {
	vector<int> score;

	int n;
	cin >> n;

	score.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}

	cout << solution(score, n) << endl;
}