// 백준 2011번
// bottom-up
#include <iostream>
#include <vector>

using namespace std;

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

	vector<long long> dp(code.size() + 1, 0);

	dp[0] = 1;
	dp[1] = 1;

	// 이전 값들을 이용하여 현재 단계의 값을 계산
	// 이전 code값들에 따라 현재 code가 해석 될 수 있는 case를 나눔
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