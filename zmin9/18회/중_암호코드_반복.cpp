// ���� 2011��
// bottom-up
#include <iostream>
#include <vector>

using namespace std;

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
int solution(vector<int> code) {
	// ��ȣ�� �ƽ�Ű�ڵ�� �ؼ��� �� ����
	// ù ���ں��� 0�� ��� �߸��� ��ȣ
	if (code[0] == 0)
		return 0;
	// 0�� �������� ���������� �߸��� ��ȣ
	for (int i = 2; i < code.size(); i++)
		if (code[i - 1] == 0 && code[i] == 0)
			return 0;

	vector<long long> dp(code.size() + 1, 0);

	dp[0] = 1;
	dp[1] = 1;

	// ���� ������ �̿��Ͽ� ���� �ܰ��� ���� ���
	// ���� code���鿡 ���� ���� code�� �ؼ� �� �� �ִ� case�� ����
	for (int i = 2; i <= code.size(); i++) {
		int temp = i - 1;
		if (code[temp] == 0 && code[temp - 1] > 2) return 0;

		if (code[temp] != 0) dp[i] += dp[i - 1];
		if (code[temp - 1] == 1 || (code[temp - 1] == 2 && code[temp] < 7)) dp[i] += dp[i - 2];

		dp[i] %= 1000000;
	}

	return int(dp[code.size()]);
}

int main() {
	while (true) {
		vector<int> code(0);
		string code_str;
		cin >> code_str;

		for (int i = 0; i < code_str.size(); i++)
			code.push_back(code_str[i] - '0');

		cout << solution(code) << endl;
	}
}