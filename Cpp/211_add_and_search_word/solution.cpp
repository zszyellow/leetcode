class TrieNode
{
public:
    TrieNode()  
    { 
        isTerminal = false;
        for(int i = 0; i < 26; ++ i) children[i] = NULL; 
    }
    ~TrieNode()
    {
        for(int i = 0; i < 26; ++ i)
        {
            delete children[i];
            children[i] = NULL;
        }
    }
public:
    bool isTerminal; 
    TrieNode* children[26];
};

class WordDictionary 
{
private:
    TrieNode* myTrie;
    bool find(string word, TrieNode* node) 
    {
        TrieNode* cur = node;
        for (int i = 0; word[i]; i++) 
        {
            if (cur && word[i] != '.')
                cur = cur->children[word[i]-'a'];
            else if (cur && word[i] == '.') 
            { 
                TrieNode* tmp = cur;
                for (int j = 0; j < 26; j ++) 
                {
                    cur = tmp->children[j];
                    if (find(word.substr(i+1), cur))
                        return true;
                }
            }
            else break;
        }
        return cur && cur->isTerminal; 
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    {
        myTrie = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        TrieNode* cur = myTrie;
        for (char c : word) 
        {
            if (cur->children[c-'a'] == NULL) cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isTerminal = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return find(word, myTrie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */