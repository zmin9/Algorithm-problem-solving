// ���α׷��ӽ� 72413��
#include <vector>
#define MAX 2000000

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    int answer = MAX;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, MAX));

    // �����
    for (int i = 0; i < fares.size(); i++) {
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    // �ش� ��ġ���� �ش� ��ġ���� ���� ����� 0�̶�� ����
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // �÷��̵� ����
    // ��� ������-������ ���� ����ġ �ּڰ��� ����
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // �ս��� s->i ���� �̷������ i���� ������ ������ ���� ����� �� ���� �� �� �ּڰ��� ã��
    for (int i = 1; i <= n; i++)
        answer = min(answer, dp[s][i] + dp[a][i] + dp[b][i]);

    return answer;
}