import java.util.Scanner;
class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        sc.nextLine();
        for(int i = 0; i < tc; i++){
            String str = sc.nextLine();
            String[] words = str.split(" ");
            int idx = 0;
            for(String word : words){
                String wordReversed = "";
                for(int j = word.length() - 1; j >= 0; j--){
                    wordReversed += word.charAt(j);
                }
                words[idx++] = wordReversed;
            }
            System.out.println(String.join(" ", words));
        }
    }
}