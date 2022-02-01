package Set;

import java.util.*;

class zero_sum_subarray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        if(zero_sum(a)) System.out.println("Zero sum sub array present ");
        else System.out.println("Zero sum sub array not present");
        sc.close();
    }

    public static boolean zero_sum(int a[]){
        Set<Integer> s = new HashSet<>();
        int sum =0;
        for(int ele : a){
            s.add(sum);
            sum += ele;
            if(s.contains(sum))return true;
        }
        
        return false;
    } 
}