// 백준 2231번
#include <iostream>

using namespace std;

// solution 함수로 return값 낼 수 있도록 작성
int solution(int N) {
	// 부르트포스 알고리즘
	// 1부터 N까지 모든 수에 대해서 계산 -> O(nlogn), n의 크기가 제한적
	for (int n = 1; n < N; n++) {
		int sum = n;
		int temp = n;
		while ((int)temp / 10 != 0) {
			sum = sum + temp % 10;
			temp = (int)temp / 10;
		}
		sum += temp;
		// 만약 생성자를 찾았다면 1부터 차례로 시작했으므로 그것이 최소 생성자가 됨
		if (sum == N)
			return n;
	}

	// for 문을 빠져 나왔다는 것은 생성자를 찾지 못한 것
	return 0;
}

int main() {
	int N;
	cin >> N;

	cout << solution(N) << endl;
}