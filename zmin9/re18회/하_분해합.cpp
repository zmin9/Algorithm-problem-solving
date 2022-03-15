// ���� 2231��
#include <iostream>
using namespace std;

/*
* <���Ʈ���� �˰���>
* ������ ��� ����� ���� Ž��
* -> �ð��ʰ��� ���� ��쵵 ���� ������ ������ ã���ִ� ���� �ʿ�
* 
* �� �������� n�� ������ 1000000 �̸��̶� ����Ƚ���� �׷��� ���� �ʾ� ��ü ��츦 �׳� Ž���ϴ� ���� ����
* 
* �ð����⵵: nlogn
*/

int solution(int n) {
	int answer = 0;

	for (int i = 1; i < n; i++) {
		// ���� ���� ����ϱ� ���� �ӽ������� �����ص�
		int temp = i;
		// ���� ���� �����ڷ� ������ ���� ���
		int sum = i;	// ���� ��
		while (temp != 0) {
			sum += temp % 10;	// �� �ڸ���; ���� ���� �ڸ����� ���س���
			temp /= 10;
		}
		if (sum == n) {		// ���� ���ٸ� i�� n�� ���� ���� �����ڰ� ��
			answer = i;
			break;
		}
	}

	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int answer = solution(n);
	cout << answer;

	return 0;
}