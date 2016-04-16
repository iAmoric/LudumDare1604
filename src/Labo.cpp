//
// Created by Jehan on 16/04/2016.
//

#include "Labo.hpp"

Labo::Labo() {

    initLaboPieceVector();

    m_ScientificVector.push_back(new Scientific("Josette", 5, 1));
    m_ScientificVector.push_back(new Scientific("Yvonne", 5, 2));

    m_ptr_stats = new Stats();
    m_YPS, m_CPS = 0;
    m_YPSBonus, m_CPSBonus = 1;
    m_money = 0;
    m_restartBonus = 1;
    m_reputationPointWaiting = 0;
    m_reputationPointOwned = 0;
    m_evolutionLevel = 1;


}

Labo::~Labo() {

}

//TODO Complete LaboPieceList
void Labo::initLaboPieceVector() {
    m_LaboPieceVector.empty();
    m_LaboPieceVector.push_back(new LaboPiece("Clicker", 1, 5, true));
    m_LaboPieceVector.push_back(new LaboPiece("2Flasks", 2, 10, false));
    m_LaboPieceVector.push_back(new LaboPiece("2TestTubes", 3, 20, false));
    m_LaboPieceVector.push_back(new LaboPiece("4TestTubes", 4, 60, false));
    m_LaboPieceVector.push_back(new LaboPiece("HeatingMantle", 5, 180, false));
    m_LaboPieceVector.push_back(new LaboPiece("HeatingMantleBalloon", 6, 540, false));
    m_LaboPieceVector.push_back(new LaboPiece("MagnifyingGlass", 7, 2160, false));
    m_LaboPieceVector.push_back(new LaboPiece("microscope", 8, 8640, false));
    m_LaboPieceVector.push_back(new LaboPiece("PinkBurette", 9, 34560, false));
    m_LaboPieceVector.push_back(new LaboPiece("PinkFlaks", 10, 138240, false));
    m_LaboPieceVector.push_back(new LaboPiece("PurpleBallon", 11, 691200, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment12", 12, 345600, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment13", 13, 17280000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment14", 14, 86400000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment15", 15, 432000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment16", 16, 2592000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment17", 17, 15552000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment18", 18, 93312000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment19", 19, 559872000000, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment20", 20, 3359232000000, false));
}

void Labo::lvlUpLaboPiece(unsigned int id) {
    m_YPS = m_YPS - m_LaboPieceVector.at(id)->getYPS();
    m_LaboPieceVector.at(id)->nextLvl();
    m_YPS = m_YPS + m_LaboPieceVector.at(id)->getYPS();
}

void Labo::lvlUpScientific(unsigned int type) {
    m_LaboPieceVector.at(type)->nextLvl();
    if(type == 1){
        m_CPSBonus = m_CPSBonus + 0.15;
        updateCPS();
    }
    else if(type == 2){
        m_YPSBonus = m_YPSBonus + 0.15;
        updateYPS();
    }
}

void Labo::updateYPS() {
    m_YPS = 0;
    for(unsigned int i = 0; i < m_LaboPieceVector.size(); i++ ){
        m_YPS = m_YPS + m_LaboPieceVector.at(i)->getYPS();
    }
    m_YPS *= m_YPSBonus;
    m_YPS *= m_restartBonus;
}

void Labo::updateCPS() {
    double percentage = 100;
    m_CPS = (unsigned long long) (percentage * m_LaboPieceVector.at(0)->getYPS());
    for(unsigned int i = 1; i < m_LaboPieceVector.size(); i++ ){
        percentage = percentage - i/2;
        m_CPS = (unsigned long long) (percentage * m_LaboPieceVector.at(i)->getYPS());
    }
    m_CPS *= m_CPSBonus;
    m_CPS *= m_restartBonus;
}


void Labo::restart() {
    m_restartBonus *= 1.1;
    m_reputationPointOwned += m_reputationPointWaiting;
    m_reputationPointWaiting;
    initLaboPieceVector();
    updateYPS();
    updateCPS();
    m_YPS, m_CPS = 0;
    m_evolutionLevel = 1;
}

void Labo::evolution() {
    unsigned long long moneyGain = 0;
    if(m_evolutionLevel == 5 || m_evolutionLevel == 10 ||
            m_evolutionLevel == 15 || m_evolutionLevel == 20){
        m_reputationPointWaiting += 5 * m_evolutionLevel;
    }
    m_evolutionLevel ++;

    for(unsigned int i = 1; i < m_LaboPieceVector.size(); i++ ){
        if(m_LaboPieceVector.at(i)->isBuyable()) moneyGain = m_LaboPieceVector.at(i)->getPrice();
    }
    m_money += moneyGain * 3;
}

/**
 * Grant (YPS of the last item) / 10 money each sec
 * Upload also the time
 */
void Labo::grant(){
    unsigned long long moneyGain = 0;
    for(unsigned int i = 1; i < m_LaboPieceVector.size(); i++ ){
        if(m_LaboPieceVector.at(i)->isBuyable()) moneyGain = m_LaboPieceVector.at(i)->getYPS() / 10;
    }
    m_time += m_YPS;
}

void Labo::click() {
    m_time += m_CPS;
}
