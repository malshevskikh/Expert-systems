// Алгоритм прохода в глубину в C++

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Vertex
{
public:
    int data, metka;
    Vertex(int d, int m)
    {
        data = d;
        metka = m; // 0 - не помечена, 1 - помечена
    }
};

class Rule
{
public:
    int data, metka;
    Rule(int d, int m)
    {
        data = d;
        metka = m; // 0 - не помечена, 1 - помечена
    }
};

class Rebro_new
{
public:
    Vertex vrtx;
    Rule rul;
    int start, end, metka;
    Rebro_new(Vertex _vrtx, Rule _rul, int _metka) : vrtx(_vrtx), rul(_rul)
    {
        vrtx = _vrtx;
        rul = _rul;
        metka = _metka;
        start = vrtx.data;
        end = rul.data;
    }
    Rebro_new(Rule _rul, Vertex _vrtx, int _metka) : rul(_rul), vrtx(_vrtx)
    {
        rul = _rul;
        vrtx = _vrtx;
        metka = _metka;
        start = rul.data;
        end = vrtx.data;
    }

    void print()
    {
        cout << "Вершина " << vrtx.data << " " << vrtx.metka << endl;
        cout << "Правило " << rul.data << " " << rul.metka << endl;
        cout << "Метка " << metka << endl;
    }
};

class Graph
{
public:
    vector<shared_ptr<Rebro_new>> list_of_rebro;
    vector<shared_ptr<Vertex>> list_of_vershina;
    vector<shared_ptr<Rule>> list_of_rule;
    vector<shared_ptr<Vertex>> sow;
    vector<shared_ptr<Rule>> sop;
    vector<shared_ptr<Vertex>> szw;
    vector<shared_ptr<Rule>> szp;

    bool fr, fn, fy;

    Graph(vector<shared_ptr<Rebro_new>> list_of_rebro, vector<shared_ptr<Vertex>> list_of_vershina, vector<shared_ptr<Rule>> list_of_rule, vector<shared_ptr<Vertex>> sow, vector<shared_ptr<Rule>> sop, vector<shared_ptr<Vertex>> szw, vector<shared_ptr<Rule>> szp)
    {
        this->list_of_rebro = list_of_rebro;
        this->list_of_vershina = list_of_vershina;
        this->list_of_rule = list_of_rule;
        this->sow = sow;
        this->sop = sop;
        this->szw = szw;
        this->szp = szp;
    }

