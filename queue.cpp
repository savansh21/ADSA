#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
class queue
{
private:
    /* data */
    int *arr;
    int size;
    int front;
    int rear;

public:
    queue(int n){
        size = n;
        arr = new int[n];
        front = rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout << "\nQueue is full";
            return;
        }

        arr[rear] = data;
        rear++;
        return;
    }

    int pop(){
        if(rear == 0){
            cout << "\nQueue is empty";
            return -1;
        }
        int ans = arr[front];
        if (front == rear)
        {
            rear = front = 0;
        }

        else{
            front++;
        }

        return ans;
    }
    int frontele(){
        if (rear == 0){
            cout << "\nQueue is empty";
            return -1;
        }

        return arr[front];
    }
};

int main()
{
    queue q1(10);
    auto start = high_resolution_clock::now();
    q1.push(23);
    q1.push(2);
    q1.push(4);
    //cout << "\nfront element is : " << q1.frontele();
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