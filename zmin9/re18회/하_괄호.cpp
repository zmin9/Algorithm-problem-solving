// 백준 9012번
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
* <자료구조:stack>
* 을 이용하는 대표적인 문제, LIFO 성질을 가지고 있음
* 
* 시간복잡도 : 문자열의 길이에 따라 조금씩 다르겠지만.. Tn?
*/

vector<string> solution(int T, vector<string> parenthesis) {
	vector<string> answer;
	// 각 괄호문자열에 대해 검사함
	for (int i = 0; i < T; i++) {
		stack<int> stack;
		string input = parenthesis[i];
		int n;
		// 해당 괄호문자열에 대해 각 괄호들을 탐색
		for (n = 0; n < input.size(); n++) {
			// 열린 괄호라면 스택에 넣음
			if (input[n] == '(')
				stack.push(1);
			else {
				// 닫힌 괄호인데 저장된 열린괄호가 없는 경우 VPS가 아님
				if (stack.empty()) {
					break;
				}
				else {
					stack.pop();
				}
			}
		}

		// 모든 괄호를 탐색했고 남은 열린괄호가 없는 경우 -> VPS
		if (stack.empty() && n == input.size())
			answer.push_back("YES");
		else // 남은 열린 괄호가 있거나, 열린괄호는 남지 않았지만 마지막까지 탐색하지 않은경우(이미 다 닫혀있는데 또 닫힌괄호가 나온 경우)
			answer.push_back("NO");
	}

	return answer;
}

int main() {
	int T;
	cin >> T;

	vector<string> parenthesis(T);

	for (int i = 0; i < T; i++)
		cin >> parenthesis[i];

	vector<string> result = solution(T, parenthesis);

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}
}