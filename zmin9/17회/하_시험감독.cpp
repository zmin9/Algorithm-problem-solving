// ���� 13458��
#include <iostream>
#define MAX 1000001

using namespace std;

// ���������� �������� ������ �̸��Ҵ� ���� ������ stack overflow �߻��� �� ����
int A[MAX] = { 0 };

long long solution(int N, int A[], int B, int C) {
	long long result = 0;

	for (int i = 0; i < N; i++) {
		// �Ѱ�����
		A[i] -= B;
		result++;
		// ���Ҵٸ� �ΰ�����
		if (A[i] > 0) {
			result += A[i] / C;
			if (A[i] % C != 0)
				result++;
		}
	}

	return result;
}

int main() {
	
	int N = 0, B = 0, C = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;

	cout << solution(N, A, B, C) << endl;
	return 0;
}