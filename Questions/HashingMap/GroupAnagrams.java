//Anagrams are words with same characters in this question we have to group all anagrams in a different array


import java.util.*;


class GroupAnagrams{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s[]= new String[n];
        for(int i=0; i<n; i++){
            s[i] = sc.nextLine();
        }
        List<List<String>> l = new ArrayList<>();
        
        l = groupAnagram(s);
        for(int i=0; i<l.size(); i++){
            for(int j=0; j<l.get(i).size(); j++){
                System.out.print(l.get(i).get(j) + " ");
            }
            System.out.println();
        }
        sc.close();

    }

    public static List<List<String>> groupAnagram(String[] s){
        Map<String, List<String>> mp = new HashMap<>();
        for(String a: s){
            char[] c = a.toCharArray();
            Arrays.sort(c);
            String sorted = new String(c);

            if(!mp.containsKey(sorted)){
                mp.put(sorted, new LinkedList<String>());
            }
            mp.get(sorted).add(a);
        }
        return new LinkedList<>(mp.values());
    }
}