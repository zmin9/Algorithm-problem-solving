// ���� 11399��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& v,int left,int right) {
	// ���� �����ؾ��ϴ� �迭(����)�� ���̰� 1 ������ ��� ���ٸ� ���� ���� ����
	if ( left >= right )
		return;

	// index ��
	int pivot = left;
	int low = left + 1;
	int high = right;

	while (low < high)
	{
		// v[pivot] �� �������� ���ʿ��� ����� �𿩵�� ��Ұ��踦 �����ϴ� ������ �ε����� ã��
		while (high >= left && v[high] > v[pivot])
			high--;
		while (low <= right && v[low] <= v[pivot])
			low++;

		// low, high�� �������� �ʾ��� ��쿡�� ã�� �� ���Ҹ� ��ȯ -> ��Ұ��� ������
		if (low < high)
		{
			int temp = v[high];
			v[high] = v[low];
			v[low] = temp;
		}
	}

	// v[pivot]�� ���ʿ��� ���� ��, �����ʿ��� ū ���� ��ġ�ϴ� �ڸ��� �̵���Ŵ
	int temp = v[pivot];
	v[pivot] = v[high];
	v[high] = temp;

	// ������ �迭�鿡 ���� ���� ���� �ݺ�
	quickSort(v, left, high - 1);
	quickSort(v, high + 1, right);
}

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
int solution(vector<int>& withdrawal) {
	int result = 0;
	/* 1) c++ <algorithm> ���� ����ϴ� sort(������)�Լ� ����ϱ� */
	sort(withdrawal.begin(),withdrawal.end());
	

	/* 2) �� ���ľ˰��� ���� �����ϱ� 
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