#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

template<typename T>
class Graph{

	unordered_map<T, list<pair<T, int>>> l;

public:
	void addEdge(T x, T y, int cost){
		l[x].push_back(make_pair(y,cost));
		l[y].push_back(make_pair(x,cost));
	}

	void dijkstra(T src){
		map<T, int> distance;
		for(auto p : l){
			distance[p.first] = INF;
		}
		distance[src] = 0;

		//s<distance, node>
		set<pair<int, T>> s;
		s.insert(make_pair(0, src));

		while(!s.empty()){

			//fetch top node
			auto top = *(s.begin());

			int nodeDis = top.first;
			T nodeName = top.second;

			//remove top element
			s.erase(top);

			//traverse on neighbours
			for(auto p : l[nodeName]){
				if(nodeDis + p.second < distance[p.first]){
					auto record = s.find(make_pair(distance[p.first], p.first));

					//if record not found
					if(record != s.end()){
						s.erase(record);
					}

					//update distance and insert in set
					distance[p.first] = nodeDis + p.second;
					s.insert(make_pair(distance[p.first], p.first));
				
				}
			}


		}

		for(auto d : distance){
			cout<<src<<" --> "<<d.first<<" : "<<d.second<<endl;
		}


	}

};

int main(){

	int t=0;
	cin>>t;
	while(t--){

		Graph<int> g;
		int node=0, edge=0;
		cin>>node>>edge;
		// assert(node >= 1 and node <= 1LL*(edge*(edge-1))/2);

		for(int i=0; i<edge; i++){
			
			int x=0, y=0, cost=0;
			cin>>x>>y>>cost;
			// assert(x>=1 and x<=node);
			// assert(y>=1 and y<=node);

			g.addEdge(x, y, cost);

		}

		int src=0;
		cin>>src;
		g.dijkstra(src);
		cout<<endl;
		cout<<endl;
		cout<<endl;


	}


	return 0;
}