import java.util.Arrays;
import java.util.Scanner;
public class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        for(int tc = 0; tc < n; tc++){
            String str = sc.next();
            int used = 0;
            boolean is_group_word = true;
    
            for(int i = 1; i < str.length(); i++){
                if((used & (1 << str.charAt(i) - 'a')) != 0){
                    is_group_word = false;
                    break;
                } 
                if(str.charAt(i) != str.charAt(i-1)){
                    used |= (1 << str.charAt(i-1) - 'a');
                }
            }
            if(is_group_word) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
