// ���� 2210��
#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, int j, int depth, int value, vector<vector<int>>& grid, vector<bool>& isMade) {
	value = value * 10 + grid[i][j];
	if (depth == 6)
	{
		if (!isMade[value])
			isMade[value] = true;
		return;
	}

	// �ش� ��ġ���� �����¿쿡 ���� Ž��
	if (i - 1 >= 0) dfs(i - 1, j, depth + 1, value, grid, isMade);
	if (j - 1 >= 0) dfs(i, j - 1, depth + 1, value, grid, isMade);
	if (i + 1 < grid.size()) dfs(i + 1, j, depth + 1, value, grid, isMade);
	if (j + 1 < grid[0].size()) dfs(i, j + 1, depth + 1, value, grid, isMade);
	return;
}

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
int solution(vector<vector<int>> grid) {
	// ���� �ʱ�ȭ
	vector<bool> isMade(1000000, false);

	// ���� �켱 Ž������ ��� ��� Ž���ϱ�
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(i, j, 1, 0, grid, isMade);

	int result = 0;

	for (int i = 0; i < 1000000; i++)
		if (isMade[i])
			result++;

	return result;
}

int main() {
	vector<vector<int>> grid(5, vector<int>(5));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> grid[i][j];

	cout << solution(grid);
}