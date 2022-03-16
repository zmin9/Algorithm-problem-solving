// 백준 11399번
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* <그리디 알고리즘..?>
* 순간순간마다 가장 최적의 선택을 하여 최종적으로 결과를 내는 알고리즘(다만 최종 결과는 최적해가 아닐 수 있음)
* 여기서는 첫 번째 사람이 인출하는 시간동안 대기해야하는데 그 대기시간이 가장 짧은 경우를 선택하고
* 또 (첫번째사람을제외하고) 두 번째사람이 인출하는 대기시간이 가장 짧은 경우를 경우를 선택하고 ... 
* 이런식으로 구해나가기 때문에 그리디 알고리즘이라고 하는 것 같다
* 
* 시간복잡도 : nlogn(sort에서 퀵정렬을 사용하기 때문)
* 
* <퀵 정렬>
* 첫 번째 값을 pivot으로 잡고 남은 아이들을 양 끝에서부터 검사해오면서 pivot과의 대소관계가 맞지 않는 아이들끼리 교환 -> 교차될 때 까지
* 이후 low 값고 pivot의 위치를 바꾸고 pivot 기준으로 양쪽에 생긴 배열에 대해 다시 검토 -> 재귀적 
*/


int solution(int N, vector<int> withdrawal) {
	int answer = 0;
	// 퀵 정렬 함수, 기본이 오름차순이며 마지막 인자로 greater<자료형>()을 주면 내림차순으로 정렬 가능
	sort(withdrawal.begin(), withdrawal.end());

	// 각 사람들의 대기 시간은 앞 사람들의 돈 인출시간을 전부 더하고 자신의 인출시간까지 더한 값
	// 따라서 인출 시간이 가장 짧은 사람이 앞쪽으로 와야 전체 사람의 대기시간을 줄 일 수 있음
	for (int i = 0; i < N; i++)
		answer += withdrawal[i] * (N - i);
	return answer;
}

int main() {
	int N;
	cin >> N;
	vector<int> withdrawal(N);

	for (int i = 0; i < N; i++) {
		cin >> withdrawal[i];
	}

	cout << solution(N, withdrawal) << endl;
}