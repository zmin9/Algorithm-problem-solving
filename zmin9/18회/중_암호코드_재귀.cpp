// 백준 2011번
// top-down
// 채점은 되는데 bottom up보다 메모리를 많이 쓰고 오래걸림
#include <iostream>
#include <vector>

using namespace std;

long decode(int n, vector<int> code, vector<long long>& dp) {
	if (dp[n] == -1) {
		// 현재 인덱스까지 해독했을 때 마지막 문자의 아스키코드가 한 자리인 경우, 두 자리인 경우 나누어서 생각
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

// solution 함수로 return값 낼 수 있도록 작성
int solution(vector<int> code) {
	// 암호를 아스키코드로 해석할 수 있음
	// 첫 숫자부터 0인 경우 잘못된 암호
	if (code[0] == 0)
		return 0;
	// 0이 연속으로 놓여있으면 잘못된 암호
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