#ifndef POPULATION_H
#define POPULATION_H
#include "personnage.h"
#include <QList>
#include<QString>

class Population
{
private:
    QList<Personnage *> m_population;
    QList<Personnage *> m_populationVictoire;
    QList<Personnage *> m_populationDefaite;

public:
    Population();

    void ajoutePersonnage(Personnage * personnage);

    void combat();
    int tirageAuSort(int size);
};

#endif // POPULATION_H
