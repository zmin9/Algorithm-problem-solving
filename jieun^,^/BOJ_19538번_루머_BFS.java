import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_19538번_루머_BFS{
    
    static int N;   // 사람 수
    static int M;   // 최초 유포자의 수
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // N 입력 받기
        N = Integer.parseInt(br.readLine());
        
        // N명의 관계도
        List<List<Integer>> graph = new ArrayList<>();
        
        // N명의 관계도 입력 받기
        StringTokenizer st;
        for (int n=0; n<N; n++){
            List<Integer> arr = new ArrayList<>();
            st = new StringTokenizer(br.readLine());
            while(true){
                Integer a = Integer.parseInt(st.nextToken());
                if (a==0){break;}   // 0이 들어오면 입력 끝
                else{
                    arr.add(a);
                }
            }
            graph.add(arr);
        }

        // 주변인의 절반 이상이 감염됐는지 체크할 배열
        Integer[] check = new Integer[N];
        for (int n=0; n<N; n++){
            check[n] = (int) Math.ceil(graph.get(n).size()/2.0);    // ceil 함수는 double형으로 반환
        }
        
        // 루머를 믿는데 걸리는 시간을 기록하는 배열
        Integer[] ans = new Integer[N];
        for (int a=0; a<N; a++){ans[a]=-1;} // -1로 초기화
        
        // BFS를 위한 큐
        Queue<Integer> Q = new LinkedList<>();

        // M 입력 받기
        M = Integer.parseInt(br.readLine());

        // 최초 유포자 배열
        Integer[] first = new Integer[M];
        st = new StringTokenizer(br.readLine());
        for (int m=0; m<M; m++){
            first[m] = Integer.parseInt(st.nextToken());
            ans[first[m]-1]=0;  // 최초 유포자들은 루머를 믿는데 걸리는 시간 0분
            Q.add(first[m]-1);  // 루머를 믿는 사람들은 큐에 넣음
        }

        // Q가 비게 될 때까지
        while (!Q.isEmpty()){
            // 큐에서 꺼냄
            Integer rumor = Q.poll();

            // rumor의 주변인들에게 퍼트리기
            for(int g: graph.get(rumor)){
                check[g-1]-=1;  // rumor의 주변인 입장에선 주변에 믿는 사람 +1

                // ans[g-1]==-1 : 아직 루머를 믿지 않는가?
                // check[g-1]<=0 : 주변에 믿는 사람이 절반 이상임
                if (check[g-1]<=0 && ans[g-1]==-1){ 
                    Q.add(g-1);
                    ans[g-1] = ans[rumor]+1;
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (int a: ans){
            sb.append(a);
            sb.append(" ");
        }
        System.out.println(sb);
    }
}
