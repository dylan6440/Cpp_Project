#include "population.h"
#include <QTextStream>
#include "qstd.cpp"
#include <random>


/**********************************************************************************/
Population::Population()
{

}
/**********************************************************************************/
void Population::ajoutePersonnage(Personnage *personnage)
{
    m_population.append(personnage);
}
/**********************************************************************************/
int Population::sizeList(QList<Personnage *> liste)
{
    return liste.size();
}
/**********************************************************************************/
void Population::combat(Personnage *combattant, Personnage *adversaire)
{
    // indice du combatant
    int bufCombattant = 0;
    // indice de l'adversaire
    int bufCombattantAdversaire = 0;

    QString res;
    QTextStream buf(&res);
    buf<<"Combant entre "<<combattant->nom()<<" et "<<adversaire->nom()<<" ! \n";

    /************************************TEST FORCE**************************************/
    if (combattant->force()>adversaire->force())
    {
        bufCombattant++;
    }else if (combattant->force()<adversaire->force())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST INTELLIGENCE**************************************/
    if (combattant->intelligence()>adversaire->intelligence())
    {
        bufCombattant++;
    }else if (combattant->intelligence()<adversaire->intelligence())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST AGILITE**************************************/
    if (combattant->agilite()>adversaire->agilite())
    {
        bufCombattant++;
    }else if (combattant->agilite()<adversaire->agilite())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST MAGIE / PUISSANCE DE FEU**************************************/
    if (combattant->magiePuissanceDeFeu()>adversaire->magiePuissanceDeFeu())
    {
        bufCombattant++;
    }else if (combattant->magiePuissanceDeFeu()<adversaire->magiePuissanceDeFeu())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST RESISTANCE**************************************/
    if (combattant->resistance()>adversaire->resistance())
    {
        bufCombattant++;
    }else if (combattant->resistance()<adversaire->resistance())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************FIN TEST**************************************/

    if(bufCombattant > bufCombattantAdversaire)
    {
        buf<<"Le gagnat est :"<<combattant->nom()<<"\n";
        combattant->ajoutCaracteristique(combattant->faiblesse(),adversaire->pointFort(),1);
        m_populationVictoire.append(combattant);
        m_populationDefaite.append(adversaire);
        m_population.removeOne(combattant);
        m_population.removeOne(adversaire);
    }
    else if(bufCombattant == bufCombattantAdversaire)
    {
        if (combattant->style()>adversaire->style())
        {
            buf<<"Le gagnat est :"<<combattant->nom()<<"\n";
            combattant->ajoutCaracteristique(combattant->faiblesse(),adversaire->pointFort(),1);
            m_populationVictoire.append(combattant);
            m_populationDefaite.append(adversaire);
            m_population.removeOne(combattant);
            m_population.removeOne(adversaire);
        }
        else if (combattant->style()==adversaire->style())
        {
            if ((combattant->totalAvecStyle()>adversaire->totalAvecStyle()))
            {
                buf<<"Le gagnat est :"<<combattant->nom()<<"\n";
                combattant->ajoutCaracteristique(combattant->faiblesse(),adversaire->pointFort(),1);
                m_populationVictoire.append(combattant);
                m_populationDefaite.append(adversaire);
                m_population.removeOne(combattant);
                m_population.removeOne(adversaire);
            }
            else {
                buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
                adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
                m_populationDefaite.append(combattant);
                m_populationVictoire.append(adversaire);
                m_population.removeOne(combattant);
                m_population.removeOne(adversaire);
            }
        }else {
            buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
            adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
            m_populationDefaite.append(combattant);
            m_populationVictoire.append(adversaire);
            m_population.removeOne(combattant);
            m_population.removeOne(adversaire);
        }

    }else {
        buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
        adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
        m_populationDefaite.append(combattant);
        m_populationVictoire.append(adversaire);
        m_population.removeOne(combattant);
        m_population.removeOne(adversaire);
    }

    qstd::cout<<res;


}
/**********************************************************************************/
int Population::tirageAuSort()
{
    srand(time(NULL));
    int nombre(0);
    nombre = 1+(rand()%(m_population.size()-1));
    return nombre;
}
/**********************************************************************************/
void Population::listeVictoire()
{
    foreach (Personnage *perso, m_populationVictoire)
    {
        qstd::cout<<perso->nom()<<" a gagner son combat !\n"<<"Il Obtient de nouvelle caractérisque qui sont les suivantes:\n";
        qstd::cout<<" - Force : "<<perso->force()<<"\n";
        qstd::cout<<" - Intelligence : "<<perso->intelligence()<<"\n";
        qstd::cout<<" - Agilité : "<<perso->agilite()<<"\n";
        qstd::cout<<" - Magie / Puissance de Feu : "<<perso->magiePuissanceDeFeu()<<"\n";
        qstd::cout<<" - Resistance : "<<perso->resistance()<<"\n";
        qstd::cout<<" - Style : "<<perso->style()<<"\n";
    }
}
/**********************************************************************************/
void Population::combatListeSecondaire(Personnage *combattant, Personnage *adversaire)
{
    // indice du combatant
    int bufCombattant = 0;
    // indice de l'adversaire
    int bufCombattantAdversaire = 0;

    QString res;
    QTextStream buf(&res);
    buf<<"Combant entre "<<combattant->nom()<<" et "<<adversaire->nom()<<" ! \n";

    /************************************TEST FORCE**************************************/
    if (combattant->force()>adversaire->force())
    {
        bufCombattant++;
    }else if (combattant->force()<adversaire->force())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST INTELLIGENCE**************************************/
    if (combattant->intelligence()>adversaire->intelligence())
    {
        bufCombattant++;
    }else if (combattant->intelligence()<adversaire->intelligence())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST AGILITE**************************************/
    if (combattant->agilite()>adversaire->agilite())
    {
        bufCombattant++;
    }else if (combattant->agilite()<adversaire->agilite())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST MAGIE / PUISSANCE DE FEU**************************************/
    if (combattant->magiePuissanceDeFeu()>adversaire->magiePuissanceDeFeu())
    {
        bufCombattant++;
    }else if (combattant->magiePuissanceDeFeu()<adversaire->magiePuissanceDeFeu())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST RESISTANCE**************************************/
    if (combattant->resistance()>adversaire->resistance())
    {
        bufCombattant++;
    }else if (combattant->resistance()<adversaire->resistance())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************FIN TEST**************************************/

    if(bufCombattant > bufCombattantAdversaire)
    {
        buf<<"Le gagnat est :"<<combattant->nom()<<"\n";
        combattant->ajoutCaracteristique(combattant->faiblesse(),adversaire->pointFort(),1);
        m_populationVictoire.append(combattant);
        m_populationDefaite.append(adversaire);
        m_populationSecondeChance.removeOne(combattant);
        m_populationSecondeChance.removeOne(adversaire);
    }
    else if(bufCombattant == bufCombattantAdversaire)
    {
        if (combattant->style()>adversaire->style())
        {
            buf<<"Le gagnat est :"<<combattant->nom()<<"\n";
            combattant->ajoutCaracteristique(combattant->faiblesse(),adversaire->pointFort(),1);
            m_populationVictoire.append(combattant);
            m_populationDefaite.append(adversaire);
            m_populationSecondeChance.removeOne(combattant);
            m_populationSecondeChance.removeOne(adversaire);
        }
        else if (combattant->style()==adversaire->style())
        {
            if ((combattant->totalAvecStyle()>adversaire->totalAvecStyle()))
            {
                buf<<"Le gagnat est :"<<combattant->nom()<<"\n";
                combattant->ajoutCaracteristique(combattant->faiblesse(),adversaire->pointFort(),1);
                m_populationVictoire.append(combattant);
                m_populationDefaite.append(adversaire);
                m_populationSecondeChance.removeOne(combattant);
                m_populationSecondeChance.removeOne(adversaire);
            }
            else {
                buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
                adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
                m_populationDefaite.append(combattant);
                m_populationVictoire.append(adversaire);
                m_populationSecondeChance.removeOne(combattant);
                m_populationSecondeChance.removeOne(adversaire);
            }
        }else {
            buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
            adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
            m_populationDefaite.append(combattant);
            m_populationVictoire.append(adversaire);
            m_populationSecondeChance.removeOne(combattant);
            m_populationSecondeChance.removeOne(adversaire);
        }

    }else {
        buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
        adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
        m_populationDefaite.append(combattant);
        m_populationVictoire.append(adversaire);
        m_populationSecondeChance.removeOne(combattant);
        m_populationSecondeChance.removeOne(adversaire);
    }

    qstd::cout<<res;


}
/**********************************************************************************/
void Population::preparationRoundSecondeChance()
{
    m_population = m_population + m_populationVictoire;
    m_populationSecondeChance = m_populationDefaite;
    m_populationDefaite = {};
    m_populationVictoire = {};
}
/**********************************************************************************/
