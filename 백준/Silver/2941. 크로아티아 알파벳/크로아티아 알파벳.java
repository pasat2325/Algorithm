import java.util.Arrays;
import java.util.Scanner;
public class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        String[] croatians = {"dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="};
        
        for(String c : croatians){
            str = str.replace(c, "#");
        }
        System.out.println(str.length());
    }
}
