// Алгоритм прохода в глубину в C++

#include <iostream>
#include <list>
#include <vector>
#include <memory>

using namespace std;

class Rebro
{
public:
    int firstNum, lastNum, ves, metka;
    Rebro(int fn, int ln, int vs, int m)
    {
        firstNum = fn;
        lastNum = ln;
        ves = vs;
        metka = m;
    }
    void print()
    {
        cout << "nodes " << firstNum << " " << lastNum << " " << ves << " " << metka;
    }
};

class Vershina
{
public:
    int data;
    Vershina(int d)
    {
        data = d;
    }
};

/*
class Elem
{
public:
    int data;
    Elem *next, *prev;
    Elem(int d)
    {
        data = d;
        this->prev = this->next = NULL;
    }
};

class List_of_open_nodes
{
public:
    Elem *head, *tail;

    List_of_open_nodes()
    {
        this->head = this->tail = NULL;
    }

    Elem *push_front(int data)
    {
        Elem *ptr = new Elem(data);

        ptr->next = head;
        if (head != NULL)
            head->prev = ptr;
        if (tail == NULL)
            tail = ptr;
        head = ptr;

        return ptr;
    }

    void pop_front()
    {
        if (head == NULL)
            return;

        Elem *ptr = head->next;
        if (ptr != NULL)
            ptr->prev = NULL;
        else
            tail = NULL;

        delete head;
        head = ptr;
    }
};

class List_of_close_nodes
{
public:
    Elem *head, *tail;
    List_of_close_nodes()
    {
        this->head = this->tail = NULL;
    }

    Elem *push_front(int data)
    {
        Elem *ptr = new Elem(data);

        ptr->next = head;
        if (head != NULL)
            head->prev = ptr;
        if (tail == NULL)
            tail = ptr;
        head = ptr;

        return ptr;
    }

    void pop_front()
    {
        if (head == NULL)
            return;

        Elem *ptr = head->next;
        if (ptr != NULL)
            ptr->prev = NULL;
        else
            tail = NULL;

        delete head;
        head = ptr;
    }
};

*/

int main()
{
    vector<Rebro> list_of_rebro; // список ребер графа

    vector<shared_ptr<Vershina>> list_of_vershina;

    vector<int> sov; // список открытых вершин
    vector<int> sop; // список открытых правил

    vector<int> szv; // список запрещенных вершин
    vector<int> szp; // список запрещенных правил

    vector<int> s;
    vector<int> close_tops;

    Rebro r1(1, 2, 12, 0);
    Rebro r2(3, 4, 13, 0);
    list_of_rebro.push_back(r1);
    list_of_rebro.push_back(r2);
    // list_of_rebro[0].print();
    // list_of_rebro[1].print();

    std::shared_ptr<Vershina> sp0(new Vershina(1));
    std::shared_ptr<Vershina> sp1(new Vershina(11));
    std::shared_ptr<Vershina> sp2(new Vershina(111));
    std::shared_ptr<Vershina> sp3(new Vershina(1111));

    std::cout << "address: " << sp0 << "value: " << sp0->data << std::endl;
    std::cout << "address: " << sp1 << "value: " << sp1->data << std::endl;
    std::cout << "address: " << sp2 << "value: " << sp2->data << std::endl;
    std::cout << "address: " << sp3 << "value: " << sp3->data << std::endl;

    list_of_vershina.push_back(sp0);
    list_of_vershina.push_back(sp1);

    for (const auto &element : list_of_vershina)
    {
        std::cout << element << "\n";
    }

    std::shared_ptr<Rebro> sp4(new Rebro(1, 2, 100, 0));
    std::shared_ptr<Rebro> sp5(new Rebro(2, 3, 101, 0));
    std::shared_ptr<Rebro> sp6(new Rebro(2, 5, 102, 0));
    std::shared_ptr<Rebro> sp7(new Rebro(3, 5, 103, 0));

    std::cout << "address: " << sp4 << "value: " << sp4->firstNum << std::endl;

    /*
    List_of_open_nodes l1;
    l1.push_front(12);
    l1.push_front(10);
    l1.push_front(9);
    l1.push_front(8);
    for (Elem *ptr = l1.head; ptr != NULL; ptr = ptr->next)
        std::cout << ptr->data << " ";
    std::cout << std::endl;
    l1.pop_front();
    for (Elem *ptr = l1.head; ptr != NULL; ptr = ptr->next)
        std::cout << ptr->data << " ";
    */
    // Rebro r1(1, 2, 12, 0);
    // r1.print();
}
