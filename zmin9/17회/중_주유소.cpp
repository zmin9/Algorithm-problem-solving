// 백준 13305번
#include <iostream>

using namespace std;

long long solution(int N, int dist[], int price[]) {
	long long answer = 0;
	long long min_price = price[0];

	// 각 정점의 주유소의 가격을 비교해가며 최소 가격으로 주유하도록 함
	for (int i = 0; i < N - 1; i++)
	{
		if (min_price > price[i])
			min_price = price[i];
		answer += min_price * dist[i];
	}
	return answer;
}

int main() {
	int N;
	int dist[100000] = { 0 };
	int price[100000] = { 0 };
	int i;
	

	cin >> N;

	for (i = 0; i < N - 1; i++)
		cin >> dist[i];

	for (i = 0; i < N; i++)
		cin >> price[i];
	
	cout << solution(N, dist, price) << endl;
}