// Алгоритм прохода в глубину в C++

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;



class Atom
{
public:
    string field;
    Atom(string f)
    {
        field = f;
    }
};

class Disunct
{
public:
    vector<shared_ptr<Atom>> disunct;
    Disunct(vector<shared_ptr<Atom>> d)
    {
        disunct = d;
    }
    
    void output()
    {
        for (const auto &element : disunct)
        {
            cout << "Дизъюнкт: " << element->field << endl;
        }
    }
};

class Resolventa
{
public:
    vector<shared_ptr<Disunct>> list_of_disunct;
    Resolventa(vector<shared_ptr<Disunct>> l_of_d)
    {
        list_of_disunct = l_of_d;
    }
    
    void resolution()
    {
        vector<shared_ptr<Disunct>> sorted_list;
        vector<int> arr_of_num;
        int max = 0;
        for (int i = 0; i < list_of_disunct.size(); i++) {
            cout << list_of_disunct[i]->disunct.size() << endl;
            if (list_of_disunct[i]->disunct.size() == 1)
            {
                std::shared_ptr<Disunct> ptr(new Disunct(list_of_disunct[i]->disunct));
                sorted_list.push_back(ptr);
            }
            if (list_of_disunct[i]->disunct.size() > max)
            {
                max = list_of_disunct[i]->disunct.size();
            }
            for (int j = 0; j < list_of_disunct[i]->disunct.size(); j++)
                cout << list_of_disunct[i]->disunct[j]->field << " ";
                
            cout << endl;
        }
        
        // стратегия унитарности
        // сортировка
        cout << "Max size: " << max << endl;
        int c = 2;
        while (c <= max)
        {
            for (int k = 0; k < list_of_disunct.size(); k++)
            {
                if (list_of_disunct[k]->disunct.size() == c)
                {
                    std::shared_ptr<Disunct> ptr(new Disunct(list_of_disunct[k]->disunct));
                    sorted_list.push_back(ptr);
                }
            }
            c++;
            if (c > max)
            {
                break;
            }

        }
        
        cout << "---------Отсортированные по атомам дизъюнкты------------" << endl;
        for (int i = 0; i < sorted_list.size(); i++) {
            //cout << sorted_list[i]->disunct.size() << endl;
            for (int j = 0; j < sorted_list[i]->disunct.size(); j++)
                cout << sorted_list[i]->disunct[j]->field << " ";
            cout << endl;
        }
        

        int fl1 = 0, fl2 = 0, fl_for_check = 0, fl_one_atom = 0; // флаг что найдно пустое множество
        int h = 0, counter_of_one_atom = 0, all_one_atom = 0;
        vector<int> list_of_index;
        string atom = "";

        while(fl1 == 0)
        {
            vector<string> atoms;
            if (sorted_list[h]->disunct.size() == 1)
            {
                fl_one_atom = 1;
                if (sorted_list[h]->disunct[0]->field.find("not") != string::npos)
                {
                    cout << "not есть в дизъюнкте " << sorted_list[h]->disunct[0]->field << endl;
                    size_t pos = sorted_list[h]->disunct[0]->field.find("not");
                    //cout << pos << endl;
                    atom = sorted_list[h]->disunct[0]->field.substr(pos + 3, sorted_list[h]->disunct[0]->field.size() - pos + 3);
                    cout << "Атом для поиска в дизъюнктах: " << atom << endl;
                    
                    fl_for_check = 1;
                    
                }
                else
                {
                    cout << "not нету в дизъюнкте " << sorted_list[h]->disunct[0]->field << endl;
                    atom = "not" + sorted_list[h]->disunct[0]->field;
                    cout << "Атом для поиска в дизъюнктах: " << atom << endl;
                    
                    fl_for_check = 2;
                    
                }
                
                for (int i = 0; i < sorted_list.size(); i++)
                {
                    //cout << sorted_list[i]->disunct.size() << endl;
                    if (i != h)
                    {
                        fl2 = 0;
                        for (int j = 0; j < sorted_list[i]->disunct.size(); j++)
                        {
                            //cout << "Атом " << atom << " есть в дизъюнкте " << sorted_list[i]->disunct[j]->field << endl;
                            
                            if (fl_for_check == 1)
                            {
                                if ((sorted_list[i]->disunct[j]->field.find(atom) != string::npos) && !(sorted_list[i]->disunct[j]->field.find("not" + atom) != string::npos))
                                {
                                    fl2 = 1;
                                    cout << "Атом " << atom << " есть в дизъюнкте: " << endl;
                                    
                                    for (int l = 0; l < sorted_list[i]->disunct.size(); l++)
                                    {
                                        cout << sorted_list[i]->disunct[l]->field << " ";
                                    }
                                    cout << endl;
                                    break;
                                }
                            }
                            
                            else if (fl_for_check == 2)
                            {
                                if (sorted_list[i]->disunct[j]->field.find(atom) != string::npos  )
                                {
                                    fl2 = 1;
                                    cout << "Атом " << atom << " есть в дизъюнкте: " << endl;
                                    
                                    for (int l = 0; l < sorted_list[i]->disunct.size(); l++)
                                    {
                                        cout << sorted_list[i]->disunct[l]->field << " ";
                                    }
                                    cout << endl;
                                    break;
                                }
                            }
                        }
                        
                        if (fl2 == 1)
                        {
                            
                            vector<shared_ptr<Atom>> l_temp;

                            
                            if (sorted_list[i]->disunct.size() > 1)
                            {
                                for (int j = 0; j < sorted_list[i]->disunct.size(); j++)
                                {
                                    if (!(sorted_list[i]->disunct[j]->field.find(atom) != string::npos ))
                                    {
                                        //cout << "Atom: " << atom << " " << "Elem: " << sorted_list[h]->disunct[0]->field << " " << sorted_list[i]->disunct[j]->field << endl;
                                        std::shared_ptr<Atom> at_temp(new Atom(sorted_list[i]->disunct[j]->field));
                                        l_temp.push_back(at_temp);
                                    }
                                }
                            }
                            else
                            {
                                // пустое множество
                                std::shared_ptr<Atom> at_temp(new Atom("#"));
                                l_temp.push_back(at_temp);
                                
                                
                            }

                            cout << "Новый дизъюнкт для добавления" << endl;
                            for (const auto &element : l_temp)
                            {
                                cout << element->field << " ";
                            }
                            cout << endl;
                            
                            std::shared_ptr<Disunct> ptr(new Disunct(l_temp));
                            sorted_list.push_back(ptr);
                            
                        }
                    }
                }
            }
            
            // если отсуствуют дизъюнкты из 1 атома, то берем из головы
            if ((sorted_list.size() - 1 == h) && (fl_one_atom == 0))
            {
                h = 0;
                vector<string> atoms_to_find;
                for (int i = 0; i < sorted_list[h]->disunct.size(); i ++)
                {
                    atoms.push_back(sorted_list[h]->disunct[i]->field);
                }
                
                cout << "Дизъюнкт с больше чем 1 атомом" << endl;
                for (int j = 0; j < atoms.size(); j++)
                {
                    cout << atoms[j] << " ";
                }
                cout << endl;
                
                for (int j = 0; j < atoms.size(); j++)
                {
                    if (atoms[j].find("not") != string::npos)
                    {
                        cout << "not есть в атоме " << atoms[j] << endl;
                        size_t pos = atoms[j].find("not");
                        //cout << pos << endl;
                        atom = atoms[j].substr(pos + 3, atoms[j].size() - pos + 3);
                        cout << "Атом для поиска в дизъюнктах: " << atom << endl;
                        atoms_to_find.push_back(atom);
                        
                    }
                    else
                    {
                        cout << "not нету в дизъюнкте " << atoms[j] << endl;
                        atom = "not" + atoms[j];
                        cout << "Атом для поиска в дизъюнктах: " << atom << endl;
                        atoms_to_find.push_back(atom);
                        
                        
                    }

                }
                
                cout << "Атомы для поиска в других дизъюнктах: " << endl;
                for (int j = 0; j < atoms_to_find.size(); j++)
                {
                    cout << atoms_to_find[j] << " ";
                }
                cout << endl;
                
               // ищеи контрарную пару
                
                for (int i = 0; i < sorted_list.size(); i++)
                {
                    if (i != h)
                    {
                        int fl_new = 0;
  
                        for (int m = 0; m < atoms_to_find.size(); m++)
                        {
                            //cout << "fl_new: " << fl_new << endl;
                            
                            
                            for (int j = 0; j < sorted_list[i]->disunct.size(); j++)
                            {
                                if (atoms_to_find[m].find("not") != string::npos)
                                {
                                    if (sorted_list[i]->disunct[j]->field.find(atoms_to_find[m]) != string::npos  )
                                    {
                                        cout << "Атом " << atoms_to_find[m] << " есть в дизъюнкте: " << endl;
                                        for (int l = 0; l < sorted_list[i]->disunct.size(); l++)
                                        {
                                            cout << sorted_list[i]->disunct[l]->field << " ";
                                        }
                                        cout << endl;
                                        //cout << "--" <<fl_new << endl;
                                        fl_new = 1;
                                        //cout << fl_new << endl;
                                        break;
                                    }
                                }
                                else
                                {
                                    if ((sorted_list[i]->disunct[j]->field.find(atoms_to_find[m]) != string::npos) && !(sorted_list[i]->disunct[j]->field.find("not" + atoms_to_find[m]) != string::npos))
                                    {
                                        cout << "Атом " << atoms_to_find[m] << " есть в дизъюнкте: " << endl;
                                        for (int l = 0; l < sorted_list[i]->disunct.size(); l++)
                                        {
                                            cout << sorted_list[i]->disunct[l]->field << " ";
                                        }
                                        cout << endl;
                                        fl_new = 1;
                                        break;
                                    }
                                }
                            }
                            
                            
                            if (fl_new == 1)
                            {
                                //out << "break!" << endl;
                                break;
                            }

                            
                        }
                        
                        
                        
                        
                        if (fl_new == 1)
                        {
                            cout << "---" << endl;
                            vector<shared_ptr<Atom>> l_temp;
                            vector<string> zapr;
                            for (int j = 0; j < sorted_list[i]->disunct.size(); j++)
                            {
                                int flag_5 = 0;
                                cout << "Рассматриваем: " << sorted_list[i]->disunct[j]->field << endl;
                                for (int m = 0; m < atoms_to_find.size(); m++)
                                {
                                    cout << "Сравниавем " << sorted_list[i]->disunct[j]->field << " vs " << atoms_to_find[m] << endl;
                                    if (sorted_list[i]->disunct[j]->field.find(atoms_to_find[m]) != string::npos)
                                    {
                                        flag_5 = 1;
                                        break;
                                    }
                                
                                }
                                
                                if (flag_5 == 0)
                                {
                                    std::shared_ptr<Atom> at_temp(new Atom(sorted_list[i]->disunct[j]->field));
                                    l_temp.push_back(at_temp);
                                }

                            
                            }
                            
                            
                            cout << "Новый дизъюнкт для добавления" << endl;
                            for (const auto &element : l_temp)
                            {
                                cout << element->field << " ";
                            }
                            cout << endl;
                            
                            if (l_temp.empty())
                            {
                                // пустое множество
                                std::shared_ptr<Atom> at_temp(new Atom("#"));
                                l_temp.push_back(at_temp);
                            }
                            
                            std::shared_ptr<Disunct> ptr(new Disunct(l_temp));
                            sorted_list.push_back(ptr);
                            
                            
                        }
                        
                    }
                }
                
                
            }
            
            // проверка, что уже можно получиить пустое множество
            
            
            
            
            
            h++;
            
            
            
            
            
            // для выхода
            
            for (int i = 0; i < sorted_list.size(); i++) {
                //cout << sorted_list[i]->disunct.size() << endl;
                for (int j = 0; j < sorted_list[i]->disunct.size(); j++)
                    if (sorted_list[i]->disunct[j]->field == "#")
                    {
                        fl1 = 1;
                        break;
                    }
                if (fl1 == 1)
                {
                    break;
                }
            }
            
            //if (h == 5)
            //{
            //    fl1 = 1;
            //}
            
            //подсчет сколько дизъюнктов с 1 атомом
            
        }
        
        cout << "---------С новыми дизъюнктами ------------" << endl;
        for (int i = 0; i < sorted_list.size(); i++) {
            //cout << sorted_list[i]->disunct.size() << endl;
            for (int j = 0; j < sorted_list[i]->disunct.size(); j++)
                cout << sorted_list[i]->disunct[j]->field << " ";
            cout << endl;
        }
        
        
    }
    
};


