
import java.util.HashMap;
import java.util.Scanner;

public class zero_sum_subarr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        int ans = zsa(a, n);
        System.out.println(ans);
        sc.close();
    }

    public static int zsa(int a[], int n){
        HashMap<Integer, Integer> mp = new HashMap<>();
        int sum = 0, count = 0;
        for(int i=n-1; i>=0; i--){
            sum+= a[i];
            if(sum == 0) {count++;
                System.out.print(i + " ");
            }
            if(mp.containsKey(sum)){
                count += mp.get(sum);
                System.out.print(i + " ");
            }
            if(!mp.containsKey(sum)){
                mp.put(sum, 1);
            }
            else{
                mp.put(sum, mp.get(sum) + 1);
            }
        }
        return count;
    }
}
