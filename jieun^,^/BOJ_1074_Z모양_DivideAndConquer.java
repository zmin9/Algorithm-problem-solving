import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1074_Z모양_DivideAndConquer{

    static int N, R, C;
    static int ans;
    static double half;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        ans = 0;

        while (N>0){
            half = Math.pow(2, N-1);

            // 1 사분면
            if (R<half && C<half){}
            
            // 2 사분면
            if (R<half && C>=half){
                ans += Math.pow(half, 2);

                C -= half;
            }

            // 3 사분면
            if (R>=half && C<half){
                ans += 2 * Math.pow(half, 2);
                R -= half;
            }
            
            // 4 사분면
            if (R>=half && C>=half){
                ans += 3 * Math.pow(half, 2);
                R -= half;
                C -= half;
            }

            N--;
        }

        System.out.println(ans);
    }
}