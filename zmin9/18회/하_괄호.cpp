// ���� 9012��
#include <iostream>
#include <vector>

using namespace std;

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
vector<string> solution(vector<string> parenthesis) {
	vector<string> result;
	
	for (int i = 0; i < parenthesis.size(); i++) {
		// ��ȣ���ڿ��� ���̰� Ȧ���� ��� ������ VPS�� �ƴ�
		if (parenthesis[i].length() % 2 != 0) {
			result.push_back("NO");
			continue;
		}

		vector<char> stack;

		int j;
		for ( j = 0; j < parenthesis[i].size(); j++) {
			// '(' �̸� ���ÿ� �ְ� ')' �̸� ������ ���Ҹ� ����
			if (parenthesis[i][j] == '(')
				stack.push_back('(');
			else {
				if(!stack.empty())
					stack.pop_back();
				else {
					// ')'�ε� ������ ����ִ� ��� ¦�� ���� ����
					break;
				}
			}
		}

		if (j == parenthesis[i].length() && stack.empty())
			result.push_back("YES");
		else	// ��� ���Ҹ� �˻��������� ������ ������� �ʴ� ��쵵 ¦�� ���� ����
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