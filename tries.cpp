#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;
    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie
{
    Node *root;
public:
    Trie(){

    }

    void addWord(string word){
        Node* temp = root;
        for(auto c:word){
            if(temp->children.count(ch)==0){
                Node *chil = new Node(c);
                temp->children[c]=child;
                temp = child;
            }
            else{
                temp=temp->children[c];
            }
        }
        temp->terminal = true;
    }
};

int main(){
    
}