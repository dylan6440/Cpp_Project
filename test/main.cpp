#include "qstd.cpp"
#include <QTextStream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test()
{
    srand(time(NULL));
    int nombre= qrand() % 2;
    int nombreCarac = qrand() % 4;
    //int indexPersonnage = tirageAuSort(m_population);

    if (nombre == 0)
    {
        if (nombreCarac != 0)
        {
            nombreCarac = -nombreCarac ;
        }
    }

    qstd::cout<<"Le nombre est : "<<nombre<<" avec nombre carac : "<<nombreCarac<<".\n";
}
int main()
{

    for(int i =0; i<20; i++)
    {
        test();
    }


}
