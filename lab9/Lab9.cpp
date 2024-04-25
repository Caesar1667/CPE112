//Pansa Intawong 66070503474
#include <bits/stdc++.h>
using namespace std;

class Graph{
int numVertices;
list<int> *adjList;
bool *visited;

public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS(int v);
    void BFS(int startNode);
};

Graph::Graph(int V){
  numVertices = V;
  adjList = new list<int>[V];
  visited = new bool[V];
}

void Graph::addEdge(int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

void Graph::BFS(int startNode){
  visited = new bool[numVertices];
  for(int i = 0; i < numVertices; i++){
    visited[i] = false;
  }

  list<int> queue;
  visited[startNode] = true;
  queue.push_back(startNode);

  list<int>::iterator i;
  while(!queue.empty()){
    int currentNode = queue.front();
    cout << currentNode << " ";
    queue.pop_front();
    for(i = adjList[currentNode].begin(); i != adjList[currentNode].end(); ++i){
      int adjVertex = *i;
      if(!visited[adjVertex]){
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::DFS(int v){
  visited[v] = true;
  list<int> adjLists = adjList[v];
  cout << v << " ";

  list<int>::iterator i;
  for(i = adjLists.begin(); i != adjLists.end(); ++i){
    if(!visited[*i]){
      DFS(*i);
    }
  }
}

int main(){
  int num;
  cin >> num;
  Graph g(num);

  for(int i = 0; i < num; i++){
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v);
  }
  int start;
  cin >> start;
  g.DFS(start);
  cout << endl;
  g.BFS(start);
  return 0;
}