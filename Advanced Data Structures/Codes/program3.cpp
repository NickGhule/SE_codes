#include <iostream>
using namespace std;

#define maxsize 10

class Node
{
    public:
        int vertex;
        Node* next;
};

Node* createnode(int vertex)
{
    Node* temp = new Node;  
    temp->next = NULL;
    temp->vertex = vertex;
    return temp;
}
int* createadjmatrix(int vertices)
{
    int *adjmatrix[maxsize][maxsize];
    adjmatrix = new int[10][80];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<<"\nisEdge ("<<i<<","<<") :: ";
            cin>>adjmatrix[i][j];
        }
    }
    return adjmatrix;
}
void showadjmatrix(int *arr, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        cout<<i;
        for (int j = 0; j < vertices; j++)
        {
            cout<<"\t"<<arr[i][j];
        }
        cout<<endl;
    }
    
}
Node* createadjlist(int *arr, int vertices)
{
    Node *headarr = new Node[maxsize];
    Node* temp = NULL;
    for (int i = 0; i < vertices; i++)
    {   
        temp = headarr[i];
        for (int j = 0; j < vertices; j++)
        {
            if (arr[i][j])
            {
                temp->next = createnode(j);
                temp = temp->next;
            }   
        }   
    }
}

void showadjlist(Node* headarr, int vertices)
{
    Node* temp =NULL;
    for (int i = 0; i < vertices; i++)
    {
        temp = headarr[i];
        cout<<endl<<headarr[i]->vertex<<" :: ";
        while(temp != NULL)
        {
            cout<<" -> "<<temp->vertex;
        }
    }
    
}
int main()
{
    int arr[]={1,2,3,4,5,6};
    showadjmatrix(arr,6);
}