    void poisk_v_glubinu_alghoritm_ot_celi_first()
    {

        // Создание указателя на объект класса Vertex

        std::shared_ptr<Vertex> sp0(new Vertex(0, 0));
        std::shared_ptr<Vertex> sp1(new Vertex(1, 0));
        std::shared_ptr<Vertex> sp2(new Vertex(2, 0));
        std::shared_ptr<Vertex> sp3(new Vertex(3, 0));
        std::shared_ptr<Vertex> sp4(new Vertex(4, 0));
        std::shared_ptr<Vertex> sp5(new Vertex(5, 0));
        std::shared_ptr<Vertex> sp6(new Vertex(6, 0));
        std::shared_ptr<Vertex> sp7(new Vertex(7, 0));
        std::shared_ptr<Vertex> sp8(new Vertex(8, 0));
        std::shared_ptr<Vertex> sp9(new Vertex(9, 0));
        std::shared_ptr<Vertex> sp10(new Vertex(10, 0));
        std::shared_ptr<Vertex> sp11(new Vertex(11, 0));
        std::shared_ptr<Vertex> sp12(new Vertex(12, 0));
        std::shared_ptr<Vertex> sp13(new Vertex(13, 0));
        std::shared_ptr<Vertex> sp14(new Vertex(14, 0));
        std::shared_ptr<Vertex> sp15(new Vertex(15, 0));
        std::shared_ptr<Vertex> sp16(new Vertex(17, 0));
        std::shared_ptr<Vertex> sp17(new Vertex(18, 0));
        std::shared_ptr<Vertex> sp18(new Vertex(19, 0));
        std::shared_ptr<Vertex> sp19(new Vertex(20, 0));
        std::shared_ptr<Vertex> sp20(new Vertex(21, 0));
        std::shared_ptr<Vertex> sp21(new Vertex(22, 0));
        std::shared_ptr<Vertex> sp22(new Vertex(23, 0));
        std::shared_ptr<Vertex> sp23(new Vertex(31, 0));
        std::shared_ptr<Vertex> sp24(new Vertex(33, 0));

        // Добавление указателей в список list_of_vershina

        list_of_vershina.push_back(sp0);
        list_of_vershina.push_back(sp1);
        list_of_vershina.push_back(sp2);
        list_of_vershina.push_back(sp3);
        list_of_vershina.push_back(sp4);
        list_of_vershina.push_back(sp5);
        list_of_vershina.push_back(sp6);
        list_of_vershina.push_back(sp7);
        list_of_vershina.push_back(sp8);
        list_of_vershina.push_back(sp9);
        list_of_vershina.push_back(sp10);
        list_of_vershina.push_back(sp11);
        list_of_vershina.push_back(sp12);
        list_of_vershina.push_back(sp13);
        list_of_vershina.push_back(sp14);
        list_of_vershina.push_back(sp15);
        list_of_vershina.push_back(sp16);
        list_of_vershina.push_back(sp17);
        list_of_vershina.push_back(sp18);
        list_of_vershina.push_back(sp19);
        list_of_vershina.push_back(sp20);
        list_of_vershina.push_back(sp21);
        list_of_vershina.push_back(sp22);
        list_of_vershina.push_back(sp23);
        list_of_vershina.push_back(sp24);

        // Создание указателя на объект класса Rule

        std::shared_ptr<Rule> r0(new Rule(101, 0));
        std::shared_ptr<Rule> r1(new Rule(102, 0));
        std::shared_ptr<Rule> r2(new Rule(103, 0));
        std::shared_ptr<Rule> r3(new Rule(104, 0));
        std::shared_ptr<Rule> r4(new Rule(105, 0));
        std::shared_ptr<Rule> r5(new Rule(106, 0));
        std::shared_ptr<Rule> r6(new Rule(107, 0));
        std::shared_ptr<Rule> r7(new Rule(108, 0));
        std::shared_ptr<Rule> r8(new Rule(109, 0));
        std::shared_ptr<Rule> r9(new Rule(110, 0));
        std::shared_ptr<Rule> r10(new Rule(111, 0));
        std::shared_ptr<Rule> r11(new Rule(112, 0));
        std::shared_ptr<Rule> r12(new Rule(113, 0));
        std::shared_ptr<Rule> r13(new Rule(114, 0));
        std::shared_ptr<Rule> r14(new Rule(115, 0));

        // Добавление указателей в список list_of_rule

        list_of_rule.push_back(r0);
        list_of_rule.push_back(r1);
        list_of_rule.push_back(r2);
        list_of_rule.push_back(r3);
        list_of_rule.push_back(r4);
        list_of_rule.push_back(r5);
        list_of_rule.push_back(r6);
        list_of_rule.push_back(r7);
        list_of_rule.push_back(r9);
        list_of_rule.push_back(r10);
        list_of_rule.push_back(r11);
        list_of_rule.push_back(r12);
        list_of_rule.push_back(r13);
        list_of_rule.push_back(r14);

        // Создание указателя на объект класса Rebro_new

        Vertex vtx1(1, 0);
        Rule rl1(101, 0);
        std::shared_ptr<Rebro_new> rb0(new Rebro_new(vtx1, rl1, 0));

        Vertex vtx2(2, 0);
        Rule rl2(101, 0);
        std::shared_ptr<Rebro_new> rb2(new Rebro_new(vtx2, rl2, 0));

        Vertex vtx3(2, 0);
        Rule rl3(102, 0);
        std::shared_ptr<Rebro_new> rb3(new Rebro_new(vtx3, rl3, 0));

        Vertex vtx4(3, 0);
        Rule rl4(102, 0);
        std::shared_ptr<Rebro_new> rb4(new Rebro_new(vtx4, rl4, 0));

        Vertex vtx5(4, 0);
        Rule rl5(102, 0);
        std::shared_ptr<Rebro_new> rb5(new Rebro_new(vtx5, rl5, 0));

        Vertex vtx6(4, 0);
        Rule rl6(106, 0);
        std::shared_ptr<Rebro_new> rb6(new Rebro_new(vtx6, rl6, 0));

        Vertex vtx7(5, 0);
        Rule rl7(103, 0);
        std::shared_ptr<Rebro_new> rb7(new Rebro_new(vtx7, rl7, 0));

        Vertex vtx8(6, 0);
        Rule rl8(103, 0);
        std::shared_ptr<Rebro_new> rb8(new Rebro_new(vtx8, rl8, 0));

        Vertex vtx9(7, 0);
        Rule rl9(105, 0);
        std::shared_ptr<Rebro_new> rb9(new Rebro_new(vtx9, rl9, 0));

        Vertex vtx10(8, 0);
        Rule rl10(104, 0);
        std::shared_ptr<Rebro_new> rb10(new Rebro_new(vtx10, rl10, 0));

        Vertex vtx11(9, 0);
        Rule rl11(105, 0);
        std::shared_ptr<Rebro_new> rb11(new Rebro_new(vtx11, rl11, 0));

        Vertex vtx12(9, 0);
        Rule rl12(110, 0);
        std::shared_ptr<Rebro_new> rb12(new Rebro_new(vtx12, rl12, 0));

        Vertex vtx13(10, 0);
        Rule rl13(111, 0);
        std::shared_ptr<Rebro_new> rb13(new Rebro_new(vtx13, rl13, 0));

        Vertex vtx14(10, 0);
        Rule rl14(112, 0);
        std::shared_ptr<Rebro_new> rb14(new Rebro_new(vtx14, rl14, 0));

        Vertex vtx15(11, 0);
        Rule rl15(106, 0);
        std::shared_ptr<Rebro_new> rb15(new Rebro_new(vtx15, rl15, 0));

        Vertex vtx16(11, 0);
        Rule rl16(111, 0);
        std::shared_ptr<Rebro_new> rb16(new Rebro_new(vtx16, rl16, 0));

        Vertex vtx17(12, 0);
        Rule rl17(107, 0);
        std::shared_ptr<Rebro_new> rb17(new Rebro_new(vtx17, rl17, 0));

        Vertex vtx18(12, 0);
        Rule rl18(113, 0);
        std::shared_ptr<Rebro_new> rb18(new Rebro_new(vtx18, rl18, 0));

        Vertex vtx19(13, 0);
        Rule rl19(107, 0);
        std::shared_ptr<Rebro_new> rb19(new Rebro_new(vtx19, rl19, 0));

        Vertex vtx20(13, 0);
        Rule rl20(109, 0);
        std::shared_ptr<Rebro_new> rb20(new Rebro_new(vtx20, rl20, 0));

        Vertex vtx21(15, 0);
        Rule rl21(108, 0);
        std::shared_ptr<Rebro_new> rb21(new Rebro_new(vtx21, rl21, 0));

        Vertex vtx22(17, 0);
        Rule rl22(108, 0);
        std::shared_ptr<Rebro_new> rb22(new Rebro_new(vtx22, rl22, 0));

        Vertex vtx23(17, 0);
        Rule rl23(110, 0);
        std::shared_ptr<Rebro_new> rb23(new Rebro_new(vtx23, rl23, 0));

        Vertex vtx24(18, 0);
        Rule rl24(106, 0);
        std::shared_ptr<Rebro_new> rb24(new Rebro_new(vtx24, rl24, 0));

        Vertex vtx25(19, 0);
        Rule rl25(112, 0);
        std::shared_ptr<Rebro_new> rb25(new Rebro_new(vtx25, rl25, 0));

        Vertex vtx26(19, 0);
        Rule rl26(115, 0);
        std::shared_ptr<Rebro_new> rb26(new Rebro_new(vtx26, rl26, 0));

        Vertex vtx27(20, 0);
        Rule rl27(109, 0);
        std::shared_ptr<Rebro_new> rb27(new Rebro_new(vtx27, rl27, 0));

        Vertex vtx28(20, 0);
        Rule rl28(113, 0);
        std::shared_ptr<Rebro_new> rb28(new Rebro_new(vtx28, rl28, 0));

        Vertex vtx29(21, 0);
        Rule rl29(109, 0);
        std::shared_ptr<Rebro_new> rb29(new Rebro_new(vtx29, rl29, 0));

        Vertex vtx30(21, 0);
        Rule rl30(115, 0);
        std::shared_ptr<Rebro_new> rb30(new Rebro_new(vtx30, rl30, 0));

        Vertex vtx31(22, 0);
        Rule rl31(114, 0);
        std::shared_ptr<Rebro_new> rb31(new Rebro_new(vtx31, rl31, 0));

        Vertex vtx32(23, 0);
        Rule rl32(114, 0);
        std::shared_ptr<Rebro_new> rb32(new Rebro_new(vtx32, rl32, 0));

        Vertex vtx33(31, 0);
        Rule rl33(104, 0);
        std::shared_ptr<Rebro_new> rb33(new Rebro_new(vtx33, rl33, 0));

        //-------------------------

        Rule rl34(101, 0);
        Vertex vtx34(3, 0);
        std::shared_ptr<Rebro_new> rb34(new Rebro_new(rl34, vtx34, 0));

        Rule rl35(102, 0);
        Vertex vtx35(7, 0);
        std::shared_ptr<Rebro_new> rb35(new Rebro_new(rl35, vtx35, 0));

        Rule rl36(103, 0);
        Vertex vtx36(4, 0);
        std::shared_ptr<Rebro_new> rb36(new Rebro_new(rl36, vtx36, 0));

        Rule rl37(104, 0);
        Vertex vtx37(3, 0);
        std::shared_ptr<Rebro_new> rb37(new Rebro_new(rl37, vtx37, 0));

        Rule rl38(105, 0);
        Vertex vtx38(14, 0);
        std::shared_ptr<Rebro_new> rb38(new Rebro_new(rl38, vtx38, 0));

        Rule rl39(106, 0);
        Vertex vtx39(9, 0);
        std::shared_ptr<Rebro_new> rb39(new Rebro_new(rl39, vtx39, 0));

        Rule rl40(107, 0);
        Vertex vtx40(11, 0);
        std::shared_ptr<Rebro_new> rb40(new Rebro_new(rl40, vtx40, 0));

        Rule rl41(108, 0);
        Vertex vtx41(33, 0);
        std::shared_ptr<Rebro_new> rb41(new Rebro_new(rl41, vtx41, 0));

        Rule rl42(109, 0);
        Vertex vtx42(19, 0);
        std::shared_ptr<Rebro_new> rb42(new Rebro_new(rl42, vtx42, 0));

        Rule rl43(110, 0);
        Vertex vtx43(14, 0);
        std::shared_ptr<Rebro_new> rb43(new Rebro_new(rl43, vtx43, 0));

        Rule rl44(111, 0);
        Vertex vtx44(9, 0);
        std::shared_ptr<Rebro_new> rb44(new Rebro_new(rl44, vtx44, 0));

        Rule rl45(112, 0);
        Vertex vtx45(17, 0);
        std::shared_ptr<Rebro_new> rb45(new Rebro_new(rl45, vtx45, 0));

        Rule rl46(113, 0);
        Vertex vtx46(10, 0);
        std::shared_ptr<Rebro_new> rb46(new Rebro_new(rl46, vtx46, 0));

        Rule rl47(114, 0);
        Vertex vtx47(12, 0);
        std::shared_ptr<Rebro_new> rb47(new Rebro_new(rl47, vtx47, 0));

        Rule rl48(115, 0);
        Vertex vtx48(17, 0);
        std::shared_ptr<Rebro_new> rb48(new Rebro_new(rl48, vtx48, 0));

        // Добавление указателей в список list_of_rebro

        list_of_rebro.push_back(rb0);
        list_of_rebro.push_back(rb2);
        list_of_rebro.push_back(rb3);
        list_of_rebro.push_back(rb4);
        list_of_rebro.push_back(rb5);
        list_of_rebro.push_back(rb6);
        list_of_rebro.push_back(rb7);
        list_of_rebro.push_back(rb8);
        list_of_rebro.push_back(rb9);
        list_of_rebro.push_back(rb10);
        list_of_rebro.push_back(rb11);
        list_of_rebro.push_back(rb12);
        list_of_rebro.push_back(rb13);
        list_of_rebro.push_back(rb14);
        list_of_rebro.push_back(rb15);
        list_of_rebro.push_back(rb16);
        list_of_rebro.push_back(rb17);
        list_of_rebro.push_back(rb18);
        list_of_rebro.push_back(rb19);
        list_of_rebro.push_back(rb20);
        list_of_rebro.push_back(rb21);
        list_of_rebro.push_back(rb22);
        list_of_rebro.push_back(rb23);
        list_of_rebro.push_back(rb24);
        list_of_rebro.push_back(rb25);
        list_of_rebro.push_back(rb26);
        list_of_rebro.push_back(rb27);
        list_of_rebro.push_back(rb28);
        list_of_rebro.push_back(rb29);
        list_of_rebro.push_back(rb30);
        list_of_rebro.push_back(rb31);
        list_of_rebro.push_back(rb32);
        list_of_rebro.push_back(rb33);
        list_of_rebro.push_back(rb34);
        list_of_rebro.push_back(rb35);
        list_of_rebro.push_back(rb36);
        list_of_rebro.push_back(rb37);
        list_of_rebro.push_back(rb38);
        list_of_rebro.push_back(rb39);
        list_of_rebro.push_back(rb40);
        list_of_rebro.push_back(rb41);
        list_of_rebro.push_back(rb42);
        list_of_rebro.push_back(rb43);
        list_of_rebro.push_back(rb44);
        list_of_rebro.push_back(rb45);
        list_of_rebro.push_back(rb46);
        list_of_rebro.push_back(rb47);
        list_of_rebro.push_back(rb48);

        printf("МЕТОД ПОИСКА В ГЛУБИНУ\n");
        bool flag1 = false, flag2 = false;
        fn = true;
        fy = true;
        int a, b, first_elem, counter;

        a = -100;
        b = -100;
        counter = 1;
        while (flag1 == false)
        {
            printf("Введите cel (от 1 до 15, от 17 до 23, 31 и 32): ");
            scanf("%d", &a);
            if ((a >= 1 && a <= 15) || (a >= 17 && a <= 23) || (a >= 31 && a <= 33))
            {
                flag1 = true;
            }
        }
        while (flag2 == false)
        {
            printf("Введите входные вершины (от 1 до 15, от 17 до 23, 31 и 32), отличающуюся от cel или < 0, чтобы прекратить ввод: ");
            scanf("%d", &b);
            if (b < 0)
            {
                if (szw.empty())
                {
                    flag2 = false;
                    cout << "Вы ничего не доабвили" << endl;
                }
                else
                {
                    flag2 = true;
                    break;
                }
            }
            if (((b >= 1 && b <= 15) || (b >= 17 && b <= 23) || (b >= 31 && b <= 33)) && (a != b))
            {
                flag2 = false;
                std::shared_ptr<Vertex> wer(new Vertex(b, 0)); // флаг = 0 - разрешено
                szw.push_back(wer);
            }
            else
            {
                cout << "Введены неправильные данные" << endl;
            }
        }

        cout << "Цель: " << a << endl;

        std::shared_ptr<Vertex> wer(new Vertex(a, 0));
        sow.push_back(wer);

        cout << "SOW: " << endl;
        for (const auto &element : sow)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "SZW: " << endl;
        for (const auto &element : szw)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "SOP: " << endl;
        for (const auto &element : sop)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "SZP: " << endl;
        for (const auto &element : szp)
        {
            cout << element->data << " ";
        }
        cout << endl;

        while ((fn == true) && (fy == true))
        {
            // cout << "---------------------------------" << endl;
            cout << "---------"
                 << "Шаг № " << counter << " ---------" << endl;
            cout << "Флаги fn и fy: " << fn << " " << fy << endl;

            if ((sow.empty()) && (sop.empty()))
            {
                for (const auto &element : szw)
                {
                    if (element->data == a)
                    {
                        fn = false;
                        fy = true;
                        break;
                    }
                }
            }
            else
            {
                // cout << "1_1" << endl;
                first_elem = sow.front()->data;

                cout << "Вершина стека = " << first_elem << endl;

                find_descendants(first_elem, a);

                cout << "------------" << endl;

                cout << "SOW: " << endl;
                for (const auto &element : sow)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                cout << "SZW: " << endl;
                for (const auto &element : szw)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                cout << "SOP: " << endl;
                for (const auto &element : sop)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                cout << "SZP: " << endl;
                for (const auto &element : szp)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                // fn = false;
                cout << "---------------------------------" << endl;
            }
            counter++;
        }
    }

