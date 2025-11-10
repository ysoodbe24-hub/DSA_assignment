#include <iostream>
using namespace std;

#define SIZE 100

class Queue
{
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    bool isFull()
    {
        return rear == SIZE - 1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }
        arr[++rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return -1;
        }
        return arr[front++];
    }

    int size()
    {
        return (rear - front + 1);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY!\n";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void interleave()
    {
        int n = size();
        if (n % 2 != 0)
        {
            cout << "Queue size must be even to interleave!\n";
            return;
        }

        int mid = n / 2;
        int firstHalf[mid];

        for (int i = 0; i < mid; i++)
        {
            firstHalf[i] = dequeue();
        }

        int originalRear = rear;
        for (int i = 0; i < mid; i++)
        {
            enqueue(firstHalf[i]);
            enqueue(dequeue());
        }
    }
};

int main()
{
    Queue q;
    int n, value;

    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.enqueue(value);
    }

    cout << "\nOriginal Queue: ";
    q.display();

    q.interleave();

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
