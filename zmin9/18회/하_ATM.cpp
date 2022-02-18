// 백준 11399번
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& v,int left,int right) {
	// 만약 정렬해야하는 배열(벡터)의 길이가 1 이하일 경우 별다른 연산 없이 종료
	if ( left >= right )
		return;

	// index 값
	int pivot = left;
	int low = left + 1;
	int high = right;

	while (low < high)
	{
		// v[pivot] 을 기준으로 양쪽에서 가운데로 모여들며 대소관계를 위반하는 원소의 인덱스를 찾음
		while (high >= left && v[high] > v[pivot])
			high--;
		while (low <= right && v[low] <= v[pivot])
			low++;

		// low, high가 교차되지 않았을 경우에만 찾은 두 원소를 교환 -> 대소관계 맞춰줌
		if (low < high)
		{
			int temp = v[high];
			v[high] = v[low];
			v[low] = temp;
		}
	}

	// v[pivot]의 왼쪽에는 작은 값, 오른쪽에는 큰 값만 위치하는 자리로 이동시킴
	int temp = v[pivot];
	v[pivot] = v[high];
	v[high] = temp;

	// 양쪽의 배열들에 대해 위의 과정 반복
	quickSort(v, left, high - 1);
	quickSort(v, high + 1, right);
}

// solution 함수로 return값 낼 수 있도록 작성
int solution(vector<int>& withdrawal) {
	int result = 0;
	/* 1) c++ <algorithm> 에서 사용하는 sort(퀵정렬)함수 사용하기 */
	sort(withdrawal.begin(),withdrawal.end());
	

	/* 2) 퀵 정렬알고리즘 직접 구현하기 
	quickSort(withdrawal, 0, withdrawal.size() - 1);
	*/

	for (int i = 1; i <= withdrawal.size(); i++) {
		result += withdrawal[withdrawal.size() - i] * i;
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	vector<int> withdrawal(N);

	for (int i = 0; i < N; i++) {
		cin >> withdrawal[i];
	}

	cout << solution(withdrawal) << endl;
}