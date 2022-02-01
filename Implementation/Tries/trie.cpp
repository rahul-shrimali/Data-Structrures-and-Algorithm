//Tries are data structures to store search and print strings in sorted order in an efficient order
#include<bits/stdc++.h>
using namespace std;

struct Trie{
    bool  end;
    Trie* child[26]; //We are assuming trie only for 26 alphabets
    Trie(){
        end = false;
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
    }
    void insert(Trie* &root, string s){
        if(root == NULL){
            root = new Trie();
        }
        int l = s.length();
        // cout<<s<<" "<<l;
        Trie* temp = root;
        for(int i=0; i<l; i++){
            // cout<<i<<" "<<temp<<" "<<s[i];
            
            if(temp->child[s[i] - 'a'] == NULL){
                temp->child[s[i] - 'a'] = new Trie();
            }
            temp = temp->child[s[i] - 'a'];
            // cout<<temp<<" ";
        }
        temp->end = true;
    }

    void printTrie(Trie* node, string s){
        if(node->end){
            cout<<"String : "<<s<<"\n";
        }

        for(int i=0; i<26; i++){
            if(node->child[i] != NULL){
                // cout<<i<<" "<<s<<"\n";
                char toAdd = 'a' + i;
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

    bool search(string s){
        if(s.length() == 0) return true;
        if(this == NULL) return false;
        if(this->child[s[0] - 'a'] == NULL) return false;
        if(s.length() == 1){
           return this->child[s[0]-'a']->end;
        }

        return this->child[s[0] - 'a']->search(s.substr(1));        
    }
};

int main(){
    Trie* root = NULL;
    root->insert(root, "rahul");
    root->insert(root, "ram");
    root->insert(root, "rajesh");
    root->insert(root, "kunal");
    root->insert(root, "aman");
    root->insert(root, "raman");
    root->insert(root, "r");
    root->insert(root, "ajay");
    root->insert(root, "sanjay");
    root->insert(root, "ganesh");
    root->insert(root, "rahul");

    root->print(root);

    cout<<"\n"<<root->search("raman");
    cout<<"\n"<<root->search("rama");
    cout<<"\n"<<root->search("gama");
    return 0;
}