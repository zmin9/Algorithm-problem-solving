// 백준 1074번
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int n, int r, int c) {
	long long length = pow(2, n);
	long long result = 0;

	// 각 반복마다 r행 c열의 위치를 포함하는 사각형 이전의 총 사각형 개수를 더한 뒤
	// 다시 포함하는 사각형을 4등분하여 어디 위치하는지 확인한다
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