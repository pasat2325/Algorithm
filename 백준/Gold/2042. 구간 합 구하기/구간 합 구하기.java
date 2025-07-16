import java.util.Scanner;

class SegmentTree{
    long tree[]; // 각 원소가 담길 트리
    int treeSize; // 트리의 크기

    public SegmentTree(int arrSize){
        // 트리 높이 구하기
        int h = (int) Math.ceil(Math.log(arrSize) / Math.log(2));
        // 트리를 저장할 배열 크기 구하기
        this.treeSize = (int) Math.pow(2, (h + 1));
        // 배열 생성하기
        tree = new long[treeSize];
    }
    public long init(long[] arr, int node, int start, int end){
        // 배열의 시작과 끝이 같다면 -> leaf node
        if(start == end){
            return tree[node] = arr[start];
        }
        return tree[node] = 
        init(arr, node * 2, start, (start + end) / 2) + init(arr, node * 2 + 1, (start + end) / 2 + 1, end);
    }
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
}
public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n,m,k;
        n = sc.nextInt(); m = sc.nextInt(); k = sc.nextInt();
        long[] ary = new long[n + 1];
        for(int i = 1; i <= n; i++){
            ary[i] = sc.nextLong(); 
        }
        SegmentTree st = new SegmentTree(n);
        st.init(ary, 1, 1, n);
        for(int i = 0; i < m + k; i++){
            int a,b;
            a = sc.nextInt(); b = sc.nextInt();
            // 변경
            if(a == 1){
                long c = sc.nextLong();
                long diff = c - ary[b];
                ary[b] = c;
                st.update(1, 1, n, b, diff);
            }
            // 구간합 
            else{
                int c = sc.nextInt();
                long result = st.sum(1,1,n,b,c);
                System.out.println(result);
            }
        }

    }
}