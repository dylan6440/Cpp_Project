#include "qstd.cpp"
#include <QTextStream>

int main()
{

    QList<int> liste = {8,9,2,5,6,0,8,9};
    int index;
    int number = 100;

    for(int i =0; i<liste.size();i++)
    {
        if (liste[i]< number)
        {
            number = liste[i];
            index = i;
        }
        qstd::cout<<liste[i]<<"\n";

    }

    qstd::cout<<"Le nombre le plus petit est : "<<number<<" a l'index : "<<index<<".\n";


}
