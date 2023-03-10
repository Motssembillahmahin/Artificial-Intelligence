#include<bits/stdc++.h>
#include<map> //to use adjacency list
using namespace std;

template<typename T> //to use int as well as string
class Graph {
  map< T,list<T> >l;
public :
    void addEdge(int x,int y){
        l[x].push_back(y);   //assume as bidirectional
        l[y].push_back(x);

    }
    void bfs(T src) {
        map<T,int> visited; //for iterating each node
        queue<T> q;   // for storage node

        q.push(src);
        visited[src] = true; //to prevent one node push another

    while(!q.empty()) {         // for travesling graph
       T node  = q.front();
       q.pop();
       cout<<node<<" ";
        for (int nbr : l[node])  //l[node] given adjcency list and neigbour
        if(!visited[nbr]){
            q.push(nbr);
            //marked that visited
            visited[nbr] = true;
        }
     }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 4);
    g.addEdge(4, 5);


    g.bfs(0);
    return 0;
}
