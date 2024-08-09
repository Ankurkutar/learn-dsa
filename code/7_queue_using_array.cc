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
            if(queueFull()){
                cout<<"Queue is Overflow: "<<endl;
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
            if(queueEmpty()){
                cout<<"Queue is Underflow: "<<endl;
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
            if(queueEmpty()){
                cout<<"Queue is Underflow: "<<endl;
                return;
            }

            cout<<"Element are: "<<endl;
            for(int i =front; i<=rear; i++){
                cout<<queue[i]<<" ";
            }
        }

        void queueTopElement(){
            if(queueEmpty()){
                cout<<"Queue is Empty: "<<endl;
                return;
            }

            cout<<"Last Element is: "<<queue[rear];
        }

        void queueElement(){
            if(queueEmpty()){
                cout<<"Queue is Empty: "<<endl;
                return;
            }

            cout<<"Total Element in the Queue: "<<rear - front + 1<<endl;
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

        void queueBottomElement(){
            if(queueEmpty()){
                cout<<"Queue is Empty: "<<endl;
                return;
            }

            cout<<"first Element is: "<<queue[front];
        }

        void duplicateElement(){
            if(queueEmpty()){
                cout<<"Queue is Empty: "<<endl;
                return;
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
        cout << "8. Total Element in the Queue \n";
        cout << "9. Check duplicate Element in the Queue \n";
        cout << "10. Exit\n";
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
        case 4:
            q.queueBottomElement();
            break;
        case 5:
            q.queueTopElement();
            break;
        case 6:
            q.isEmpty();
            break;
        case 7:
            q.isFull();
            break;
        case 8:
            q.queueElement();
            break;
        case 9:
            q.duplicateElement();
            break;
        case 10:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}