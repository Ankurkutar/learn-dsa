#include<iostream>
using namespace std;

class Sample
{
    public:
     int a, b;
     
    Sample(){
        a= 10;
        b= 20;
    }
};

int main(){
    Sample obj;
    cout<<obj.a<<endl;
    cout<<obj.b<<endl;

    return 0;

}