// Given a tree find the kth ancestor of the tree
#include<bits/stdc++.h>
using namespace std;

//This class implement a tree which can give its kth ancestor in log(n) time
class TreeAncestor {
    vector<vector<int>> ancestors;
    int size;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestors.resize(n, vector<int> (31, -1));
        size = n;

        //building the ancestor array which stores the 2^i ancestor of a node
        for(int j =0; j< 31 ;j++){
            for(int i =0; i<n; i++){
                //if j is zero store the first ancestor using parent array 
                if(j == 0){
                    ancestors[i][j] = parent[i];
                }else{
                    // jth ancestor of a node is the j/2 ancestor of j/2 ancestor of this node
                    // Example the 16th ancestor of a node let 1 is same as 8th ancestor of another node let 5 which is 8th ancestor of 1
                    // In the ancestor dp we are storing the pow(2, j) ancestors of a node
                    int node_ancestor = ancestors[i][j-1];
                    if(node_ancestor != -1) ancestors[i][j] = ancestors[node_ancestor][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(node == -1) return -1;
        if(k == 0) return node;
        for(int i =0; i<31; i++){
            // When we need to find the kth ancestor as we have stored ancestors as power of 2
            // if there is a 1 in binary representation then we can directly find that ancestor
            if(k & (1<<i)){
                int val = pow(2,i);
                int parent_node = ancestors[node][i];
                return getKthAncestor(parent_node , k - val);
            }
        }
        return -1;
    }
};

int main(){
    vector<int> parent_of_tree = {-1, 0, 0, 1, 1, 2, 2};
    TreeAncestor* ancestorTree = new TreeAncestor(parent_of_tree.size(), parent_of_tree);

    //Find the kth ancestor using the kth ancestor method
    cout<<ancestorTree->getKthAncestor(5, 2);
    return 0;
}