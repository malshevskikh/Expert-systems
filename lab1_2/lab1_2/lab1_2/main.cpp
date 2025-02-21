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
        //ves = vs;
        metka = m;
    }
    void print()
    {
        cout << "nodes " << firstNum << " " << lastNum << " " << " " << metka;
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
        type = t; // v - врешина, r - правило
    }
};


class Poisk_shirinu
{
public:
    vector<shared_ptr<Rebro>> list_of_rebro;
    vector<shared_ptr<Vershina>> list_of_vershina;
    vector<shared_ptr<Vershina_and_Rule>> list_of_ver_and_rule;
    vector<shared_ptr<Vershina>> sow;
    vector<shared_ptr<Vershina>> sop;
    vector<shared_ptr<Vershina>> szw;
    vector<shared_ptr<Vershina>> szp;
    
    //флаги
    bool fr, fn, fy;
    
    Poisk_shirinu(vector<shared_ptr<Rebro>> list_of_rebro, vector<shared_ptr<Vershina>> list_of_vershina, vector<shared_ptr<Vershina_and_Rule>> list_of_ver_and_rule, vector<shared_ptr<Vershina>> sow, vector<shared_ptr<Vershina>> sop, vector<shared_ptr<Vershina>> szw, vector<shared_ptr<Vershina>> szp)
    {
        this->list_of_rebro = list_of_rebro;
        this->list_of_vershina = list_of_vershina;
        this->list_of_ver_and_rule = list_of_ver_and_rule;
        this->sow = sow;
        this->sop = sop;
        this->szw = szw;
        this->szp = szp;
    }
    
    //основной алгоритм
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
        int a, b, first_elem;
        fn = true;
        fy = true;
        a = -100;
        b = -100;
        while (flag1 == false) {
            printf("Введите cel (от 1 до 15, от 17 до 23, 31 и 32): ");
            scanf("%d", &a);
            if((a >= 1 && a <= 15) || (a>= 17 && a <= 23) || (a >= 31 && a <= 33))
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
        
        cout << "a: " << a << endl;
        
        std::shared_ptr<Vershina> wer(new Vershina(a, 0));
        sow.push_back(wer);
        
        cout << "szw: " << endl;
        for (const auto& element : szw)
        {
            cout << element->data << " ";
        }
        cout << endl;
        
        
        while ((fn == true) && (fy == true))
        {
            cout << "^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            first_elem = sow.front()->data; //извлекаем вершину из стека sow
            
            find_descendants(first_elem, a); // вызов метода потмоков
            
            cout << "sow: " << endl;
            for (const auto& element : sow)
            {
                cout << element->data << " ";
            }
            cout << endl;
            
            cout << "szw: " << endl;
            for (const auto& element : szw)
            {
                cout << element->data << " - " << element->metka << "; ";
            }
            cout << endl;
            
            cout << "sop: " << endl;
            for (const auto& element : sop)
            {
                cout << element->data << " - " << element->metka << "; ";
            }
            cout << endl;
            
            
            cout << "szp: " << endl;
            for (const auto& element : szp)
            {
                cout << element->data << " - " << element->metka << "; ";
            }
            cout << endl;
            cout << "<><><><><><><><><><><><><>" << endl;
        }
        
    }
    