int main()
{
    vector<string> K;
    vector<vector<string>> list_of_sep_dis;
    string resolveta;
    
    vector<shared_ptr<Disunct>> d1;
    
    
    vector<shared_ptr<Atom>> l1;
    std::shared_ptr<Atom> at1(new Atom("A"));
    std::shared_ptr<Atom> at2(new Atom("B"));

    l1.push_back(at1);
    l1.push_back(at2);
    
    Disunct dis1(l1);
    
    std::shared_ptr<Disunct> p1(new Disunct(l1));
    d1.push_back(p1);

    
    vector<shared_ptr<Atom>> l2;
    std::shared_ptr<Atom> at3(new Atom("notA"));
    std::shared_ptr<Atom> at4(new Atom("C"));

    l2.push_back(at3);
    l2.push_back(at4);
    
    Disunct dis2(l2);
    
    std::shared_ptr<Disunct> p2(new Disunct(l2));
    d1.push_back(p2);
    
    vector<shared_ptr<Atom>> l3;
    std::shared_ptr<Atom> at5(new Atom("notB"));
    std::shared_ptr<Atom> at6(new Atom("D"));

    l3.push_back(at5);
    l3.push_back(at6);
    
    Disunct dis3(l3);
    
    std::shared_ptr<Disunct> p3(new Disunct(l3));
    d1.push_back(p3);
    
    
    vector<shared_ptr<Atom>> l4;
    std::shared_ptr<Atom> at7(new Atom("notC"));
    //std::shared_ptr<Atom> at9(new Atom("D")); // optional

    l4.push_back(at7);
    //l4.push_back(at9); // optional
    
    
    Disunct dis4(l4);

    std::shared_ptr<Disunct> p4(new Disunct(l4));
    d1.push_back(p4);
    
    vector<shared_ptr<Atom>> l5;
    std::shared_ptr<Atom> at8(new Atom("notD"));
    //std::shared_ptr<Atom> at10(new Atom("notA")); // optional
    //std::shared_ptr<Atom> at11(new Atom("notB")); // optional
    
    

    l5.push_back(at8);
    //l5.push_back(at10); // optional
    //l5.push_back(at11); // optional
    
    std::shared_ptr<Disunct> p5(new Disunct(l5));
    d1.push_back(p5);
    
    
    Disunct dis5(l5);
    
    dis1.output();
    dis2.output();
    dis3.output();
    dis4.output();
    dis5.output();

    Resolventa r1(d1);
    r1.resolution();
    
    /*    int j = 0;
    while (j == 0)
    {
        printf("Введите резольвенту или путсую строку, чтобы остановить ввод: ");
        getline(cin, resolveta);
        if (!(resolveta.empty()))
        {
            if (resolveta.find('|') != string::npos)
            {
                cout << '|' << endl;
                cout << resolveta << endl;
                
                
                vector<int> list_of_pos;
            
                
                for (int i = 0; i < resolveta.size(); i++)
                {
                    if (resolveta[i] == '|')
                    {
                        list_of_pos.push_back(i);
                    }
                }
                
                for (int x : list_of_pos)
                {
                    cout << "Поизиция |: " << x << ", ";
                }
                cout << endl;
                
                
                vector<string> separate_dis;
                for (int i = 0; i < list_of_pos.size(); i++)
                {
                    if (i == 0)
                    {
                        string sub = resolveta.substr(0, list_of_pos[i]);
                        cout << "Подстрока 0: " << sub << "; ";
                        separate_dis.push_back(sub);
                        string sub1 = resolveta.substr(list_of_pos[i] + 1, list_of_pos[i + 1] - list_of_pos[i] - 1);
                        cout << "Подстрока 1: " << sub1 << "; ";
                        separate_dis.push_back(sub1);
                    }
                    else if (i != list_of_pos.size() - 1)
                    {
                        string sub = resolveta.substr(list_of_pos[i] + 1, list_of_pos[i + 1] - list_of_pos[i] - 1);
                        cout << "Подстрока: " << sub << "; ";
                        separate_dis.push_back(sub);
                    }
                    else if (i == list_of_pos.size() - 1)
                    {
                        string sub = resolveta.substr(list_of_pos[i] + 1, list_of_pos.size() - list_of_pos[i]);
                        cout << "Подстрока: " << sub << "; ";
                        separate_dis.push_back(sub);
                    }
                    cout << endl;
                }
                
                list_of_sep_dis.push_back(separate_dis);
                
                
            }
            else if (resolveta.find("not") != string::npos)
            {
                cout << "not" << endl;
                cout << resolveta << endl;
            }
            K.push_back(resolveta);
        }
        else
        {
            j++;
        }
        
    }
    
    for (int i = 0; i < list_of_sep_dis.size(); i++) {
        for (int j = 0; j < list_of_sep_dis[i].size(); j++)
            cout << list_of_sep_dis[i][j] << " ";
        cout << endl;
    }
    
    for (string x : K)
        cout << x << ", ";
    cout << endl;

     */

    
    
}
