#include <iostream>
#define TRUE 1
#define FALSE 0

using namespace std;

typedef int Boolean;
typedef struct L *Lref; // Тип: указатель на заголовочный узел.
typedef struct T *Tref; // Тип: указатель на дуговой узел.

//Описание типа заголовочного узла.
typedef struct L
{
    int Key; //Имя заголовочного узла.
    int Count; //Количество предшественников.
    Boolean Flag; //Флаг посещения узла при обходе.
    Tref Trail; //Указатель на список смежности.
    Lref Next; //Указатель на следующий узел в списке заголовочных узлов.
} Leader;

//Описание типа дугового узла.
typedef struct T
{
    Lref Id;
    Tref Next;
} Trailer;

//Описание типа узла стека.
typedef Tref TipElement;
typedef struct Zveno *svqz;
typedef struct Zveno
{
    TipElement Element; //Указатель на список смежности.
    svqz Sled;
} St;

class Spisok
{
private:
    Lref Head; //Указатель на голову списка заголовочных узлов.
    Lref Tail; //Указатель на фиктивный элемент
    // в конце списка заголовочных узлов.
    void SearchGraph (int, Lref *);
    void W_S (svqz *, TipElement);
    void YDALENIE (svqz *, TipElement *);
public:
    Spisok() {//Инициализация списка заголовочных узлов.
        Head = Tail =  new (Leader); }
    Lref GetHead() { return Head; }
    Lref GetTail() { return Tail; }
    void MakeGraph ();
    void PrintGraph ();
    void Depth_First_Search (Lref);
    void Depth_First_Search_1 (Lref);
};

int main(int argc, char* argv[])
{
    Spisok A;
    Lref t; //Рабочий указатель для перемещения
    // по списку заголовочных звеньев.
    //Построение графа и вывод его структуры Вирта.
    A.MakeGraph ();
    A.PrintGraph (); cout<<endl;
    //Рекурсивный обход графа в глубину.
    cout<<"Результат рекурсивного обхода...\n";
    t = A.GetHead();
    while (t!=A.GetTail())
    { (*t).Flag = TRUE; t = (*t).Next; }
    A.Depth_First_Search (A.GetHead()); cout<<endl;
    //Нерекурсивный обход графа в глубину.
    cout<<"Результат нерекурсивного обхода...\n";
    t = A.GetHead();
    while (t!=A.GetTail())
    { (*t).Flag = TRUE; t = (*t).Next;}
    A.Depth_First_Search_1 (A.GetHead()); cout<<endl;
}

void Spisok::SearchGraph (int w, Lref *h)
//Функция возвращает указатель на заголовочный узел
//с ключом w в графе, заданном структурой Вирта с указателем Head.
{
    *h = Head; (*Tail).Key = w;
    while ((**h).Key!=w) *h = (**h).Next;
    if (*h==Tail)
        //В списке заголовочных узлов нет узла с ключом w.
        //Поместим его в конец списка Head.
    { Tail = new (Leader); (**h).Count = 0;
        (**h).Trail = NULL; (**h).Next = Tail; }
}

void Spisok::MakeGraph ()
//Функция возвращает указатель Head на структуру
//Вирта, соответствующую ориентированному графу.
{
    int x,y;
    Lref p,q; //Рабочие указатели.
    Tref t,r; //Рабочие указатели.
    Boolean Res; //Флаг наличия дуги.
    cout<<"Вводите начальную вершину дуги: ";
    cin>>x;
    while (x!=0)
    {
        cout<<"Вводите конечную вершину дуги: "; cin>>y;
        //Определим, существует ли в графе дуга (x,y)?
        SearchGraph (x, &p); SearchGraph (y,&q);
        r = (*p).Trail; Res = FALSE;
        while ((r!=NULL)&&(!Res))
            if ((*r).Id==q) Res = TRUE;
            else r = (*r).Next;
        if (!Res) //Если дуга отсутствует, то поместим её в граф.
        { t = new (Trailer); (*t).Id = q;
            (*t).Next = (*p).Trail; (*p).Trail = t; (*q).Count++; }
        cout<<"Вводите начальную вершину дуги: "; cin>>x;
    }
}

