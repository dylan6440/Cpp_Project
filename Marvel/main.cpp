#include "population.h"

void test()
{
    Personnage p1("Iron",5,10,6,9,5,8);
    Personnage p2("Hulk",5,6,6,9,10,8);

    Population pp1;
    pp1.ajoutePersonnage(&p1);
    pp1.ajoutePersonnage(&p2);

    pp1.combat();

}


int main()
{
    test();

}
