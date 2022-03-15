// ���� 2579��
#include <iostream>
#include <vector>
using namespace std;

/*
* 
* <���̳��� ���α׷���>
* ������ ����ص� ���� �����صξ��ٰ� �ʿ��Ҷ� �ٽ� ������� �ʰ� �ٽ� ����� -> Memoization
* ����� ����
* �κй��� ���� -> ������� ��ȭ���̿�
* 
* �ð����⵵ : n
*/

int solution(int n, vector<int>score) {
	// �� ����� �ִ� ���ھ ������ ����(dp)
	vector<int> score_sum(n + 1, 0);

	// ù ��° ���
	score_sum[1] = score[1];
	// �� ��° ��� -> �ִ��� �����ϰ� �ǹǷ� �翬�� �� ����� ��� ��� ���� �ִ��� ��
	score_sum[2] = score[1] + score[2];

	// �� ��° ��ܺ��� n��° ��ܱ��� ���� ���
	for (int i = 3; i < n + 1; i++) {
		// 1) i-2 ��ܿ��� �� ĭ �پ� �ö���� ���
		// 2) i-1 ��ܿ��� �� ĭ �پ� �ö���� ���->�� ĭ �������� ������ �ȵǹǷ� ������ ���� ĭ�� i-3 ����̾�� ��
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