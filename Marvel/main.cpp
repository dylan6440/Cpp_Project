#include "population.h"
#include "qstd.h"

/**********************************************************************************/
void combatListeSecondaire(Population pp1, QList<Personnage *> liste)
{
    while(liste.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(liste);
        pp1.combatListeSecondaire(liste[commbattant],liste[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }
}
/**********************************************************************************/
void combatListePrincipale(Population pp1, QList<Personnage *> liste)
{
    while(liste.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(liste);
        pp1.combat(liste[commbattant],liste[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }
}
/**********************************************************************************/
QString generation(Population pp1)
{
     qstd::cout<<"\n------------------------------------------------------\n";
    std::random_shuffle(pp1.m_population.begin(),pp1.m_population.end());
     qstd::cout<<"\n------------------------------------------------------\n";
    pp1.eventAleatoire();
    // premier round liste principale 20 perso
    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_population.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_population);
        pp1.combat(pp1.m_population[commbattant],pp1.m_population[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }

    qstd::cout<<"\nFin des Combat ! \n";

    //pp1.listeVictoire();

    pp1.preparationRoundSecondeChance();

    // premier round liste secondaire 10 perso
    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_populationSecondeChance.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_populationSecondeChance);
        pp1.combatListeSecondaire(pp1.m_populationSecondeChance[commbattant],pp1.m_populationSecondeChance[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }

    //pp1.listeVictoire();

    // mettre les vainqueure dans la liste secondaire
    pp1.preparationRound();
    // eliminer le plus faible des vainqueure de la liste secondaire
    pp1.m_populationSecondeChance = pp1.supressionDuPlusFaible(pp1.m_populationSecondeChance);
    // il reste 4 joueur
    // les 4 s'affronte
    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_populationSecondeChance.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_populationSecondeChance);
        pp1.combatListeSecondaire(pp1.m_populationSecondeChance[commbattant],pp1.m_populationSecondeChance[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }
    // il reste 2 personne qui s'affronte
    pp1.preparationRound();
    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_populationSecondeChance.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_populationSecondeChance);
        pp1.combatListeSecondaire(pp1.m_populationSecondeChance[commbattant],pp1.m_populationSecondeChance[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }
    // il en reste 1

    //pp1.listeVictoire();
    pp1.preparationRound();

    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_population.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_population);
        pp1.combat(pp1.m_population[commbattant],pp1.m_population[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }

    //pp1.listeVictoire();

    pp1.supressionDeListe();

    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_population.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_population);
        pp1.combat(pp1.m_population[commbattant],pp1.m_population[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }

    //pp1.listeVictoire();


    pp1.preparationRoundSecondeChance();

    pp1.m_populationSecondeChance = pp1.supressionDuPlusFaible(pp1.m_populationSecondeChance);
    // il reste 2 joueur
    // les 2 s'affronte
    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_populationSecondeChance.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_populationSecondeChance);
        pp1.combatListeSecondaire(pp1.m_populationSecondeChance[commbattant],pp1.m_populationSecondeChance[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }

    //pp1.listeVictoire();

    pp1.supressionDeListe();

    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_population.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_population);
        pp1.combat(pp1.m_population[commbattant],pp1.m_population[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }

    //pp1.listeVictoire();

    pp1.supressionDeListe();

    qstd::cout<<"\n------------------------------------------------------\n";
    while(pp1.m_population.size()>0)
    {
        qstd::cout<<"\nNouveau Combat ! \n";
        int commbattant = 0;
        int adversaire = pp1.tirageAuSort(pp1.m_population);
        pp1.combat(pp1.m_population[commbattant],pp1.m_population[adversaire]);
        qstd::cout<<"\n------------------------------------------------------\n";
    }

    //pp1.listeVictoire();

    pp1.supressionDeListe();

    QString res;

    pp1.m_population[0]->setVictoire(1);

    res = pp1.Vainqueur();

    pp1.ajoutCarac(pp1.m_populationTampon);

    pp1.m_population += pp1.m_populationTampon;

    pp1.m_populationTampon.empty();

    return res;
}
/**********************************************************************************/
int main()
{
        Personnage p1("Iron Man",5,10,6,9,5,10);
        Personnage p2("Thor",10,5,5,8,8,8);
        Personnage p3("Capitaine America",6,6,6,2,5,4);
        Personnage p4("Hulk",10,6,4,4,10,7);
        Personnage p5("Black Widow",4,9,8,2,2,10);
        Personnage p6("Capitaine Marvel",7,6,7,10,6,2);
        Personnage p7("Spiderman",7,8,10,4,2,7);
        Personnage p8("Vision",4,10,8,6,3,2);
        Personnage p9("Wanda",4,7,4,10,3,6);
        Personnage p10("Black Panther",6,6,10,6,5,7);
        Personnage p11("Thanos",9,6,5,3,9,4);
        Personnage p12("Soldat de l'hiver",6,6,6,2,5,7);
        Personnage p13("Wolverine",7,4,7,0,7,5);
        Personnage p14("DeadPool",6,4,7,5,10,9);
        Personnage p15("Loki",4,10,4,8,4,7);
        Personnage p16("AntMan",4,8,6,4,6,6);
        Personnage p17("Groot",8,3,3,4,10,9);
        Personnage p18("Star Lord",5,6,5,4,2,7);
        Personnage p19("Dr. Strange",5,10,6,10,3,7);
        Personnage p20("Pr. Xavier",0,15,0,15,3,8);

        Population pp1;

        pp1.ajoutePersonnage(&p1);
        pp1.ajoutePersonnage(&p2);
        pp1.ajoutePersonnage(&p3);
        pp1.ajoutePersonnage(&p4);
        pp1.ajoutePersonnage(&p5);
        pp1.ajoutePersonnage(&p6);
        pp1.ajoutePersonnage(&p7);
        pp1.ajoutePersonnage(&p8);
        pp1.ajoutePersonnage(&p9);
        pp1.ajoutePersonnage(&p10);
        pp1.ajoutePersonnage(&p11);
        pp1.ajoutePersonnage(&p12);
        pp1.ajoutePersonnage(&p13);
        pp1.ajoutePersonnage(&p14);
        pp1.ajoutePersonnage(&p15);
        pp1.ajoutePersonnage(&p16);
        pp1.ajoutePersonnage(&p17);
        pp1.ajoutePersonnage(&p18);
        pp1.ajoutePersonnage(&p19);
        pp1.ajoutePersonnage(&p20);


        for(int i = 0; i < 2; i++)
        {
            qstd::cout<<"-----------------------"<<i<<" Generation------------------"<<"\n";
            pp1.m_populationAlpha += generation(pp1);
            pp1.listeToString(pp1.m_population);
        }


        qstd::cout<<"-----------------------Stats Alpha------------------"<<"\n";

        qstd::cout<<pp1.m_populationAlpha.size()<<"\n";        

        for(int i = 0; i<pp1.m_populationAlpha.size();i++)
        {
            qstd::cout<<pp1.m_populationAlpha[i];
        }

        pp1.alpha();

        qstd::cout<<"-----------------------Grand Alpha------------------"<<"\n";
        foreach (Personnage *perso, pp1.m_population)
        {
            qstd::cout<<"-----------------------------------------"<<"\n";
            qstd::cout<<" Le grand Alpha est: "<<perso->nom()<<" avec un total de "<<perso->victoire()<<" victoire\n";
            qstd::cout<<" - Force : "<<perso->force()<<"\n";
            qstd::cout<<" - Intelligence : "<<perso->intelligence()<<"\n";
            qstd::cout<<" - Agilité : "<<perso->agilite()<<"\n";
            qstd::cout<<" - Magie / Puissance de Feu : "<<perso->magiePuissanceDeFeu()<<"\n";
            qstd::cout<<" - Resistance : "<<perso->resistance()<<"\n";
            qstd::cout<<" - Style : "<<perso->style()<<"\n";
        }

    return 0;
}
