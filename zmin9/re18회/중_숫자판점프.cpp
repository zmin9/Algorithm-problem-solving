// ���� 2210��
#include <iostream>
#include <vector>

using namespace std;

/*
* <���Ʈ���� �˰���>
* grid�� ũ�Ⱑ �������ֱ� ������ �ð����⵵�� ����� �ǰ�
* ���� grid��ü�� �׷��� ũ�� �ʾ� ����� ��� ��츦 Ž���� �� �ִ�.
* 
* <DFS>
* ���� �켱 Ž��
* ������ �̵��ذ��� ���� ������ �ϳ��� ���� ����Ͽ� �����ؾ� �ϱ� ������
* ���� �켱 Ž�� �˰����� �����ϴٰ� �Ǵ�
*/


// ������ ���� 000000 ~ 999999, �ش� ���� ���� �� �ִ��� ��Ÿ��
bool existed[1000000];

// �� �� �� ��

void dfs(int row, int col, int value, int depth, vector<vector<int>> grid) {
	// ĭ�� �ִ� ���ڸ� ����� ���� �� -> ���� ���� �����ʿ� ���ڸ� ����
	value = value * 10 + grid[row][col];

	// ���� ���� depth�� 6�̶�� == ���ڰ� 6�ڸ� ���
	// �ش� ���� �����ϴ� ���� ǥ���ϰ� return;
	if (depth == 6) {
		if (!existed[value])
			existed[value] = true;
		return;
	}

	// depth�� �����ϴٸ� �� ���⿡ ���� �ε����� grid�� ����� �ʴ��� �Ǵ��ϰ�
	// �ش� �����¿� ĭ�鿡�� �ٽ� dfs
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

	// ��������� ������ dfs�� �� ǥ���ߴٸ� existed �迭�� Ž���Ͽ� ������ ��
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