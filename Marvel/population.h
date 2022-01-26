#ifndef POPULATION_H
#define POPULATION_H
#include "personnage.h"
#include <QList>
#include<QString>

class Population
{

public:

    QList<Personnage *> m_population;
    QList<Personnage *> m_populationSecondeChance;
    QList<Personnage *> m_populationVictoire;
    QList<Personnage *> m_populationDefaite;

    Population();

    void ajoutePersonnage(Personnage * personnage);

    int sizeList(QList<Personnage *> liste);
    void combat(Personnage *combattant, Personnage *adversaire);
    void combatListeSecondaire(Personnage *combattant, Personnage *adversaire);
    int tirageAuSort();
    void listeVictoire();
    void ajoutCaracVictoire();
    void preparationRoundSecondeChance();
};

#endif // POPULATION_H
