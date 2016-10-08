class WordDictionary {
public:
    struct Node {
        bool isWord;
        vector<Node *> children;
        int depth;
        Node():isWord(false), children(26, NULL), depth(0){}
    };
    
    Node *root = NULL;
    
    // Adds a word into the data structure.
    void addWord(string word) {
        if(root == NULL){
            root = new Node();
        }
        
        auto current = root;

        for(auto c : word){
            int idx = c - 'a';
            if(current->children[idx] == NULL){
                auto newNode = new Node();
                current->children[idx] = newNode;
                newNode->depth = current->depth + 1;
                current = newNode;
                
            }else{
                current = current->children[idx];
            }
        }
        
        current->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string word, int pos, Node *node){
        if(node == NULL) return false;
        
        //check
        if(pos == word.size()){
            // return true;
            return node->isWord;
        }
        
        char c = word[pos];
        int idx = c - 'a';
        if(c != '.'){
            if(node->children[idx] == NULL){
                return false;
            }else{
                return dfs(word, pos+1, node->children[idx]);
            }
        }else{
            for(auto child : node->children){
                if(child != NULL && dfs(word, pos+1, child)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
