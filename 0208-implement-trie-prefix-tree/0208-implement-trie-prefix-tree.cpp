struct Node{
    vector<Node*> child;
    bool flag;

    Node(){
        child.resize(26,nullptr);
        flag=false;
    }

    bool isword(char ch){
        return child[ch-'a']==nullptr;
    }

    void set(char ch,Node *node){
        child[ch-'a']=node;
    }

    Node* get(char ch){
        return child[ch-'a'];
    }
};
class Trie {
private:
    Node *root;
public:

    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->isword(word[i])==true){
                node->set(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->isword(word[i])==true) return false;
            node=node->get(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.size();i++){
            if(node->isword(prefix[i])==true) return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */