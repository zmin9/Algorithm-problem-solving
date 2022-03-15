// ���� 9012��
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
* <�ڷᱸ��:stack>
* �� �̿��ϴ� ��ǥ���� ����, LIFO ������ ������ ����
* 
* �ð����⵵ : ���ڿ��� ���̿� ���� ���ݾ� �ٸ�������.. Tn?
*/

vector<string> solution(int T, vector<string> parenthesis) {
	vector<string> answer;
	// �� ��ȣ���ڿ��� ���� �˻���
	for (int i = 0; i < T; i++) {
		stack<int> stack;
		string input = parenthesis[i];
		int n;
		// �ش� ��ȣ���ڿ��� ���� �� ��ȣ���� Ž��
		for (n = 0; n < input.size(); n++) {
			// ���� ��ȣ��� ���ÿ� ����
			if (input[n] == '(')
				stack.push(1);
			else {
				// ���� ��ȣ�ε� ����� ������ȣ�� ���� ��� VPS�� �ƴ�
				if (stack.empty()) {
					break;
				}
				else {
					stack.pop();
				}
			}
		}

		// ��� ��ȣ�� Ž���߰� ���� ������ȣ�� ���� ��� -> VPS
		if (stack.empty() && n == input.size())
			answer.push_back("YES");
		else // ���� ���� ��ȣ�� �ְų�, ������ȣ�� ���� �ʾ����� ���������� Ž������ �������(�̹� �� �����ִµ� �� ������ȣ�� ���� ���)
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