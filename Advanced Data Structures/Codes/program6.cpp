#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char uppercase(char ch)
{
    if (ch>='a' && ch<='z')
        ch = ch - 32;
    return ch;
}
class Node
{
    public:
    string word;
    string meaning;
    Node* next;
};

Node* createnode(string word, string meaning)
{
    Node* temp;
    temp = new Node;
    temp->word = word;
    temp->meaning = meaning;
    temp->next = NULL;
}
class Dict
{
    Node *Dictionary[26];
    public:
    Dict()
    {
        for (int i = 0; i < 26; i++)
        {
            Dictionary[i] == NULL;
        }
        
    }
    void insert(string word, string meaning)
    {
        int flag = 0; 
        if(Dictionary[uppercase(word[0])-65] != NULL)
        {
            Dictionary[uppercase(word[0])-65] = createnode(word, meaning);
        }
        else
        {
            for(int i = uppercase(word[0])-65+1; uppercase(word[0])-65 != i; i %= 26)
            {
                if(Dictionary[i] == NULL)
                {
                    Dictionary[i] = createnode(word, meaning);
                    flag =1;
                    break;
                }
            }
            if(flag == 0)
            {
                cout<<"storage Full!";
            }
        }
    }
    void show()
    {
        for(int i = 0 ; i< 26; i++)
        {
            if(Dictionary[i] != NULL)
                cout<<Dictionary[i]->word<<Dictionary[i]->meaning;
        }
    }
};

int main(int argc, const char** argv) 
{
    Dict tempArr;
    string word,meaning;
    while(1){
    cout<<"Enter word";
    cin>>word;
    cout<<"meaning::";
    cin>>meaning;
    tempArr.insert(word,meaning);
    tempArr.show();}

    return 0;
}