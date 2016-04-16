//
// Created by Jehan on 16/04/2016.
//

#include "Labo.hpp"

Labo::Labo() {
    //TODO Complete LaboPieceList
    m_LaboPieceVector.push_back(new LaboPiece("Clicker", 1, 1, 1, true));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost", 1, 1, 5, false));

    m_ScientificVector.push_back(new Scientific("Josette", 5, 1));
    m_ScientificVector.push_back(new Scientific("Yvonne", 5, 2));

    m_ptr_stats = new Stats();
    m_YPS, m_clickBonus = 0;
}

Labo::~Labo() {

}


