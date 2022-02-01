#include<bits/stdc++.h>
using namespace std;
struct Trie{
    Trie* child[2];
    // Trie* right;
    bool end;
    Trie(){
        child[0] = NULL;
        child[1] = NULL;
        end = false;
    }
    
    
};


void insert(Trie* &root, int x){   //to insert each element into the Trie
        if(root == NULL) root = new Trie();    
        Trie *t = root;
        bitset<32> bs(x);
        
        for(int j=31; j>=0; j--){
            if(!t->child[bs[j]]) t->child[bs[j]] = new Trie(); //start from the MSB =, move to LSB using bitset
            t = t->child[bs[j]];
        }    
}


 int maxXOR(Trie* root, int n){
        Trie *t = root;
        bitset<32> bs(n);
        int ans=0; 
        for(int j=31; j>=0; j--){
            if(t->child[!bs[j]]) ans += (1<<j), t = t->child[!bs[j]]; //Since 1^0 = 1 & 1^1 = 0, 0^0 = 0
           
            else t = t->child[bs[j]];
        }
        return ans;
}

 void printTrie(Trie* node, string s){
        if(node->end){
            cout<<"String : "<<s<<"\n";
        }

        for(int i=0; i<2; i++){
            if(node->child[i] != NULL){
                // cout<<i<<" "<<s<<"\n";
                char toAdd = '0' + i;
                printTrie(node->child[i], s+toAdd);
            }
        }
}
void print(Trie* root){
        if(root == NULL){
            cout<<"Trie is empty\n";
            return ;
        }
        // cout<<"gone";
        printTrie(root, "");
}


int findMaximumXOR(vector<int>& nums) {
        Trie* root = NULL;
        for(int i =0; i<nums.size(); i++){
            insert(root, nums[i]);
        }
        cout<<"\n";
        int ans = 0;
        for(auto n : nums){
            ans = max(ans, maxXOR(root, n));
        }
}

int main(){
    vector<int> nums = {3,10,5,25,2,8};
    cout<<findMaximumXOR(nums);
    return 0;
}