#include <iostream>
#include <vector>
#include<iterator>
using namespace std;

class Patient
{
    static int current_token;
    int Token_no;
    int time;
    string name;
    public:
        Patient(string name, string type)
        {
            this->name = name;
            if(type == "Y" || type == "y")
                time = 30;
            else time = 15;
            Token_no = current_token++;
        }
        int get_token()
        {
            return Token_no;
        }
        string get_name()
        {
            return name;
        }
        int get_time()
        {
            return time;
        }

};

int Patient::current_token = 1;

int main(int argc, char const *argv[])
{
    Patient *pt;
    int ch, time = 0;
    string name, type;
    vector<Patient*> patient_que;
    Patient* ptr;
    while(1){
    cout<<"\n***** Welcome to Hospital *****";
    cout<<"\n1. Book Apointment";
    cout<<"\n2. Dislay Patients ";
    cout<<"\n3. Cancel Apointment";
    cout<<"\n Enter Choice";
    cin>>ch;
    switch (ch)
    {
    case 1:
        cout<<"\n Enter your Name :";
        cin>>name;
        cout<<"\n Are you a new Patient (Y/N)::";
        cin>>type;
        pt = new Patient(name,type);
        
        
        for (auto i = patient_que.begin(); i != patient_que.end(); i++)
        {
            ptr = *i;
            time += ptr->get_time();
        }
        cout<<" Apointment added! your expected time is ::"<<time<<" min";
        patient_que.push_back(pt);

        break;
    
    case 2:
        for (auto i = patient_que.begin(); i != patient_que.end(); i++)
        {
            ptr = *i;
            cout<<"\n Token ::"<<ptr->get_token()<<"\t"<<ptr->get_name(); 
        }
    default:
        break;
    }
    }


    return 0;
}
