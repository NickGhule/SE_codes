/*
Incase of rolling back this code from Array implementation to BST

commit 53d7edc98667fd23d1105c88a9918c0d98374df4
Author: NickGhule <56317799+NickGhule@users.noreply.github.com>
Date:   Sat May 2 19:39:08 2020 +0530

    Sets partially implemented using BST
*/

#include <iostream>
using namespace std;

#define max_size 100
// SET :: START >>>>>>>>>>>>>>>>>>

template<class dynamic>
class Set {
    dynamic *dataArray;
    int lastIndex;
    public:

    Set();
    void print();
    bool insert(dynamic);
    bool remove(dynamic);
    int size();
    bool ispresent(dynamic);
    dynamic *begin();
    dynamic *end();
    Set<dynamic> __intersection(Set<dynamic> &);
    Set<dynamic> __union(Set<dynamic> &);
    Set<dynamic> __difference(Set<dynamic> &);

};

template<class dynamic>
Set<dynamic>::Set() {
    dataArray = new dynamic[max_size];       // Initialisation
    lastIndex = -1;                          // stores the index where last element is present ... similar to top in stack
}

template<class dynamic>
bool Set<dynamic>::ispresent(dynamic element) {
    for (int i = 0; i <= lastIndex; i++) {
        if( dataArray[i] == element ) return 1;  //element found
    }
    return 0;       //element not found
    
}

template<class dynamic>
bool Set<dynamic>::remove(dynamic element) {
    int shiftFlag = 0;
    for (int i = 0; i < this->size(); i++) {
        if( dataArray[i] == element ) {
            lastIndex--;                //decrement top as we want to delete
            shiftFlag = 1;              //sets shiftflag to shift all other elements to left
        }
        if (shiftFlag) {                // if shiftflag is one shift element to left this will remove overlap the elemnt we want to delete
            dataArray[i] = dataArray[i+1];
        }
    }
    if (shiftFlag) return 1; // element successfully deleted
    return 0;       //element not found
    
}


template<class dynamic>
bool Set<dynamic>::insert(dynamic element) {
    if (!ispresent(element)) {
        dataArray[++lastIndex] = element;    // first increment the last index (top) and then insert
        return 1; //successfully inserted
    }
    return 0; 
}

template<class dynamic>
int Set<dynamic>::size() {
    return lastIndex + 1;
}

template<class dynamic>
Set<dynamic> Set<dynamic>::__intersection(Set<dynamic> &otherSet) {
    Set<dynamic> intersectionSet;
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < otherSet.size(); j++) {
            if(this->dataArray[i] == otherSet.dataArray[j])         // if same element is found insert it to intersection set
                intersectionSet.insert(dataArray[i]);
        }
    }
    return intersectionSet;
}

template<class dynamic>
Set<dynamic> Set<dynamic>::__union(Set<dynamic> &otherSet) {
    Set<dynamic> unionSet;
    for (int i = 0; i < this->size(); i++) {
        unionSet.insert(this->dataArray[i]);        // add elements of 1st set
    }
    for (int i = 0; i < otherSet.size(); i++) {
        unionSet.insert(otherSet.dataArray[i]);     //add elements of 2nd set to union set ... duplicates will not be added defined in insert()
    }
    return unionSet;
}

template<class dynamic>
Set<dynamic> Set<dynamic>::__difference(Set<dynamic> &otherSet) {
    int presentFlag = 0;
    Set<dynamic> differenceSet;
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < otherSet.size(); j++) {
            if(this->dataArray[i] == otherSet.dataArray[j]){
                presentFlag = 1;            // set if element is present in other set
                break;
            }
        }
        if (!presentFlag) differenceSet.insert(dataArray[i]);  // if element is not present in other set insert
    }
    return differenceSet;
}

template<class dynamic>
void Set<dynamic>::print() {
    cout<<" { ";
    for (auto i = this->begin(); i< this->end(); i++) {         // use of behin and end iterators
        cout<<*i<<", ";
    }

    // for (int i = 0; i < this->size(); i++) {
    //     cout<<dataArray[i]<<", ";
    // }
    cout<<"} \n";
}

template<class dynamic>
dynamic* Set<dynamic>::begin() {
    return dataArray;          // 0th position or address of 1st element of array is returned
}

template<class dynamic>
dynamic* Set<dynamic>::end() {
    dynamic* addr = &dataArray[lastIndex];
    return ++addr;          // last +1  position or address of next to last element of array is returned
}


// SET :: END <<<<<<<<<<<<<<<<<<

// Driver Function
// MAIN :: START >>>>>>>>>>>>>>>>
int main(int argc, char const *argv[]) {
    
    int choice = 1, element;
    while (choice) {
        Set<int> set_A, set_B;      // defined in while so that sets will reset to empty while entering next set of inputs
        while(choice) {
            cout<<" Enter Element for Set A :: ";
            cin>>element;
            if ( !set_A.insert(element)) {
                cout<<"Element Already Present! ";
            }
            cout<<"\n Do you want to add more? (press 1 to Add / 0) :: ";
            cin>>choice;
        }
        choice = 1;
        while(choice) {
            cout<<" Enter Element for Set B :: ";
            cin>>element;
            if (!set_B.insert(element)) {
                cout<<"Element Already Present! ";
            }
            cout<<"\n Do you want to add more? (press 1 to Add / 0) :: ";
            cin>>choice;
        }
        while (choice - 4)
        {
            cout<<"\n\n***************** Sets *****************\n";
            cout<<"\nSet A :: ";
            set_A.print();
            cout<<"\nSet B :: ";
            set_B.print();
            cout<<"\n 1. Intersection ";
            cout<<"\n 2. Union ";
            cout<<"\n 3. Difference ";
            cout<<"\n 4. Exit ";
            cout<<"\n  Enter Your Choice :: ";
            cin>>choice;

            switch (choice)
            {
            case 1:
                cout<<"Intersection :: ";
                set_A.__intersection(set_B).print();
                break;

            case 2:
                cout<<"Union ::";
                set_A.__union(set_B).print();
                break;

            case 3:
                cout<<"Difference ::";
                set_A.__difference(set_B).print();
            
            default:
                cout<<"Try Again!";
                break;
            }
            system("pause");
        }

        cout<<"Do you want to exit or continue with next set of inputs ? ( press 0 to exit else 1) ::";
        cin>>choice;
        
        
    }
    
    

    return 0;
}

