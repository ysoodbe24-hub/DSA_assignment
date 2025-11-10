#include<iostream>
using namespace std;
#define size 5
class Queue{
    int front, rear;
    int arr[size];
    public: 
    Queue(){
        front=-1;
        rear=-1;
    }
    bool isFull(){
        return (rear==size-1);
    }
    bool isEmpty(){
        return (front==-1 || front>rear);
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front==-1) front=0;
        arr[++rear]=x;
        cout<<x<<" enqueued successfully"<<endl;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<arr[front++]<<" dequeued successfully"<<endl;
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No element to peek.\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements: ";
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    int choice, value;
    while(true){
        cout<<"1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. IsFull\n6. IsEmpty\n7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                q.isFull();
                break;
            case 6:
                q.isEmpty();
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}