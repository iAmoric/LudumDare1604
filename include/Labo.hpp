//
// Created by Jehan on 16/04/2016.
//

#ifndef CLIENT_LABO_HPP
#define CLIENT_LABO_HPP

#include "Scientific.hpp"
#include "LaboPiece.hpp"
#include "Stats.hpp"
#include <vector>

class Labo{
private:
    std::vector<LaboPiece *> m_LaboPieceVector;
    std::vector<Scientific *> m_ScientificVector;
    Stats* m_ptr_stats;
    unsigned long long m_YPS;
    unsigned long long m_CPS;
    unsigned long long m_money;
    unsigned long long m_time;
    long m_reputationPointWaiting;
    long m_reputationPointOwned;
    double m_restartBonus;
    double m_CPSBonus;
    double m_YPSBonus;
    int m_evolutionLevel;

    void initLaboPieceVector();
public:
    Labo();
    ~Labo();

    void lvlUpScientific(unsigned int type);
    void lvlUpLaboPiece(unsigned int id);
    void updateYPS();
    void updateCPS();
    void evolution();
    void restart();
    void grant();
    void click();
};

#endif //CLIENT_LABO_HPP
