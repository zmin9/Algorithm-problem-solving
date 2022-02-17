// ���� 2231��
#include <iostream>

using namespace std;

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
int solution(int N) {
	// �θ�Ʈ���� �˰���
	// 1���� N���� ��� ���� ���ؼ� ��� -> O(nlogn), n�� ũ�Ⱑ ������
	for (int n = 1; n < N; n++) {
		int sum = n;
		int temp = n;
		while ((int)temp / 10 != 0) {
			sum = sum + temp % 10;
			temp = (int)temp / 10;
		}
		sum += temp;
		// ���� �����ڸ� ã�Ҵٸ� 1���� ���ʷ� ���������Ƿ� �װ��� �ּ� �����ڰ� ��
		if (sum == N)
			return n;
	}

	// for ���� ���� ���Դٴ� ���� �����ڸ� ã�� ���� ��
	return 0;
}

int main() {
	int N;
	cin >> N;

	cout << solution(N) << endl;
}