    // поиск потомков
    void find_descendants(int elem, int cel)
    {
        cout << "---Вызов метода поиска потомков---" << endl;
        // cout << "Вершина: " << elem << endl;
        bool f0 = false, f1 = false, f2 = false, f3 = false;
        int j = 0, i = 0;
        int pravilo;
        while ((i <= list_of_rebro.size() - 1) && (j == 0))
        {
            // cout << "i: " << i << endl;
            // cout << "Ребро №" << i+1 << " " << list_of_rebro[i]->firstNum << " " << list_of_rebro[i]->lastNum << " " << list_of_rebro[i]->metka << endl;
            //  cout << "# " << i << endl;
            //  cout << list_of_rebro[i]->firstNum << " " << list_of_rebro[i]->lastNum << " " << endl;
            f1 = false;
            if ((list_of_rebro[i]->end == elem) && (list_of_rebro[i]->metka == 0))
            {
                // cout << list_of_rebro[i]->lastNum << " = " << elem << " " << list_of_rebro[i]->metka << " = " << "0" << endl;
                if (!(szp.empty()))
                {
                    for (const auto &el : szp)
                    {
                        // cout << el->data << " == " << list_of_rebro[i]->firstNum << " ?" << endl;
                        // cout << list_of_rebro[i]->firstNum << endl;
                        if (el->data == list_of_rebro[i]->start)
                        {
                            f1 = true;
                            i++;
                            break;
                        }
                    }
                    if (f1 == false)
                    {
                        pravilo = list_of_rebro[i]->start;
                        j++;
                    }
                }
                else
                {
                    pravilo = list_of_rebro[i]->start;
                    j++;
                }
            }
            else
            {
                // cout << list_of_rebro[i]->lastNum << " != " << elem << " " << list_of_rebro[i]->metka << " != " << " 0 " << endl;
                i++;
            }
        }

        if (j > 0)
        {
            // cout << "Найдено" << endl;
            // cout << "Ребро №" << i << " " << list_of_rebro[i]->firstNum << " " << list_of_rebro[i]->lastNum << " " << list_of_rebro[i]->metka << endl;

            // cout << "1" << endl;
            // cout << "Добавляем в sop: " << list_of_rebro[i]->firstNum << endl;
            std::shared_ptr<Rule> prv(new Rule(list_of_rebro[i]->start, 0));
            if (!(sop.empty()))
            {
                sop.insert(sop.begin(), prv);
            }
            else
            {
                sop.push_back(prv);
            }

            // cout << "2" << endl;
            vector<int> one_versh;  // вектор с закрытми вершинами
            vector<int> zero_versh; // вектор с открытыми вершинами
            //------------------------------
            for (int id = list_of_rebro.size() - 1; id >= 0; id--)
            {
                f2 = false;
                f3 = false;
                if (list_of_rebro[id]->end == pravilo)
                {
                    // проверка что вершина не в списке закрытых вершин
                    for (const auto &element1 : szw)
                    {
                        if (list_of_rebro[id]->start == element1->data)
                        {
                            f3 = true;
                            if (element1->metka == 0)
                            {
                                f2 = true;
                            }
                        }
                    }

                    if ((f3 == true) && (f2 == true))
                    {
                        one_versh.push_back(list_of_rebro[id]->start);
                    }
                    else if (f3 == false)
                    {
                        zero_versh.push_back(list_of_rebro[id]->start);
                    }
                }
            }

            /*
            cout << "***1***" << endl;
            for (int x : one_versh)
                cout << x << " ";
            cout << endl;
            cout << "******" << endl;
            cout << "***2***" << endl;
            for (int x : zero_versh)
                cout << x << " ";
            cout << endl;
            cout << "******" << endl;
            */
            if ((one_versh.empty() == false) && (zero_versh.empty()))
            {
                // cout << "Все вершины правила покрываются закрытыми (== 1)" << endl;
                marking_method(one_versh, pravilo, cel);
            }
            else if (((one_versh.empty()) && (zero_versh.empty() == false)) || ((one_versh.empty() == false) && (zero_versh.empty() == false)))
            {
                // cout << "Не все вершины правила покрываются закрытыми" << endl;
                for (int i : zero_versh)
                {
                    // for (const auto& element1 : szw)

                    // cout << i << " - эту вершину добавляем в sow" << endl;
                    std::shared_ptr<Vertex> wer(new Vertex(i, 0));
                    if (!(sow.empty()))
                    {
                        sow.insert(sow.begin(), wer);
                    }
                    else
                    {
                        sow.push_back(wer);
                    }
                }
            }

            one_versh.clear();
            zero_versh.clear();

            //------------------------------
        }
        else if (j == 0)
        {
            if (elem == cel)
            {
                // некуда делать backtracking, всё

                // пушим вершину в список закрытых вершин
                std::shared_ptr<Vertex> wer(new Vertex(elem, 1)); // флаг = 1 - запрещено
                szw.push_back(wer);

                // удаялем из sow вершину
                auto iter0 = sow.cbegin();
                sow.erase(iter0);

                fn = false;
            }
            else
            {
                backtracking(elem);
            }
            // backtracking
        }
    }

