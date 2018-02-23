class TrieNode
{
public:
    vector<TrieNode*> children;

    TrieNode()
    {
        children.resize(26);
    }
};

class Trie 
{    
public:
    TrieNode* root;
    Trie() : root(new TrieNode) {}
    
    void insert(string word) 
    {
        auto cur = root;
        for (int i = 0; i < word.size(); i ++)
        {
            if (!cur->children[word[i]-'a'])
            {
                if (i == word.size()-1) cur->children[word[i]-'a'] = new TrieNode();
                else break;
            }
            cur = cur->children[word[i]-'a'];                
        }   
    }
};


class Solution 
{
public:
    static bool comp(string i, string j) 
    {
        return i.size() < j.size(); 
    }
    
    string find(TrieNode* root)
    {
        string tmp("");
        if (root == NULL) return tmp;
        string res("");
        int longest = 0;
        for (int i = 0; i < 26; i ++)
        {
            if (root->children[i] != NULL )
            {
                tmp = 'a' + i;
                tmp += find(root->children[i]);
                if (tmp.size() > longest) 
                {
                    res = tmp;
                    longest = tmp.size();
                }
            }
        }
        return res;
    }

    string longestWord(vector<string>& words) 
    {
        string res("");
        bool flag = false;
    
        for (string word : words)
        {
            if (word.size() == 1) flag = true;
        }
        if (!flag) return res;
        
        std::sort(words.begin(), words.end(), comp);
        Trie* t = new Trie();
        for (string word : words) t->insert(word);
        return find(t->root);
    }
};