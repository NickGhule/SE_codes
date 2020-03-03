#include <iostream>
using namespace std;
class Contact
{
    public:
        int number;
        string name;
        Contact* next;
};
Contact *createcontact(int phoneNumber, std::string Name)
{
    Contact* temp;
    temp = new Contact;
    temp->number = phoneNumber;
    temp->name = Name;
    temp->next = NULL;
    return temp;
}
int hashfunction(int data)
{
    return data % 10;
}
void insert(Contact *tempArr[], int phoneNumber, std::string Name)
{
    int key = hashfunction(phoneNumber);
    Contact *temp = tempArr[key], *prev = temp;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(prev != NULL)
        prev->next = createcontact(phoneNumber, Name);
    else
        tempArr[key] = createcontact(phoneNumber, Name);
}
Contact *searchcontact(Contact *tempArr[],int phoneNumber)
{
    int key = hashfunction(phoneNumber);
    Contact *temp = tempArr[key];
    while(temp->number != phoneNumber && temp != NULL)
        temp = temp->next;
    if(temp!= NULL)
        return temp;
    return NULL;
}
void display(Contact **tempArr)
{
    Contact *temp ;
    for (int i = 0; i < 10; i++)
    {
        temp = tempArr[i];
        cout<<i<<"::";
        while (temp != NULL)
        {
            cout<<temp->number<<" : "<<temp->name<<" -- ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
void deletecontact(Contact **tempArr,int phoneNumber)
{
    int key = hashfunction(phoneNumber);
    Contact *temp = tempArr[key], *prev;
    while(temp->number != phoneNumber && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == tempArr[key])
    {
        tempArr[key] == tempArr[key]->next;
        free(temp);
    }
    else if(temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        cout<<"\nnot present";
    }
}
int main(int argc, const char** argv)
{
    int number, ch=1;
    string name;
    Contact *tempArr[10];
    for (int i = 0; i < 10; i++)
    {
        tempArr[i]= NULL;
    }
    while(ch)
    {
        cout<<"\n********PhoneBook********";
        cout<<"\n0. Exit";
        cout<<"\n1. Insert Contact";
        cout<<"\n2. Delete Contact";
        cout<<"\n3. Search Contact";
        cout<<"\n4. Display All";
        cout<<"\n   Enter your Choice ::";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\n Enter Name:: ";
            cin>>name;
            cout<<"\n Enter Number ::";
            cin>>number;
            insert(tempArr, number, name);
            cout<<"\n Contact :: "<<name<<" : " <<number<<" added successfully!";
            break;
        case 2:
            cout<<"\n Enter Number ::";
            cin>>number;
            deletecontact(tempArr,number);
            cout<<"\nContact "<<number<<" deleted successfully!";
            break;
        case 3:
            cout<<"\n Enter Number ::";
            cin>>number;
            cout<<"\n"<<number<<" :: "<<searchcontact(tempArr, number)->name;
            break;
        case 4:
            cout<<"****** contact list ******";
            display(tempArr);
        case 0:
            cout<<"******** Exit ********";
        default:
            break;
        }
    }
    return 0;
}
