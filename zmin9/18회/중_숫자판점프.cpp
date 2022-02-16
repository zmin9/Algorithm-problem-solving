// 백준 2210번
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

	// 해당 위치에서 상하좌우에 대해 탐색
	if (i - 1 >= 0) dfs(i - 1, j, depth + 1, value, grid, isMade);
	if (j - 1 >= 0) dfs(i, j - 1, depth + 1, value, grid, isMade);
	if (i + 1 < grid.size()) dfs(i + 1, j, depth + 1, value, grid, isMade);
	if (j + 1 < grid[0].size()) dfs(i, j + 1, depth + 1, value, grid, isMade);
	return;
}

// solution 함수로 return값 낼 수 있도록 작성
int solution(vector<vector<int>> grid) {
	// 벡터 초기화
	vector<bool> isMade(1000000, false);

	// 깊이 우선 탐색으로 모든 경우 탐색하기
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