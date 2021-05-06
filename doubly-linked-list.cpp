#include <iostream>

using namespace std;

struct Node
{
	int inf;
	Node* prev;
	Node* next;
};

struct List
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
			spt->prev = nullptr;
			begin = end = spt;
		}
		else
		{
			spt->prev = end;
			end->next = spt;
			end = spt;
		}
		size++;
	}

	void push_front(int inf)
	{
		Node* spt = new Node;
		spt->inf = inf;
		spt->prev = nullptr;

		if (begin == nullptr)
		{
			spt->next = nullptr;
			begin = end = spt;
		}
		else
		{
			begin->prev = spt;
			spt->next = begin;
			begin = spt;
		}
		size++;
	}

	void insert(Node* sp, int inf)
	{
		if (sp == nullptr) return;
		
		Node* spt = new Node;
		spt->inf = inf;
		spt->prev = sp;
		spt->next = sp->next;

		if (sp->next != nullptr) sp->next->prev = spt;
		sp->next = spt;

		if (spt->next == nullptr) end = spt;
		size++;
	}

	void pop_back()
	{
		if (begin == nullptr) return;

		Node* spt = end;
		if (spt->prev) spt->prev->next = nullptr;
		else begin = spt->next;
		end = end->prev;

		delete spt;
		size--;
	}

	void pop_front()
	{
		if (end == nullptr) return;

		Node* spt = begin;
		if (spt->next) spt->next->prev = nullptr;
		else end = spt->prev;
		begin = begin->next;

		delete spt;
		size--;
	}

	void remove(Node* sp)
	{
		if (sp == nullptr) return;

		Node* spt = sp;

		if (spt->prev) spt->prev->next = spt->next;
		else begin = spt->next;
		if (spt->next) spt->next->prev = spt->prev;
		else end = spt->prev;

		delete spt;
		size--;
	}

	void remove(int x)
	{
		Node* spt = begin;

		while (spt->next && spt->inf != x)
		{
			spt = spt->next;
		}
		if (spt->inf == x)
		{
			if (spt->prev) spt->prev->next = spt->next;
			else begin = spt->next;
			if (spt->next) spt->next->prev = spt->prev;
			else end = spt->prev;
			delete spt;
			size--;
		}
		else return;
	}

	Node* search(int x)
	{
		if (begin == nullptr) return nullptr;

		Node* spt = begin;
		while (spt->next && spt->inf != x)
		{
			spt = spt->next;
		}
		if (spt->inf == x) return spt;
		else return nullptr;
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

	void exchangeNodes(Node* sp1, Node* sp2)
	{
		if (sp1 == nullptr || sp2 == nullptr || sp1 == sp2) return;
		
		Node* spt;
		if (sp1->next == sp2)
		{
			spt = sp1->prev;
			sp1->prev = sp2;
			sp2->prev = spt;
			
			spt = sp2->next;
			sp2->next = sp1;
			sp1->next = spt;
		}
		else if (sp2->next == sp1)
		{
			spt = sp2->prev;
			sp2->prev = sp1;
			sp1->prev = spt;

			spt = sp1->next;
			sp1->next = sp2;
			sp2->next = spt;
		}
		else
		{
			spt = sp1->next;
			sp1->next = sp2->next;
			sp2->next = spt;

			spt = sp1->prev;
			sp1->prev = sp2->prev;
			sp2->prev = spt;
		}

		if (sp1->next) sp1->next->prev = sp1;
		else end = sp1;
		if (sp1->prev) sp1->prev->next = sp1;
		else begin = sp1;

		if (sp2->next) sp2->next->prev = sp2;
		else end = sp2;
		if (sp2->prev) sp2->prev->next = sp2;
		else begin = sp2;
	}

	void InsertionSort()
	{
		if (begin == end) return;

		Node* spt1, * spt2;
		for (spt1 = begin->next; spt1; spt1 = spt1->next)
			for (spt2 = spt1; spt2->prev && spt2->inf < spt2->prev->inf; exchangeNodes(spt2, spt2->prev));
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
	/* Create List */
	cout << "- Create Doubly Linked List:" << endl;
	List l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(4);
	l.push_front(5);
	l.push_front(6);
	l.show();
	cout << "- List size: " << l.size << endl;
	
	/* Search element
	cout << endl << "- Search element 3:" << endl;
	Node* n1 = l.search(3);
	cout << n1->inf << endl;
	*/

	/* Insert element after
	cout << endl << "- Insert 77 after 1:" << endl;
	l.insert(l.search(1), 77);
	l.show();
	*/

	/* Remove element
	cout << endl << "- Remove 77:" << endl;
	l.remove(l.search(77));
	l.show();
	
	cout << endl << "- Remove 3:" << endl;
	l.remove(3);
	l.show();

	cout << endl << "- Pop back & fornt:" << endl;
	l.pop_back();
	l.pop_front();
	l.show();

	cout << "- List size: " << l.size << endl;
	*/

	/* Exchange elements
	cout << endl << "- Exchange 2 & 5:" << endl;
	l.exchangeNodes(l.search(2), l.search(5));
	l.show();

	cout << endl << "- Exchange first & last:" << endl;
	l.exchangeNodes(l.begin, l.end);
	l.show();

	cout << endl << "- Exchange first two:" << endl;
	l.exchangeNodes(l.begin, l.begin->next);
	l.show();

	cout << endl << "- Exchange last two:" << endl;
	l.exchangeNodes(l.end, l.end->prev);
	l.show();
	*/

	/* Sort
	cout << endl << "- Insertion sort:" << endl;
	l.InsertionSort();
	l.show();
	*/

	/* Empty
	cout << "- Is empty: " << l.empty() << endl;
	*/

	
	/* Clear List*/
	l.clear();

	cout << endl << "- List deleted." << endl;
	cout << "- List size: " << l.size << endl;

	return 0;
}