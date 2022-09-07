#include <bits/stdc++.h>
using namespace std;

class Graph{

	list<int> *l;
	int V;

public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool directed = true){
		l[x].push_back(y);
		if(!directed){
			l[y].push_back(x);
		}
	}

	bool cycle_helper(int node, bool *visited, int parent){
		visited[node] = true;

		for(int nbr : l[node]){
			if(!visited[nbr]){
				//visit that node
				
				if(cycle_helper(nbr, visited, node)){
					return true;
				}
			}
			else if(nbr != parent){
				return true;
			}

		}
		return false;
	}

	bool contains_cycle(){

		bool *visited = new bool[V];

		for(int i=0; i<V; i++){
			visited[i] = false;
		}

		return cycle_helper(0, visited, -1);


	}

};


int main(){

	Graph g(5);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	// g.addEdge(4, 0);


	if(g.contains_cycle()){
		cout<<"Yes. The undirected graph contains cycle."<<endl;
	}
	else{
		cout<<"No. The undirected graph doesn't contain cycle."<<endl;
	}

	return 0;
}