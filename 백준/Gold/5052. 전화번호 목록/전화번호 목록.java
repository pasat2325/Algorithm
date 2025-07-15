import java.util.Arrays;
import java.util.Scanner;
public class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for(int i = 0; i < tc; i++){
            boolean consistency = true;
            int n = sc.nextInt();
            String[] numbers = new String[n];
            for(int j = 0; j < n; j++){
                String number = sc.next();
                numbers[j] = number;
            }
            Arrays.sort(numbers);

            for(int j = 0; j < n - 1; j++){
                if(numbers[j+1].startsWith(numbers[j])){
                    consistency = false;
                    break;
                }
            }
            if(consistency) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