void Spisok::PrintGraph ()
//Вывод структуры Вирта, заданной указателем
//Head и соответствующей ориентированному графу.
{
    Lref p; //Рабочий указатель.
    Tref q; //Рабочий указатель.

    p = Head;
    while (p!=Tail)
    {
        cout<<"("<<(*p).Key; q = (*p).Trail;
        while (q!=NULL)
        { cout<<(*(*q).Id).Key; q = (*q).Next; }
        cout<<")"; p = (*p).Next; cout<<" ";
    }
}

void Spisok::W_S (svqz *stk, TipElement el)
//Помещение элемента el в стек stk.
{
    svqz q=new (St);
    (*q).Element = el; (*q).Sled = *stk; *stk = q;
}

void Spisok::YDALENIE (svqz *stk, TipElement *klad)
//Удаление звена из стека, заданного указателем *stk.
//Значение информационного поля удаляемого звена сохраня-
//ется в параметре klad.
{
    svqz q;

    if (*stk==NULL) cout<<"Попытка выбора из пустого стека!\n";
    else
    { *klad = (**stk).Element; q = *stk; *stk = (**stk).Sled; delete q; }
}

void Spisok::Depth_First_Search (Lref r)
//Рекурсивный обход графа в глубину. r - указатель
//на структуру Вирта.
{
    Tref t;

    t = (*r).Trail; cout<<(*r).Key; (*r).Flag = FALSE;
    while (t!=NULL)
    { if ((*(*t).Id).Flag) Depth_First_Search ((*t).Id); t = (*t).Next; }
}

void Spisok::Depth_First_Search_1 (Lref r)
//Нерекурсивный обход графа в глубину.
//r - указатель на структуру Вирта.
{
    Tref t;
    svqz Stack = NULL; //Стек пуст.
    //Посетим первую непосещенную вершину графа и
    //поместим ее указатель на ее список смежности
    //в первоначально пустой стек.
    cout<<(*r).Key; (*r).Flag = FALSE;
    W_S (&Stack,(*r).Trail);
    while (Stack!=NULL)
    { //Рассмотрим "верхушку" стека.
        t = (*Stack).Element;
        if ((*(*t).Id).Trail!=NULL)
        { //У рассматриваемой вершины есть смежные вершины.
            if ((*(*t).Id).Flag)
                //У рассматриваемой вершины есть
                // непосещенные смежные вершины.
            {
                //Посетим рассматриваемую вершину
                // и поместим указатель на ее список смежности в стек.
                cout<< (*(*t).Id).Key; (*(*t).Id).Flag = FALSE;
                W_S (&Stack,(*(*t).Id).Trail);
            }
                //У рассматриваемой вершины нет
                //непосещенных смежных вершин.
            else {
                t = (*Stack).Element;
                if ((*t).Next!=NULL)
                    //Заменяем верхушку стека
                    //указателем на следующий  элемент списка смежности.
                { YDALENIE (&Stack,&t); W_S (&Stack,(*t).Next); }
                    //Удаляем верхушку стека.
                else YDALENIE (&Stack,&t);
            }
        }
            //У рассматриваемой вершины нет смежных вершин.
        else {
            if ((*(*t).Id).Flag) //Посетим рассматриваемую вершину.
            { cout<<(*(*t).Id).Key; (*(*t).Id).Flag = FALSE; }
            t = (*Stack).Element;
            if ((*t).Next!=NULL)
                //Заменяем верхушку стека указателем на следующий
                // элемент списка смежности.
            { YDALENIE (&Stack,&t); W_S (&Stack,(*t).Next); }
                //Удаляем верхушку стека.
            else YDALENIE (&Stack,&t);
        }
    }
}
