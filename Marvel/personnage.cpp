#include "personnage.h"
/**********************************************************************************/
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
bool Personnage::triParTotalStyle(Personnage *p1, Personnage *p2)
{
    // return du plus petit au plus grand
    return p1->totalAvecStyle()< p2->totalAvecStyle();
}
/**********************************************************************************/

