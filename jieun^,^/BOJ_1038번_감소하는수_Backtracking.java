import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class BOJ_1038번_감소하는수_Backtracking {

    static int N;
    static int cnt;
    static ArrayList<Integer> ans;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());    // N번째 감소하는 수 (0 <= N <= 1,000,000)
        // 최소: 0(N=0), 최대: 9876543210 (N=1022)

        cnt = 0;

        for (int d=1; d<11; d++){   // 자리수가 바뀔 때마다 (자리수: 1~10)
            for (int a=0; a<10; a++){   // 끝자리수 0 ~ 9
                ans = new ArrayList<Integer>();
                ans.add(a);
                Backtrack(ans, d);
                if (cnt>N){break;}
            }
            if (cnt>N){break;}
        }

        if (N>1022){System.out.println("-1");}  // 정답이 존재하지 않음
        
    }

    public static void Backtrack(ArrayList<Integer> ans, int digit){
        
        // N번 카운트 & digit만큼의 자리수
        if (cnt==N && ans.size()==digit){
            cnt+=1;
            printList(ans);    // 정답 출력
        } 
        else if (ans.size()==digit){
            cnt += 1;
        } 
        else{
            for (int i=0; i<10; i++){
                if (i < ans.get(ans.size()-1)){     // i < 맨 끝자리 수 (감소하는 수)
                    ans.add(i); // 마지막에 i 추가
                    Backtrack(ans, digit);
                    ans.remove(ans.size()-1);   // 마지막 인덱스 삭제
                }
            }
        }
    }

    public static void printList(ArrayList<Integer> ans){
        String answer = "";
        for (int a: ans){
            answer += Integer.toString(a);
        }
        System.out.println(answer);
    }
}
