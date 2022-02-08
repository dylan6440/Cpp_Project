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
        buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<combattant->competence(combattant->faiblesse());
        buf<<" et obttien egalement 1 point de : "<<combattant->competence(adversaire->pointFort())<<"\n";
        m_populationVictoire.append(combattant);
        m_populationDefaite.append(adversaire);
        m_population.removeOne(combattant);
        m_population.removeOne(adversaire);
    }
    else if(bufCombattant == bufCombattantAdversaire)
    {
        if (combattant->style()>adversaire->style())
        {
            buf<<"Le gagnant est :"<<combattant->nom()<<"\n";
            combattant->ajoutCaracteristique(combattant->faiblesse(),adversaire->pointFort(),1);
            buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<combattant->competence(combattant->faiblesse());
            buf<<" et obttien egalement 1 point de : "<<combattant->competence(adversaire->pointFort())<<"\n";
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
                buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<combattant->competence(combattant->faiblesse());
                buf<<" et obttien egalement 1 point de : "<<combattant->competence(adversaire->pointFort())<<"\n";
                m_populationVictoire.append(combattant);
                m_populationDefaite.append(adversaire);
                m_population.removeOne(combattant);
                m_population.removeOne(adversaire);
            }
            else {
                buf<<"Le gagnant est :"<<adversaire->nom()<<"\n";
                adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
                buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<adversaire->competence(adversaire->faiblesse());
                buf<<" et obttien egalement 1 point de : "<<adversaire->competence(combattant->pointFort())<<"\n";
                m_populationDefaite.append(combattant);
                m_populationVictoire.append(adversaire);
                m_population.removeOne(combattant);
                m_population.removeOne(adversaire);
            }
        }else {
            buf<<"Le gagnant est :"<<adversaire->nom()<<"\n";
            adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
            buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<adversaire->competence(adversaire->faiblesse());
            buf<<" et obttien egalement 1 point de : "<<adversaire->competence(combattant->pointFort())<<"\n";
            m_populationDefaite.append(combattant);
            m_populationVictoire.append(adversaire);
            m_population.removeOne(combattant);
            m_population.removeOne(adversaire);
        }

    }else {
        buf<<"Le gagnant est :"<<adversaire->nom()<<"\n";
        adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
        buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<adversaire->competence(adversaire->faiblesse());
        buf<<" et obttien egalement 1 point de : "<<adversaire->competence(combattant->pointFort())<<"\n";
        m_populationDefaite.append(combattant);
        m_populationVictoire.append(adversaire);
        m_population.removeOne(combattant);
        m_population.removeOne(adversaire);
    }

    qstd::cout<<res;


}
/**********************************************************************************/
int Population::tirageAuSort(QList<Personnage *> liste)
{
    srand(time(NULL));
    int nombre(0);
    nombre = 1+(rand()%(liste.size()-1));
    return nombre;
}
/**********************************************************************************/
void Population::listeVictoire()
{
    foreach (Personnage *perso, m_populationVictoire)
    {
        qstd::cout<<"-----------------------------------------"<<"\n";
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
void Population::listeToString(QList<Personnage *> liste)
{
    foreach (Personnage *perso, liste)
    {
        qstd::cout<<"-----------------------------------------"<<"\n";
        qstd::cout<<perso->nom()<<" A de nouvelle caractérisque qui sont les suivantes:\n";
        qstd::cout<<" - Force : "<<perso->force()<<"\n";
        qstd::cout<<" - Intelligence : "<<perso->intelligence()<<"\n";
        qstd::cout<<" - Agilité : "<<perso->agilite()<<"\n";
        qstd::cout<<" - Magie / Puissance de Feu : "<<perso->magiePuissanceDeFeu()<<"\n";
        qstd::cout<<" - Resistance : "<<perso->resistance()<<"\n";
        qstd::cout<<" - Style : "<<perso->style()<<"\n";
    }
}
/**********************************************************************************/
void Population::ajoutCarac(QList<Personnage *> liste)
{
    foreach (Personnage *perso, liste)
    {
        perso->setAgilite(2);
        perso->setForce(2);
        perso->setIntelligence(2);
        perso->setMagiePuissanceDeFeu(2);
        perso->setResistance(2);
        perso->setStyle(1);
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
        buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<adversaire->competence(adversaire->faiblesse());
        buf<<"et obttien egalement 1 point de : "<<adversaire->competence(combattant->pointFort())<<"\n";
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
            buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<combattant->competence(combattant->faiblesse());
            buf<<" et obttien egalement 1 point de : "<<combattant->competence(adversaire->pointFort())<<"\n";
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
                buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<combattant->competence(combattant->faiblesse());
                buf<<" et obttien egalement 1 point de : "<<combattant->competence(adversaire->pointFort())<<"\n";
                m_populationVictoire.append(combattant);
                m_populationDefaite.append(adversaire);
                m_populationSecondeChance.removeOne(combattant);
                m_populationSecondeChance.removeOne(adversaire);
            }
            else {
                buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
                adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
                buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<combattant->competence(combattant->faiblesse());
                buf<<" et obttien egalement 1 point de : "<<combattant->competence(adversaire->pointFort())<<"\n";
                m_populationDefaite.append(combattant);
                m_populationVictoire.append(adversaire);
                m_populationSecondeChance.removeOne(combattant);
                m_populationSecondeChance.removeOne(adversaire);
            }
        }else {
            buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
            adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
            buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<adversaire->competence(adversaire->faiblesse());
            buf<<"et obttien egalement 1 point de : "<<adversaire->competence(combattant->pointFort())<<"\n";
            m_populationDefaite.append(combattant);
            m_populationVictoire.append(adversaire);
            m_populationSecondeChance.removeOne(combattant);
            m_populationSecondeChance.removeOne(adversaire);
        }

    }else {
        buf<<"Le gagnat est :"<<adversaire->nom()<<"\n";
        adversaire->ajoutCaracteristique(adversaire->faiblesse(),combattant->pointFort(),1);
        buf<<combattant->nom()<<" a obtenue de nouvelle caractéristique, 1 point : "<<adversaire->competence(adversaire->faiblesse());
        buf<<"et obttien egalement 1 point de : "<<adversaire->competence(combattant->pointFort())<<"\n";
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
void Population::preparationRound()
{
    m_populationSecondeChance = m_populationVictoire;
    m_populationTampon += m_populationDefaite;
    m_populationDefaite = {};
    m_populationVictoire = {};
}
/**********************************************************************************/
void Population::supressionDeListe()
{
    m_population = m_population + m_populationVictoire + m_populationSecondeChance;
    m_populationTampon += m_populationDefaite;
    m_populationDefaite = {};
    m_populationVictoire = {};
    m_populationSecondeChance = {};
}
/**********************************************************************************/
void Population::alpha()
{
    int victoire = 0;

    foreach (Personnage *perso, m_population)
    {
        if ((perso->victoire() > victoire) || (perso->victoire() == victoire))
        {
            victoire = perso->victoire();

        }
        else
        {
            m_population.removeOne(perso);
        }
    }
    foreach (Personnage *perso, m_population)
    {
        if ((perso->victoire() > victoire) || (perso->victoire() == victoire))
        {
            victoire = perso->victoire();

        }
        else
        {
            m_population.removeOne(perso);
        }
    }
}
/**********************************************************************************/
QList<Personnage *> Population::supressionDuPlusFaible(QList<Personnage *> liste)
{
    QList<Personnage *> result;
    int index=0;
    int score=1000;
    int i = 0;

    foreach(Personnage *perso, liste)
    {
        if (perso->totalAvecStyle() < score)
        {
            score = perso->totalAvecStyle();
            i = index;
        }
        index++;
    }
    m_populationTampon.append(liste[i]);
    QString res;
    QTextStream buf(&res);
    buf<<"La personne la plus faible va etre éliminé.\n";
    buf<<liste[i]->nom()<<" est le plus faible!\n";
    qstd::cout<<res;
    liste.removeAt(i);
    result = liste;
    return result;
}
/**********************************************************************************/
QString Population::Vainqueur()
{
    QString res;
    QTextStream buf(&res);
    buf<<"L'alpha est : "<<m_population[0]->nom()<<"\n";
    buf<<"Il as les caractéristique suivante : \n";
    buf<<" - Force : "<<m_population[0]->force()<<"\n";
    buf<<" - Intelligence : "<<m_population[0]->intelligence()<<"\n";
    buf<<" - Agilité : "<<m_population[0]->agilite()<<"\n";
    buf<<" - Magie / Puissance de Feu : "<<m_population[0]->magiePuissanceDeFeu()<<"\n";
    buf<<" - Resistance : "<<m_population[0]->resistance()<<"\n";
    buf<<" - Style : "<<m_population[0]->style()<<"\n";
    buf<<" Il as remporte "<<m_population[0]->victoire()<<" generation \n";

    return res;
}
/**********************************************************************************/
