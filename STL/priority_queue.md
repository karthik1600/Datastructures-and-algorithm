# Priority Queues
with class
```c++
class Node{
public:
	int key;
	int weight;
	Node(int k,int w){
		key=k;
		weight=w;
	}
};
bool operator<(const Node& lhs,const Node& rhs)
{
	return lhs.weight<rhs.weight;
}

int main()
{
	priority_queue<Node> pq;
	for(int i=0;i<3;i++)
	{
		int key;
		int weight;
		cin>>key;
		cin>>weight;
		Node newn(key,weight);
		pq.push(newn);


	}
	while(!pq.empty())
	{
		cout<<pq.top().key<<" "<<pq.top().weight<<endl;
		pq.pop();
	}
}
```
input:
```
1 5
2 3
3 6
```
output:
```
3 6
1 5
2 3
```

`
---
# Minheap for distance and node in djikshtras
```cpp
int main()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(int i=0;i<3;i++)
	{
		int key;
		int weight;
		cin>>weight>>key;
		pq.push({weight,key});
	}
	while(!pq.empty())
	{
		cout<<pq.top().first<<" "<<pq.top().second<<endl;
		pq.pop();
	}
}
```
input
```
12 2
11 2
2 3
```
output
```
2 3
11 2
12 2
```
- so weight should be first so it sorts according to firsst of pair