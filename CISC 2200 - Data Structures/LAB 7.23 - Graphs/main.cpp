#include <iostream>
using namespace std;
#include "graph.h"
int main()
{
   Graph theGraph;
   int vertextCount;
   cin>>vertextCount;
   char vertex;
   for (int i=0; i<vertextCount; i++)
   {
      cin>>vertex;
      theGraph.addVertex(vertex);
   }
   int edges;
	cin>> edges;

   int from,to;
   for (int i=0; i<edges; i++)
   {
      cin>>from;
      cin>>to;
      theGraph.addEdge(from,to);
   }

   cout<<"Vertices: ";
   theGraph.displayVertices();
   cout<<endl;
   cout<<"Edges:"<<endl;
   theGraph.displayEdges();

   cout<<"\nRemoving Vertex 0 Edges:"<<endl;
   cout<<"Removing Vertex ";
   theGraph.displayVertex(0);
   cout<<" Edges:"<<endl;

   theGraph.removeVertexEdges(0);
   cout<<endl;
   cout<<"Edges:"<<endl;
   theGraph.displayEdges();
}