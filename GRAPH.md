# Graph
[ref material](refMat\graph_theory_algorithms.pdf)
## DFS :
 As the name suggests, a DFS plunges depth first into a graph without regard for which edge it takes next until it cannot go any further at which point it backtracks and continues.\
[dfs algo](refMat\graph_theory_algorithms.pdf#page=106)
```C++
void dfs(vector<int> &vis,vector<vector<int>> g,int a)
{
	if(vis[a])return; //if already visited
    vis[a]=1;
	for(int i=0;i<g[a].size();i++)
	{
		if(g[a][i]==0)continue;  //if no connection in graph
		if(vis[i]==1)continue; //if already visited - not necessary as we already check 
		dfs(vis,ordering,g,i);
	}

}
```
## Graph colouring
Sometimes a graph is split into multiple components. It’s useful to be able to identify and count these components.\
[graph colouring algo](refMat/graph_theory_algorithms.pdf#page=150)
```c++
void dfs(vector<int> &vis,vector<vector<int>> g,int a)
{
	if(vis[a])return; //if already visited
    vis[a]=1;
    color[i]=c;
	for(int i=0;i<g[a].size();i++)
	{
		if(g[a][i]==0)continue;  //if no connection in graph
		if(vis[i]==1)continue; //if already visited - not necessary as we already check 
		dfs(vis,ordering,g,i);
	}

}
void colouring(vector<int> &vis,vector<vector<int>> g)
{
    int c=-1
    for(int i=0;i<g.size();i++)//all nodes in a graph
    {
        if(vis[i]==0)
        {
            c++;
            dfs(vis,g,i);
        }
    }
}
```
---
## BFS
he Breadth First Search (BFS) is another fundamental search algorithm used to explore nodes and edges of a graph. It runs with a time complexity of O(V+E) and is often used as a building block in other algorithms.\
[BFS algo](refMat/graph_theory_algorithms.pdf#page=202)
```c++
#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> g,int source,int dest)
{
    queue<int> q;
    vector<int> vis(g.size(),0);
    vector<int> prev(g.size(),-1);
    q.push(source);
    prev[source]=source;
    vis[source]=1;
    int t;
    while(!q.empty())
	{
		t=q.front(); 
		q.pop();
		for(int i=0;i<g[t].size();i++) //go through all nodes connected to current node
		{
			if(vis[g[t][i]]==0)//check if node has been visited
			{
				q.push(g[t][i]);
				vis[g[t][i]]=1;
				prev[g[t][i]]=t;
			}
		}
        
	}
    while(prev[b]!=b)
	{
	    cout<<b<<"->";
	    b=prev[b];
    }
    cout<<b;
}
```
BFS Maze
```c++
void bfs(vector<vector<int>> v,int x1,int y1,int x2,int y2)
{
    int dx[]={0,0,1,-1}; //directions 1=>right -1 =>left
    int dy[]={1,-1,0,0}; //directions 1=>down -1 => up
    vector<vector<int>> m(v.size());//visited
    vector<int> prev(v.size()); // to hold the parent or previos part
    vector<vector<int>> label(v.size());
    int l=1;
    for(int i=0;i<v.size();i++)      //to initialise the labels
    {
        for(int j=0;j<v[0].size();j++)
        {
            m[i].push_back(0);
            
            label[i].push_back(l);
            prev.push_back(-1);
            l++;
        }
    }
    if(v[x1][y1]==1){ cout<<"not possible";  return;} //when entry point is one
    if(v.size()==1&&v[0].size()==1){cout<<"\n\ndistance = 0"; return;} //when we have a single block as a maze
 
    prev[label[x1][y1]]=label[x1][y1];        
    m[x1][y1]=1;
    int tx,ty;
    queue<int> qx,qy;       //to hold the coordinates
    qx.push(x1);                       
    qy.push(y1);
    int drx,dry;
    while(!qx.empty()||!qy.empty())
    {
        tx=qx.front();
        ty=qy.front();
        qx.pop();
        qy.pop();
        for(int i=0;i<4;i++)
        {   
            drx=tx+dx[i];  //to create coordinate
            dry=ty+dy[i];//to create coordinate
            if(drx<0||dry<0)continue;              //if out of range
            if(drx>=v.size()||dry>=v[0].size())continue;  //if out range
            if(v[drx][dry]==1)continue;     //if block is 1 which we cannot traverse
            if(m[drx][dry]==1)continue;     //if already visited
            qx.push(drx);        //pushes x coordinate to queue
            qy.push(dry);        //pushes y coordinate to queue
            m[drx][dry]=1;
            prev[label[drx][dry]]=label[tx][ty];
            if(label[drx][dry]==label[x2][y2]) //executes only when exit reached and only once
            {
                printmaze_num(label);
                int c=0;
                stack<int> s;
                do
                {
                    s.push(label[x2][y2]);
                    c++;
                    label[x2][y2]=prev[label[x2][y2]];
        
                }
                while(prev[label[x2][y2]]!=label[x2][y2]);
                cout<<label[x2][y2];
                while(!s.empty())
                {
                    cout<<"->"<<s.top();
                    s.pop();
                }
                cout<<"\n\ndistance = "<<c;
                return;
            }
            
        }
    }
 
    cout<<"not possible";
    
}
```
in the above problem we can use class as shown below
```java
 private static class Point {
        int x;
        int y;
        Point parent;

        public Point(int x, int y, Point parent) {
            this.x = x;
            this.y = y;
            this.parent = parent;
        }

        public Point getParent() {
            return this.parent;
        }

        public String toString() {
            return "x = " + x + " y = " + y;
        }
  }

```
---
## Topological Sort
[topological sort ref](refMat/graph_theory_algorithms.pdf#page=302)

```c++
void dfs(vector<int> &vis,vector<int> &ordering,vector<vector<int>> g,int &k,int a)
{
	vis[a]=1;
	for(int i=0;i<g[a].size();i++)
	{
		if(g[a][i]==0)continue;
		if(vis[i]==1)continue;
		dfs(vis,ordering,g,k,i);
	}
	ordering[k]=a;
	k--;

}
vector<int> topological(vector<vector<int>> g)
{
	vector<int> visited(g.size(),0);
	 vector<int> ordering(g.size(),0);
	int k=g.size()-1;
	for(int i=0;i<g.size();i++)   //visit all nodes in that node
	{
		if(visited[i]!=1)
		{
			dfs(visited,ordering,g,k,i);
		}
	}
	for(int i=0;i<ordering.size();i++)
		cout<<ordering[i]<<" ";
	return ordering;
}
```
---
# single source shortest distance path in DAG
```c++
void shortestpath(vector<vector<int>> G,int st,int end)
{

	vector<int> ordering=topological(G);
	vector<int> dist(ordering.size(),INT_MAX);//initialize all dist to infinity
	dist[st]=0;
	for(int i=0;i<ordering.size();i++)//so that we get to know if end before source
	{
		for(int j=0;j<ordering.size();j++)
		{	

			if(dist[ordering[i]]==INT_MAX){
				if(ordering[i]==end) {cout<<"not possible";return;}
				continue;
			}
			if(G[ordering[i]][j]!=0)
			{
				if(dist[ordering[i]]+G[ordering[i]][j]<dist[j])
				{
					dist[j]=dist[ordering[i]]+G[ordering[i]][j];
				}
			}
		}
	}
	
		cout<<"sdp of "<<end<<" from "<<st<<" "<<dist[end]<<endl;
	

}
```
- longest path can be taken in a dag ny multiplying edges into -1
- this is only for DAG
---
## Dijkstra's Shortest Path
[]
- is a Single Source Shortest Path (SSSP) algorithm for graphs with `non-negative edge weights`
- Depending on how the algorithm is implemented and what data structures are used the time complexity is typically `O(E*log(V))`which is competitive against other shortest path algorithms
[Dijkstra's ref](refMat/graph_theory_algorithms.pdf#page=302)
```c++
class Node
{
    public:
    int key;
    int weight;
    Node(int key,int weight){
        this->key=key;
        this->weight=weight;
    }

};

bool operator<(const Node& a,const Node& b)
{
	return a.weight<b.weight;
}


void dijks(vector<vector<int>> g,int s,int d)
{
	unordered_set<int> vis;
	vector<int> dist(g.size(),INT_MAX);
	dist[s]=0;
	vector<int> prev(g.size(),-1);
	priority_queue<Node> pq;
	Node newn(s,0);
    pq.push(newn);
	while(!pq.empty())
	{

		Node temp=pq.top();
		if(temp.key==d)break;
		vis.insert(temp.key);
		pq.pop();
		for(int i=0;i<g.size();i++)
		{
			if(vis.find(i)!=vis.end())continue;
			if(dist[temp.key]+g[temp.key][i]<dist[i] && g[temp.key][i]!=0)
			{
				dist[i]=dist[temp.key]+g[temp.key][i];
                prev[i]=temp.key;
                Node newin(i,dist[i]);
			    pq.push(newin);
			}

		}
		if(temp.key==d) break;
	} 
	if(vis.find(d)==vis.end()){
		cout<<"not possible";
		return;
	}
	cout<<"dist="<<dist[d]<<endl;
	while(prev[d]!=-1)
	{
		cout<<d<<"->";
		d=prev[d];
	}
	cout<<s;

}
```
---
## Bellman Ford
[algo ref](refMat/graph_theory_algorithms.pdf#page=546)
```c++
void belmanford(vector<vector<int>> G)
{
	vector<int> dist(G.size(),INT_MAX);
	dist[0]=0;
	for(int i=0;i<G.size();i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			if(G[i][j]==0)continue;
			if(dist[i]+G[i][j]<dist[j])
			{
				dist[j]=dist[i]+G[i][j];
				//cout<<j<<" distance = "<<dist[j]<<endl;
			}
		}
	}
	for(int i=0;i<G.size();i++)//for negative cycles
	{
		for(int j=0;j<G[i].size();j++)
		{
			if(G[i][j]==0)continue;
			if(dist[i]+G[i][j]<dist[j])
			{
				dist[j]=INT_MIN;
			}
		}
	}
}
```
---
## Floyd warshall
[algo ref](refMat/graph_theory_algorithms.pdf#page=606)
- used to find the shortest dist between all paths 
- If there is no edge from node i to node j then set the edge value for m[i][j] to be positive infinity
```c++
void graphConverter(vector<vector<double>> &G)//converts graph into a format needed to solve in the given algo
{
	for(int i=0;i<G.size();i++)
	{
		for(int j=0;j<G.size();j++)
		{
			if(i!=j&&G[i][j]==0){
				G[i][j]=INF;
			}
		}	
	}
}
void intializer(vector<vector<double>> &table,vector<vector<double>> G,vector<vector<double>> &next)
{
	for(int i=0;i<G.size();i++)
    {
        for(int j=0;j<G.size();j++)
		{
			table[i][j]=G[i][j];
			if(G[i][j]!=INF)
			{
				next[i][j]=j;
			}
		}
	}
}
void pathconstructor(vector<vector<double>> table,vector<vector<double>> next,int source,int dest)
{
	int i=source;
	vector<int> v;
	while(i!=dest)
	{
		
		v.push_back(i);
		i=next[i][dest];
		
	}
	
	for(int j=0;j<v.size();j++)
	{
		cout<<v[j]<<"->";
	}cout<<dest;
}
void floydWarshalSolver(vector<vector<double>> G,int source,int dest)
{
	graphConverter(G);
	vector<vector<double>> table(G.size(),vector<double>(G.size(),0));
	vector<vector<double>> next(G.size(),vector<double>(G.size(),-1));
	intializer(table,G,next);
	for(int k=0;k<G.size();k++)
	{
		for(int i=0;i<G.size();i++)
		{
			for(int j=0;j<G.size();j++)
			{
				if(table[i][j]>table[i][k]+table[k][j])
				{
					if(table[i][k]==INT_MAX&&table[k][j]==INT_MAX)continue;
					table[i][j]=table[i][k]+table[k][j];
					next[i][j]=next[i][k];
				}
			}
		}
	}
	
	if(table[source][dest]!=INF)
	{cout<<"distance = "<<table[source][dest];
pathconstructor(table,next,source,dest);
	}else
	cout<<"not possible"<<;
}
```
- can solve for negative cycle by executing algo once more
---
