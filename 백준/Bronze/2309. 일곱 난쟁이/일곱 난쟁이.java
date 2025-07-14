import java.util.Arrays;
import java.util.Scanner;
public class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = 9;
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        for(int i = 0; i  < (1 << 9); i++){
            if (Integer.bitCount(i) == 7){
                int sum = 0;
                for (int j = 0; j < 9; j++){
                    if((i & (1 << j)) != 0){
                        sum += arr[j];
                    }
                }
                if(sum == 100){
                    int[] result = new int[7];
                    int idx = 0;
                    for(int j = 0; j < 9; j++) {
                        if((i & (1 << j)) != 0){
                            result[idx++] = arr[j];
                        }
                    }
                    Arrays.sort(result); 
                    for(int x : result) {
                        System.out.println(x);
                    }
                    break;
                }
            }
        }
    }
}