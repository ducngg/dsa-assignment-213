class Graph
{
private:
	int V;
	Adjacency *adj;

public:

	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        list<int> q;
        bool* visited=new bool[V];
        bool* tobevisited=new bool[V];
        
        visited[0]=0;
        tobevisited[0]=0;
        
        Adjacency* OUTPUT=new Adjacency;
        
        q.push_back(v);
        tobevisited[v]=true;
        
        while(!q.empty())
        {
            int n=q.front();
            OUTPUT->push(n);
            visited[n]=true;
            tobevisited[n]=false;
            
            for(int i=0;i<adj[n].getSize();i++)
            {
                if(!visited[adj[n].getElement(i)] && !tobevisited[adj[n].getElement(i)])
                {
                    q.push_back(adj[n].getElement(i));
                    tobevisited[adj[n].getElement(i)]=true;
                }
            }
            
            q.pop_front();
        }
        
        delete[] visited;
        delete[] tobevisited;
        
        return OUTPUT;
	}
};

////////////////
////////////////
////////////////

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	void DFS(int v, bool*& visited, Adjacency*& OUTPUT){
        visited[v] = true;
        OUTPUT->push(v);
 
        for(int i=0;i<adj[v].getSize();i++)
        {
            if(!visited[adj[v].getElement(i)])
            {
                DFS(adj[v].getElement(i),visited,OUTPUT);
            }
        }
	}
	
	Adjacency *DFS(int v)
    {
        bool* visited=new bool[V];
        Adjacency* OUTPUT=new Adjacency;
        
        DFS(v,visited,OUTPUT);
        
        delete[] visited;
        return OUTPUT;
	}
};

////////////////
////////////////
////////////////



////////////////
////////////////
////////////////



////////////////
////////////////
////////////////



////////////////
////////////////
////////////////



class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    //Heling functions
    void topologicalSort(int v, bool*& visited, list<int>& st){
        visited[v] = true;
 
        for(int i=0;i<adj[v].getSize();i++)
        {
            if(!visited[adj[v].getElement(i)])
            {
                topologicalSort(adj[v].getElement(i),visited,st);
            }
        }
        
        st.push_back(v);
	}
    void topologicalSort(){
        //TODO
        list<int> st;
        bool* visited=new bool[V];
        for(int i=0;i<V;i++) visited[i]=false;
        
        for(int i=0;i<V;i++) if(!visited[i]) topologicalSort(i,visited,st);
        
        while(!st.empty())
        {
            int n=st.back();
            st.pop_back();
            cout<<n<<" ";
        }
        
        delete[] visited;
    }
};