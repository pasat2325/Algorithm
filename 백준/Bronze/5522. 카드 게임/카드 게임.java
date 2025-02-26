import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int result = 0;
        while(sc.hasNextInt())
        {
            int num = sc.nextInt();
            result += num;
        }
        System.out.println(result);
    }
}