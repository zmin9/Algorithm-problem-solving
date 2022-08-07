import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_13305번_주유소_Greedy {


    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        long[] dist = new long[N-1];
        long[] price = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N-1; i++){
            dist[i] = Long.parseLong(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            price[i] = Long.parseLong(st.nextToken());
        }

        long ans = 0;
        long minOil = price[0];

        for (int i=0; i<N-1; i++){
            if (minOil > price[i]){
                minOil = price[i];
            }
            ans += minOil * dist[i];
        }

        System.out.println(ans);
    }
}
