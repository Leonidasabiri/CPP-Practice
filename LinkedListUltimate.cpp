#include <iostream>
#include <cstdarg>
#include <vector>
#include <utility>

//Singly linked-list node
template<class T>
class Singly_Node
{
public:
	T data;
	Singly_Node* next;
	Singly_Node* h = nullptr;

	void pushfront(T d)
	{
		Singly_Node<T>* newnode = new Singly_Node<T>;
		newnode->data = d;
		newnode->next = h;
		h = newnode;
	}
	void pushback(T d)
	{
		Singly_Node<T>* newnode = new Singly_Node<T>, * tmp;
		if (h == nullptr)										//In case if the head is a null pointer make it the new allocated node
		{
			newnode->data = d;
			newnode->next = h;
			h = newnode;
			return;
		}
		tmp = h;												// Otherwise make another tmp pointer to traverse the list
		while (tmp->next != nullptr)
			tmp = tmp->next;
		newnode->data = d;
		tmp->next = newnode;									// Note here that changes that will affect tmp pointer will affect the head pointer too which will give us an updated list with new elements each time we call it
	}
	void deleteAt(int ind)
	{
		Singly_Node<T>* curr = h, * prev = nullptr;
		for (size_t i = 0; i < ind && curr->next != nullptr; i++)	// Loop untill we find the index we want
		{
			prev = curr;											// With each step make the prev pointer hold the node before passing to the next one
			curr = curr->next;
		}
		prev->next = curr->next;		//let's say we want tp delete index 2 , the last node 
										//prev will hold is node2
										//node1->node2->node3->node4 and next of prev(node2) is next of curr(node3)
										//giving us node1->node2->node4 then we delete node3 to free it's memory
		delete curr;
	}
	void printList()
	{
		while (h != nullptr)
		{
			std::cout << h->data;
			h = h->next;
		}
	}
	void remove(int data);
	void merge(Singly_Node* n2);
	void reverse();
	void sort();

	~Singly_Node()
	{
		Singly_Node<T>* curr = h, * next = nullptr;
		while (curr != nullptr)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
		h = nullptr; // dereferencing the head pointer
	}
};

//Doubly linked-list node
template<typename T, typename U>
class Doubly_Node
{
	Doubly_Node* next;
	Doubly_Node* prev;

	Doubly_Node* h = nullptr;
};

template<typename ...Arg>
class Stack
{
	Stack* top = nullptr;
	// LIFO
	/*Stack(Arg&& args...)
	{

	}*/
};

template<typename ...Arg>
class Queue
{
	// FIFO
	/*Queue(Arg&& args...)
	{

	}*/
};

int main()
{
	Singly_Node<int> n;
	n.pushback(0);
	n.pushback(1);
	n.pushback(2);
	n.pushback(3);
	n.pushback(4);
	n.deleteAt(2);
	n.printList();
}
