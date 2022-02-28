// 프로그래머스 43238번
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long num_person = 0;
    long long start = 1, end = 0;
    long long mid;

    for(int i=0;i<times.size();i++)
        if(end < times[i])
            end=(long long)times[i];

    // 첫 end는 n명의 사람이 가장 오래걸리는 심사관에게 모두 심사받는 경우
    end *= (long long)n;
    
    long long answer = (start + end) / 2;
    
    // 이분탐색
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