    // бэктрэкинг
    void backtracking(int zapr_ver)
    {
        cout << "---Вызов backtracking---" << endl;
        int head_rule;

        // пушим вершину в список закрытых вершин
        std::shared_ptr<Vertex> wer(new Vertex(zapr_ver, 1)); // флаг = 1 - запрещено
        szw.push_back(wer);

        // удаялем из sow вершину
        auto iter0 = sow.cbegin();
        sow.erase(iter0);

        head_rule = sop.front()->data;

        // пушим в начало списка szp
        std::shared_ptr<Rule> prv(new Rule(head_rule, 1));
        szp.insert(szp.begin(), prv);

        // удлаяем первый элемент из списка sop
        auto iter = sop.cbegin();
        sop.erase(iter);

        /*

        cout << "Промежуточный sow" << endl;
        for (const auto &element : sow)
        {
            cout << element->data << " ";
        }
        cout << endl;
         */

        // удаляем все вершины раскрывающие текущее правило из sow и также пушим в swz с флагом 1 - запрещено
        for (const auto &element : list_of_rebro)
        {
            if (element->end == head_rule)
            {
                // cout << "Походит: " << element->firstNum << " " << element->lastNum << endl;
                for (int x = 0; x < sow.size(); x++)
                {
                    {
                        if (element->start == sow[x]->data)
                        {
                            // cout << "Удалям из стека sow " << element->firstNum << " == " << sow[x]->data << endl;

                            std::shared_ptr<Vertex> wer(new Vertex(sow[x]->data, 1)); // флаг = 1 - запрещено
                            szw.push_back(wer);

                            sow.erase(sow.begin() + x);
                        }
                    }
                }
            }
        }
    }