    void find_descendants(int head_el, int cel)
    {
        
        bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
        bool f2, f3, f4;
        cout << "метод поиска потомков" << endl;
        
        // чтое если конец графа
        // пушим вершину в список закрытых вершин
        std::shared_ptr<Vershina> wer(new Vershina(head_el, 1)); // флаг = 1 - запрещено
        szw.push_back(wer);
        
        //удаялем из sow вершину
        auto iter0 = sow.cbegin();
        sow.erase(iter0);
        
        
        //проходим по базе парвил, чтобы найти подходящее
        for (int i = 0; i < list_of_rebro.size(); i++)
        {
            flag1 = false;
            if ((list_of_rebro[i]->lastNum == head_el) && (list_of_rebro[i]->metka == 0))
            {
                flag4 = true;
                cout << "----" << endl;
                cout << "Подходит правило: " << list_of_rebro[i]->firstNum << endl;
                
                
                vector<int> one_versh;  // вектор с закртыми вершинами
                vector<int> zero_versh; // вектор с открытыми вершинами
                vector<int> all_versh;
                
                for (int j = 0; j < list_of_rebro.size(); j++)
                {
                    f2 = false;
                    f3 = false;
                    
                    if (list_of_rebro[j]->lastNum == list_of_rebro[i]->firstNum)
                    {
                        // проверка что вершина не в списке закрытых вершин
                        for (const auto &element1 : szw)
                        {
                            if (list_of_rebro[j]->firstNum == element1->data)
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
                            one_versh.push_back(list_of_rebro[j]->firstNum);
                            //
                            all_versh.push_back(list_of_rebro[j]->firstNum);
                            
                        }
                        else if (f3 == false)
                        {
                            zero_versh.push_back(list_of_rebro[j]->firstNum);
                            //
                            all_versh.push_back(list_of_rebro[j]->firstNum);
                        }
                        
                    }
                    
                }
                
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
                
                if ((one_versh.empty() == false) && (zero_versh.empty()))
                {
                    cout << "Все вершины правила покрываются закрытыми (== 1)" << endl;
                    //marking_method(one_versh, pravilo, cel);
                }
                else if (zero_versh.empty() == false)
                {
                    if (one_versh.empty())
                    {
                        cout << "Все вершины правила не покрываются закрытыми" << endl;
                        for (int i : zero_versh)
                        {
                            // for (const auto& element1 : szw)
                            
                            cout << i << " - эту вершину добавляем в sow" << endl;
                            
                            
                            std::shared_ptr<Vershina> wer(new Vershina(i, 0));
                            if (!(sow.empty()))
                            {
                                f4 = false;
                                for (const auto& e : sow)
                                {
                                    if (e->data == i)
                                    {
                                        f4 = true;
                                        break;
                                    }
                                }
                                
                                if (f4 == false)
                                {
                                    sow.push_back(wer);
                                    //sow.insert(sow.begin(), wer);
                                }
                                
                            }
                            else
                            {
                                sow.push_back(wer);
                            }
                        }

                    }
                    else if (one_versh.empty() == false)
                    {
                        cout << "Не все вершины правила покрываются закрытыми" << endl;
                        for (int i : all_versh)
                        {
                            // for (const auto& element1 : szw)
                            
                            cout << i << " - эту вершину добавляем в sow" << endl;
                            
                            
                            std::shared_ptr<Vershina> wer(new Vershina(i, 0));
                            if (!(sow.empty()))
                            {
                                f4 = false;
                                for (const auto& e : sow)
                                {
                                    if (e->data == i)
                                    {
                                        f4 = true;
                                        break;
                                    }
                                }
                                
                                if (f4 == false)
                                {
                                    sow.push_back(wer);
                                    //sow.insert(sow.begin(), wer);
                                }
                                
                            }
                            else
                            {
                                sow.push_back(wer);
                            }
                        }
                    }
                }

                one_versh.clear();
                zero_versh.clear();
                all_versh.clear();
                
                
                /*
                 
                
                
                for (int j = 0; j < list_of_rebro.size(); j++)
                {
                    if (list_of_rebro[i]->firstNum == list_of_rebro[j]->lastNum)
                    {
                        cout << "Подходит вершина: " << list_of_rebro[j]->firstNum << endl;
                        
                        // проверка, что вершина является закрытой
                        flag2 = false;
                        
                        for (int k = 0; k < szw.size(); k++)
                        {
                            if ((szw[k]->data == list_of_rebro[j]->firstNum) && (szw[k]->metka == 0))
                            {
                                // вершина в закрытых
                                
                                // метод разметки
                                flag2 = true;
                                
                                // проверка, что дргуие вершины, указывающие на текущее парвило также закрыты
                                
                                for (const auto& el : list_of_rebro)
                                {
                                    if ((el->lastNum == list_of_rebro[i]->firstNum) && (el->firstNum != list_of_rebro[j]->firstNum))
                                    {
                                        for (const auto& el1 : szw)
                                        {
                                            if (el1->data == el->firstNum)
                                            {
                                                // соседняя вершина в закрытых
                                                flag5 = true;
                                                
                                                
                                            }
                                        }
                                    }
                                }
                                
                                
                                marking_method(list_of_rebro[j]->firstNum, list_of_rebro[i]->firstNum, cel);
                                //
                                fn = false;
                                fy = false;
                                //
                            }
                            else if ((szw[k]->data == list_of_rebro[j]->firstNum) && (szw[k]->metka == 1))
                            {
                                flag2 = true;
                                break;
                            }
                        }
                        
                        if (flag2 == false)
                        {
                            // вершины нету в закрытых => пушим в sow
                            
                            // проверяем, что вершины нету в sow
                            
                            flag3 = false;
                            
                            if (!(sow.empty()))
                            {
                                for (int l = 0; l < sow.size(); l++)
                                {
                                    if (sow[l]->data == list_of_rebro[j]->firstNum)
                                    {
                                        flag3 = true;
                                        break;
                                    }
                                }
                            }
                            
                            if (flag3 == false)
                            {
                                std::shared_ptr<Vershina> wer(new Vershina(list_of_rebro[j]->firstNum, 0)); // флаг = 0 - разрешено
                                sow.push_back(wer);
                            }
                            
                        }
                        
                    }
                }
                
                */
                
                // пушим в начало списка szp
                std::shared_ptr<Vershina> prv(new Vershina(list_of_rebro[i]->firstNum, 2));
                sop.insert(sop.begin(), prv);
                
                // удлаяем первый элемент из списка sop
                //auto iter = sop.cbegin();
                //sop.erase(iter);
                
                cout << "----" << endl;
                
            }
            
        }
        
        if (flag4 == false)
        {
            //у вершины нет потомков
            // не уверен
            
            
        }
        //-------
        //fn = false;
        //fy = false;
        //-------
        
        
    }
    
    
    // меод разметки
    void marking_method(int crnt_ver, int crnt_prv, int cel)
    {
        cout << "#######" << endl;
        cout << "Метод разметки" << endl;
        
        cout << "Текущая вершина: " << crnt_ver << endl;
        cout << "Текущее правило: " << crnt_prv << endl;
        cout << "Текущая цель: " << cel << endl;
        
        
        bool fr = true, fy = true;
        
        while ((fr == 1) && (fy == 1))
        {
            
        }
        
        
        
        cout << "sow: " << endl;
        for (const auto& element : sow)
        {
            cout << element->data << " ";
        }
        cout << endl;
        
        cout << "szw: " << endl;
        for (const auto& element : szw)
        {
            cout << element->data << " - " << element->metka << "; ";
        }
        cout << endl;
        
        cout << "sop: " << endl;
        for (const auto& element : sop)
        {
            cout << element->data << " - " << element->metka << "; ";
        }
        cout << endl;
        
        
        cout << "szp: " << endl;
        for (const auto& element : szp)
        {
            cout << element->data << " - " << element->metka << "; ";
        }
        cout << endl;
        
        cout << "#######" << endl;
    }
    
};



int main(int argc, const char * argv[]) 
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
    
    Poisk_shirinu ex2(l_of_r, l_of_v, l_of_v_a_r, s_ow, s_op, s_zw, s_zp);
    
    ex2.main_algorithm();
}
