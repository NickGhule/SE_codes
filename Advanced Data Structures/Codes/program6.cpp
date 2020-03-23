#include <iostream>
#include <string.h>
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
};

Node* createnode(string word, string meaning)
{
    Node* temp;
    temp = new Node;
    temp->word = word;
    temp->meaning = meaning;
    return temp;
}
class Dict
{
    Node *Dictionary[26];
    public:
    Dict()
    {
        for (int i = 0; i < 26; i++)
        {
            Dictionary[i] = NULL;
        }
        
    }
    void insert(string word, string meaning)
    {
        int flag = 0; 
        if(Dictionary[uppercase(word[0])-65] == NULL)
        {
            Dictionary[uppercase(word[0])-65] = createnode(word, meaning);
        }
        else
        {
            for(int i = uppercase(word[0])-65+1; uppercase(word[0])-65 != i;i++, i %= 26)
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
            cout<<"\n"<<i<<" :: ";
            if(Dictionary[i] != NULL)
                cout<<Dictionary[i]->word<<" :: "<<Dictionary[i]->meaning;
        }
    }
    void deleteword(string word)
    {
        if(Dictionary[uppercase(word[0])-65] != NULL)
        {
            for(int i = uppercase(word[0])-65;  uppercase(word[0])-65-1 != i;i++, i %= 26 )
            {
                if(Dictionary[i] != NULL)
                {
                    if(word.compare(Dictionary[i]->word) == 0)
                    {
                        Node* temp = Dictionary[i];
                        Dictionary[i] = NULL;
                        delete(temp);
                        cout<<"\nWord Deleted";
                        return;
                    }
                }
                
            }
        }
        cout<<"\n Word not present";
    }
    void search(string word)
    {
        if(Dictionary[uppercase(word[0])-65] != NULL)
        {
            for(int i = uppercase(word[0])-65;  uppercase(word[0])-65-1 != i;i++, i %= 26 )
            {
                if(Dictionary[i] != NULL)
                {
                    if(word.compare(Dictionary[i]->word) == 0)
                    {
                        cout<<"\n"<<Dictionary[i]->word<<" :: "<<Dictionary[i]->meaning;
                        return;
                    }
                }
                
            }
        }
        cout<<"\n Word not present";

    }
};


int main(int argc, const char** argv) 
{
    Dict tempArr;
    string word,meaning;
    int ch;
    while(1)
    {
        cout<<"\n********** Dictionary **********";
        cout<<"\n1. Add Word";
        cout<<"\n2. Delete word";
        cout<<"\n3. Search word";
        cout<<"\n4. Show";
        cout<<"\n Enter your choice ::";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nEnter word :: ";
            cin>>word;
            cout<<"\nEnter meaning :: ";
            cin>>meaning;
            tempArr.insert(word,meaning);
            break;
        case 2:
            cout<<"\nEnter word :: ";
            cin>>word;
            tempArr.deleteword(word);
            break;
        case 3:
            cout<<"\nEnter word :: ";
            cin>>word;
            tempArr.search(word);
            break;
        case 4:
            tempArr.show();
            break;
        default:
            break;
        }
        
    }

    return 0;
}