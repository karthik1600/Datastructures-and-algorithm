# Graph
# undirected graph
## adjacency list
```cpp
int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	int adj[n+1][n+1]; 
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u][v] = 1; 
	    adj[v][u] = 1; 
	}
	return 0;
}
```
space: O(n^2)
adjacency list
```cpp
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1]; 
    vector<pair<int,int>> adj[n+1]; //if weighted
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); //adj[u].push_back({v,w})
	    adj[v].push_back(u); //adj[v].push_back({u,w})
    }   
````
space complexity: o(V+E)
![](img\adjcencylist.png)
---
# BFS
```cpp
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    vector<int> bfs; 
	    vector<int> vis(V+1, 0); 
        for(int i=1;i<V+1;i++){
            if(!vis[i]){  //if not visited
                queue<int> q; 
                q.push(i); 
                vis[i] = 1; 
                while(!q.empty()) {
                    int node = q.front();
                    q.pop(); 
                    bfs.push_back(node); 
                    
                    for(auto it : adj[node]) {
                        if(!vis[it]) {
                            q.push(it); 
                            vis[it] = 1; 
                        }
                    }
                }
            }
        }
	    return bfs; 
	}
```
![](img\bfs.png)

---
# DFS
```cpp
class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) { 
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V+1, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) dfs(i, vis, adj, storeDfs); 
      }
	    return storeDfs; 
	}
};
```
---
# Cycle detection in undirected graph
```cpp
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);
        
        // Create a queue for BFS
        queue<pair<int,int>> q;
        
        visited[s] = true;
        q.push({s, -1});
        
        while (!q.empty()) {
        
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
        
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int>adj[]){
        vector<int> vis(V, 0); 
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {  //if check every individual graph
                if(checkForCycle(i, V, adj, vis)) return true; 
            }
        }
        
        return false; 
    }
```
![](img\findcycleinundirectedgraph.png)

---
# Bipartite graph 
`a graph which can be coloured with 2 colours such that no 2 adj nodes are of same color`
```cpp
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) { //////////
                return false; 
            }
        }
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
```
![](img\bipartitegraph.png)
## DFS method
```cpp
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {  //////////if at some point false in recursion
                return false; 
            }
        } else if(color[it] == color[node]) return false; ////////
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}
```
![](img\bipartitegraphdfs.png)

---
# check cycle in a directed graph
```cpp
bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
        vis[node] = 1; 
        dfsVis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(checkCycle(it, adj, vis, dfsVis)) return true;
            } else if(dfsVis[it]) {
                return true; 
            }
        }
        dfsVis[node] = 0; 
        return false;
    }
public:
	bool isCyclic(int N, vector<int> adj[]) {
	   int vis[N], dfsVis[N]; 
	   memset(vis, 0, sizeof vis); 
	   memset(dfsVis, 0, sizeof dfsVis); 
	   
	   for(int i = 0;i<N;i++) {
	       if(!vis[i]) {
	           // cout << i << endl; 
	           if(checkCycle(i, adj, vis, dfsVis)) {
	               return true; 
	           }
	       }
	   }
	   return false; 
	}
```
![](img\checkcycledirected.png)

---
# Topologicall sort
`Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
`
```cpp
void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node); // exiting dfs recursion so add
    }
	public:
