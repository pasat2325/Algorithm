import java.util.Scanner;

class Node{
    int nMax;
    int nMin;
}
class SegmentTree{
    Node tree[]; // 각 노드가 담길 트리
    int treeSize; // 트리의 크기

    public SegmentTree(int arrSize){
        // 트리 높이 구하기
        int h = (int) Math.ceil(Math.log(arrSize) / Math.log(2));
        // 트리를 저장할 배열 크기 구하기
        this.treeSize = (int) Math.pow(2, (h + 1));
        // 배열 생성하기
        tree = new Node[treeSize];
    }
    public Node init(int[] arr, int node, int start, int end){
        // 배열의 시작과 끝이 같다면 -> leaf node
        if(start == end){
            tree[node] = new Node();
            tree[node].nMax = arr[start];
            tree[node].nMin = arr[start];
            return tree[node];
        }
        tree[node] = new Node();
        Node leftChild = init(arr, node * 2, start, (start + end) / 2);
        Node rightChild = init(arr, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node].nMax = Math.max(leftChild.nMax, rightChild.nMax);
        tree[node].nMin = Math.min(leftChild.nMin, rightChild.nMin);
        return tree[node];
    }
    /* 
    public void update(int node, int start, int end, int idx, long diff){
        if(idx < start || end < idx) return;
        tree[node] += diff;
        if(start != end){
            update(node * 2, start, (start + end) / 2, idx, diff);
            update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
        }
    }
    public long sum(int node, int start, int end, int left, int right){
        if(left > end || right < start){
            return 0;
        }
        if(left <= start && end <= right){
            return tree[node];
        }
        return sum(node * 2, start, (start + end) / 2, left, right) + 
            sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
    */
    public int findMax(int node, int start, int end, int left, int right){
        // 1. 범위가 포함되는 경우
        if(left <= start && end <= right){
            return tree[node].nMax;
        }
        // 2. 범위에 포함되지 않는 경우
        else if(left > end || right < start){
            return 0;
        }
        // 3. 범위에 걸치는 경우
        else{
            return Math.max(findMax(node * 2, start, (start + end) / 2, left, right),
            findMax(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
        }
    }
    public int findMin(int node, int start, int end, int left, int right){
        // 1. 범위가 포함되는 경우
        if(left <= start && end <= right){
            return tree[node].nMin;
        }
        // 2. 범위에 포함되지 않는 경우
        else if(left > end || right < start){
            return (int)2e9;
        }
        // 3. 범위에 걸치는 경우
        else{
            return Math.min(findMin(node * 2, start, (start + end) / 2, left, right),
            findMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
        }
    }
}
public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n,m;
        n = sc.nextInt(); m = sc.nextInt();
        int[] ary = new int[n + 1];
        for(int i = 1; i <= n; i++){
            ary[i] = sc.nextInt();
        }
        SegmentTree st = new SegmentTree(n + 1);
        st.init(ary, 1, 1, n);
        for(int i = 0; i < m; i++){
            int fr, re;
            fr = sc.nextInt(); re = sc.nextInt();
            int ma = st.findMax(1, 1, n, fr, re);
            int mi = st.findMin(1, 1, n, fr, re);
            System.out.printf("%d %d\n", mi,ma);
        }
    }
}