class TrieNode
{
public:
    bool is_word;
    vector<TrieNode*> children;

    TrieNode(bool is_word = false)
    {
        this->is_word = is_word;
        children.resize(26);
    }
    
    ~TrieNode()
    {
        for (auto child : children)
            delete child;
    }
};

class Trie 
{    
private:
    TrieNode* root;
    TrieNode* findNode(string str)
    {
        auto cur = root;
        for (int i = 0; i < str.size() && cur; i ++)
            cur = cur->children[str[i]-'a'];
        return cur;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new TrieNode();    
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        auto cur = root;
        for (int i = 0; i < word.size(); i ++)
        {
            if (!cur->children[word[i]-'a'])
                cur->children[word[i]-'a'] = new TrieNode();
            cur = cur->children[word[i]-'a'];                
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        auto tmp = findNode(word);
        if (tmp && tmp->is_word) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        return findNode(prefix) != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */