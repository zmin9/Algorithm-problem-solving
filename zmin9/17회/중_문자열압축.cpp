// 15ȸ E-PPER 5��
#include <iostream>

using namespace std;

string solution(string input) {
	string answer = "";
	// ù ���ڰ� 1�̸� ���� �տ� 1�� �ٿ���
	if (input[0] == '1')
		answer += '1';

	int count = 0;
	char temp;

	// ���� �ε����� ���� �ε����� ���ڸ� ���ؼ� ���� ��� count�� �ʱ�ȭ�ϰ� answer�� ���ĺ� �߰�
	// �ƽ�Ű�ڵ� �̿�
	for (int i = 1; i < input.size(); i++)
	{
		if (input[i - 1] != input[i]) {
			temp = count + 'A';
			answer += temp;
			count = 0;
			continue;
		}
		count++;
	}

	temp = count + 'A';
	answer += temp;

	return answer;
}


int main() {
	string input;
	cin >> input;
	cout << solution(input) << endl;
	return 0;
}