// 백준 13458번
#include <iostream>
#define MAX 1000001

using namespace std;

// 전역변수로 선언하지 않으면 미리할당 문제 때문에 stack overflow 발생할 수 있음
int A[MAX] = { 0 };

long long solution(int N, int A[], int B, int C) {
	long long result = 0;

	for (int i = 0; i < N; i++) {
		// 총감독관
		A[i] -= B;
		result++;
		// 남았다면 부감독관
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