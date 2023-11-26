#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
struct Qnode
{

    int data;

    Qnode *next;

    Qnode(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
private:
    Qnode *front;
    Qnode *rear;

public:
    Queue(){
        front = rear = NULL;
    }

    void push(int data){

        Qnode *newNode = new Qnode(data);

        if(front == NULL){
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        return;
    }

    void pop()
    {

        if(front == NULL){
            cout << "\nQueue is empty ...... ";
            return;
        }

        if(front == rear){
            front = rear = NULL;
            return;
        }

        Qnode *temp = front;
        front = front->next;

        delete temp;

        return;
    }

    void print(){

        Qnode *temp = front;

        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    Queue q1;

    auto start = high_resolution_clock::now();
    q1.push(23);
    q1.push(2);
    q1.push(4);
    q1.push(8);
    q1.push(10);
    q1.push(43);
    q1.push(0);
    q1.push(32);
    q1.push(14);
    q1.push(67);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by push function: "
         << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();

    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by pop function: "
         << duration.count() << " microseconds" << endl;
}