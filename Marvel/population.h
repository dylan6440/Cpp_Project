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
    QList<Personnage *> m_populationTampon;
    QList <QString> m_populationAlpha;

    Population();

    void ajoutePersonnage(Personnage * personnage);
    int sizeList(QList<Personnage *> liste);
    void combat(Personnage *combattant, Personnage *adversaire);
    void combatListeSecondaire(Personnage *combattant, Personnage *adversaire);
    int tirageAuSort(QList<Personnage *> liste);
    void listeVictoire();
    void listeToString(QList <Personnage *> liste);
    void ajoutCarac(QList<Personnage *> liste);
    void preparationRoundSecondeChance();
    void preparationRound();
    void supressionDeListe();

    void alpha();

    QList<Personnage *> supressionDuPlusFaible(QList<Personnage *> liste);
    QString Vainqueur();
};

#endif // POPULATION_H
