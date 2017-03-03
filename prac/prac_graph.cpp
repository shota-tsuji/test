#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Vertex;

class Edge
{
public:
  Edge( Vertex *org, Vertex *dest, int dist)
  {
    origin = org;
    destination = dest;
    distance = dist;
  }

  Vertex* getOrigin() { return origin; }
  Vertex* getDestination() { return destination; }
  int getDistance() { return distance; }
private:
  Vertex* origin;
  Vertex* destination;
  int distance;
};

class Vertex
{
public:
  Vertex( string id )
  {
    name = id;
  }

  void addEdge( Vertex *v, int dist )
  {
    Edge newEdge( this, v, dist );
    edges.push_back( newEdge );
  }

  void printEdges()
  {
    cout << name << ":" << endl;
    for ( int i = 0; i < edges.size(); i++ )
    {
      Edge e = edges[i];
      cout << e.getDestination()->getName() << " - " << e.getDistance() << endl;
    }
    cout << endl;
  }

  string getName() { return name; }
  vector<Edge> getEdges() { return edges; }

private:
  string name;
  vector<Edge> edges;
};

class Graph
{
public:
  Graph() {}

  void insert( Vertex *v)
  {
    vertices.push_back( v );
  }

  void printGraph()
  {
    for ( int i = 0; i < vertices.size(); i++ ) { vertices[i]->printEdges(); }
  }
private:
  vector<Vertex*> vertices;
};

int main()
{
  Graph g;

  Vertex v1 = Vertex( "Seattle" );
  Vertex v2 = Vertex( "Portland" );
  Vertex v3 = Vertex( "Everett" );
  Vertex v4 = Vertex( "Lynnwood" );
  Vertex v5 = Vertex( "Northgate" );
  Vertex v6 = Vertex( "Bellevue" );
  Vertex v7 = Vertex( "Arlington" );
  Vertex v8 = Vertex( "Bellingham" );
}
