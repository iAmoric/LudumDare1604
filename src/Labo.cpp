//
// Created by Jehan on 16/04/2016.
//

#include "Labo.hpp"

Labo::Labo() {

    initLaboPieceVector();

    m_ScientificVector.push_back(new Scientific("Josette", 5, 1));
    m_ScientificVector.push_back(new Scientific("Yvonne", 5, 2));

    m_ptr_stats = new Stats();
    m_YPS, m_YPSBonus, m_clickBonus = 0;
}

Labo::~Labo() {

}

//TODO Complete LaboPieceList
void Labo::initLaboPieceVector() {
    m_LaboPieceVector.push_back(new LaboPiece("Clicker", 1, 1, 1, true));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost", 2, 1, 5, false));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost2", 3, 2, 10, false));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost3", 4, 2, 20, false));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost4", 5, 3, 60, false));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost5", 6, 3, 180, false));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost6", 7, 3, 540, false));
    m_LaboPieceVector.push_back(new LaboPiece("YPSBoost6", 8, 4, 2160, false));
}

void Labo::lvlUpLaboPiece(unsigned int id) {
    m_YPS = m_YPS - m_LaboPieceVector.at(id)->getYPS();
    m_LaboPieceVector.at(id)->nextLvl();
    m_YPS = m_YPS + m_LaboPieceVector.at(id)->getYPS();
}

void Labo::lvlUpScientific(unsigned int type) {
    m_LaboPieceVector.at(type)->nextLvl();
    if(type == 1) m_clickBonus = m_clickBonus +15;
    else if(type == 2){
        m_YPSBonus = m_YPSBonus +15;
        updateYPS();
    }
}

void Labo::updateYPS() {
    m_YPS = 0;
    for(unsigned int i = 1; i <= m_LaboPieceVector.size(); i++ ){
        m_YPS = m_YPS + m_LaboPieceVector.at(i)->getYPS();
    }
}
