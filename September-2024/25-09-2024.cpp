class TrieNode{
    public:
    char ch;
    TrieNode* child[26];
    int cnt;
    TrieNode(char c)
    {
        ch = c;
        for(int i = 0; i<26; i++)
        {
            child[i] = NULL;
        }
        cnt = 0;
    }
};

class Solution {
public:
    void insert(TrieNode* root, string word)
    {
        for(int i = 0; i<word.size(); i++)
        {
            char ch = word[i];
            if(root->child[ch-'a'] == NULL)
            {
                TrieNode* node = new TrieNode(ch);
                root->child[ch-'a'] = node;
            }
            
            root = root->child[ch-'a'];
            root->cnt++;
        }
    }
    int search(TrieNode* root, string word)
    {
        int prefixCount = 0;

        for(int i = 0; i<word.size(); i++)
        {
            char ch = word[i];
            root = root->child[ch-'a'];
            prefixCount += root->cnt;
        }

        return prefixCount;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        TrieNode* root = new TrieNode('/');
        for(auto word : words)
        {
            insert(root, word);
        }

        for(auto word : words)
        {
            ans.push_back(search(root, word));
        }

        return ans;
    }
};