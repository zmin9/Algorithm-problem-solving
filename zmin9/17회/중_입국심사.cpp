// ���α׷��ӽ� 43238��
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long num_person = 0;
    long long start = 1, end = 0;
    long long mid;

    for(int i=0;i<times.size();i++)
        if(end < times[i])
            end=(long long)times[i];

    // ù end�� n���� ����� ���� �����ɸ��� �ɻ������ ��� �ɻ�޴� ���
    end *= (long long)n;
    
    long long answer = (start + end) / 2;
    
    // �̺�Ž��
    while(start <= end){
        num_person = 0;
        mid = (start + end) / 2;
        for(int i=0;i<times.size();i++)
            num_person += mid/times[i];
        
        if(n > num_person)
            start = mid + 1;
        else {
            end = mid - 1;
            if(answer > mid)
                answer = mid;
        }
    }
    return answer;
}