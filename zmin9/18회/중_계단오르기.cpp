// ���� 2579��

#include <iostream>
#include <vector>

using namespace std;

// ����Լ� ����
int stair(int n, vector<int>& dp, vector<int>& score) {
	/* ������ �ش� ���� ����� ���� �ִ� ��� �ٷ� �ش� ���� ��ȯ�ϰ�
	   �׷��� ���� ��� ����Ͽ� ������ �� ��ȯ�Ѵ� */
	if (dp[n] == -1)
		dp[n] = max(stair(n - 3, dp, score) + score[n - 1], stair(n - 2, dp, score)) + score[n];

	return dp[n];
}

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
int solution(vector<int>& score, int n) {
	// �� ��ܱ����� �ִ��� ������ dp ���� ���� �� �ʱ�ȭ
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