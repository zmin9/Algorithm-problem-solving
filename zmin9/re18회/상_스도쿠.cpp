// ���� 2580��
#include <iostream>
#include <vector>

using namespace std;
/*
* <��Ʈ��ŷ>
* ���� �������� ���� �� �� ���� ��찡 ������ ���̶�� �����Ͽ� ��� �����ϴٰ� Ʋ�� ��� �ٽ� ���ƿͼ� �ٸ� ��츦 �����ϴ� �˰���
* ���Ʈ���� �˰���� ��������� ���� �ƴ� ��츦 ������ �� ����
*/

// ����ִ� ĭ�� ��ǥ�� ������ ����
vector<pair<int, int>> blank;

// �� ��, ��, �ڽ��� 1-9�� ���ڰ� �ִ��� Ȯ���� �迭(������ ��Ģ�� ��Ÿ�� ��)
bool row[9][10] = { false, };
bool col[9][10] = { false, };
bool box[9][10] = { false, };

bool backtracking(int idx, vector<vector<int>>& answer) {
	// ���� ȣ���� �ε����� blank�� ũ��� ���ٸ� ��� ��ĭ�� ä���ٴ� ��
	if (idx == blank.size())
		return true;

	int r = blank[idx].first, c = blank[idx].second;

	for (int n = 1; n < 10; n++) {
		// 1-9���� ��� Ž���ϸ� �� ��, ��, �ڽ��� ���� ���ڸ� ã�Ƴ�
		if (!row[r][n] && !col[c][n] && !box[3 * (r / 3) + (c / 3)][n]) {
			row[r][n] = true;
			col[c][n] = true;
			box[3 * (r / 3) + (c / 3)][n] = true;
			
			// �ش� ĭ�� n���� ä��� ���� ĭ ä��� �õ�
			// ���� ����ĭ�� �����ϰ� ä�����ٸ� return true
			if (backtracking(idx + 1, answer)) {
				answer[r][c] = n;
				return true;
			}
			else {
				// ���� ���߿� �߸��� ���̾��ٸ� �ٽ� ������� �����־���
				row[r][n] = false;
				col[c][n] = false;
				box[3 * (r / 3) + (c / 3)][n] = false;
				// �׸��� ���� nŽ��
			}
		}
	}
	// �����ϰ� �� n�� ���� ���
	return false;
}

vector<vector<int>> solution(vector<vector<int>> sudoku) {
	vector<vector<int>> answer = sudoku;

	// �־��� ������ Ž���ϸ� ����ִ� ĭ�� ���� ��Ƶΰ�
	// �� ��, ��, �ڽ��� ������ ���� ���θ� ǥ���Ѵ�
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0)
				blank.push_back(pair<int, int>(i, j));
			else {
				row[i][sudoku[i][j]] = true;
				col[j][sudoku[i][j]] = true;
				box[3 * (i / 3) + (j / 3)][sudoku[i][j]] = true;
			}
		}
	}

	backtracking(0, answer);

	return answer;
}


int main() {
	vector<vector<int>> sudoku(9, vector<int>(9));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];

	auto result = solution(sudoku);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << result[i][j] << ' ';
		cout << '\n';
	}
}