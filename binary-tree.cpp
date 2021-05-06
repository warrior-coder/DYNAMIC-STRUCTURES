#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
    int inf;
    Node* left;
    Node* right;
};

struct Tree
{
    Node* root = nullptr;
    int size = 0;
   
    bool empty()
    {
        return !root;
    }

    void push(int inf)
    {
        Node* pt = new Node;
        pt->left = pt->right = nullptr;
        pt->inf = inf;
        
        if (root == nullptr)
        {
            root = pt;
        }
        else
        {
            Node* rt = root, * rt2 = root;
            while (rt)
            {
                rt2 = rt;
                if (inf < rt->inf) rt = rt->left;
                else rt = rt->right;
            }
            if (inf < rt2->inf) rt2->left = pt;
            else rt2->right = pt;
        }
        size++;
    }

    void create_balance(int left, int right, int* mas)
    {
        if (root) return;
        root = add_balance(left, right, mas);
    }
    Node* add_balance(int left, int right, int* mas)
    {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        Node* pt = new Node;
        pt->inf = mas[mid];
        size++;

        pt->left = add_balance(left, mid-1, mas);
        pt->right = add_balance(mid+1, right, mas);

        return pt;
    }

    void show(Node* p)
    {
        if (p == nullptr) return;

        show(p->left);
        cout << p->inf << ' ';
        show(p->right);
    }

    void show_direct(Node* p)
    {
        if (p == nullptr) return;

        cout << p->inf << ' ';
        show_direct(p->left);
        show_direct(p->right);
    }

    void show_reverse(Node* p)
    {
        if (p == nullptr) return;

        show_reverse(p->left);
        show_reverse(p->right);
        cout << p->inf << ' ';
    }

    void print(Node* p, char dir, int w = 0)
    {
        if (p == nullptr) return;
        print(p->left, static_cast<char>(218), w+4);
        cout << setw(w) << dir << static_cast<char>(196) << p->inf << endl;
        print(p->right, static_cast<char>(192), w+4);
    }

    void remove(int x)
    {
        // find del element
        Node* del = root, * pdel = root;
        while (del && del->inf != x)
        {
            pdel = del;
            if (x < del->inf) del = del->left;
            else del = del->right;
        }
        if (del == nullptr) return;

        // find replace element
        Node* rep, * prep;
        prep = del;
        if (del->left == nullptr) rep = del->right;
        else
        {
            rep = del->left;
            while (rep->right)
            {
                prep = rep;
                rep = rep->right;
            }
        }

        // replace del element
        if (rep) // if not leaf
        {
            // remove rep
            if (prep->left == rep) prep->left = rep->left;
            else prep->right = rep->left;
            // place rep instead of del
            del->left = rep->left;
            del->right = rep->right;
        }

        // if root is deleting
        if (del == root) root = rep;
        else
        {
            if (pdel->left == del) pdel->left = rep;
            else pdel->right = rep; 
        }

        delete del;
        size--;
    }

    Node* search(int x)
    {
        Node* p = root;
        while (p)
        {
            if (p->inf == x) return p;
            if (x < p->inf) p = p->left;
            else p = p->right;
        }
        return nullptr;
    }

    Node* search_max()
    {
        Node* p = root;
        while (p->right) p = p->right;
        return p;
    }

    Node* search_min()
    {
        Node* p = root;
        while (p->left) p = p->left;
        return p;
    }

    int count_levels(Node* p, int level = 0)
    {
        if (p == nullptr) return level;
        else
        {
            int level_left = count_levels(p->left, level+1);
            int level_right = count_levels(p->right, level+1);
            return (level_left > level_right) ? level_left : level_right;
        }
    }

    void clear(Node* p)
    {
        if (p == nullptr) return;
        clear(p->left);
        clear(p->right);
        delete p;
        p = nullptr;
        size--;
    }
};

int main()
{
    
    /* Creating balanced tree */
    Tree t;
    int mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
    t.create_balance(0, 9, mas);
    

    /* Creating ordinary tree 
    int n;
    cout << "Enter tree size: "; cin >> n;
    if (n < 1)
    {
        cout << "Tree is empty" << endl;
        return 0;
    }
    
    Tree t;
    int inf;
    cout << "Enter tree: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inf;
        t.push(inf);
    }
    */

    /* Tree form print */
    cout << "Tree: " << endl;
    t.print(t.root, 'R', 0);
    cout << endl;

    /* Info */

    cout << "Root: " << t.root->inf << endl;
    cout << "Levels: " << t.count_levels(t.root) << endl;
    cout << "Nodes (=size): " << t.size << endl;
    cout << endl;

    /* Show
    cout << "Bypass:" << endl;
    cout << "Symmetrical: ";
    t.show_direct(t.root);
    cout << endl;

    cout << "Direct: ";
    t.show_direct(t.root);
    cout << endl;

    cout << "Reverse: ";
    t.show_reverse(t.root);
    cout << endl;
    */

    /* Search 
    cout << "Max element: " << t.search_max()->inf << endl;
    cout << "Min element: " << t.search_min()->inf << endl;
    
    Node* n1 = t.search(4);
    cout << "Search 4: ";
    (n1) ? (cout << "4" << endl) : (cout << "Not found" << endl);
    */

    /* Remove 
    t.remove(4);

    cout << "Remove 4: " << endl;
    t.show(t.root);  
    cout << endl;
    cout << "Size: " << t.size << endl;
    */

    /* Clear */
    t.clear(t.root);
    cout << "Tree cleared" << endl;
    cout << "Size: " << t.size << endl;

    return 0;
}