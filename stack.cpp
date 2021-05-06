#include <iostream>

using namespace std;

struct Node
{
    int inf;
    Node* next;
};

struct Stack
{
    Node* top = nullptr;
    int size = 0;

    bool empty()
    {
        return !top;
    }

    void push(int inf)
    {
        Node* spt = new Node;
        spt->inf = inf;
        spt->next = top;
        top = spt;
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
        if (top == nullptr) return;

        Node* spt = top;
        top = top->next;
        delete spt;
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
        Node* spt = top;
        while (spt)
        {
            cout << spt->inf << ' ';
            spt = spt->next;
        }
        cout << endl;
    }
    
    Node* search(int x)
    {
        if (top == nullptr) return nullptr;
        
        Node* spt = top;
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
        Node* top_tmp = new Node;
        top_tmp->next = top;
        top = top_tmp;
        BubbleSortAfter(top);
        top = top->next;
        delete top_tmp;
    }

    void clear()
    {
        Node* spt;
        while (top)
        {
            spt = top;
            top = top->next;
            delete spt;
        }
        size = 0;
    }
};

int main()
{
    /* Create */
    cout << "- Create Stack:" << endl;
    Stack s;
    s.push(3);
    s.push(22);
    s.push(1);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(10);
    s.show();
    cout << "Stack size: " << s.size << endl;

    /* pop_back
    cout << endl << "- pop_back:" << endl;
    s.pop_back();
    s.show();
    cout << "Stack size: " << s.size << endl;
    */

    /* Search element
    cout << endl << "- Search element:" << endl;
    Node* n1 = s.search(22);
    cout << n1->inf << endl;
    */

    /* Add after
    cout << endl << "- Add 77 after 6:" << endl;
    s.insertAfter(s.search(6), 77);
    s.show();
    */

    /* Delete after
    cout << endl << "- Delete after last:" << endl;
    s.removeAfter(s.top);
    s.show();
    cout << "Stack size: " << s.size << endl;

    cout << endl << "- Delete after 6:" << endl;
    s.removeAfter(s.search(6));
    s.show();
    cout << "Stack size: " << s.size << endl;

    cout << endl << "- Delete after 999 (not exist):" << endl;
    s.removeAfter(s.search(999));
    s.show();
    cout << "Stack size: " << s.size << endl;
    */

    /* Exchange after
    cout << endl << "- Exchange after last:" << endl;
    s.exchangeAfter(s.top);
    s.show();
    
    cout << endl << "- Exchange after 3:" << endl;
    Node* n1 = s.search(3);
    s.exchangeAfter(n1);
    s.show();
    */

    /* Sort
    cout << endl << "- Sort after 77:" << endl;
    s.BubbleSortAfter(s.search(77));
    s.show();

    cout << endl << "- Sort Stack:" << endl;
    s.BubbleSort();
    s.show();
    */

    /* Empty
    cout << "- Is empty: " << s.empty() << endl;
    */

    /* Delete stack*/
    s.clear();

    cout << endl << "- Stack deleted." << endl;
    cout << "- Stack size: " << s.size << endl;

    return 0;
}