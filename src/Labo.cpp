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
    m_LaboPieceVector.push_back(new LaboPiece("Clicker", 1, 1, 5, true));
    m_LaboPieceVector.push_back(new LaboPiece("2Flasks", 2, 2, 10, false));
    m_LaboPieceVector.push_back(new LaboPiece("2TestTubes", 3, 2, 20, false));
    m_LaboPieceVector.push_back(new LaboPiece("4TestTubes", 4, 3, 60, false));
    m_LaboPieceVector.push_back(new LaboPiece("HeatingMantle", 5, 3, 180, false));
    m_LaboPieceVector.push_back(new LaboPiece("HeatingMantleBalloon", 6, 3, 540, false));
    m_LaboPieceVector.push_back(new LaboPiece("MagnifyingGlass", 7, 4, 2160, false));
    m_LaboPieceVector.push_back(new LaboPiece("microscope", 8, 4, 8640, false));
    m_LaboPieceVector.push_back(new LaboPiece("PinkBurette", 9, 4, 34560, false));
    m_LaboPieceVector.push_back(new LaboPiece("PinkFlaks", 10, 4, 138240, false));
    m_LaboPieceVector.push_back(new LaboPiece("PurpleBallon", 11, 5, 691200, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment12", 12, 5, 345600, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment13", 13, 5, 17280000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment14", 14, 5, 86400000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment15", 15, 6, 432000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment16", 16, 6, 2592000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment17", 17, 6, 15552000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment18", 18, 6, 93312000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment19", 19, 6, 559872000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment20", 20, 6, 3359232000000, false));
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

//TODO Rajouter bonus scientific
void Labo::updateYPS() {
    m_YPS = 0;
    for(unsigned int i = 1; i <= m_LaboPieceVector.size(); i++ ){
        m_YPS = m_YPS + m_LaboPieceVector.at(i)->getYPS();
    }
}
