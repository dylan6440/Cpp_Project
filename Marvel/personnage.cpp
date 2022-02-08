#include "personnage.h"
#include <QList>

/**********************************************************************************/
void Personnage::setVictoire(int victoire)
{
    m_victoire = m_victoire + victoire;
}

int Personnage::victoire() const
{
    return m_victoire;
}

int Personnage::force() const
{
    return m_force;
}
/**********************************************************************************/
void Personnage::setForce(int force)
{
    m_force = m_force + force;
}
/**********************************************************************************/
int Personnage::intelligence() const
{
    return m_intelligence;
}
/**********************************************************************************/
void Personnage::setIntelligence(int intelligence)
{
    m_intelligence = m_intelligence + intelligence;
}
/**********************************************************************************/
int Personnage::agilite() const
{
    return m_agilite;
}
/**********************************************************************************/
void Personnage::setAgilite(int agilite)
{
    m_agilite = m_agilite + agilite;
}
/**********************************************************************************/
int Personnage::magiePuissanceDeFeu() const
{
    return m_magiePuissanceDeFeu;
}
/**********************************************************************************/
void Personnage::setMagiePuissanceDeFeu(int magiePuissanceDeFeu)
{
    m_magiePuissanceDeFeu = m_magiePuissanceDeFeu + magiePuissanceDeFeu;
}
/**********************************************************************************/
int Personnage::resistance() const
{
    return m_resistance;
}
/**********************************************************************************/
void Personnage::setResistance(int resistance)
{
    m_resistance = m_resistance + resistance;
}
/**********************************************************************************/
int Personnage::style() const
{
    return m_style;
}
/**********************************************************************************/
void Personnage::setStyle(int style)
{
    m_style = m_style + style;
}
/**********************************************************************************/
QString Personnage::nom() const
{
    return m_nom;
}
/**********************************************************************************/
QString Personnage::competence(int index)
{
    QString res;
    switch (index) {
    case 0:
        res = "Force";;
        break;
    case 1:
        res = "Intelligence";
        break;
    case 2:
        res = "Agilite";
        break;
    case 3:
        res = "Magie / Puissance de Feu";
        break;
    case 4:
        res = "Resistance";
        break;
    }

    return res;
}
/**********************************************************************************/
int Personnage::total()
{
    m_total = m_force + m_intelligence + m_agilite + m_magiePuissanceDeFeu + m_resistance;
    return m_total;
}
/**********************************************************************************/
int Personnage::totalAvecStyle()
{
    m_totalAvecStyle = m_force + m_intelligence + m_agilite + m_magiePuissanceDeFeu + m_resistance + m_style;
    return m_totalAvecStyle;
}
/**********************************************************************************/
void Personnage::ajoutCaracteristique(int faiblesse, int pointFort, int style)
{
    switch (faiblesse) {
    case 0:
        setForce(1);
        break;
    case 1:
        setIntelligence(1);
        break;
    case 2:
        setAgilite(1);
        break;
    case 3:
        setMagiePuissanceDeFeu(1);
        break;
    case 4:
        setResistance(1);
        break;
    }

    switch (pointFort) {
    case 0:
        setForce(1);
        break;
    case 1:
        setIntelligence(1);
        break;
    case 2:
        setAgilite(1);
        break;
    case 3:
        setMagiePuissanceDeFeu(1);
        break;
    case 4:
        setResistance(1);
        break;
    }
    setStyle(style);
}
/**********************************************************************************/
int Personnage::faiblesse()
{
    int index;
    int number = 100;

    QList<int> liste = {m_force,
                       m_intelligence,
                       m_agilite,
                       m_magiePuissanceDeFeu,
                       m_resistance};

    for(int i =0; i<liste.size();i++)
    {
        if (liste[i]< number)
        {
            number = liste[i];
            index = i;
        }

    }
    return index;
}
/**********************************************************************************/
int Personnage::pointFort()
{
    int index;
    int number = 0;

    QList<int> liste = {m_force,
                       m_intelligence,
                       m_agilite,
                       m_magiePuissanceDeFeu,
                       m_resistance};

    for(int i =0; i<liste.size();i++)
    {
        if (liste[i]> number)
        {
            number = liste[i];
            index = i;
        }

    }
    return index;
}
/**********************************************************************************/
bool Personnage::triParTotalStyle(Personnage *p1, Personnage *p2)
{
    // return du plus petit au plus grand
    return p1->totalAvecStyle()< p2->totalAvecStyle();
}
/**********************************************************************************/

