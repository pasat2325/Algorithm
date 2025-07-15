import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
/*
 * str[front] == 'B' 이고, str[back] == 'A'라면
 * 뒤에 A를 붙힌건지, 뒤에 B를 붙히고 뒤집은건지 알 수가 없음
 * 
 */
public class Main{
    public static boolean is_possible = false;
    public static void solve(String a, String b){
        
        if(a.length() == b.length()){
            if(b.equals(a)) is_possible = true;
            return;
        }
        if(b.charAt(0) == 'B' && b.charAt(b.length() - 1) == 'A'){
            String reverse = "";
            for(int i = b.length()- 1; i >= 1; i--){
                reverse += b.charAt(i);
            }
            solve(a,reverse);

            String next = "";
            for(int i = 0; i < b.length() - 1; i++){
                next += b.charAt(i);
            }
            solve(a,next);
        }
        else if(b.charAt(0) == 'B'){
            String reverse = "";
            for(int i = b.length()- 1; i >= 1; i--){
                reverse += b.charAt(i);
            }
            solve(a,reverse);

        }
        else if(b.charAt(b.length() - 1) == 'A'){
            String next = "";
            for(int i = 0; i < b.length() - 1; i++){
                next += b.charAt(i);
            }
            solve(a,next);
        }
    } 
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
        solve(a, b);
        if(is_possible) System.out.println(1);
        else System.out.println(0);
    }
}