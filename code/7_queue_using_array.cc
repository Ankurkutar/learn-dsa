#include<iostream>
using namespace std;
#define MAX 1000


class Queue{
    private:
        int front, rear;
    public:
        int queue[MAX];
        Queue(){
            front = -1;
            rear = -1;
        }

        void enqueue(int data){
            if(isFull()){
                return;
            }
            if(front == -1 && rear == -1){
                front  = 0;
                rear = 0;
                queue[rear] = data;
            }else{
                queue[++rear] = data;
            }
            cout<<"Element Inserted: "<<data<<endl;
        }

        void dequeue(){
            if(isEmpty()){
                return;
            }
            if(front == rear){
                front = -1;
                rear = -1;
            }

            cout<<"Element deleted: "<<queue[front]<<endl;
            front++;
        }

        void display(){
            if(isEmpty()){
                return;
            }

            cout<<"Element are: "<<endl;
            for(int i =0; i<=rear; i++){
                cout<<queue[i]<<" ";
            }
        }

        bool isEmpty() {
            if (front == -1) {
                cout<<"Queue is Empty: "<<endl;
            } else {
                cout<<"Queue is not Empty: "<<endl;
            }
        }

        bool isFull() {
            if (rear == MAX - 1) {
                cout<<"Queue is Full: "<<endl;
            } else {
                cout<<"Queue is not Full: "<<endl;
            }
        }

        bool queueEmpty() {
            if (front == -1) {
                return true;
            } else {
                return false;
            }
        }

        bool queueFull() {
            if (rear == MAX - 1) {
                return true;
            } else {
                return false;
            }
        }
};


int main()
{
    Queue q;
    int choice, value;

    while (1)
    {
         cout << "\n\n********* Queue Operations Menu *********\n";
        cout << "Choose one option from the following list ...\n";
        cout << "===============================================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Front Element\n";
        cout << "5. Rear Element\n";
        cout << "6. Queue is Empty\n";
        cout << "7. Queue is Full\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push into the stack: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        // case 4:
        //     s.stackBottomElemnt();
        //     break;
        // case 5:
        //     s.stackEmpty();
        //     break;
        // case 6:
        //     s.stackFull();
        //     break;
        // case 7:
        //     s.stackSize();
        //     break;
        // case 8:
        //     s.stackCurrentSize();
        //     break;
        // case 9:
        //     s.print();
        //     break;
        // case 10:
        //     s.totalElement();
        //     break;
        case 11:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}