#include <iostream>
#include <string.h>
using namespace std;
enum index_section{Book = 1, Chapter = 2, Section = 3, Subsection = 4};
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
Node<dynamic> *insert(Node<dynamic>* rootNode, dynamic element, enum index_section index)
{
    string temp_string;
    switch (index)
    {
    case 1:
        rootNode = search(rootNode, Book);
        if (rootNode != NULL)
        {
            rootNode->right = create_node(element);
            rootNode = rootNode->right;
        }
        else
        {
            rootNode = create_node(element);
        }
        return rootNode;
        break;
    case 2:
        rootNode = search(rootNode, Chapter);
        if (rootNode != NULL)
        {
            rootNode->right = create_node(element);
            rootNode = rootNode->right;
        }
        else
        {
            rootNode = create_node(element);
        }
        return rootNode;
        break;
    case 3:
        rootNode = search(rootNode, Section);
        if (rootNode != NULL)
        {
            rootNode->right = create_node(element);
            rootNode = rootNode->right;
        }
        else
        {
            rootNode = create_node(element);
        }
        return rootNode;
        break;
    case 4:
        rootNode = search(rootNode, Subsection);
        if (rootNode != NULL)
        {
            rootNode->right = create_node(element);
            rootNode = rootNode->right;
        }
        else
        {
            rootNode = create_node(element);
        }
        return rootNode;
        break;
    default:
        break;
    }
}
template<class dynamic>
Node<dynamic>* subsearch(Node<dynamic>* rootNode, dynamic searchElement)
{
    string tempStr = rootNode->data;
    while(rootNode != NULL)
        {
            if(!strcmp(tempStr, searchElement))
                break;
            rootNode = rootNode->right;
        }
        return rootNode;
}
template<class dynamic>
Node<dynamic>* search(Node<dynamic>* rootNode, enum index_section index)
{
    dynamic searchElement;
    string bookName;
    string chapterName;
    switch (index)
    {
    case 1:
        cout<<"\nEnter the Book Name ::";
        cin>>searchElement;
        rootNode = subsearch(rootNode, searchElement);
        if (rootNode == NULL)
        {
            cout<<"Sorry Book Not Present !";
            return NULL;
        }
        return rootNode;
        break;
    case 2:
        cout<<"\nEnter the Book Name ::";
        cin>>bookName;
        rootNode = subsearch(rootNode, bookName);
        if (rootNode == NULL)
        {
            cout<<"Sorry Book Not Present !";
            return NULL;
        }
        cout<<"\nEnter the Chapter Name ::";
        cin>>searchElement;
        rootNode = subsearch(rootNode, searchElement);
        if (rootNode == NULL)
        {
            cout<<"Sorry Chapter Not Present !";
            return NULL;
        }
        return rootNode;
        break;
    case 3:
        cout<<"\nEnter the Book Name ::";
        cin>>bookName;
        rootNode = subsearch(rootNode, bookName);
        if (rootNode == NULL)
        {
            cout<<"Sorry Book Not Present !";
            return NULL;
        }
        cout<<"\nEnter the Chapter Name ::";
        cin>>chapterName;
        rootNode = subsearch(rootNode, chapterName);
        if (rootNode == NULL)
        {
            cout<<"Sorry Chapter Not Present !";
            return NULL;
        }
        cout<<"\nEnter the Section Name ::";
        cin>>searchElement;
        rootNode = subsearch(rootNode, searchElement);
        if (rootNode == NULL)
        {
            cout<<"Sorry Section Not Present !";
            return NULL;
        }
        return rootNode;
        break;
    default:
        break;
    }
}
template<class dynamic>
void displayall(Node<dynamic>* rootNode)
{
    if(rootNode != NULL)
    {
        cout<<rootNode->data;
        displayall(rootNode->left);
        displayall(rootNode->right);
    }
}
int main(int argc, const char** argv)
{
    Node<string> * rootNode = NULL;
    string tempStr = "book";
    insert(rootNode,tempStr, Book);
    return 0;
}
