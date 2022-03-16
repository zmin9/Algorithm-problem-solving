// 백준 2210번
#include <iostream>
#include <vector>

using namespace std;

/*
* <브루트포스 알고리즘>
* grid의 크기가 정해져있기 때문에 시간복잡도는 상수가 되고
* 실제 grid자체도 그렇게 크지 않아 충분히 모든 경우를 탐색할 수 있다.
* 
* <DFS>
* 깊이 우선 탐색
* 블럭에서 이동해가며 밟은 값들을 하나의 수로 취급하여 생각해야 하기 때문에
* 깊이 우선 탐색 알고리즘이 적합하다고 판단
*/


// 가능한 값은 000000 ~ 999999, 해당 값을 만들 수 있는지 나타냄
bool existed[1000000];

// 상 하 좌 우

void dfs(int row, int col, int value, int depth, vector<vector<int>> grid) {
	// 칸에 있는 숫자를 밟았을 때의 값 -> 기존 수의 오른쪽에 숫자를 붙임
	value = value * 10 + grid[row][col];

	// 만약 현재 depth가 6이라면 == 숫자가 6자리 라면
	// 해당 수가 존재하는 것을 표시하고 return;
	if (depth == 6) {
		if (!existed[value])
			existed[value] = true;
		return;
	}

	// depth가 부족하다면 각 방향에 대해 인덱스가 grid를 벗어나지 않는지 판단하고
	// 해당 상하좌우 칸들에서 다시 dfs
	if (row + 1 < 5) dfs(row + 1, col, value, depth + 1, grid);
	if (col + 1 < 5) dfs(row, col + 1, value, depth + 1, grid);
	if (row - 1 >= 0) dfs(row - 1, col, value, depth + 1, grid);
	if (col - 1 >= 0) dfs(row, col - 1, value, depth + 1, grid);
}

int solution(vector<vector<int>> grid) {
	int answer = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(i, j, 0, 1, grid);

	// 만들어지는 수들을 dfs로 다 표시했다면 existed 배열을 탐색하여 갯수를 셈
	for (int i = 0; i < 1000000; i++)
		if (existed[i])
			answer++;

	return answer;
}

int main() {
	vector<vector<int>> grid(5, vector<int>(5));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> grid[i][j];

	cout << solution(grid);
}