vector<int> topoSort(int N, vector<int> adj[]) {
    stack<int> st; 
    vector<int> vis(N, 0); 
    for(int i = 0;i<N;i++) {
        if(vis[i] == 0) {
            findTopoSort(i, vis, st, adj); 
        }
    }
    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top()); 
        st.pop(); 
    }
    return topo; 
}	    
```
- the first one to come out of dfs is the ele after which there is no one
- in a -> b -> c recursive call goes from a to c after which there is no one to call or it means there is no one after c 
- so c is last ele in toposort
- ordering a b c => there after each call put it in stack
- this is the logic used
---
# topological sort - bfs -kahns algo
```cpp
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {  //for a - > b indeg(b)=1 indeg(a)=0
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;  //decreasing indegree or removing edge from parent towards it while removing parent
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
```
- add every node whose indegree = 0 to queue
- this will be highest ele
- now remove each ele from queue and decrease the indegree of adj nodes while removing it
- after decreasing the indegree of node check if indegree ==0 then add it to queue
---
# cycle detection in directed graphs
```cpp
bool isCyclic(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; // cnt is the number of ele put in sorted order
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false;  //in toposort you get n ele as n ele are ordered but if cycle is present this alhgo fails
	    return true; 
}
```
- the toposort algo fails for cyclic so we just use reverse logic 
- if `cnt==N` then there is no cycles so false else true

---
# Shortest distance in a undirected graph
```cpp
void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 
	
} 
```
![](img\shortdistundirgrap.png)
---
# Shortest distance in a directed Acyclic graph
```cpp
void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
	int vis[N] = {0};
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9; 
	dist[src] = 0; 

	while(!st.empty()) 
	{  
		int node = st.top(); 
		st.pop(); 
 
		if (dist[node] != INF) {
		    for(auto it : adj[node]) {
		        if(dist[node] + it.second < dist[it.first]) {
		            dist[it.first] = dist[node] + it.second; 
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) 
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 
```
![](img\shortdistdirgrap.png)

---
#
```cpp
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		for( auto it: g[prev]){
			int next = it.first;
			int nextDist = it.second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}
```
![](img\djikshtrasshortestpath.png)

---
# Spanning tree
```
N vertices 
N-1 edges
if above conditions are satisfied then it is a spanning tree
the tree with minimum
```
![](img\mst-exp.png)
# prims minimum spanning tree
```cpp
int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  

    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)//for n-1 edges
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++) // to find the edge with minimum weight which is not yet visited
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
                
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) //to create tree
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
```
efficient
- by using to priority queue O(log(n)) to find smallest edge instead of searching through all edges which takes o( n )
```cpp
    int spanningTree(int N, vector<vector<int>> adj[])
    {
        int parent[N+1]; 
          
        int key[N+1]; 
          
        bool mstSet[N+1]; 
      
        for (int i = 0; i <= N; i++) 
            key[i] = INT_MAX, mstSet[i] = false; 
        
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    
        key[0] = 0; 
        parent[0] = -1; 
        pq.push({0, 0});
        while(!pq.empty())
        { 
            int u = pq.top().second; 
            pq.pop(); 
            
            mstSet[u] = true; 
            
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if (mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
    		key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
                
        }
        int sum = 0;
        for(int i = 1;i<=N;i++) {  //for sum 
            if(key[i] != INT_MAX) sum += key[i];
        }
        return sum; 
    }
```
![](img\mst-prim.png)

---
# disjoint sets , union and path compreesion
```cpp
int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); //path compression
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) { //if rank of v greater
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {  //if rank of u greater
    	parent[v] = u; 
    }
    else {     //similar rank
    	parent[v] = u;
    	rank[u]++; 
    }
}
```
- a and b are said to be disjoint if `parent(a)!=parent(b)`
![](img\disjoint,union,pathcompression.png)

---
# Krushkals mst
```cpp
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {   //comparator for sorting
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	sort(edges.begin(), edges.end(), comp); 
	
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
	
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}
```
![](img\mst-krushkal.png)

---
# Bridges
- edges which when taken away makes the graph into 2 diff graphs
```cpp
void dfs(vector<int> adj[],int node,int parent,int& timer,vector<int>& vis,vector<int>& tin,vector<int>& lowt){
	vis[node]=1;
	timer++;
	lowt[node]=tin[node]=timer++;
	for(auto child:adj[node]){
		if(child==parent)continue;//to not recurse back to parent
		if(!vis[child]){  //all unvisited adj nodes
			dfs(adj,child,node,timer,vis,tin,lowt);
			lowt[node]=min(lowt[child],lowt[node]);//this only changes if in dfs you have met an ancestor so it forms a cycle so you dont cut this edge
			if(lowt[child]>tin[node])
				cout<<node<<"-"<<child<<endl;
		}else
			lowt[node]=min(lowt[node],tin[child]);//visited already ancestor
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	while(e--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	vector<int> vis(n,0);
	vector<int> tin(n,0);
	vector<int> lowt(n,0);
	for(int i=0;i<n;i++){
		int timer=0;
		if(!vis[i])
		{
			dfs(adj,i,-1,timer,vis,tin,lowt);
		}
	}
}
```
![](img\bridges.png)

---
# Articulate point
```cpp
vector<int> artp(5,0); // create a hashing array to store articulate points
void dfs(vector<int> adj[],int node,int parent,int& timer,vector<int>& vis,vector<int>& tin,vector<int>& lowt){
	vis[node]=1;
	timer++;
	int children=0;
	lowt[node]=tin[node]=timer++;
	for(auto child:adj[node]){
		if(child==parent)continue;
		if(!vis[child]){
			dfs(adj,child,node,timer,vis,tin,lowt);
			lowt[node]=min(lowt[child],lowt[node]);
			if(lowt[child]>=tin[node] && parent!=-1 )  // if min timer of child > = timer of node
				artp[node]=1;
			children++; //inc individual child
		}else
			lowt[node]=min(lowt[node],tin[child]); //reached an ancestor
	}
	if(parent==-1 && children>1)artp[node]=1; //more than one individual childs and is first node

}
```
- when `low[child]==tin[node]` , `node` is the start of cycle
- only if indiv childs of first node is more than 1 i.e it can do dfs more than once and not reach the other adj nodes
- if low[child]>tin[node] there is no cycle after dfs so current node is articulate point 
- we take tin[node] in comparison as there may be inner cycles that may change low[node]  
![](img\articulatepoint.png)

---
