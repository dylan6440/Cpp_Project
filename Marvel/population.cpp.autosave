#include "population.h"
#include <QTextStream>
#include "qstd.cpp"


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
void Population::combat()
{
    // indice du combatant
    int combattantId = 0;
    int bufCombattant = 0;
    // indice de l'adversaire
    int combattantAdversaireId = tirageAuSort(m_population.size());
    int bufCombattantAdversaire = 0;

    QString res;
    QTextStream buf(&res);
    buf<<"Combant entre "<<m_population[combattantId]->nom()<<" et "<<m_population[combattantAdversaireId]->nom()<<" ! \n";

    /************************************TEST FORCE**************************************/
    if (m_population[combattantId]->force()>m_population[combattantAdversaireId]->force())
    {
        bufCombattant++;
    }else if (m_population[combattantId]->force()<m_population[combattantAdversaireId]->force())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST INTELLIGENCE**************************************/
    if (m_population[combattantId]->intelligence()>m_population[combattantAdversaireId]->intelligence())
    {
        bufCombattant++;
    }else if (m_population[combattantId]->intelligence()<m_population[combattantAdversaireId]->intelligence())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST AGILITE**************************************/
    if (m_population[combattantId]->agilite()>m_population[combattantAdversaireId]->agilite())
    {
        bufCombattant++;
    }else if (m_population[combattantId]->agilite()<m_population[combattantAdversaireId]->agilite())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST MAGIE / PUISSANCE DE FEU**************************************/
    if (m_population[combattantId]->magiePuissanceDeFeu()>m_population[combattantAdversaireId]->magiePuissanceDeFeu())
    {
        bufCombattant++;
    }else if (m_population[combattantId]->magiePuissanceDeFeu()<m_population[combattantAdversaireId]->magiePuissanceDeFeu())
    {
        bufCombattantAdversaire++;
    }
    else
    {
        // Nothing
    }
    /************************************TEST RESISTANCE**************************************/
    if (m_population[combattantId]->resistance()>m_population[combattantAdversaireId]->resistance())
    {
        bufCombattant++;
    }else if (m_population[combattantId]->resistance()<m_population[combattantAdversaireId]->resistance())
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
        buf<<"Le gagnat est :"<<m_population[combattantId]->nom()<<"\n";
        m_populationVictoire.append(m_population[combattantId]);
        m_populationDefaite.append(m_population[combattantAdversaireId]);
        m_population.removeAt(combattantId);
        m_population.removeAt(combattantAdversaireId);
    }
    else if(bufCombattant == bufCombattantAdversaire)
    {
        if (m_population[combattantId]->style()>m_population[combattantAdversaireId]->style())
        {
            buf<<"Le gagnat est :"<<m_population[combattantId]->nom()<<"\n";
            m_populationVictoire.append(m_population[combattantId]);
            m_populationDefaite.append(m_population[combattantAdversaireId]);
            m_population.removeAt(combattantId);
            m_population.removeAt(combattantAdversaireId);
        }
        else if (m_population[combattantId]->style()==m_population[combattantAdversaireId]->style())
        {
            if ((m_population[combattantId]->totalAvecStyle()>m_population[combattantAdversaireId]->totalAvecStyle()))
            {
                buf<<"Le gagnat est :"<<m_population[combattantId]->nom()<<"\n";
                m_populationVictoire.append(m_population[combattantId]);
                m_populationDefaite.append(m_population[combattantAdversaireId]);
                m_population.removeAt(combattantId);
                m_population.removeAt(combattantAdversaireId);
            }
            else {
                buf<<"Le gagnat est :"<<m_population[combattantAdversaireId]->nom()<<"\n";
                m_populationDefaite.append(m_population[combattantId]);
                m_populationVictoire.append(m_population[combattantAdversaireId]);
                m_population.removeAt(combattantId);
                m_population.removeAt(combattantAdversaireId);
            }
        }else {
            buf<<"Le gagnat est :"<<m_population[combattantAdversaireId]->nom()<<"\n";
            m_populationDefaite.append(m_population[combattantId]);
            m_populationVictoire.append(m_population[combattantAdversaireId]);
            m_population.removeAt(combattantId);
            m_population.removeAt(combattantAdversaireId);
        }

    }else {
        buf<<"Le gagnat est :"<<m_population[combattantAdversaireId]->nom()<<"\n";
        m_populationDefaite.append(m_population[combattantId]);
        m_populationVictoire.append(m_population[combattantAdversaireId]);
        m_population.removeAt(combattantId);
        m_population.removeAt(combattantAdversaireId);
    }

    qstd::cout<<res;


}
/**********************************************************************************/
int Population::tirageAuSort(int size)
{
    return 1+(qrand()%(size-1));
}
/**********************************************************************************/
