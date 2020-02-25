#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minelement(int key[], bool mstSet[])
{
 int min = INT_MAX, min_index;
 for (int v = 0; v < 4; v++)
  if (mstSet[v] == false && key[v] < min)
   min = key[v], min_index = v;
 return min_index;
}
void printMST(int parent[], int adjmatrix[4][4])
{
 cout<<"Edge \tWeight\n";
 for (int i = 1; i < 4; i++)
  cout<<parent[i]<<" - "<<i<<" \t"<<adjmatrix[i][parent[i]]<<" \n";
}
void prims(int adjmatrix[4][4])
{
    int parent[4];
 int key[4];
 bool visited[4];
 for (int i = 0; i < 4; i++)
  key[i] = INT_MAX, visited[i] = false;
 key[0] = 0;
 parent[0] = -1; // First node is always root of MST 
 for (int count = 0; count < 4 - 1; count++)
 {
  int u = minelement(key, visited);
  visited[u] = true;
  for (int v = 0; v < 4; v++)
   if (adjmatrix[u][v] && visited[v] == false && adjmatrix[u][v] < key[v])
    parent[v] = u, key[v] = adjmatrix[u][v];
    }
    printMST(parent, adjmatrix);
}
int main(int argc, const char** argv)
{
    int adjmatrix[4][4] = {0,2,5,0,2,0,10,7,5,10,0,4,0,7,4,0};
    int visitSequence[4][2];
    prims(adjmatrix);
}
