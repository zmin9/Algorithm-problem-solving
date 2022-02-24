// ���� 2580��
// ����ð��� 3�� ���� �� �ɸ�..
#include <iostream>
#include <vector>

using namespace std;

// �� ������ ���� ����, ��, ��, �ڽ�
bool num_state[3][9][10] = { false, };
// �������� ����ִ� ĭ ������ ����
vector<pair<int, int>> blank;

// ��Ʈ��ŷ
// ���Ƿ� �ϳ��� ���ڸ� ���ؼ� �� �����غ��ٰ� �ƴ� ��� �ٽ� �ǵ��ƿͼ� �ٸ� ���ڸ� �����غ��� ���
bool fillSudoku(int index, vector<vector<int>>& sudoku) {
	// index�� blank�� �ε���. blank.size()�� ���ٴ� ���� ���� ä���ٴ� �� -> true ��ȯ
	if (index == blank.size())
		return true;

	for (int num = 1; num <= 9;num++) {
		int i = blank[index].first, j = blank[index].second;
		// ��ĭ�� ������ ��, ��, �ڽ� ���� �������� �ʴ� num�� ���� ��Ʈ��ŷ �ǽ�
		if (!num_state[0][i][num] && !num_state[1][j][num] && !num_state[2][int(i / 3) * 3 + int(j / 3)][num]) {
			
			num_state[0][i][num] = true;
			num_state[1][j][num] = true;
			num_state[2][int(i / 3) * 3 + int(j / 3)][num] = true;

			// ���� ��Ʈ��ŷ ���� �߸��� ���� �˾Ҵٸ� �ٽ� ������� �������� ���� num ����
			if (!fillSudoku(index + 1, sudoku)) {
				num_state[0][i][num] = false;
				num_state[1][j][num] = false;
				num_state[2][int(i / 3) * 3 + int(j / 3)][num] = false;
			}
			else {
				// ������ ���� 18���� true�� ���� ��� ���������� true �߻�
				sudoku[i][j] = num;
				return true;
			}
		}
	}

	// �˸��� num�� ���� ��� false ��ȯ -> �׷� ���� �Է����� �־����� ����
	return false;
}

// solution �Լ��� return�� �� �� �ֵ��� �ۼ�
vector<vector<int>> solution(vector<vector<int>> sudoku) {

	vector<vector<int>> result = sudoku;

	// ��� ĭ ���鼭 ��ĭ�̸� blank���Ϳ� �߰��ϰ� �ƴ� ��� ���¸� true�� �ٲ�
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0)
				blank.push_back(pair<int, int>(i, j));
			else {
				num_state[0][i][sudoku[i][j]] = true;
				num_state[1][j][sudoku[i][j]] = true;
				num_state[2][int(i / 3) * 3 + int(j / 3)][sudoku[i][j]] = true;
			}
		}
	}
			
	fillSudoku(0, result);
	
	return result;
}

int main() {
	vector<vector<int>> sudoku(9, vector<int>(9));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];

	auto result = solution(sudoku);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << result[i][j]<<' ';
		cout << '\n';
	}
}