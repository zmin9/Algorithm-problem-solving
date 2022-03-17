// ���� 2011��
#include <iostream>
#include <vector>

using namespace std;

/*
* <���̳��� ���α׷���>
*/

int solution(string s, int n) {
	// ���ۺ��� 0�� ���� �ٷ� return
	if (s[0] == '0')
		return 0;

	// �򰥸��� �ʾƾ� �ϴ°� s�� ù��° ����(�ε��� 0)�� ������ ���� pwd�� �ε��� 1�� ����
	vector<int> pwd(n + 1, 0);

	pwd[0] = 1;
	pwd[1] = 1;

	// ��� ���ڵ鿡 ���� �˻�
	for (int i = 1; i < n; i++) {
		long long temp = 0;
		// ���� ���� ���ڰ� 0�̶��
		if (s[i] == '0') {
			// ���� ���ڰ� 0�̳� 3�̻��̸� �߸��� ��ȣ�ڵ��̹Ƿ� return
			if (s[i - 1] == '0' || s[i - 1] > '2')
				return 0;
			// 1 �Ǵ� 2�� ��� 10 20 ���� �ؼ��� �� �����Ƿ� ���ڸ��� ����
			temp += pwd[i-1];
		}
		else {
			// ���� ���ڰ� 0�� �ƴϰ� ���� ���ڸ� ���� �� 11~26�ȿ� ���Եȴٸ� ���ڸ��� ����
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
				temp += pwd[i - 1];
			// 0 �� �ƴ� ���� ������ ȥ�� ������ �� �����Ƿ�
			temp += pwd[i];
		}
		// pwd�� temp ���������� �������ش�
		// ���� �� ���� ��꿡 ���̴��� ��������δ� ��� 1000000�� �������� ���ϰ� �� ���̹Ƿ� ������ ������ ����
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