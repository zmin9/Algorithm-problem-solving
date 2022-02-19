// 백준 9012번
#include <iostream>
#include <vector>

using namespace std;

// solution 함수로 return값 낼 수 있도록 작성
vector<string> solution(vector<string> parenthesis) {
	vector<string> result;
	
	for (int i = 0; i < parenthesis.size(); i++) {
		// 괄호문자열의 길이가 홀수인 경우 무조건 VPS가 아님
		if (parenthesis[i].length() % 2 != 0) {
			result.push_back("NO");
			continue;
		}

		vector<char> stack;

		int j;
		for ( j = 0; j < parenthesis[i].size(); j++) {
			// '(' 이면 스택에 넣고 ')' 이면 스택의 원소를 삭제
			if (parenthesis[i][j] == '(')
				stack.push_back('(');
			else {
				if(!stack.empty())
					stack.pop_back();
				else {
					// ')'인데 스택이 비어있는 경우 짝이 맞지 않음
					break;
				}
			}
		}

		if (j == parenthesis[i].length() && stack.empty())
			result.push_back("YES");
		else	// 모든 원소를 검사했음에도 스택이 비어있지 않는 경우도 짝이 맞지 않음
			result.push_back("NO");
	}
	return result;
}

int main() {
	int T;
	cin >> T;

	vector<string> parenthesis(T);

	for (int i = 0; i < T; i++)
		cin >> parenthesis[i];

	vector<string> result = solution(parenthesis);

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}
}