    // меод разметки
    void marking_method(vector<int> vec_of_ver, int prvl, int cel)
    {
        bool f0 = false, f1 = false, f2 = false, fn_new = true, fy_new = true;
        // fr = true, fy = true,
        int head_rule, head_ver;

        cout << "---Метод разметки---" << endl;
        /*


        cout << "SOW: " << endl;
        for (const auto &element : sow)
        {
            cout << element->data << " ";
        }
        cout << endl;
         */
        /*


        cout << "Закрытые вершины" << endl;
        for (int x : vec_of_ver)
            cout << x << " ";
        cout << endl;
        cout << "правило: " << prvl << endl;
         */
        // while ((fn == 1) && (fy == 1))
        while ((fn_new == 1) && (fy_new == 1))
        {
            head_rule = sop.front()->data;
            // cout << "правило из sop: " << head_rule << endl;

            // проверяем что головная вершина из sow совпадает, с вершиной в которую приходит правило

            head_ver = sow.front()->data;
            f0 = false;
            f1 = false;
            f2 = false;

            for (int i = 0; i < list_of_rebro.size(); i++)
            {
                if ((list_of_rebro[i]->start == head_rule) && (list_of_rebro[i]->end == head_ver))
                {
                    f0 = true;
                    break;
                }
            }

            if (f0 == false)
            {
                cout << "??Что-то пошло не так 1??" << endl;

                fn = 0; // нет решения
                fn_new = 0;
            }
            else if (f0 == true)
            {
                // cout << cel << " = " << head_ver << endl;
                if (head_ver == cel) // проверка что если выходная вершина правила равно цели
                {

                    fy = 0; // решение найдено
                    fy_new = 0;
                    cout << "!!!!Нашли решение!!!!" << endl;

                    // пушим в начало списка szp
                    std::shared_ptr<Rule> prv(new Rule(head_rule, 1));
                    szp.insert(szp.begin(), prv);

                    // удлаяем первый элемент из списка sop
                    auto iter = sop.cbegin();
                    sop.erase(iter);

                    // пушим вершину в список закрытых вершин
                    std::shared_ptr<Vertex> wer(new Vertex(head_ver, 1)); // флаг = 1 - запрещено
                    szw.push_back(wer);

                    // удаялем из sow вершину
                    auto iter0 = sow.cbegin();
                    sow.erase(iter0);
                }
                else
                {
                    // проверяем закрыты ли все вершины, на которые указывают то же правило, что и текущая вершина

                    // удаляем из sop и пушим в szp правило, которое 100% закрыто

                    // пушим в начало списка szp
                    std::shared_ptr<Rule> prv(new Rule(head_rule, 1));
                    szp.insert(szp.begin(), prv);

                    // удлаяем первый элемент из списка sop
                    auto iter = sop.cbegin();
                    sop.erase(iter);

                    // берем первое парвило из sop
                    head_rule = sop.front()->data;

                    // cout << "Мы еще не у цели" << endl;

                    for (const auto &element : list_of_rebro)
                    {
                        f1 = false;
                        f2 = false;

                        if ((element->start != head_ver) && (element->end == head_rule))
                        {
                            // проверка что веришна в списке закрытых вершин

                            for (const auto &element1 : szw)
                            {
                                if (element1->data == element->start)
                                {
                                    f1 = true;
                                    break;
                                }
                            }

                            // пушим вершину в список закрытых вершин
                            std::shared_ptr<Vertex> wer(new Vertex(head_ver, 1)); // флаг = 1 - запрещено
                            szw.push_back(wer);

                            // удаялем из sow вершину
                            auto iter0 = sow.cbegin();
                            sow.erase(iter0);

                            if (f1 == false)
                            {
                                // проверка что вершина в списке открытых вершин
                                for (const auto &element2 : sow)
                                {
                                    if (element2->data == element->start)
                                    {
                                        f2 = true;
                                        break;
                                    }
                                }

                                if (f2 == false)
                                {
                                    cout << "??Что-то пошло не так 2??" << endl;
                                    fn = 0; // нет решения
                                    fn_new = 0;
                                    break;
                                }
                                else if (f2 == true)
                                {
                                    // вершина есть в sow
                                    // fy = 0;
                                    fy_new = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        /*

        cout << "Последствия неувренности: " << endl;

        cout << "1) sow: " << endl;
        for (const auto &element : sow)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "2) szw: " << endl;
        for (const auto &element : szw)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "3) sop: " << endl;
        for (const auto &element : sop)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "4) szp: " << endl;
        for (const auto &element : szp)
        {
            cout << element->data << " ";
        }
        cout << endl;

        */
    }

    void print()
    {
        cout << "list_of_rebro" << endl;
        for (const auto &element : list_of_rebro)
        {
            cout << element << " " << element->start << " " << element->end << " " << element->metka << "\n";
        }

        cout << "list_of_vershina" << endl;
        for (const auto &element : list_of_vershina)
        {
            cout << element << " " << element->data << " " << element->metka << "\n";
        }

        cout << "list_of_rule" << endl;
        for (const auto &element : list_of_rule)
        {
            cout << element << " " << element->data << " " << element->metka << "\n";
        }
    }

    void poisk_v_shirinu_alghoritm_ot_celi_first()
    {

        // Создание указателя на объект класса Vertex

        std::shared_ptr<Vertex> sp0(new Vertex(0, 0));
        std::shared_ptr<Vertex> sp1(new Vertex(1, 0));
        std::shared_ptr<Vertex> sp2(new Vertex(2, 0));
        std::shared_ptr<Vertex> sp3(new Vertex(3, 0));
        std::shared_ptr<Vertex> sp4(new Vertex(4, 0));
        std::shared_ptr<Vertex> sp5(new Vertex(5, 0));
        std::shared_ptr<Vertex> sp6(new Vertex(6, 0));
        std::shared_ptr<Vertex> sp7(new Vertex(7, 0));
        std::shared_ptr<Vertex> sp8(new Vertex(8, 0));
        std::shared_ptr<Vertex> sp9(new Vertex(9, 0));
        std::shared_ptr<Vertex> sp10(new Vertex(10, 0));
        std::shared_ptr<Vertex> sp11(new Vertex(11, 0));
        std::shared_ptr<Vertex> sp12(new Vertex(12, 0));
        std::shared_ptr<Vertex> sp13(new Vertex(13, 0));
        std::shared_ptr<Vertex> sp14(new Vertex(14, 0));
        std::shared_ptr<Vertex> sp15(new Vertex(15, 0));
        std::shared_ptr<Vertex> sp16(new Vertex(17, 0));
        std::shared_ptr<Vertex> sp17(new Vertex(18, 0));
        std::shared_ptr<Vertex> sp18(new Vertex(19, 0));
        std::shared_ptr<Vertex> sp19(new Vertex(20, 0));
        std::shared_ptr<Vertex> sp20(new Vertex(21, 0));
        std::shared_ptr<Vertex> sp21(new Vertex(22, 0));
        std::shared_ptr<Vertex> sp22(new Vertex(23, 0));
        std::shared_ptr<Vertex> sp23(new Vertex(31, 0));
        std::shared_ptr<Vertex> sp24(new Vertex(33, 0));

        // Добавление указателей в список list_of_vershina

        list_of_vershina.push_back(sp0);
        list_of_vershina.push_back(sp1);
        list_of_vershina.push_back(sp2);
        list_of_vershina.push_back(sp3);
        list_of_vershina.push_back(sp4);
        list_of_vershina.push_back(sp5);
        list_of_vershina.push_back(sp6);
        list_of_vershina.push_back(sp7);
        list_of_vershina.push_back(sp8);
        list_of_vershina.push_back(sp9);
        list_of_vershina.push_back(sp10);
        list_of_vershina.push_back(sp11);
        list_of_vershina.push_back(sp12);
        list_of_vershina.push_back(sp13);
        list_of_vershina.push_back(sp14);
        list_of_vershina.push_back(sp15);
        list_of_vershina.push_back(sp16);
        list_of_vershina.push_back(sp17);
        list_of_vershina.push_back(sp18);
        list_of_vershina.push_back(sp19);
        list_of_vershina.push_back(sp20);
        list_of_vershina.push_back(sp21);
        list_of_vershina.push_back(sp22);
        list_of_vershina.push_back(sp23);
        list_of_vershina.push_back(sp24);

        // Создание указателя на объект класса Rule

        std::shared_ptr<Rule> r0(new Rule(101, 0));
        std::shared_ptr<Rule> r1(new Rule(102, 0));
        std::shared_ptr<Rule> r2(new Rule(103, 0));
        std::shared_ptr<Rule> r3(new Rule(104, 0));
        std::shared_ptr<Rule> r4(new Rule(105, 0));
        std::shared_ptr<Rule> r5(new Rule(106, 0));
        std::shared_ptr<Rule> r6(new Rule(107, 0));
        std::shared_ptr<Rule> r7(new Rule(108, 0));
        std::shared_ptr<Rule> r8(new Rule(109, 0));
        std::shared_ptr<Rule> r9(new Rule(110, 0));
        std::shared_ptr<Rule> r10(new Rule(111, 0));
        std::shared_ptr<Rule> r11(new Rule(112, 0));
        std::shared_ptr<Rule> r12(new Rule(113, 0));
        std::shared_ptr<Rule> r13(new Rule(114, 0));
        std::shared_ptr<Rule> r14(new Rule(115, 0));

        // Добавление указателей в список list_of_rule

        list_of_rule.push_back(r0);
        list_of_rule.push_back(r1);
        list_of_rule.push_back(r2);
        list_of_rule.push_back(r3);
        list_of_rule.push_back(r4);
        list_of_rule.push_back(r5);
        list_of_rule.push_back(r6);
        list_of_rule.push_back(r7);
        list_of_rule.push_back(r9);
        list_of_rule.push_back(r10);
        list_of_rule.push_back(r11);
        list_of_rule.push_back(r12);
        list_of_rule.push_back(r13);
        list_of_rule.push_back(r14);

        // Создание указателя на объект класса Rebro_new

        Vertex vtx1(1, 0);
        Rule rl1(101, 0);
        std::shared_ptr<Rebro_new> rb0(new Rebro_new(vtx1, rl1, 0));

        Vertex vtx2(2, 0);
        Rule rl2(101, 0);
        std::shared_ptr<Rebro_new> rb2(new Rebro_new(vtx2, rl2, 0));

        Vertex vtx3(2, 0);
        Rule rl3(102, 0);
        std::shared_ptr<Rebro_new> rb3(new Rebro_new(vtx3, rl3, 0));

        Vertex vtx4(3, 0);
        Rule rl4(102, 0);
        std::shared_ptr<Rebro_new> rb4(new Rebro_new(vtx4, rl4, 0));

        Vertex vtx5(4, 0);
        Rule rl5(102, 0);
        std::shared_ptr<Rebro_new> rb5(new Rebro_new(vtx5, rl5, 0));

        Vertex vtx6(4, 0);
        Rule rl6(106, 0);
        std::shared_ptr<Rebro_new> rb6(new Rebro_new(vtx6, rl6, 0));

        Vertex vtx7(5, 0);
        Rule rl7(103, 0);
        std::shared_ptr<Rebro_new> rb7(new Rebro_new(vtx7, rl7, 0));

        Vertex vtx8(6, 0);
        Rule rl8(103, 0);
        std::shared_ptr<Rebro_new> rb8(new Rebro_new(vtx8, rl8, 0));

        Vertex vtx9(7, 0);
        Rule rl9(105, 0);
        std::shared_ptr<Rebro_new> rb9(new Rebro_new(vtx9, rl9, 0));

        Vertex vtx10(8, 0);
        Rule rl10(104, 0);
        std::shared_ptr<Rebro_new> rb10(new Rebro_new(vtx10, rl10, 0));

        Vertex vtx11(9, 0);
        Rule rl11(105, 0);
        std::shared_ptr<Rebro_new> rb11(new Rebro_new(vtx11, rl11, 0));

        Vertex vtx12(9, 0);
        Rule rl12(110, 0);
        std::shared_ptr<Rebro_new> rb12(new Rebro_new(vtx12, rl12, 0));

        Vertex vtx13(10, 0);
        Rule rl13(111, 0);
        std::shared_ptr<Rebro_new> rb13(new Rebro_new(vtx13, rl13, 0));

        Vertex vtx14(10, 0);
        Rule rl14(112, 0);
        std::shared_ptr<Rebro_new> rb14(new Rebro_new(vtx14, rl14, 0));

        Vertex vtx15(11, 0);
        Rule rl15(106, 0);
        std::shared_ptr<Rebro_new> rb15(new Rebro_new(vtx15, rl15, 0));

        Vertex vtx16(11, 0);
        Rule rl16(111, 0);
        std::shared_ptr<Rebro_new> rb16(new Rebro_new(vtx16, rl16, 0));

        Vertex vtx17(12, 0);
        Rule rl17(107, 0);
        std::shared_ptr<Rebro_new> rb17(new Rebro_new(vtx17, rl17, 0));

        Vertex vtx18(12, 0);
        Rule rl18(113, 0);
        std::shared_ptr<Rebro_new> rb18(new Rebro_new(vtx18, rl18, 0));

        Vertex vtx19(13, 0);
        Rule rl19(107, 0);
        std::shared_ptr<Rebro_new> rb19(new Rebro_new(vtx19, rl19, 0));

        Vertex vtx20(13, 0);
        Rule rl20(109, 0);
        std::shared_ptr<Rebro_new> rb20(new Rebro_new(vtx20, rl20, 0));

        Vertex vtx21(15, 0);
        Rule rl21(108, 0);
        std::shared_ptr<Rebro_new> rb21(new Rebro_new(vtx21, rl21, 0));

        Vertex vtx22(17, 0);
        Rule rl22(108, 0);
        std::shared_ptr<Rebro_new> rb22(new Rebro_new(vtx22, rl22, 0));

        Vertex vtx23(17, 0);
        Rule rl23(110, 0);
        std::shared_ptr<Rebro_new> rb23(new Rebro_new(vtx23, rl23, 0));

        Vertex vtx24(18, 0);
        Rule rl24(106, 0);
        std::shared_ptr<Rebro_new> rb24(new Rebro_new(vtx24, rl24, 0));

        Vertex vtx25(19, 0);
        Rule rl25(112, 0);
        std::shared_ptr<Rebro_new> rb25(new Rebro_new(vtx25, rl25, 0));

        Vertex vtx26(19, 0);
        Rule rl26(115, 0);
        std::shared_ptr<Rebro_new> rb26(new Rebro_new(vtx26, rl26, 0));

        Vertex vtx27(20, 0);
        Rule rl27(109, 0);
        std::shared_ptr<Rebro_new> rb27(new Rebro_new(vtx27, rl27, 0));

        Vertex vtx28(20, 0);
        Rule rl28(113, 0);
        std::shared_ptr<Rebro_new> rb28(new Rebro_new(vtx28, rl28, 0));

        Vertex vtx29(21, 0);
        Rule rl29(109, 0);
        std::shared_ptr<Rebro_new> rb29(new Rebro_new(vtx29, rl29, 0));

        Vertex vtx30(21, 0);
        Rule rl30(115, 0);
        std::shared_ptr<Rebro_new> rb30(new Rebro_new(vtx30, rl30, 0));

        Vertex vtx31(22, 0);
        Rule rl31(114, 0);
        std::shared_ptr<Rebro_new> rb31(new Rebro_new(vtx31, rl31, 0));

        Vertex vtx32(23, 0);
        Rule rl32(114, 0);
        std::shared_ptr<Rebro_new> rb32(new Rebro_new(vtx32, rl32, 0));

        Vertex vtx33(31, 0);
        Rule rl33(104, 0);
        std::shared_ptr<Rebro_new> rb33(new Rebro_new(vtx33, rl33, 0));

        //-------------------------

        Rule rl34(101, 0);
        Vertex vtx34(3, 0);
        std::shared_ptr<Rebro_new> rb34(new Rebro_new(rl34, vtx34, 0));

        Rule rl35(102, 0);
        Vertex vtx35(7, 0);
        std::shared_ptr<Rebro_new> rb35(new Rebro_new(rl35, vtx35, 0));

        Rule rl36(103, 0);
        Vertex vtx36(4, 0);
        std::shared_ptr<Rebro_new> rb36(new Rebro_new(rl36, vtx36, 0));

        Rule rl37(104, 0);
        Vertex vtx37(3, 0);
        std::shared_ptr<Rebro_new> rb37(new Rebro_new(rl37, vtx37, 0));

        Rule rl38(105, 0);
        Vertex vtx38(14, 0);
        std::shared_ptr<Rebro_new> rb38(new Rebro_new(rl38, vtx38, 0));

        Rule rl39(106, 0);
        Vertex vtx39(9, 0);
        std::shared_ptr<Rebro_new> rb39(new Rebro_new(rl39, vtx39, 0));

        Rule rl40(107, 0);
        Vertex vtx40(11, 0);
        std::shared_ptr<Rebro_new> rb40(new Rebro_new(rl40, vtx40, 0));

        Rule rl41(108, 0);
        Vertex vtx41(33, 0);
        std::shared_ptr<Rebro_new> rb41(new Rebro_new(rl41, vtx41, 0));

        Rule rl42(109, 0);
        Vertex vtx42(19, 0);
        std::shared_ptr<Rebro_new> rb42(new Rebro_new(rl42, vtx42, 0));

        Rule rl43(110, 0);
        Vertex vtx43(14, 0);
        std::shared_ptr<Rebro_new> rb43(new Rebro_new(rl43, vtx43, 0));

        Rule rl44(111, 0);
        Vertex vtx44(9, 0);
        std::shared_ptr<Rebro_new> rb44(new Rebro_new(rl44, vtx44, 0));

        Rule rl45(112, 0);
        Vertex vtx45(17, 0);
        std::shared_ptr<Rebro_new> rb45(new Rebro_new(rl45, vtx45, 0));

        Rule rl46(113, 0);
        Vertex vtx46(10, 0);
        std::shared_ptr<Rebro_new> rb46(new Rebro_new(rl46, vtx46, 0));

        Rule rl47(114, 0);
        Vertex vtx47(12, 0);
        std::shared_ptr<Rebro_new> rb47(new Rebro_new(rl47, vtx47, 0));

        Rule rl48(115, 0);
        Vertex vtx48(17, 0);
        std::shared_ptr<Rebro_new> rb48(new Rebro_new(rl48, vtx48, 0));

        // Добавление указателей в список list_of_rebro

        list_of_rebro.push_back(rb0);
        list_of_rebro.push_back(rb2);
        list_of_rebro.push_back(rb3);
        list_of_rebro.push_back(rb4);
        list_of_rebro.push_back(rb5);
        list_of_rebro.push_back(rb6);
        list_of_rebro.push_back(rb7);
        list_of_rebro.push_back(rb8);
        list_of_rebro.push_back(rb9);
        list_of_rebro.push_back(rb10);
        list_of_rebro.push_back(rb11);
        list_of_rebro.push_back(rb12);
        list_of_rebro.push_back(rb13);
        list_of_rebro.push_back(rb14);
        list_of_rebro.push_back(rb15);
        list_of_rebro.push_back(rb16);
        list_of_rebro.push_back(rb17);
        list_of_rebro.push_back(rb18);
        list_of_rebro.push_back(rb19);
        list_of_rebro.push_back(rb20);
        list_of_rebro.push_back(rb21);
        list_of_rebro.push_back(rb22);
        list_of_rebro.push_back(rb23);
        list_of_rebro.push_back(rb24);
        list_of_rebro.push_back(rb25);
        list_of_rebro.push_back(rb26);
        list_of_rebro.push_back(rb27);
        list_of_rebro.push_back(rb28);
        list_of_rebro.push_back(rb29);
        list_of_rebro.push_back(rb30);
        list_of_rebro.push_back(rb31);
        list_of_rebro.push_back(rb32);
        list_of_rebro.push_back(rb33);
        list_of_rebro.push_back(rb34);
        list_of_rebro.push_back(rb35);
        list_of_rebro.push_back(rb36);
        list_of_rebro.push_back(rb37);
        list_of_rebro.push_back(rb38);
        list_of_rebro.push_back(rb39);
        list_of_rebro.push_back(rb40);
        list_of_rebro.push_back(rb41);
        list_of_rebro.push_back(rb42);
        list_of_rebro.push_back(rb43);
        list_of_rebro.push_back(rb44);
        list_of_rebro.push_back(rb45);
        list_of_rebro.push_back(rb46);
        list_of_rebro.push_back(rb47);
        list_of_rebro.push_back(rb48);

        printf("МЕТОД ПОИСКА В ШИРИНУ\n");
        bool flag1 = false, flag2 = false;
        fn = true;
        fy = true;
        int a, b, head_elem, counter;

        a = -100;
        b = -100;
        counter = 1;
        while (flag1 == false)
        {
            printf("Введите cel (от 1 до 15, от 17 до 23, 31 и 32): ");
            scanf("%d", &a);
            if ((a >= 1 && a <= 15) || (a >= 17 && a <= 23) || (a >= 31 && a <= 33))
            {
                flag1 = true;
            }
        }
        while (flag2 == false)
        {
            printf("Введите входные вершины (от 1 до 15, от 17 до 23, 31 и 32), отличающуюся от cel или < 0, чтобы прекратить ввод: ");
            scanf("%d", &b);
            if (b < 0)
            {
                if (szw.empty())
                {
                    flag2 = false;
                    cout << "Вы ничего не доабвили" << endl;
                }
                else
                {
                    flag2 = true;
                    break;
                }
            }
            if (((b >= 1 && b <= 15) || (b >= 17 && b <= 23) || (b >= 31 && b <= 33)) && (a != b))
            {
                flag2 = false;
                std::shared_ptr<Vertex> wer(new Vertex(b, 0)); // флаг = 0 - разрешено
                szw.push_back(wer);
            }
            else
            {
                cout << "Введены неправильные данные" << endl;
            }
        }

        cout << "Цель: " << a << endl;

        std::shared_ptr<Vertex> wer(new Vertex(a, 0));
        sow.push_back(wer);

        cout << "SOW: " << endl;
        for (const auto &element : sow)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "SZW: " << endl;
        for (const auto &element : szw)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "SOP: " << endl;
        for (const auto &element : sop)
        {
            cout << element->data << " ";
        }
        cout << endl;

        cout << "SZP: " << endl;
        for (const auto &element : szp)
        {
            cout << element->data << " ";
        }
        cout << endl;

        while ((fn == true) && (fy == true))
        {
            // cout << "---------------------------------" << endl;
            cout << "---------"
                 << "Шаг № " << counter << " ---------" << endl;
            cout << "Флаги fn и fy: " << fn << " " << fy << endl;

            if ((sow.empty()) && (sop.empty()))
            {
                for (const auto &element : szw)
                {
                    if (element->data == a)
                    {
                        fn = false;
                        fy = true;
                        break;
                    }
                }
            }
            else
            {
                // cout << "1_1" << endl;

                // head_elem = sow.back()->data;
                head_elem = sow.front()->data;
                ;

                cout << "Первый элемент очереди = " << head_elem << endl;

                find_descendants_in_width(head_elem, a);

                cout << "------------" << endl;

                cout << "SOW: " << endl;
                for (const auto &element : sow)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                cout << "SZW: " << endl;
                for (const auto &element : szw)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                cout << "SOP: " << endl;
                for (const auto &element : sop)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                cout << "SZP: " << endl;
                for (const auto &element : szp)
                {
                    cout << element->data << " ";
                }
                cout << endl;

                fn = false;
                cout << "---------------------------------" << endl;
            }
            counter++;
        }
    }

    void find_descendants_in_width(int elem, int cel)
    {
        cout << "---Вызов метода поиска в ширину---" << endl;
        bool f0 = false, f1 = false, f2 = false, f3 = false, f4 = false;
        int j = 0, i = 0, change_metka;
        int pravilo;

        vector<int> rules;

        while ((i <= list_of_rebro.size() - 1) && (j == 0))
        {
            // cout << list_of_rebro[i]->start << " " << list_of_rebro[i]->end << " = " << elem << " " << list_of_rebro[i]->metka << " = " << "0" << endl;
            f1 = false;
            if (list_of_rebro[i]->end == elem)
            {
                f0 = false;

                // проверка что метка парвила равна 0
                for (int k = 0; k < list_of_rule.size(); k++)
                {
                    if ((list_of_rule[k]->data == list_of_rebro[i]->start) && (list_of_rule[k]->metka == 0))
                    {
                        f0 = true;
                        change_metka = k;
                        break;
                    }
                }

                if (f0 == true)
                {
                    cout << list_of_rebro[i]->start << " " << list_of_rebro[i]->end << " = " << elem << " " << list_of_rebro[i]->metka << " = "
                         << "0" << endl;
                    if (!(szp.empty()))
                    {
                        for (const auto &el : szp)
                        {
                            // cout << el->data << " == " << list_of_rebro[i]->firstNum << " ?" << endl;
                            // cout << list_of_rebro[i]->firstNum << endl;
                            if (el->data == list_of_rebro[i]->start)
                            {
                                f1 = true;
                                i++;
                                break;
                            }
                        }
                        if (f1 == false)
                        {
                            pravilo = list_of_rebro[i]->start;
                            cout << "Нужное правило " << pravilo << endl;
                            rules.push_back(pravilo);

                            // меняем метку на 1
                            list_of_rule[change_metka]->metka = 1;

                            // j++;
                            i++;
                        }
                    }
                    else
                    {
                        pravilo = list_of_rebro[i]->start;
                        cout << "Нужное правило " << pravilo << endl;
                        rules.push_back(pravilo);

                        // меняем метку на 1
                        list_of_rule[change_metka]->metka = 1;

                        // j++;
                        i++;
                    }
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
            // i++;
        }

        for (int x : rules)
            cout << x << " ";
        cout << endl;

        if (rules.empty())
        {
            printf("Вершина последняя не раскрыввет ничего!!!\n");
        }
        else
        {
            cout << "Вершины, которые идут в очередь: " << endl;
            for (int x : rules)
            {
                for (const auto &element : list_of_rebro)
                {
                    if (x == element->end)
                    {
                        f2 = false;

                        cout << element->start << endl;

                        // Проверка что вершина закрытая

                        for (const auto &element1 : szw)
                        {
                            if (element1->data == element->start)
                            {
                                f2 = true;
                                break;
                            }
                        }

                        if (f2 == true)
                        {
                            printf("Вершина %d закрыта!!!\n", element->start);
                            // вершина закрыта
                        }
                        else
                        {

                            // пушим в очередь с проверкой

                            f3 = false;
                            for (const auto &element2 : sow)
                            {
                                if (element2->data == element->start)
                                {
                                    f3 = true;
                                    break;
                                }
                                if (f3 == false)
                                {
                                    // пушим в очередь
                                    std::shared_ptr<Vertex> wer(new Vertex(element->start, 0));
                                    sow.push_back(wer);

                                    // проверяем правило в sow
                                    f4 = false;

                                    for (const auto &element3 : sop)
                                    {
                                        if (element3->data == x)
                                        {
                                            f4 = true;
                                            break;
                                        }
                                    }

                                    if (f4 == false)
                                    {
                                        // пушим в sop
                                        std::shared_ptr<Rule> rl(new Rule(x, 0));
                                        sop.push_back(rl);
                                    }
                                }
                                cout << element2->data << " ";
                            }
                        }

                        cout << endl;
                    }
                }
            }
        }
    }
};

class Rebro
{
public:
    int firstNum, lastNum, metka;
    Rebro(int fn, int ln, int m)
    {
        firstNum = fn;
        lastNum = ln;
        // ves = vs;
        metka = m;
    }
    void print()
    {
        cout << "nodes " << firstNum << " " << lastNum << " "
             << " " << metka;
    }
};

class Vershina
{
public:
    int data, metka;
    Vershina(int d, int m)
    {
        data = d;
        metka = m; // 0 - не помечена, 1 - помечена
    }
};

class Vershina_and_Rule
{
public:
    int data, metka;
    char type;
    Vershina_and_Rule(int d, int m, char t)
    {
        data = d;
        metka = m; // 0 - не помечена, 1 - помечена
        type = t;  // v - врешина, r - правило
    }
};

class Poisk_glub
{
public:
    vector<shared_ptr<Rebro>> list_of_rebro;
    vector<shared_ptr<Vershina>> list_of_vershina;
    vector<shared_ptr<Vershina_and_Rule>> list_of_ver_and_rule;
    vector<shared_ptr<Vershina>> sow;
    vector<shared_ptr<Vershina>> sop;

    vector<shared_ptr<Vershina>> szw;
    vector<shared_ptr<Vershina>> szp;

    Poisk_glub(vector<shared_ptr<Rebro>> list_of_rebro, vector<shared_ptr<Vershina>> list_of_vershina, vector<shared_ptr<Vershina_and_Rule>> list_of_ver_and_rule, vector<shared_ptr<Vershina>> sow, vector<shared_ptr<Vershina>> sop, vector<shared_ptr<Vershina>> szw, vector<shared_ptr<Vershina>> szp)
    {
        this->list_of_rebro = list_of_rebro;
        this->list_of_vershina = list_of_vershina;
        this->list_of_ver_and_rule = list_of_ver_and_rule;
        this->sow = sow;
        this->sop = sop;
        this->szw = szw;
        this->szp = szp;
    }

    void print()
    {
        cout << "list_of_rebro" << endl;
        for (const auto &element : list_of_rebro)
        {
            cout << element << " " << element->firstNum << " " << element->lastNum << " " << element->metka << "\n";
        }

        cout << "list_of_vershina" << endl;
        for (const auto &element : list_of_vershina)
        {
            cout << element << " " << element->data << "\n";
        }

        cout << "szw: " << endl;
        for (const auto &element : szw)
        {
            cout << element << " " << element->data << "\n";
        }

        cout << "sow: " << endl;
        for (const auto &element : sow)
        {
            cout << element << " " << element->data << "\n";
        }
    }

    void alghoritm_ot_celi_first()
    {
        // Создание указателя на объект класса Vershina

        std::shared_ptr<Vershina> sp0(new Vershina(0, 0));
        std::shared_ptr<Vershina> sp1(new Vershina(1, 0));
        std::shared_ptr<Vershina> sp2(new Vershina(2, 0));
        std::shared_ptr<Vershina> sp3(new Vershina(3, 0));
        std::shared_ptr<Vershina> sp4(new Vershina(4, 0));
        std::shared_ptr<Vershina> sp5(new Vershina(5, 0));
        std::shared_ptr<Vershina> sp6(new Vershina(6, 0));
        std::shared_ptr<Vershina> sp7(new Vershina(7, 0));
        std::shared_ptr<Vershina> sp8(new Vershina(8, 0));
        std::shared_ptr<Vershina> sp9(new Vershina(9, 0));

        // Добавление указателей в список list_of_vershina

        list_of_vershina.push_back(sp0);
        list_of_vershina.push_back(sp1);
        list_of_vershina.push_back(sp2);
        list_of_vershina.push_back(sp3);
        list_of_vershina.push_back(sp4);
        list_of_vershina.push_back(sp5);
        list_of_vershina.push_back(sp6);
        list_of_vershina.push_back(sp7);
        list_of_vershina.push_back(sp8);
        list_of_vershina.push_back(sp9);

        // Создание указателя на объект класса Rebro

        std::shared_ptr<Rebro> r0(new Rebro(0, 1, 0));
        std::shared_ptr<Rebro> r1(new Rebro(0, 2, 0));
        std::shared_ptr<Rebro> r2(new Rebro(0, 3, 0));
        std::shared_ptr<Rebro> r3(new Rebro(1, 4, 0));
        std::shared_ptr<Rebro> r4(new Rebro(2, 4, 0));
        std::shared_ptr<Rebro> r5(new Rebro(2, 5, 0));
        std::shared_ptr<Rebro> r6(new Rebro(3, 5, 0));
        std::shared_ptr<Rebro> r7(new Rebro(3, 6, 0));
        std::shared_ptr<Rebro> r8(new Rebro(4, 8, 0));
        std::shared_ptr<Rebro> r9(new Rebro(5, 4, 0));
        std::shared_ptr<Rebro> r10(new Rebro(5, 7, 0));
        std::shared_ptr<Rebro> r11(new Rebro(5, 9, 0));
        std::shared_ptr<Rebro> r12(new Rebro(6, 7, 0));
        std::shared_ptr<Rebro> r13(new Rebro(7, 9, 0));
        std::shared_ptr<Rebro> r14(new Rebro(9, 8, 0));

        // Добавление указателей в список list_of_rebro

        list_of_rebro.push_back(r0);
        list_of_rebro.push_back(r1);
        list_of_rebro.push_back(r2);
        list_of_rebro.push_back(r3);
        list_of_rebro.push_back(r4);
        list_of_rebro.push_back(r5);
        list_of_rebro.push_back(r6);
        list_of_rebro.push_back(r7);
        list_of_rebro.push_back(r8);
        list_of_rebro.push_back(r9);
        list_of_rebro.push_back(r10);
        list_of_rebro.push_back(r11);
        list_of_rebro.push_back(r12);
        list_of_rebro.push_back(r13);

        bool flag1, f2, f3;
        flag1 = false;
        f2 = false; // флаг, что решение есть
        f3 = false; // флаг, что решения нет
        int a, b, first_elem, head, corr;
        a = -100;
        b = -100;
        while (flag1 == false)
        {
            printf("Введите входную вершину (от 0 до 9): ");
            scanf("%d", &a);
            printf("Введите выходную вершину (от 0 до 9), отличающуюся от входной: ");
            scanf("%d", &b);
            if (a >= 0 && a <= 9 && b >= 0 && b <= 9 && a != b)
            {
                flag1 = true;
            }
        }
        cout << a << " " << b << " " << endl;

        // алгоритм поиска в глубина на графе "и"
        // в качестве стека будем использовать контенер sow - список открытых вершин

        std::shared_ptr<Vershina> wer(new Vershina(a, 0));
        sow.push_back(wer);

        // cout << "Верхний элемент стека: " << sow.front()->data << endl;

        cout << "Стек до 'while' (sow): " << endl;
        for (const auto &element : sow)
        {
            cout << element->data << " ";
        }
        cout << endl;

        //---------------------------------------------

        while ((f2 == false) && (f3 == false))
        {
            cout << "--------------------------------------------" << endl;
            // извлекаем первый элемент
            first_elem = sow.front()->data;

            // меняем метку элемента с 0 на 1, т.е. вершина помечена
            for (const auto &element : list_of_vershina)
            {
                if (first_elem == element->data)
                {
                    element->metka = 1;
                    break;
                }
            }

            // проверка на целевую вершину
            if (first_elem == b)
            {
                cout << first_elem << " == " << b << endl;

                f2 = true;
                // break;
            }
            else
            {
                cout << first_elem << " != " << b << endl;
            }

            if (f2 == false)
            {
                // cout << "1) " << endl;
                int idx = 0;
                bool f5 = false;
                corr = -1;

                // раскрываем подцель первым подходящим ребром

                for (const auto &element : list_of_rebro)
                {
                    // cout << "2) " << endl;
                    // cout << "Ребро: " << idx + 1 << " " << element->firstNum << " " << element->lastNum << endl;
                    if (element->firstNum == first_elem)
                    {
                        if (!(szw.empty()))
                        {
                            if (szw.size() > 1)
                            {
                                int j = 0;
                                // cout << "(1), f5 = " << f5 << endl;
                                // cout << "Длина " << szw.size()-1 << endl;
                                while (j <= (szw.size() - 1))
                                {
                                    if (element->lastNum == szw[j]->data)
                                    {
                                        f5 = true;
                                        break;
                                    }
                                    else
                                    {
                                        f5 = false;
                                    }
                                    j++;
                                }
                                // cout << "(4)" << endl;

                                if (f5 == false)
                                {
                                    corr = element->lastNum;
                                    break;
                                }
                            }
                            else if (szw.size() == 1)
                            {
                                if (element->lastNum == szw[0]->data)
                                {
                                    f5 = true;
                                }
                                else
                                {
                                    corr = element->lastNum;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            corr = element->lastNum;
                            break;
                        }
                    }
                    idx++;
                }
                // cout << "3) " << endl;

                // проверка на то, что мы раскрыли подцель
                if (corr == -1)
                {
                    // cout << "4) " << endl;
                    // cout << "__________----_________" << endl;
                    //  у нас из данной вершины никуда нельзя прийти
                    //  бэктрекинг
                    //  удаляем верхний элемент из стека

                    if (sow.empty())
                    {
                        cout << "Стек (sow) пуст" << endl;
                        f3 = true;
                        break;
                    }

                    cout << endl;
                    head = sow.front()->data;
                    // cout << "_1" << endl;
                    std::shared_ptr<Vershina> wer(new Vershina(head, 1));
                    // cout << "_2" << endl;
                    if (!(szw.empty()))
                    {
                        szw.insert(szw.begin(), wer);
                    }
                    else
                    {
                        szw.push_back(wer);
                    }
                    // cout << "_3" << endl;
                    auto iter = sow.cbegin();
                    // cout << "_4" << endl;
                    sow.erase(iter);

                    cout << "Backtracking" << endl;

                    //
                    // break;
                    //
                }
                else
                {
                    cout << "5) " << endl;
                    // нашли вершину
                    //  раскрыли подцель -> пушим вершину в стек и помечаем ребро, как пройденное
                    std::shared_ptr<Vershina> wer(new Vershina(corr, 1));
                    sow.insert(sow.begin(), wer);
                    list_of_rebro[idx]->metka = 1;
                }
            }

            cout << "Стек (sow): " << endl;
            for (const auto &element : sow)
            {
                cout << element->data << " ";
            }
            cout << endl;

            cout << "szw: " << endl;
            for (const auto &element : szw)
            {
                cout << element->data << " ";
            }
            cout << endl;

            cout << "Список ребер: " << endl;
            for (const auto &element : list_of_rebro)
            {
                cout << "[ " << element->firstNum << ", " << element->lastNum << ", " << element->metka << " ]"
                     << "; ";
            }
            cout << endl;

            cout << "Список вершин: " << endl;
            for (const auto &element : list_of_vershina)
            {
                cout << element->data << " - " << element->metka << "; ";
            }
            cout << endl;

            cout << "--------------------------------------------" << endl;

            // f2 = true;
        }

        //---------------------------------------------

        if (f2 == true)
        {
            cout << "Цель полностью раскрыта" << endl;
            cout << "Список открытвх вершин (sow):" << endl;
            for (const auto &element : sow)
            {
                cout << element->data << " ";
            }
            cout << endl;
        }
        else if (f3 == true)
        {
            cout << "Цель не раскрыта" << endl;
            cout << "Список закрытых вершин (szw):" << endl;
            for (const auto &element : szw)
            {
                cout << element->data << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<shared_ptr<Rebro_new>> l_of_rb;
    vector<shared_ptr<Vertex>> l_of_v;
    vector<shared_ptr<Rule>> l_of_rl;
    vector<shared_ptr<Vertex>> s_ow;
    vector<shared_ptr<Rule>> s_op;

    vector<shared_ptr<Vertex>> s_zw;
    vector<shared_ptr<Rule>> s_zp;

    // Poisk_glub ex1(l_of_r, l_of_v, l_of_v_a_r, s_ow, s_op, s_zw, s_zp);

    // ex1.alghoritm_ot_celi_first();

    Graph ex3(l_of_rb, l_of_v, l_of_rl, s_ow, s_op, s_zw, s_zp);

    ex3.poisk_v_glubinu_alghoritm_ot_celi_first();
    
    //ex3.poisk_v_shirinu_alghoritm_ot_celi_first();
    // ex3.print();

    // Rebro_new rb1(v1, r1, 1);

    // rb1.print();

    vector<shared_ptr<Rebro>> l_of_r1;
    vector<shared_ptr<Vershina>> l_of_v1;
    vector<shared_ptr<Vershina_and_Rule>> l_of_v_a_r1;
    vector<shared_ptr<Vershina>> s_ow1;
    vector<shared_ptr<Vershina>> s_op1;

    vector<shared_ptr<Vershina>> s_zw1;
    vector<shared_ptr<Vershina>> s_zp1;

    //Poisk_glub ex1(l_of_r1, l_of_v1, l_of_v_a_r1, s_ow1, s_op1, s_zw1, s_zp1);

    //ex1.alghoritm_ot_celi_first();

    // Poisk_glub_i_ili ex2(l_of_r1, l_of_v1, l_of_v_a_r1, s_ow1, s_op1, s_zw1, s_zp1);

    // ex2.main_algorithm();
    //  ex1.alghoritm_ot_celi_second();
    //  ex1.print();
}
