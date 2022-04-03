> # c++ implementation
```cpp
class Node{
public:
	bool isLeaf;
	unordered_map<char,Node*> map;
	Node(){
		isLeaf = false;
	}
};
class Tries{
	public:
		Node* root;
		Tries(){
			root=new Node;
		}
		void insert(string s){
			Node* root1=root;
			for(int i=0;i<s.size();i++){
				if(root1->map.find(s[i])==root1->map.end()){
					root1->map[s[i]]=new Node;
				}
				root1=root1->map[s[i]];
			}
			root1->isLeaf=true; //this is the end of this word 
		}
		bool search(string s){
			Node* curr=root;
			for(int i=0;i<s.size();i++){
				curr=curr->map[s[i]];
				if(curr==NULL)return false;
			}
			return curr->isLeaf;
		}
};
```
```cpp
Tries* trie=new Tries;
trie->insert("cat");
trie->insert("pea");
trie->insert("catr");
if(trie->search("pea"))
    cout<<"true";
else cout<<"false";
```
---
# max Xor
```cpp
class TrieNode{
public:
	TrieNode(){
	      TrieNode* next[2]={NULL,NULL};
	  }
};
int findMaximumXOR(vector<int>& nums) {
	TrieNode* root=new TrieNode;
	TrieNode* curr;
	for (int num:nums){
		curr=root;
		for(int i=31;i>=0;i++){
			int biti= num & (1<<i);//ith bit
			if(curr->next[biti]==NULL){
				curr->next[biti]=new TrieNode;
			}
			curr=curr->curr->next[biti];
		}
	}
	int maxres=0
	for(int num:nums){
		int res=0;
			for(int i=31;i>=0;i++){
				int biti= num & (1<<i);	//this time take opp
				if(curr->next[biti^1]!=NULL){
					curr=curr->next[biti^1];
					res=res+(1<<i);
				}else curr=curr->next[biti];
			}
			maxres=max(maxres,res);
		}
		return maxres;
	}
```