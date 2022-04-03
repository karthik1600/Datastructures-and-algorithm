## huffman coding
```c++
class Node{
	public:
	char ch;
	int freq;
	Node* left;
	Node* right;
	Node(char c,int freq)
	{
		this->ch=c;
		this->freq=freq;
		this->left=NULL;
		this->right=NULL;
	}
};
class Compare {
public:
    bool operator()(Node* a,
                    Node* b)
    {
        // Defining priority on
        // the basis of frequency
        return a->freq > b->freq;
    }
};
bool isLeaf(Node* nod)
{
	if(!nod->left&&!nod->right)
		return true;
	return false;
}
void printFreq(Node* root,string st)
{
	if(root==NULL)return;
	printFreq(root->left,st+'0');
	if(isLeaf(root))
	{
		cout<<root->ch<<" "<<root->freq<<" "<<st<<endl;
	}
	printFreq(root->right,st+'1');
}
void huffmantree(vector<int> freq,vector<char> ch)
{
	priority_queue<Node*,vector<Node*>,Compare> pq;
	for(int i=0;i<freq.size();i++)
	{
		Node* newnode= new Node(ch[i],freq[i]);
		pq.push(newnode);
	}
	while(pq.size()!=1)
	{
		Node* left= pq.top();
		pq.pop();
		Node* right= pq.top();
		pq.pop();
		Node* newnode=new Node('#',left->freq+right->freq);
		newnode->left=left;
		newnode->right=right;
		pq.push(newnode);
	}
	printFreq(pq.top(),"");
}
int main()
{
	vector<int> freq;int n;
	vector<char> ch;cin>>n;
	for(int i=0;i<n;i++)
	{
		int f;char c;
		cin>>c>>f;
		freq.push_back(f);
		ch.push_back(c);
	}
	huffmantree(freq,ch);
}
```
^
|
giveen an array F with size n. Assume the array content F[i] indicates the length ofthe ith file and we want to merge all these files into one single file. Check whether thefollowing algorithm gives the best solution for this problem or not?
---
Efficient huffman for sorted freq -> O(N)
```c++
class Node{
	public:
	char ch;
	int freq;
	Node* left;
	Node* right;
	Node(char c,int freq)
	{
		this->ch=c;
		this->freq=freq;
		this->left=NULL;
		this->right=NULL;
	}
};
Node* findmin(queue<Node*> &q1,queue<Node*> &q2)
{
	Node* temp;
	if(q2.empty())
	{
		temp=q1.front();
		q1.pop();
		return temp;
	}
	if(q1.empty())
	{
		temp=q2.front();
		q2.pop();
		return temp;
	}
	if(q1.front()->freq>q2.front()->freq)
	{
		temp=q2.front();
		q2.pop();
		return temp;
	}
	else
	{
		temp=q1.front();
		q1.pop();
		return temp;
	}

}
bool isLeaf(Node* nod)
{
	if(!nod->left&&!nod->right)
		return true;
	return false;
}
void printFreq(Node* root,string st)
{
	if(root==NULL)return;
	printFreq(root->left,st+'0');
	if(isLeaf(root))
	{
		cout<<root->ch<<" "<<root->freq<<" "<<st<<endl;
	}
	printFreq(root->right,st+'1');
}
void EfficientHuff(vector<int> freq,vector<char> ch)
{
	queue<Node*> q1,q2;
	for(int i=0;i<freq.size();i++)
	{
		Node* newnode=new Node(ch[i],freq[i]);
		q1.push(newnode);
	} 
	while(!q1.empty())
	{
		Node* left=findmin(q1,q2);
		Node* right=findmin(q1,q2);
		Node* newnode=new Node('$',left->freq+right->freq);
		newnode->left=left;
		newnode->right=right;
		q2.push(newnode);
	}
	printFreq(q2.front(),"");

}
```