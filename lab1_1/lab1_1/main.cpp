// Алгоритм прохода в глубину в C++

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

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

class Poisk_glub_i_ili
{
public:
    vector<shared_ptr<Rebro>> list_of_rebro;
    vector<shared_ptr<Vershina>> list_of_vershina;
    vector<shared_ptr<Vershina_and_Rule>> list_of_ver_and_rule;
    vector<shared_ptr<Vershina>> sow;
    vector<shared_ptr<Vershina>> sop;
    vector<shared_ptr<Vershina>> szw;
    vector<shared_ptr<Vershina>> szp;

    // флаги
    bool fr, fn, fy;

    Poisk_glub_i_ili(vector<shared_ptr<Rebro>> list_of_rebro, vector<shared_ptr<Vershina>> list_of_vershina, vector<shared_ptr<Vershina_and_Rule>> list_of_ver_and_rule, vector<shared_ptr<Vershina>> sow, vector<shared_ptr<Vershina>> sop, vector<shared_ptr<Vershina>> szw, vector<shared_ptr<Vershina>> szp)
    {
        this->list_of_rebro = list_of_rebro;
        this->list_of_vershina = list_of_vershina;
        this->list_of_ver_and_rule = list_of_ver_and_rule;
        this->sow = sow;
        this->sop = sop;
        this->szw = szw;
        this->szp = szp;
    }

