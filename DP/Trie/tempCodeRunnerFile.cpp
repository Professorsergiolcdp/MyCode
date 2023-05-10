#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* children[26];
    bool flag = false;

    bool containsKey(char ch){
        return children[ch - 'a'] != NULL;
    }

    Node* get(char ch){
        return children[ch-'a'];
    }

    void put(char ch, Node* node){
        children[ch-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
private:     Node* root;
public: 
        Trie(){
            root = new Node();
        }
        void Insert(string s){
            Node* node = root;
            for(int i = 0;i < s.size();i++){
                if(!node->containsKey(s[i])){
                    node->put(s[i],new Node());
                }
                node = node->get(s[i]);
            }
            node->isEnd();
        }

        bool Search(string s){
            Node* node = root;
            for(int i = 0;i < s.size(); i++){
                if(!node->containsKey(s[i])){
                    return false;
                }
                node = node->get(s[i]);
            }
            return node->isEnd();
        }

        bool startWith(string s){
             Node* node = root;
            for(int i = 0;i < s.size(); i++){
                if(!node->containsKey(s[i])){
                    return false;
                }
                node = node->get(s[i]);
            }
            return true;
        }
};


int main(){
        Trie t;
        t.Insert("apple");
        t.Insert("bad");
        t.Insert("bat");
        cout<<t.startWith("aba");
}
