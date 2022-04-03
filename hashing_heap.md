## group anagrams
approach1- count no. of characters and hash it
```c++ 
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> res;
        for(auto str :strs )
        {
            string s;
            vector<int> count(26,0);
            for(int i=0;i<str.size();i++)
            {
                count[str[i]-'a']++;
                
            }
            for(int i=0;i<26;i++)
            {
                s=s+"#";
                s=s+to_string(count[i]);
            }
            m[s].push_back(str);
        }
        for(auto st:m)
        {
            res.push_back(st.second);
        }
            return res;
    }
```
approach2 - sort chars of string and hash it
```c++
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<int> count(26,0);
        unordered_map<string,vector<string>> m;
        for(auto str :strs )
        {
            string s=str;
            vector<int> count(26,0);
            sort(s.begin(),s.end());
            
                m[s].push_back(str);
        }
        vector<vector<string>> res;

                
            for(auto st:m)
            {
                res.push_back(st.second);
            }
        
        return res;
    }
```
---
first nonrecurring character in array stream in o(1) using dequeue
```c++
        unordered_map<char,int> count;
        int index[26];
        for(int i=0;i<26;i++)
        {
            index[i]=-1;
        }
        
        deque<char> dq;
        for(int i=0;i<s.length();i++)
        {
            count[s[i]]++;
            dq.push_back(s[i]);
            if(index[s[i]-'a']==-1)
            {
                index[s[i]-'a']=i;
            }
            while(count[dq.front()]>1&&!dq.empty())//if front character has occured more than once
            {
                dq.pop_front();
            }
                
        }
        if(dq.empty())
            return -1;
        return index[dq.front()-'a'];
    }
```
without stl
```c++

struct Node
{
    char data;
    Node *prev;
    Node *next;
};

Node *insert_end(Node **head_ref, Node **tail_ref, char x)
{
    Node *temp=(struct Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;

    if(*head_ref==NULL)
    {
        *head_ref=temp;
        *tail_ref=temp;
    }
    else
    {
    (*tail_ref)->next=temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
    }

    return *tail_ref;
}

void remove(Node **head_ref, Node **tail_ref, Node *temp)
{
    if(*head_ref==NULL)
        return;

    if(*head_ref==temp)
        *head_ref=(*head_ref)->next;

    if(*tail_ref==temp)
        *tail_ref=(*tail_ref)->prev;

    if(temp->prev)
    temp->prev->next=temp->next;

    if(temp->next)
    temp->next->prev=temp->prev;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int freq[256]={0};
    Node *links[256]={NULL};
    
    int n;
    cin>>n;
    
    Node *head=NULL, *tail=NULL;
    
    while(n--)
    {
    char x;
    cin>>x;

    if(freq[x]==0)
        links[x]=insert_end(&head, &tail, x);
    if(freq[x]==1)
        remove(&head, &tail, links[x]);
    freq[x]++;

    if(head!=NULL)
    cout<<head->data<<" ";
    else cout<<"-1 ";
    }
    cout<<endl;
    }
```
