#include "population.h"
#include "qstd.h"

void test()
{
    qstd::cout<<"Debut du Test\n";

    Personnage p1("Iron",10,10,10,10,10,10);
    Personnage p2("Hulk",5,6,6,9,10,7);
    Personnage p3("Capitaine America",1,1,1,1,1,1);
    Personnage p4("Capitaine Marvel",5,5,5,5,5,5);
    Personnage p5("Wanda",8,8,8,8,8,10);
    Personnage p6("Vision",8,8,8,8,8,8);
    Personnage p7("Loki",8,8,8,8,8,6);
    Personnage p8("Spiderman",9,9,9,9,9,9);


    Population pp1;
    pp1.ajoutePersonnage(&p1);
    pp1.ajoutePersonnage(&p2);
    pp1.ajoutePersonnage(&p3);
    pp1.ajoutePersonnage(&p4);
    pp1.ajoutePersonnage(&p5);
    pp1.ajoutePersonnage(&p6);
    pp1.ajoutePersonnage(&p7);
    pp1.ajoutePersonnage(&p8);


    while(pp1.m_population.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort();
        pp1.combat(pp1.m_population[commbattant],pp1.m_population[adversaire]);
    }

    qstd::cout<<"\nFin des Combat ! \n";

    pp1.listeVictoire();

    pp1.preparationRoundSecondeChance();

    while(pp1.m_populationSecondeChance.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort();
        pp1.combatListeSecondaire(pp1.m_populationSecondeChance[commbattant],pp1.m_populationSecondeChance[adversaire]);
    }
    pp1.listeVictoire();

    pp1.preparationRoundSecondeChance();

    while(pp1.m_population.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort();
        pp1.combat(pp1.m_population[commbattant],pp1.m_population[adversaire]);
    }

}


int main()
{
    qstd::cout<<"Lancement du Test\n";
    test();
    qstd::cout<<"Fin du Test\n";
    return 0;
}
