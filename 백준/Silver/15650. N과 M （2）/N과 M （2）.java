import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main{
    private static int n,m;
    private static StringBuilder sb = new StringBuilder();
    private static char[] ans = new char[16];
    private static boolean[] vis = new boolean[8];
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i = 0; i < 2*m; i++) ans[i] = ' ';
        permutation(0, 0);
    }
    private static void permutation(int j, int depth)
    {
        if(depth == m){
            for(int i = 0; i < 2*m; i++)
                System.out.print(ans[i]);
            System.out.println();
            return;
        }

        for(int i = j; i < n; i++)
        {
            ans[depth*2] = (char)(i + '1');
            permutation(i + 1, depth + 1);
        }
    }
}