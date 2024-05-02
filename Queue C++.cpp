#include <iostream>
using namespace std;
struct node
{
	int Data;
	node* next;
};

node* current = NULL;
node* Front = NULL;
node* Rear = NULL;

void enqueue(int newdata)
{
	node* current = new node();
	current->Data = newdata;
	if (Rear != NULL)
	{
		Rear->next = current;
		Rear = current;
	}
	else
	{
		Front = current;
		Rear = current;
	}
	Rear->next = NULL;
}
void dequeue()
{
	if (Front != NULL)
	{
		current = Front;
		Front = Front->next;
		delete current;
	}
	else { cout << "No element Found to be dequeued" << endl; }
}
void dequeueAll()
{
	while (Front != NULL)
	{
		current = Front;
		Front = Front->next;
		delete current;
	}
	Rear = Front = NULL;
}
void display()
{
	if (Front != NULL)
	{
		current = Front;
		while (current != NULL)
		{
			cout << current->Data << endl;
			current = current->next;
		}
	}
	else { cout << "There is no data in the queue\n"; }
}
void app()
{
	/*
		op -> operation
		c -> confirm
		e -> enqueue node
		ao -> another operation
		s -> starter app
	*/
	int op, c, e, ao, s;
	cout << "--- Welcome to queue implementation---\n";
	do
	{
		cout << "Choise what do you want\n";
		cout << "Enqueue -> (1)\n";
		cout << "Dequeue an Elements -> (2) \n";
		cout << "Dequeue All Elements -> (3)\n";
		cout << "Display -> (4)\n";
		cout << "Exit -> (5)\n";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Enter value do you want to enqueue\n";
			cin >> e;
			enqueue(e);
			break;
		case 2:
			cout << "Are you sure to dequeue one node\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				dequeue();
				cout << "\nCheck data of queue after dequeuing first node :\n ";
				display();
			}
			else {
				cout << "Dequeue is canceled\n";
			}
			break;
		case 3:
			cout << "Are you sure to dequeue all nodes\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				dequeueAll();
				cout << "\nCheck data of queue after dequeuing all nodes :\n ";
				display();
			}
			else {
				cout << "Dequeue all is canceled\n";
			}
			break;
		case 4:
			cout << "Enqueue Elements are:\n";
			display();
			break;
		case 5:
			return;
			break;
		default:
			cout << "Wrong Input Try Again\n";
		}
		cout << "Do you want another opration\n";
		cout << "Yes -> 1 \n";
		cout << "NO -> any key \n";
		cin >> ao;
	} while (ao == 1);
}
int main()
{
	app();
	return 0;
}