    // основной алгоритм
    void main_algorithm()
    {
        // ввод данных
        std::shared_ptr<Vershina_and_Rule> sp0(new Vershina_and_Rule(1, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp1(new Vershina_and_Rule(2, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp2(new Vershina_and_Rule(3, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp3(new Vershina_and_Rule(4, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp4(new Vershina_and_Rule(5, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp5(new Vershina_and_Rule(6, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp6(new Vershina_and_Rule(7, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp7(new Vershina_and_Rule(8, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp8(new Vershina_and_Rule(9, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp9(new Vershina_and_Rule(10, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp10(new Vershina_and_Rule(11, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp11(new Vershina_and_Rule(12, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp12(new Vershina_and_Rule(13, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp13(new Vershina_and_Rule(14, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp14(new Vershina_and_Rule(15, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp15(new Vershina_and_Rule(17, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp16(new Vershina_and_Rule(18, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp17(new Vershina_and_Rule(19, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp18(new Vershina_and_Rule(20, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp19(new Vershina_and_Rule(21, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp20(new Vershina_and_Rule(22, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp21(new Vershina_and_Rule(23, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp22(new Vershina_and_Rule(31, 0, 'v'));
        std::shared_ptr<Vershina_and_Rule> sp23(new Vershina_and_Rule(33, 0, 'v'));

        std::shared_ptr<Vershina_and_Rule> sp24(new Vershina_and_Rule(101, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp25(new Vershina_and_Rule(102, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp26(new Vershina_and_Rule(103, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp27(new Vershina_and_Rule(104, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp28(new Vershina_and_Rule(105, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp29(new Vershina_and_Rule(106, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp30(new Vershina_and_Rule(107, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp31(new Vershina_and_Rule(108, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp32(new Vershina_and_Rule(109, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp33(new Vershina_and_Rule(110, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp34(new Vershina_and_Rule(111, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp35(new Vershina_and_Rule(112, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp36(new Vershina_and_Rule(113, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp37(new Vershina_and_Rule(114, 0, 'r'));
        std::shared_ptr<Vershina_and_Rule> sp38(new Vershina_and_Rule(115, 0, 'r'));

        // Добавление указателей в список list_of_vershina

        list_of_ver_and_rule.push_back(sp0);
        list_of_ver_and_rule.push_back(sp1);
        list_of_ver_and_rule.push_back(sp2);
        list_of_ver_and_rule.push_back(sp3);
        list_of_ver_and_rule.push_back(sp4);
        list_of_ver_and_rule.push_back(sp5);
        list_of_ver_and_rule.push_back(sp6);
        list_of_ver_and_rule.push_back(sp7);
        list_of_ver_and_rule.push_back(sp8);
        list_of_ver_and_rule.push_back(sp9);
        list_of_ver_and_rule.push_back(sp10);
        list_of_ver_and_rule.push_back(sp11);
        list_of_ver_and_rule.push_back(sp12);
        list_of_ver_and_rule.push_back(sp13);
        list_of_ver_and_rule.push_back(sp14);
        list_of_ver_and_rule.push_back(sp15);
        list_of_ver_and_rule.push_back(sp16);
        list_of_ver_and_rule.push_back(sp17);
        list_of_ver_and_rule.push_back(sp18);
        list_of_ver_and_rule.push_back(sp19);
        list_of_ver_and_rule.push_back(sp20);
        list_of_ver_and_rule.push_back(sp21);
        list_of_ver_and_rule.push_back(sp22);
        list_of_ver_and_rule.push_back(sp23);
        list_of_ver_and_rule.push_back(sp24);
        list_of_ver_and_rule.push_back(sp25);
        list_of_ver_and_rule.push_back(sp26);
        list_of_ver_and_rule.push_back(sp27);
        list_of_ver_and_rule.push_back(sp28);
        list_of_ver_and_rule.push_back(sp29);
        list_of_ver_and_rule.push_back(sp30);
        list_of_ver_and_rule.push_back(sp31);
        list_of_ver_and_rule.push_back(sp32);
        list_of_ver_and_rule.push_back(sp33);
        list_of_ver_and_rule.push_back(sp34);
        list_of_ver_and_rule.push_back(sp35);
        list_of_ver_and_rule.push_back(sp36);
        list_of_ver_and_rule.push_back(sp37);
        list_of_ver_and_rule.push_back(sp38);

        // Создание указателя на объект класса Rebro

        std::shared_ptr<Rebro> r0(new Rebro(1, 101, 0));
        std::shared_ptr<Rebro> r1(new Rebro(2, 101, 0));
        std::shared_ptr<Rebro> r2(new Rebro(2, 102, 0));
        std::shared_ptr<Rebro> r3(new Rebro(3, 102, 0));
        std::shared_ptr<Rebro> r4(new Rebro(4, 102, 0));
        std::shared_ptr<Rebro> r5(new Rebro(4, 106, 0));
        std::shared_ptr<Rebro> r6(new Rebro(5, 103, 0));
        std::shared_ptr<Rebro> r7(new Rebro(6, 103, 0));
        std::shared_ptr<Rebro> r8(new Rebro(7, 105, 0));
        std::shared_ptr<Rebro> r9(new Rebro(8, 104, 0));
        std::shared_ptr<Rebro> r10(new Rebro(9, 105, 0));
        std::shared_ptr<Rebro> r11(new Rebro(9, 110, 0));
        std::shared_ptr<Rebro> r12(new Rebro(10, 111, 0));
        std::shared_ptr<Rebro> r13(new Rebro(10, 112, 0));
        std::shared_ptr<Rebro> r14(new Rebro(11, 106, 0));
        std::shared_ptr<Rebro> r15(new Rebro(11, 111, 0));
        std::shared_ptr<Rebro> r16(new Rebro(12, 107, 0));
        std::shared_ptr<Rebro> r17(new Rebro(12, 113, 0));
        std::shared_ptr<Rebro> r18(new Rebro(13, 107, 0));
        std::shared_ptr<Rebro> r19(new Rebro(13, 109, 0));
        std::shared_ptr<Rebro> r20(new Rebro(15, 108, 0));
        std::shared_ptr<Rebro> r21(new Rebro(17, 108, 0));
        std::shared_ptr<Rebro> r22(new Rebro(17, 110, 0));
        std::shared_ptr<Rebro> r23(new Rebro(18, 106, 0));
        std::shared_ptr<Rebro> r24(new Rebro(19, 112, 0));
        std::shared_ptr<Rebro> r25(new Rebro(19, 115, 0));
        std::shared_ptr<Rebro> r26(new Rebro(20, 109, 0));
        std::shared_ptr<Rebro> r27(new Rebro(20, 113, 0));
        std::shared_ptr<Rebro> r28(new Rebro(21, 109, 0));
        std::shared_ptr<Rebro> r29(new Rebro(21, 115, 0));
        std::shared_ptr<Rebro> r30(new Rebro(22, 114, 0));
        std::shared_ptr<Rebro> r31(new Rebro(23, 114, 0));
        std::shared_ptr<Rebro> r32(new Rebro(31, 104, 0));

        std::shared_ptr<Rebro> r33(new Rebro(101, 3, 0));
        std::shared_ptr<Rebro> r34(new Rebro(102, 7, 0));
        std::shared_ptr<Rebro> r35(new Rebro(103, 4, 0));
        std::shared_ptr<Rebro> r36(new Rebro(104, 3, 0));
        std::shared_ptr<Rebro> r37(new Rebro(105, 14, 0));
        std::shared_ptr<Rebro> r38(new Rebro(106, 9, 0));
        std::shared_ptr<Rebro> r39(new Rebro(107, 11, 0));
        std::shared_ptr<Rebro> r40(new Rebro(108, 33, 0));
        std::shared_ptr<Rebro> r41(new Rebro(109, 19, 0));
        std::shared_ptr<Rebro> r42(new Rebro(110, 14, 0));
        std::shared_ptr<Rebro> r43(new Rebro(111, 9, 0));
        std::shared_ptr<Rebro> r44(new Rebro(112, 17, 0));
        std::shared_ptr<Rebro> r45(new Rebro(113, 10, 0));
        std::shared_ptr<Rebro> r46(new Rebro(114, 12, 0));
        std::shared_ptr<Rebro> r47(new Rebro(115, 17, 0));

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
        list_of_rebro.push_back(r14);
        list_of_rebro.push_back(r15);
        list_of_rebro.push_back(r16);
        list_of_rebro.push_back(r17);
        list_of_rebro.push_back(r18);
        list_of_rebro.push_back(r19);
        list_of_rebro.push_back(r20);
        list_of_rebro.push_back(r21);
        list_of_rebro.push_back(r22);
        list_of_rebro.push_back(r23);
        list_of_rebro.push_back(r24);
        list_of_rebro.push_back(r25);
        list_of_rebro.push_back(r26);
        list_of_rebro.push_back(r27);
        list_of_rebro.push_back(r28);
        list_of_rebro.push_back(r29);
        list_of_rebro.push_back(r30);
        list_of_rebro.push_back(r31);
        list_of_rebro.push_back(r32);
        list_of_rebro.push_back(r33);
        list_of_rebro.push_back(r34);
        list_of_rebro.push_back(r35);
        list_of_rebro.push_back(r36);
        list_of_rebro.push_back(r37);
        list_of_rebro.push_back(r38);
        list_of_rebro.push_back(r39);
        list_of_rebro.push_back(r40);
        list_of_rebro.push_back(r41);
        list_of_rebro.push_back(r42);
        list_of_rebro.push_back(r43);
        list_of_rebro.push_back(r44);
        list_of_rebro.push_back(r45);
        list_of_rebro.push_back(r46);
        list_of_rebro.push_back(r47);

        bool flag1 = false, flag2 = false;
        int a, b, first_elem, counter;
        fn = true;
        fy = true;
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
                std::shared_ptr<Vershina> wer(new Vershina(b, 0)); // флаг = 0 - разрешено
                szw.push_back(wer);
            }
            else
            {
                cout << "Введены неправильные данные" << endl;
            }
        }

        cout << "Цель: " << a << endl;

        std::shared_ptr<Vershina> wer(new Vershina(a, 0));
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
            //cout << "---------------------------------" << endl;
            cout << "---------" << "Шаг № " << counter << " ---------" << endl;
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

        cout << "Конец метода поиска в глубину: " << endl;
        cout << "Флаги fn и fy: " << fn << " " << fy << endl;
        
        if (fn == false)
        {
            cout << "Нет решения" << endl;
            
        }
        else if (fy == false)
        {
            cout << "Решение есть" << endl;
        }
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
    }

    // поиск потомков
    void find_descendants(int elem, int cel)
    {
        cout << "---Вызов метода поиска потомков---" << endl;
        //cout << "Вершина: " << elem << endl;
        bool f0 = false, f1 = false, f2 = false, f3 = false;
        int j = 0, i = 0;
        int pravilo;
        while ((i <= list_of_rebro.size() - 1) && (j == 0))
        {
            //cout << "i: " << i << endl;
            //cout << "Ребро №" << i+1 << " " << list_of_rebro[i]->firstNum << " " << list_of_rebro[i]->lastNum << " " << list_of_rebro[i]->metka << endl;
            // cout << "# " << i << endl;
            // cout << list_of_rebro[i]->firstNum << " " << list_of_rebro[i]->lastNum << " " << endl;
            f1 = false;
            if ((list_of_rebro[i]->lastNum == elem) && (list_of_rebro[i]->metka == 0))
            {
                //cout << list_of_rebro[i]->lastNum << " = " << elem << " " << list_of_rebro[i]->metka << " = " << "0" << endl;
                if (!(szp.empty()))
                {
                    for (const auto &el : szp)
                    {
                        //cout << el->data << " == " << list_of_rebro[i]->firstNum << " ?" << endl;
                        //cout << list_of_rebro[i]->firstNum << endl;
                        if (el->data == list_of_rebro[i]->firstNum)
                        {
                            f1 = true;
                            i++;
                            break;
                        }
                    }
                    if (f1 == false)
                    {
                        pravilo = list_of_rebro[i]->firstNum;
                        j++;
                    }
                }
                else
                {
                    pravilo = list_of_rebro[i]->firstNum;
                    j++;
                }
            }
            else
            {
                //cout << list_of_rebro[i]->lastNum << " != " << elem << " " << list_of_rebro[i]->metka << " != " << " 0 " << endl;
                i++;
            }
        }

        if (j > 0)
        {
            //cout << "Найдено" << endl;
            //cout << "Ребро №" << i << " " << list_of_rebro[i]->firstNum << " " << list_of_rebro[i]->lastNum << " " << list_of_rebro[i]->metka << endl;

            // cout << "1" << endl;
            //cout << "Добавляем в sop: " << list_of_rebro[i]->firstNum << endl;
            std::shared_ptr<Vershina> prv(new Vershina(list_of_rebro[i]->firstNum, 0));
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
                if (list_of_rebro[id]->lastNum == pravilo)
                {
                    // проверка что вершина не в списке закрытых вершин
                    for (const auto &element1 : szw)
                    {
                        if (list_of_rebro[id]->firstNum == element1->data)
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
                        one_versh.push_back(list_of_rebro[id]->firstNum);
                    }
                    else if (f3 == false)
                    {
                        zero_versh.push_back(list_of_rebro[id]->firstNum);
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
                //cout << "Все вершины правила покрываются закрытыми (== 1)" << endl;
                marking_method(one_versh, pravilo, cel);
            }
            else if (((one_versh.empty()) && (zero_versh.empty() == false)) || ((one_versh.empty() == false) && (zero_versh.empty() == false)))
            {
                //cout << "Не все вершины правила покрываются закрытыми" << endl;
                for (int i : zero_versh)
                {
                    // for (const auto& element1 : szw)

                    //cout << i << " - эту вершину добавляем в sow" << endl;
                    std::shared_ptr<Vershina> wer(new Vershina(i, 0));
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
                std::shared_ptr<Vershina> wer(new Vershina(elem, 1)); // флаг = 1 - запрещено
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
        std::shared_ptr<Vershina> wer(new Vershina(zapr_ver, 1)); // флаг = 1 - запрещено
        szw.push_back(wer);

        // удаялем из sow вершину
        auto iter0 = sow.cbegin();
        sow.erase(iter0);

        head_rule = sop.front()->data;

        // пушим в начало списка szp
        std::shared_ptr<Vershina> prv(new Vershina(head_rule, 1));
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
            if (element->lastNum == head_rule)
            {
                //cout << "Походит: " << element->firstNum << " " << element->lastNum << endl;
                for (int x = 0; x < sow.size(); x++)
                {
                    {
                        if (element->firstNum == sow[x]->data)
                        {
                            //cout << "Удалям из стека sow " << element->firstNum << " == " << sow[x]->data << endl;

                            std::shared_ptr<Vershina> wer(new Vershina(sow[x]->data, 1)); // флаг = 1 - запрещено
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
        //while ((fn == 1) && (fy == 1))
        while ((fn_new == 1) && (fy_new == 1))
        {
            head_rule = sop.front()->data;
            //cout << "правило из sop: " << head_rule << endl;

            // проверяем что головная вершина из sow совпадает, с вершиной в которую приходит правило

            head_ver = sow.front()->data;
            f0 = false;
            f1 = false;
            f2 = false;

            for (int i = 0; i < list_of_rebro.size(); i++)
            {
                if ((list_of_rebro[i]->firstNum == head_rule) && (list_of_rebro[i]->lastNum == head_ver))
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
                //cout << cel << " = " << head_ver << endl;
                if (head_ver == cel) // проверка что если выходная вершина правила равно цели
                {
                    
                    fy = 0; // решение найдено
                    fy_new = 0;
                    cout << "!!!!Нашли решение!!!!" << endl;

                    // пушим в начало списка szp
                    std::shared_ptr<Vershina> prv(new Vershina(head_rule, 1));
                    szp.insert(szp.begin(), prv);

                    // удлаяем первый элемент из списка sop
                    auto iter = sop.cbegin();
                    sop.erase(iter);

                    // пушим вершину в список закрытых вершин
                    std::shared_ptr<Vershina> wer(new Vershina(head_ver, 1)); // флаг = 1 - запрещено
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
                    std::shared_ptr<Vershina> prv(new Vershina(head_rule, 1));
                    szp.insert(szp.begin(), prv);

                    // удлаяем первый элемент из списка sop
                    auto iter = sop.cbegin();
                    sop.erase(iter);

                    // берем первое парвило из sop
                    head_rule = sop.front()->data;

                    //cout << "Мы еще не у цели" << endl;

                    for (const auto &element : list_of_rebro)
                    {
                        f1 = false;
                        f2 = false;

                        if ((element->firstNum != head_ver) && (element->lastNum == head_rule))
                        {
                            // проверка что веришна в списке закрытых вершин

                            for (const auto &element1 : szw)
                            {
                                if (element1->data == element->firstNum)
                                {
                                    f1 = true;
                                    break;
                                }
                            }

                            // пушим вершину в список закрытых вершин
                            std::shared_ptr<Vershina> wer(new Vershina(head_ver, 1)); // флаг = 1 - запрещено
                            szw.push_back(wer);

                            // удаялем из sow вершину
                            auto iter0 = sow.cbegin();
                            sow.erase(iter0);

                            if (f1 == false)
                            {
                                // проверка что вершина в списке открытых вершин
                                for (const auto &element2 : sow)
                                {
                                    if (element2->data == element->firstNum)
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
                                    //fy = 0;
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

    // метод, строящий дерево
    void tree_maker()
    {
        
    }
};

int main()
{
    vector<shared_ptr<Rebro>> l_of_r;
    vector<shared_ptr<Vershina>> l_of_v;
    vector<shared_ptr<Vershina_and_Rule>> l_of_v_a_r;
    vector<shared_ptr<Vershina>> s_ow;
    vector<shared_ptr<Vershina>> s_op;

    vector<shared_ptr<Vershina>> s_zw;
    vector<shared_ptr<Vershina>> s_zp;

    //Poisk_glub ex1(l_of_r, l_of_v, l_of_v_a_r, s_ow, s_op, s_zw, s_zp);

    //ex1.alghoritm_ot_celi_first();
    
    Poisk_glub_i_ili ex2(l_of_r, l_of_v, l_of_v_a_r, s_ow, s_op, s_zw, s_zp);

    ex2.main_algorithm();
    // ex1.alghoritm_ot_celi_second();
    // ex1.print();
}
