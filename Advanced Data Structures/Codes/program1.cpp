#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
template<class dynamic>
class Node
{
    public:
    dynamic data;
    Node *left, *right;
};
template<class dynamic>
Node<dynamic> *create_node(dynamic element)
{
    Node<dynamic> *tempNode;
    tempNode = new Node<dynamic>;
    tempNode->data = element;
    tempNode->left = NULL;
    tempNode->right = NULL;
    return tempNode;
}
template<class dynamic>
Node<dynamic> *insert(Node<dynamic>* rootNode, dynamic element)
{
    int error;
    Node<dynamic>* tempNode;
    tempNode = create_node(element);
    if (rootNode == NULL)
    {
        rootNode = tempNode;
        cout<<"\n::::Data added successfully!";
        return rootNode;
    }
    else
    {
        try
        {
            do
            {
                if(rootNode->data > element)
                {
                    if (rootNode->left == NULL)
                    {
                        rootNode->left = tempNode;
                        break;
                    }
                    else
                    {
                        rootNode = rootNode->left;
                        continue;
                    }
                }
                else if (rootNode->data < element)
                {
                    if (rootNode->right == NULL)
                    {
                        rootNode->right = tempNode;
                        break;
                    }
                    else
                    {
                        rootNode = rootNode->right;
                        continue;
                    }
                }
                else
                {
                    throw error;
                }
            } while (true);
            cout<<"\n::::Data added successfully!\n";
        }
        catch(const int error)
        {
            std::cerr << "\n::::Element already present!" << '\n';
        }
    }
}
template<class dynamic>
int search(Node<dynamic> *tempNode, dynamic element)
{
    int pos = 0;
    do
    {
        if (tempNode->data == element)
            return true;
        else if (tempNode->data > element)
        {
            tempNode = tempNode->left;
        }
        else
        {
            tempNode = tempNode->right;
        }
    } while (tempNode != NULL);
    return false;
}
template<class dynamic>
void inorderdisplay(Node<dynamic> *tempNode)
{
    if(tempNode != NULL)
    {
        inorderdisplay(tempNode->left);
        cout<<"("<<tempNode->data<<")"<<"-";
        inorderdisplay(tempNode->right);
    }
    return;
}
template<class dynamic>
int minimum(Node<dynamic>* tempNode)
{
    while (tempNode->left != NULL)
        tempNode = tempNode->left;
    return tempNode->data;
}
template<class dynamic>
int depth(Node<dynamic> *tempNode)
{
    if (tempNode != NULL)
        return (((depth(tempNode->left)) > (depth(tempNode->right))) ? (depth(tempNode->left)) : (depth(tempNode->right))) +1;
    return 0;
}
template<class dynamic>
void mirror(Node<dynamic> *tempNode)
{
    Node<dynamic> *tempNode_1 =NULL;
    if(tempNode!=NULL)
    {
        mirror(tempNode->left);
        mirror(tempNode->right);
        tempNode_1 = tempNode->left;
        tempNode->left = tempNode->right;
        tempNode->right = tempNode_1;
    }
    return;
}
template<class dynamic>
void stepwisedisplay(Node<dynamic> *tempNode)
{
    queue<Node<dynamic>*> tempQueue;
    tempQueue.push(tempNode);
    int height = depth(tempNode), nodesCount = 1, count = 0, x =0;
    for (int i = 0; i < height; i++)
        nodesCount = nodesCount*2;
    nodesCount -= 1;
    while (!tempQueue.empty() && nodesCount != 0)
    {
        for (int i = 1; i < height; i++)
        {
            cout<<"\t";
        }
        tempNode = tempQueue.front();
        if (tempNode == NULL)
        {
            cout<<"Null\t";
            tempQueue.push(NULL);
            tempQueue.push(NULL);
            tempQueue.pop();
        }
        else
        {
            cout<<"("<<tempNode->data<<")"<<"\t";
            tempQueue.pop();
            if(tempNode->left != NULL)
        