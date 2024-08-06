#include <iostream>
using namespace std;

#define MAX 4

class Stack
{
private:
    int top;

public:
    int stack[MAX];       // Maximum size of Stack
    Stack() { top = -1; } // Constructor initializes top

    // function start from here

    void push(int data)
    {
        if(isFull()){
            cout<<"Stack is Overflow:"<<endl;
            return;
        }

        stack[++top] = data;
        cout<<"Element Inserted: "<<data<<endl;
    }

    void pop()
    {
        if(isEmpty()){
            cout<<"Stack is UnderFlow: "<<endl;
            return;
        }
        cout<<"Element deleted: "<<stack[top]<<endl;
        stack[--top];
    }

    void peek()
    {
        if(isEmpty()){
            cout<<"Stack is Underflow: "<<endl;
            return;
        }

        cout<<"Peek element is: "<<stack[top];
    }

    void stackBottomElemnt(){
        if(isEmpty()){
            cout<<"Stack is Empty: "<<endl;
            return;
        }

        cout<<"Element is: "<<stack[0]<<endl;
    }

    bool isEmpty() {
        if (top == -1) {
            // cout << "Stack is Empty." << endl;
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
         if (top == MAX - 1) {
            // cout << "Stack is Full." << endl;
            return true;
        }else{
            return false;
        }
    }
    bool stackEmpty() {
        if (top == -1) {
            cout << "Stack is Empty." << endl;
            return true;
        }else{
            cout << "Stack is not Empty." << endl;
            return false;
        }
    }

    bool stackFull(){
         if (top == MAX - 1) {
            cout << "Stack is Full." << endl;
            return true;
        }else{
            cout << "Stack is not Full." << endl;
            return false;
        }
    }
    
    void print(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return;
        }

        cout<<"Element are: "<<endl;
        for(int i=0; i<=top; i++){
            cout<<stack[i]<<" ";
        }
    }

    void stackSize(){
        cout<<"Stack Size: "<<MAX;
        return;
    }

    void stackCurrentSize(){
        cout<<"Stack current size out of "<<MAX<<" is "<<top+1;
        return;
    }

    void totalElement(){
        if(isEmpty()){
            cout<<"Stack is Empty: "<<endl;
            return;
        }
        cout<<"Total element inside stack: "<<top+1;
    }
    
};

int main()
{
    Stack s;
    int choice, value;

    while (1)
    {
        cout << "\n\n********* Stack Operations Menu *********\n";
        cout << "Choose one option from the following list ...\n";
        cout << "===============================================\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek/Top Element\n";
        cout << "4. Lower Element\n";
        cout << "5. Stack is Empty\n";
        cout << "6. Stack is Full\n";
        cout << "7. Stack Total Size\n";
        cout << "8. Stack Current Size\n";
        cout << "9. Stack Print\n";
        cout << "10. Stack Total Element\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push into the stack: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.stackBottomElemnt();
            break;
        case 5:
            s.stackEmpty();
            break;
        case 6:
            s.stackFull();
            break;
        case 7:
            s.stackSize();
            break;
        case 8:
            s.stackCurrentSize();
            break;
        case 9:
            s.print();
            break;
        case 10:
            s.totalElement();
            break;
        case 11:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
