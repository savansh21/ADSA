#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
struct Node
{
	int data;
	Node* link;
};

Node* top;

void push(int data)
{
	Node* temp = new Node();

	if (!temp)
	{
		cout << "\nStack Overflow";
		exit(1);
	}

	temp->data = data;

	temp->link = top;

	top = temp;
}

int isEmpty()
{
	return top == NULL;
}

int peek()
{

	if (!isEmpty())
		return top->data;
	else
		exit(1);
}

void pop()
{
	Node* temp;

	if (top == NULL)
	{
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else
	{

		temp = top;
		top = top->link;
		free(temp);
	}
}

void display()
{
	Node* temp;

	if (top == NULL)
	{
		cout << "\nStack Underflow";
		exit(1);
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{

			cout << temp->data << "-> ";

			temp = temp->link;
		}
	}
}

int main()
{
    auto start = high_resolution_clock::now();
	push(11);
	push(22);
	push(33);
	push(44);
	display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "\nTime taken by push function: "
         << duration.count() << " microseconds" << endl;


	cout << "\nTop element is "
		<< peek() << endl;
    
    start = high_resolution_clock::now();
	pop();
	pop();
	display();
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by pop function: "
         << duration.count() << " microseconds" << endl;

	cout << "\nTop element is "
		<< peek() << endl;
		
	return 0;
}

