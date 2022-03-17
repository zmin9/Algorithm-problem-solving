// ���α׷��ӽ� 1829��
#include <vector>
using namespace std;

// �� ĭ�� �湮 ���θ� ������ ���� �������� ����
vector<vector<bool>> visited;

// �� �� �� �� Ž���� ���� �迭
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

// dfs�� �ֺ� Ÿ���� Ž���Ѵ�
void dfs(int row, int col, int m, int n, int* count, vector<vector<int>> picture) {
    // ���� �湮�� ���� �ִ� Ÿ���� ��� return
    if (visited[row][col])
        return;

    // �湮 ���θ� �����ϰ� Ÿ�� ������ ������Ŵ
    visited[row][col] = true;
    (*count)++;

    // �����¿쿡 ���� ���� ���̸� dfs�� �����Ѵ�.
    for (int k = 0; k < 4; k++)
        if (row + di[k] >= 0 && col + dj[k] >= 0 && row + di[k] < m && col + dj[k] < n)
            if (picture[row][col] == picture[row + di[k]][col + dj[k]])
                dfs(row + di[k], col + dj[k], m, n, count, picture);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    visited.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // �� ������ �ƴϰ� �湮�� ���� ���� ĭ�̶�� dfs
            if (picture[i][j] != 0 && !visited[i][j]) {
                number_of_area++;
                int size_of_this_area = 0;
                dfs(i, j, m, n, &size_of_this_area, picture);
                // ���� �̹��� Ž���� ĭ�� ������ Ŭ ��� �����Ѵ�
                if (size_of_this_area > max_size_of_one_area)
                    max_size_of_one_area = size_of_this_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}