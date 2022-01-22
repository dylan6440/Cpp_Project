#include "qstd.cpp"

int main()
{
    int size = 20;
    int condi = 0;
    while (condi < 100)
    {
        int num = 1+(qrand()%(size-1));
        qstd::cout<<num<<" \n";
        condi++;
    }

}
