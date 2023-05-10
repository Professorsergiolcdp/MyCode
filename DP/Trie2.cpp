#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* link[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return link[ch-'a'] != NULL;
    }

    void put(char ch,Node* node)
    {
        link[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return link[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }

};

class Trie{
    Node* root;
public:
    void Insert(string word)
    {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
        
    bool search(string word)
    {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    void delete(string s)
    {
        Node* node = root;
        
    }

};


