#include<iostream>
#include<math.h>  
using namespace std;

void add();
void sub();
void mul();
void div();
void square();
void squareRoot();

int main(){
    cout<<"Welcome to My Calculator: "<<endl;
    int opr;

    do{
        cout << "Select any operation from the C++ Calculator"  
        "\n1 = Addition"  
        "\n2 = Subtraction"  
        "\n3 = Multiplication"  
        "\n4 = Division"  
        "\n5 = Square"  
        "\n6 = Square Root"  
        "\n7 = Exit"  
        "\n \n Make a choice: ";  

        cin>>opr;
        switch (opr)
        {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mul();
            break;
        case 4:
            div();
            break;
        case 5:
            square();
            break;
        case 6:
            squareRoot();
            break;
        case 7:
            exit(0);
            break;
        
        default:
            cout <<"Something is wrong..!!";  
            break;
        }
         cout <<" \n------------------------------\n";  

    }while (opr != 7);
    
    

    return 0;
}

// void inputOutput(){
//     int a , b;
// }

void add(){
    int count,number, sum =0;
    cout<<"How many number do you want to add: ";
    cin>>count;
    for(int i=1; i<=count; i++){
        cin>>number;
        sum = number + sum;
    }
    cout << "\n Sum of the numbers = "<< sum;  

}
void sub(){
    int a, b;
    cout<<"Enter Fist Number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;

    cout<<endl<<" Subtraction of the number = "<<a-b;
}
void mul(){
    int a, b;
    cout<<"Enter Fist Number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;

    cout<<endl<<" Multipliction of the number = "<<a*b;
}
void div(){
    int a, b;
    cout<<"Enter First Number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;

    while(b == 0){
        cout << "\n Divisor canot be zero\n Please enter again: ";
        cin>>b; 
    }

    cout<<endl<<" Division of the number = "<<a/b;
}
void square(){
    int a;
    cout<<"Enter Number: ";
    cin>>a;
    cout<<endl<<" Square of the number = "<<a*a;
}
void squareRoot(){
    int a;
    cout<<"Enter Number: ";
    cin>>a;
    cout<<endl<<" Square of the number = "<<sqrt(a);
}