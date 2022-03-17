// 백준 2011번
#include <iostream>
#include <vector>

using namespace std;

/*
* <다이나믹 프로그래밍>
*/

int solution(string s, int n) {
	// 시작부터 0이 오면 바로 return
	if (s[0] == '0')
		return 0;

	// 헷갈리지 않아야 하는게 s의 첫번째 글자(인덱스 0)의 가능한 수가 pwd의 인덱스 1에 저장
	vector<int> pwd(n + 1, 0);

	pwd[0] = 1;
	pwd[1] = 1;

	// 모든 글자들에 대해 검사
	for (int i = 1; i < n; i++) {
		long long temp = 0;
		// 만약 현재 글자가 0이라면
		if (s[i] == '0') {
			// 이전 글자가 0이나 3이상이면 잘못된 암호코드이므로 return
			if (s[i - 1] == '0' || s[i - 1] > '2')
				return 0;
			// 1 또는 2인 경우 10 20 으로 해석할 수 있으므로 두자리수 가능
			temp += pwd[i-1];
		}
		else {
			// 현재 글자가 0이 아니고 이전 글자를 봤을 때 11~26안에 포함된다면 두자리수 가능
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
				temp += pwd[i - 1];
			// 0 이 아닌 수는 무조건 혼자 존재할 수 있으므로
			temp += pwd[i];
		}
		// pwd에 temp 나머지값을 저장해준다
		// 이후 이 값이 계산에 쓰이더라도 결과적으로는 계속 1000000의 나머지만 구하게 될 것이므로 값에는 영향이 없다
		pwd[i + 1] = temp % 1000000;
	}

	return (pwd[n] % 1000000);
}

int main() {
	string s;
	cin >> s;
	int answer = solution(s, s.length());
	cout << answer;
	return 0;
}