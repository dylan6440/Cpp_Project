#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QString>


class Personnage
{
private:
    QString m_nom;
    int m_force;
    int m_intelligence;
    int m_agilite;
    int m_magiePuissanceDeFeu;
    int m_resistance;
    int m_style;
    int m_total;
    int m_totalAvecStyle;

public:

    Personnage(QString nom, int force, int intel, int agi, int magiePuissance, int resistance, int style)
        : m_nom(nom),
        m_force(force),
        m_intelligence(intel),
        m_agilite(agi),
        m_magiePuissanceDeFeu(magiePuissance),
        m_resistance(resistance),
        m_style(style) {}


    int force() const;
    void setForce(int force);
    int intelligence() const;
    void setIntelligence(int intelligence);
    int agilite() const;
    void setAgilite(int agilite);
    int magiePuissanceDeFeu() const;
    void setMagiePuissanceDeFeu(int magiePuissanceDeFeu);
    int resistance() const;
    void setResistance(int resistance);
    int style() const;
    void setStyle(int style);
    QString nom() const;


    int total() ;
    int totalAvecStyle() ;

    void ajoutCaracteristique(int faiblesse,int pointFort, int style);

    int faiblesse();
    int pointFort();

    static bool triParTotalStyle(Personnage *p1, Personnage *p2);

};

#endif // PERSONNAGE_H
