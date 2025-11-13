#include <iostream>
#include <vector>
using namespace std;

class Vertex
{
    public:
    char label;
    bool wasVisited;

    Vertex(char lab)
    {
        label = lab;
        wasVisited = false;
    }

};
class Graph
{
    private:
    static const int MAX_VERTS = 20;
    vector <Vertex> vertexList;
    int adjMat[MAX_VERTS][MAX_VERTS];

    public:
    Graph()
    {
        for (int r=0; r<MAX_VERTS; r++)
            for (int c=0; c<MAX_VERTS; c++)
                adjMat[r][c]=0;
    }// end constructor

    void addVertex(char lab)
    {
        Vertex vrtx(lab);
        vertexList.push_back(vrtx);
    }

    void addEdge(int start, int end)
    {
        adjMat[start][end]=1;
    }

    void displayVertex(int v)
    {
        cout<<vertexList.at(v).label;
    }
    void displayVertices(){
        int n = static_cast<int>(vertexList.size());
        for (int i = 0; i < n; i++){
            cout << vertexList.at(i).label;
        }
        cout << endl;
    }
    void displayEdges(){
        int n = static_cast<int>(vertexList.size());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adjMat[i][j] != 0) {
                    cout << vertexList.at(i).label << "--" << vertexList.at(j).label << endl;
                }
            }
        }
        cout << endl;
    }
    void removeVertexEdges(int v){
        int n = static_cast<int>(vertexList.size());
        if (v < 0 || v >= n) return;
        for (int i = 0; i < n; ++i) {
            adjMat[v][i] = 0; 
            adjMat[i][v] = 0;
        }
    }
};//end class Graph
