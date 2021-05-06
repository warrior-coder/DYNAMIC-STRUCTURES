#include <iostream>

using namespace std;

struct Node
{
	int inf;
	Node* next;
};

struct Queue
{
	Node* begin = nullptr;
	Node* end = nullptr;
	int size = 0;

	bool empty()
	{
		return !begin;
	}

	void push_back(int inf)
	{
		Node* spt = new Node;
		spt->inf = inf;
		spt->next = nullptr;

		if (begin == nullptr)
		{
			begin = end = spt;
		}
		else
		{
			end->next = spt;
			end = spt;
		}
		size++;
	}

	void insertAfter(Node* sp, int inf)
	{
		if (sp == nullptr) return;

		Node* spt = new Node;
		spt->inf = inf;
		spt->next = sp->next;
		sp->next = spt;
		size++;
	}

	void pop_back()
	{
		if (begin == nullptr) return;

		Node* spt = begin;
		begin = begin->next;
		delete spt;

		if (begin == nullptr) end = nullptr;
		size--;
	}

	void removeAfter(Node* sp)
	{
		if (sp == nullptr || sp->next == nullptr) return;

		Node* spt = sp->next;
		sp->next = sp->next->next;
		delete spt;
		size--;
	}

	void show()
	{
		Node* spt = begin;
		while (spt)
		{
			cout << spt->inf << ' ';
			spt = spt->next;
		}
		cout << endl;
	}

	Node* search(int x)
	{
		if (begin == nullptr) return nullptr;

		Node* spt = begin;
		while (spt->next != nullptr && spt->inf != x)
		{
			spt = spt->next;
		}
		if (spt->inf == x) return spt;
		else return nullptr;
	}

	void exchangeAfter(Node* sp)
	{
		if (sp == nullptr || sp->next == nullptr || sp->next->next == nullptr) return;

		Node* spt = sp->next->next;
		sp->next->next = spt->next;
		spt->next = sp->next;
		sp->next = spt;
	}

	void BubbleSortAfter(Node* sp)
	{
		if (sp == nullptr || sp->next == nullptr || sp->next->next == nullptr) return;

		Node* spt1, * spt2;
		for (spt1 = sp; spt1->next->next != nullptr; spt1 = spt1->next)
			for (spt2 = sp; spt2->next->next != nullptr; spt2 = spt2->next)
				if (spt2->next->inf > spt2->next->next->inf) exchangeAfter(spt2);
	}

	void BubbleSort()
	{
		Node* begin_temp = new Node;
		begin_temp->next = begin;
		begin = begin_temp;
		BubbleSortAfter(begin);
		begin = begin->next;
		delete begin_temp;
	}

	void clear()
	{
		Node* spt;
		while (begin)
		{
			spt = begin;
			begin = begin->next;
			delete spt;
		}
		begin = end = nullptr;
		size = 0;
	}
};

int main()
{
	/* Create */
	cout << "- Create Queue:" << endl;
	Queue q;
	q.push_back(10);
	q.push_back(11);
	q.push_back(12);
	q.push_back(3);
	q.push_back(4);
	q.push_back(5);
	q.show();
	cout << "- Queue size: " << q.size << endl;

	/* pop_back
	cout << endl << "- pop_back element:" << endl;
	q.pop_back();
	q.show();
	cout << "- Queue size: " << q.size << endl;
	*/

	/* Search element
	cout << endl << "- Search element:" << endl;
	Node* n1 = q.search(12);
	cout << n1->inf << endl;
	*/

	/* Add After
	cout << endl << "- Add 99 after first:" << endl;
	q.insertAfter(q.begin, 99);
	q.show();

	cout << endl << "- Add 77 after 12:" << endl;
	q.insertAfter(q.search(12), 77);
	q.show();
	cout << "- Queue size: " << q.size << endl;
	*/

	/* Delete After
	cout << endl << "- Delete after first:" << endl;
	q.removeAfter(q.begin);
	q.show();

	cout << endl << "- Delete after 12:" << endl;
	q.removeAfter(q.search(10));
	q.show();

	cout << endl << "- Delete after 999 (not exist):" << endl;
	q.removeAfter(q.search(999));
	q.show();
	cout << "- Queue size: " << q.size << endl;
	*/

	/* Exchange after
	cout << endl << "- Exchange after 3:" << endl;
	q.exchangeAfter(q.search(3));
	q.show();
	*/

	/* Sort
	cout << endl << "- Sort after 11:" << endl;
	q.BubbleSortAfter(q.search(11));
	q.show();

	cout << endl << "- Sort Queue:" << endl;
	q.BubbleSort();
	q.show();
	*/

	/* Empty
	cout << "- Is empty: " << q.empty() << endl;
	*/

	/* Delete queue */
	q.clear();

	cout << endl << "- Queue deleted." << endl;
	cout << "- Queue size: " << q.size << endl;

	return 0;
}