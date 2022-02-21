// ���� 2011��
// top-down
// ä���� �Ǵµ� bottom up���� �޸𸮸� ���� ���� �����ɸ�
#include <iostream>
#include <vector>

using namespace std;

long decode(int n, vector<int> code, vector<long long>& dp) {
	if (dp[n] == -1) {
		// ���� �ε������� �ص����� �� ������ ������ �ƽ�Ű�ڵ尡 �� �ڸ��� ���, �� �ڸ��� ��� ����� ����
		long long one_digit = 0, two_digit = 0;
		if (code[n - 1] == 0 && code[n - 2] > 2) return 0;
		if (code[n - 1] != 0)
			one_digit = decode(n - 1, code, dp);
		if (code[n - 2] == 1 || (code[n - 2] == 2 && code[n - 1] < 7))
			two_digit = decode(n - 2, code, dp);

		dp[n] = (one_digit + two_digit) % 1000000;
	}

	return dp[n];
}

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

	vector<long long> dp(code.size() + 1, -1);

	dp[0] = 1;
	dp[1] = 1;

	return int(decode(code.size(), code, dp));
}

int main() {
	vector<int> code(0);
	string code_str;
	cin >> code_str;

	for (int i = 0; i < code_str.size(); i++)
		code.push_back(code_str[i] - '0');

	cout << solution(code) << endl;
}