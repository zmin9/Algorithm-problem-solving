// 백준 2231번
#include <iostream>
using namespace std;

/*
* <브루트포스 알고리즘>
* 가능한 모든 경우의 수를 탐색
* -> 시간초과가 나는 경우도 많아 적절한 경우들을 찾아주는 과정 필요
* 
* 이 문제에선 n의 범위가 1000000 미만이라 연산횟수가 그렇게 많지 않아 전체 경우를 그냥 탐색하는 것이 가능
* 
* 시간복잡도: nlogn
*/

int solution(int n) {
	int answer = 0;

	for (int i = 1; i < n; i++) {
		// 현재 수를 계산하기 위해 임시적으로 저장해둠
		int temp = i;
		// 현재 수를 생성자로 가지는 수를 계산
		int sum = i;	// 현재 수
		while (temp != 0) {
			sum += temp % 10;	// 각 자리수; 가장 작은 자리부터 더해나감
			temp /= 10;
		}
		if (sum == n) {		// 만약 같다면 i는 n의 가장 작은 생성자가 됨
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