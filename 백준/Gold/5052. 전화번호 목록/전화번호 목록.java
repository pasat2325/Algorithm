import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
class Node{
        HashMap<Character, Node> child;
        boolean end_of_word;
        public Node(){
            this.child = new HashMap<>();
            this.end_of_word = false;
        }
    }
class Trie{
        Node root;

        public Trie(){
            this.root = new Node();
        }

        public boolean insert(String str){
            Node node = this.root;
            for(int i =0 ; i < str.length(); i++){
                char c = str.charAt(i);
                if(!node.child.containsKey(c)){
                    node.child.put(c, new Node());
                }
                
                node = node.child.get(c);
                if(node.end_of_word) return false;
            }
            if(!node.child.isEmpty()) return false;
            node.end_of_word = true;
            return true;
        }

}
public class Main{
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for(int i =0; i < tc; i++){
            Trie trie = new Trie();
            int n = sc.nextInt();

            boolean cons = true;
            String[] numbers = new String[n];
            for(int j = 0; j < n; j++){
                String str = sc.next();
                numbers[j] = str;
                if(!trie.insert(str)){
                    cons = false;
                }
            }

            if(cons) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}