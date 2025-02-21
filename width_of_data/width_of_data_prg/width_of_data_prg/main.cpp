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
    Vertex cel_ver;
    // vector<int> input_vertices_connected_and;
    vector<shared_ptr<Vertex>> input_vertices_connected_and;
    Rule(int d, int m, Vertex c_v, vector<shared_ptr<Vertex>> input_vertices) : cel_ver(c_v)
    {
        data = d;
        metka = m; // 0 - открыто, 1 - закрыто , 2 - запрещено
        cel_ver = c_v;
        input_vertices_connected_and = input_vertices; // список вершин, которые связаны "и"
    }
};

class Search_in_graph
{
public:
    vector<shared_ptr<Rule>> list_of_rule;   // список всех правил
    vector<shared_ptr<Vertex>> initial_data; // список всех вершин
    vector<shared_ptr<Vertex>> sow;          // список открытых вершин
    vector<shared_ptr<Rule>> sop;            // список открытых правил
    vector<shared_ptr<Vertex>> szw;          // список закрытых вершин
    vector<shared_ptr<Rule>> szp;            // список закрытых правил
    vector<shared_ptr<Vertex>> sbw;          // список запрещенных вершин
    vector<shared_ptr<Rule>> sbp;            // список запрещенных правил
    int cel_ver, count_of_ver;
    int fn, fy;
    // Vertex vrtx;
    // Rule rul;

    Search_in_graph(vector<shared_ptr<Rule>> l_of_r, int cel, vector<shared_ptr<Vertex>> in_data, int count)
    {
        list_of_rule = l_of_r;
        cel_ver = cel;
        initial_data = in_data;
        count_of_ver = count;
        fn = 1;
        fy = 1;

        for (const auto &element1 : initial_data)
        {
            std::shared_ptr<Vertex> wer(new Vertex(element1->data, 0)); // флаг = 0 - разрешено
            szw.push_back(wer);
        }
    }

    void search_in_width_of_data()
    {
        int count_of_new_rules;
        int c = 1;
        printf("ПОИСК В ШИРИНУ ОТ ДАННЫХ\n");
        while ((fn == 1) && (fy == 1))
        {
            cout << "Шаг: №" << c << endl;
            count_of_new_rules = parent();

            if (count_of_new_rules == 0)
            {
                fn = 0;
            }

            cout << "Список закрытых парвил:" << endl;
            for (const auto &element : szp)
            {
                printf("правило - %d; ", element->data);
            }
            cout << endl;
            cout << "Список закрытых вершин:" << endl;
            for (const auto &element : szw)
            {
                printf("вершина - %d; ", element->data);
            }
            cout << endl;
            c++;
            cout << "--------------------" << endl;
        }
        if (fy == 0)
        {
            printf("Конец алгоритма\n");
            // draw_tree();
        }
        else if (fn == 0)
        {
            printf("Решения нет \n");
        }
    }

    int parent()
    {
        printf("Родители / список закрытых правил \n");
        int idx = 0;
        int number_of_found_rules = 0;
        while ((fy == 1) && (idx < list_of_rule.size()))
        {
            if (list_of_rule[idx]->metka == 0)
            {
                int number_of_close = 0;
                for (const auto &element : list_of_rule[idx]->input_vertices_connected_and)
                {
                    for (const auto &element1 : szw)
                    {
                        if (element->data == element1->data)
                        {
                            number_of_close++;
                            // cout << element->data << " == " << element1->data << endl;
                        }
                    }
                }

                if (list_of_rule[idx]->input_vertices_connected_and.size() == number_of_close)
                {
                    // printf("Кол-во входных вершин совпало с number_of_close = %d \n", number_of_close);
                    printf("Модуль %d доказан \n", list_of_rule[idx]->data);

                    // метку меняем на 1
                    list_of_rule[idx]->metka = 1;

                    // правило пишем в список закрытых правил
                    std::shared_ptr<Rule> new_close_rule(new Rule(list_of_rule[idx]->data, 1, list_of_rule[idx]->cel_ver,
                                                                  list_of_rule[idx]->input_vertices_connected_and));
                    szp.push_back(new_close_rule);

                    // дописываем выходную вершину в список закрытых, с меткой, что доказанно "1"
                    std::shared_ptr<Vertex> new_close_ver(new Vertex(list_of_rule[idx]->cel_ver.data, 1));
                    szw.push_back(new_close_ver);

                    // у всех доказанных вершин флаг установить в 1
                    for (const auto &element : list_of_rule[idx]->input_vertices_connected_and)
                    {
                        for (const auto &element1 : szw)
                        {
                            if (element->data == element1->data)
                            {
                                element1->metka = 1;
                            }
                        }
                    }

                    number_of_found_rules++;

                    // проверяем что конечная вершина = целевой
                    if (list_of_rule[idx]->cel_ver.data == cel_ver)
                    {
                        fy = 0;
                    }
                }

                // переходим к следующему правилу
                idx++;
            }
            else
            {
                idx++;
            }
        }

        return number_of_found_rules;
    }

