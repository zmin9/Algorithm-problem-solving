// ���� 1074��
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int n, int r, int c) {
	long long length = pow(2, n);
	long long result = 0;

	// �� �ݺ����� r�� c���� ��ġ�� �����ϴ� �簢�� ������ �� �簢�� ������ ���� ��
	// �ٽ� �����ϴ� �簢���� 4����Ͽ� ��� ��ġ�ϴ��� Ȯ���Ѵ�
	for (int i = 0; i < n; i++) {
		int index = 0;
		length /= 2;
		if (length <= r && length <= c)
		{
			index = 3;
			r -= length;
			c -= length;
		}
		else if (length <= r && length > c)
		{
			index = 2;
			r -= length;
		}
		else if (length > r && length <= c)
		{
			index = 1;
			c -= length;
		}
		result += (length * length * index);
	}
	return result;
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << solution(n, r, c) << endl;
	return 0;
}