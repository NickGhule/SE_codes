#include <iostream>
using namespace std;
#define __max(a,b) (((a) > (b)) ? (a) : (b))
int main(int argc, const char** argv) 
{
    cout<<__max(10,20);
    return 0;
}