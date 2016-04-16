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
    long m_YPS;
    float m_clickBonus;
public:
    Labo();
    ~Labo();
};

#endif //CLIENT_LABO_HPP
