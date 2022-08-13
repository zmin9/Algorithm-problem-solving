import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class BOJ_2606번_바이러스_BFS{
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        
        int graph[][] = new int[N][N];

        // 연결 선 입력 받기
        for (int m=0; m<M; m++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            Integer a = Integer.parseInt(st.nextToken());
            Integer b = Integer.parseInt(st.nextToken());

            graph[a-1][b-1] = 1;
            graph[b-1][a-1] = 1;
        }
        
        boolean checked[] = new boolean[N];
        Arrays.fill(checked, false);

        Queue<Integer> Q = new LinkedList<>();
        Q.offer(0);

        
        while (!Q.isEmpty()){
            int x = Q.poll();
            checked[x]=true;

            for (int i=0; i<N; i++){
                if(graph[x][i]==1 && checked[i]==false){
                    Q.offer(i);
                }
            }
        }
        
        int ans = -1;
        for (int c =0 ; c<N; c++){
            if (checked[c]==true){
                ans ++;
            }
        }
        System.out.println(ans);
    }
}