    void draw_tree()
    {
        vector<shared_ptr<Rule>> l_of_rules;
        printf("Поиск дерева решения из минимального кол-ва правил \n");
        cout << "Список закрытых правил: " << endl;
        for (const auto &element : szp)
        {
            printf("Приавло = %d \n", element->data);
            std::shared_ptr<Rule> new_rule(new Rule(element->data, 0, element->cel_ver, element->input_vertices_connected_and));
            l_of_rules.push_back(new_rule);
        }

        vector<int> all_way;
        int cur_rule, f0;

        cur_rule = l_of_rules[l_of_rules.size() - 1]->data;

        for (int id = l_of_rules.size() - 1; id >= 0; id--)
        {
            if (cur_rule == l_of_rules[id]->data)
            {
                f0 = 0;
                // all_way.push_back(l_of_rules[id]->cel_ver.data);
                for (const auto &element : l_of_rules[id]->input_vertices_connected_and)
                {
                    for (const auto &element1 : l_of_rules)
                    {
                        if (element->data == element1->cel_ver.data)
                        {
                            l_of_rules[id]->metka = 1;
                            all_way.push_back(l_of_rules[id]->data);
                            cur_rule = element1->data;
                            f0 = 1;
                            break;
                        }
                    }

                    if (f0 == 1)
                    {
                        break;
                    }
                }
                if (f0 == 0)
                {
                    break;
                }
            }
        }

        for (int x : all_way)
            cout << x << " ";
        cout << endl;

        for (const auto &element2 : l_of_rules)
        {
            cout << element2->data << " " << element2->metka << endl;
            ;
        }
        cout << endl;
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

    void search_in_width_of_data()
    {
        printf("поиск в ширину от данных");
    }

    void parent()
    {
        printf("Родители/ список закрытых правил");
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

    // Создаем базу знаний
    // 1. Иниициализируем вершины
    Vertex vtx1(1, 0);
    Vertex vtx2(2, 0);
    Vertex vtx3(3, 0);
    Vertex vtx4(4, 0);
    Vertex vtx5(5, 0);
    Vertex vtx6(6, 0);
    Vertex vtx7(7, 0);
    Vertex vtx8(8, 0);
    Vertex vtx9(9, 0);
    Vertex vtx10(10, 0);
    Vertex vtx11(11, 0);
    Vertex vtx12(12, 0);
    Vertex vtx13(13, 0);
    Vertex vtx14(14, 0);
    Vertex vtx15(15, 0);
    Vertex vtx17(17, 0);
    Vertex vtx18(18, 0);
    Vertex vtx19(19, 0);
    Vertex vtx20(20, 0);
    Vertex vtx21(21, 0);
    Vertex vtx22(22, 0);
    Vertex vtx23(23, 0);
    Vertex vtx31(31, 0);
    Vertex vtx33(33, 0);

    // 2. Создаем списки вершин, связанных "и"
    vector<shared_ptr<Vertex>> l1;
    std::shared_ptr<Vertex> wer1(new Vertex(8, 0));
    l1.push_back(wer1);
    l_of_v.push_back(wer1);
    std::shared_ptr<Vertex> wer2(new Vertex(31, 0));
    l1.push_back(wer2);
    l_of_v.push_back(wer2);

    vector<shared_ptr<Vertex>> l2;
    std::shared_ptr<Vertex> wer3(new Vertex(1, 0));
    l2.push_back(wer3);
    l_of_v.push_back(wer3);
    std::shared_ptr<Vertex> wer4(new Vertex(2, 0));
    l2.push_back(wer4);
    l_of_v.push_back(wer4);

    vector<shared_ptr<Vertex>> l3;
    std::shared_ptr<Vertex> wer5(new Vertex(5, 0));
    l3.push_back(wer5);
    l_of_v.push_back(wer5);
    std::shared_ptr<Vertex> wer6(new Vertex(6, 0));
    l3.push_back(wer6);
    l_of_v.push_back(wer6);

    vector<shared_ptr<Vertex>> l4;
    std::shared_ptr<Vertex> wer7(new Vertex(22, 0));
    l4.push_back(wer7);
    l_of_v.push_back(wer7);
    std::shared_ptr<Vertex> wer8(new Vertex(23, 0));
    l4.push_back(wer8);
    l_of_v.push_back(wer8);

    vector<shared_ptr<Vertex>> l5;
    std::shared_ptr<Vertex> wer9(new Vertex(12, 0));
    l5.push_back(wer9);
    l_of_v.push_back(wer9);
    std::shared_ptr<Vertex> wer10(new Vertex(13, 0));
    l5.push_back(wer10);
    l_of_v.push_back(wer10);

    vector<shared_ptr<Vertex>> l6;
    std::shared_ptr<Vertex> wer11(new Vertex(12, 0));
    l6.push_back(wer11);
    l_of_v.push_back(wer11);
    std::shared_ptr<Vertex> wer12(new Vertex(20, 0));
    l6.push_back(wer12);
    l_of_v.push_back(wer12);

    vector<shared_ptr<Vertex>> l7;
    std::shared_ptr<Vertex> wer33(new Vertex(13, 0));
    l7.push_back(wer33);
    l_of_v.push_back(wer33);
    std::shared_ptr<Vertex> wer13(new Vertex(20, 0));
    l7.push_back(wer13);
    l_of_v.push_back(wer13);
    std::shared_ptr<Vertex> wer14(new Vertex(21, 0));
    l7.push_back(wer14);
    l_of_v.push_back(wer14);

    vector<shared_ptr<Vertex>> l8;
    std::shared_ptr<Vertex> wer15(new Vertex(3, 0));
    l8.push_back(wer15);
    l_of_v.push_back(wer15);
    std::shared_ptr<Vertex> wer16(new Vertex(2, 0));
    l8.push_back(wer16);
    l_of_v.push_back(wer16);
    std::shared_ptr<Vertex> wer17(new Vertex(4, 0));
    l8.push_back(wer17);
    l_of_v.push_back(wer17);

    vector<shared_ptr<Vertex>> l9;
    std::shared_ptr<Vertex> wer18(new Vertex(4, 0));
    l9.push_back(wer18);
    l_of_v.push_back(wer18);
    std::shared_ptr<Vertex> wer19(new Vertex(18, 0));
    l9.push_back(wer19);
    l_of_v.push_back(wer19);
    std::shared_ptr<Vertex> wer20(new Vertex(11, 0));
    l9.push_back(wer20);
    l_of_v.push_back(wer20);

    vector<shared_ptr<Vertex>> l10;
    std::shared_ptr<Vertex> wer21(new Vertex(11, 0));
    l10.push_back(wer21);
    l_of_v.push_back(wer21);
    std::shared_ptr<Vertex> wer22(new Vertex(10, 0));
    l10.push_back(wer22);
    l_of_v.push_back(wer22);

    vector<shared_ptr<Vertex>> l11;
    std::shared_ptr<Vertex> wer23(new Vertex(10, 0));
    l11.push_back(wer23);
    l_of_v.push_back(wer23);
    std::shared_ptr<Vertex> wer24(new Vertex(19, 0));
    l11.push_back(wer24);
    l_of_v.push_back(wer24);

    vector<shared_ptr<Vertex>> l12;
    std::shared_ptr<Vertex> wer25(new Vertex(19, 0));
    l12.push_back(wer25);
    l_of_v.push_back(wer25);
    std::shared_ptr<Vertex> wer26(new Vertex(21, 0));
    l12.push_back(wer26);
    l_of_v.push_back(wer26);

    vector<shared_ptr<Vertex>> l13;
    std::shared_ptr<Vertex> wer27(new Vertex(7, 0));
    l13.push_back(wer27);
    l_of_v.push_back(wer27);
    std::shared_ptr<Vertex> wer28(new Vertex(9, 0));
    l13.push_back(wer28);
    l_of_v.push_back(wer28);

    vector<shared_ptr<Vertex>> l14;
    std::shared_ptr<Vertex> wer29(new Vertex(9, 0));
    l14.push_back(wer29);
    l_of_v.push_back(wer29);
    std::shared_ptr<Vertex> wer30(new Vertex(17, 0));
    l14.push_back(wer30);
    l_of_v.push_back(wer30);

    vector<shared_ptr<Vertex>> l15;
    std::shared_ptr<Vertex> wer31(new Vertex(17, 0));
    l15.push_back(wer31);
    l_of_v.push_back(wer31);
    std::shared_ptr<Vertex> wer32(new Vertex(15, 0));
    l15.push_back(wer32);
    l_of_v.push_back(wer32);

    Rule r101(101, 0, vtx3, l2);
    Rule r102(102, 0, vtx7, l8);
    Rule r103(103, 0, vtx4, l3);
    Rule r104(104, 0, vtx3, l1);
    Rule r105(105, 0, vtx14, l13);
    Rule r106(106, 0, vtx9, l9);
    Rule r107(107, 0, vtx11, l5);
    Rule r108(108, 0, vtx33, l15);
    Rule r109(109, 0, vtx19, l7);
    Rule r110(110, 0, vtx14, l14);
    Rule r111(111, 0, vtx9, l10);
    Rule r112(112, 0, vtx17, l11);
    Rule r113(113, 0, vtx10, l6);
    Rule r114(114, 0, vtx12, l4);
    Rule r115(115, 0, vtx17, l12);

    std::shared_ptr<Rule> rul101(new Rule(101, 0, vtx3, l2));
    l_of_rl.push_back(rul101);
    std::shared_ptr<Rule> rul102(new Rule(102, 0, vtx7, l8));
    l_of_rl.push_back(rul102);
    std::shared_ptr<Rule> rul103(new Rule(103, 0, vtx4, l3));
    l_of_rl.push_back(rul103);
    std::shared_ptr<Rule> rul104(new Rule(104, 0, vtx3, l1));
    l_of_rl.push_back(rul104);
    std::shared_ptr<Rule> rul105(new Rule(105, 0, vtx14, l13));
    l_of_rl.push_back(rul105);
    std::shared_ptr<Rule> rul106(new Rule(106, 0, vtx9, l9));
    l_of_rl.push_back(rul106);
    std::shared_ptr<Rule> rul107(new Rule(107, 0, vtx11, l5));
    l_of_rl.push_back(rul107);
    std::shared_ptr<Rule> rul108(new Rule(108, 0, vtx33, l15));
    l_of_rl.push_back(rul108);
    std::shared_ptr<Rule> rul109(new Rule(109, 0, vtx19, l7));
    l_of_rl.push_back(rul109);
    std::shared_ptr<Rule> rul110(new Rule(110, 0, vtx14, l14));
    l_of_rl.push_back(rul110);
    std::shared_ptr<Rule> rul111(new Rule(111, 0, vtx9, l10));
    l_of_rl.push_back(rul111);
    std::shared_ptr<Rule> rul112(new Rule(112, 0, vtx17, l11));
    l_of_rl.push_back(rul112);
    std::shared_ptr<Rule> rul113(new Rule(113, 0, vtx10, l6));
    l_of_rl.push_back(rul113);
    std::shared_ptr<Rule> rul114(new Rule(114, 0, vtx12, l4));
    l_of_rl.push_back(rul114);
    std::shared_ptr<Rule> rul115(new Rule(115, 0, vtx17, l12));
    l_of_rl.push_back(rul115);

    /*
    for (const auto &element1 : l_of_rl)
    {
        cout << "Rule : " << element1->data << " " << element1->metka << " " << element1->cel_ver.data << " " << endl;
        for (const auto &element : element1->input_vertices_connected_and)
        {
            cout << element->data << endl;
        }
    }
     */

    bool flag1 = false, flag2 = false;
    int a, b, counter;

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
        printf("Введите исходных вершины (от 1 до 15, от 17 до 23, 31 и 32), отличающуюся от cel или < 0, чтобы прекратить ввод: ");
        scanf("%d", &b);
        if (b < 0)
        {
            if (s_zw.empty())
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
            s_zw.push_back(wer);
            counter++;
        }
        else
        {
            cout << "Введены неправильные данные" << endl;
        }
    }

    cout << "Цель: " << a << endl;
    printf("Список исходных вершин (в количестве %d): ", counter);
    for (const auto &element : s_zw)
    {
        cout << element->data << " ";
    }
    cout << endl;

    Search_in_graph ex1(l_of_rl, a, s_zw, counter);

    ex1.search_in_width_of_data();
    // Graph ex3(l_of_rb, l_of_v, l_of_rl, s_ow, s_op, s_zw, s_zp);

    // ex3.poisk_v_glubinu_alghoritm_ot_celi_first();
    // ex3.poisk_v_shirinu_alghoritm_ot_celi_first();
    // ex3.print();

    // Rebro_new rb1(v1, r1, 1);

    // rb1.print();

    // Poisk_glub ex1(l_of_r, l_of_v, l_of_v_a_r, s_ow, s_op, s_zw, s_zp);

    // ex1.alghoritm_ot_celi_first();

    // Poisk_glub_i_ili ex2(l_of_r1, l_of_v1, l_of_v_a_r1, s_ow1, s_op1, s_zw1, s_zp1);

    // ex2.main_algorithm();
    //  ex1.alghoritm_ot_celi_second();
    //  ex1.print();
}
