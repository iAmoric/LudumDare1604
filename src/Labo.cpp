//
// Created by Jehan on 16/04/2016.
//

#include <iostream>
#include "Labo.hpp"

Labo::Labo() {

    initLaboPieceVector();

    m_ScientificVector.push_back(new Scientific("Josette", 5, 1));
    m_ScientificVector.push_back(new Scientific("Yvonne", 5, 2));

    m_ptr_stats = new Stats();
    m_ptr_monster = new Monster(30);
    m_YPS = 0;
    m_CPS = 1;
    m_YPSBonus = 1;
    m_CPSBonus = 1;
    m_money = 0;
    m_restartBonus = 1;
    m_year=0;
    m_reputationPointWaiting = 0;
    m_reputationPointOwned = 0;
    m_evolutionLevel = 1;
    moneyGain = 1;


}

Labo::~Labo() {

}

//TODO Complete LaboPieceList
void Labo::initLaboPieceVector() {
    m_LaboPieceVector.clear();
    m_LaboPieceVector.push_back(new LaboPiece("Clicker", 1, 5, true, false));
    m_LaboPieceVector.push_back(new LaboPiece("2Flasks", 2, 10, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("2TestTubes", 3, 20, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("4TestTubes", 4, 60, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("HeatingMantle", 5, 180, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("HeatingMantleBalloon", 6, 540, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("MagnifyingGlass", 7, 2160, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Microscope", 8, 8640, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("PinkBurette", 9, 34560, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("PinkFlaks", 10, 138240, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("PurpleBallon", 11, 691200, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment12", 12, 3456000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment13", 13, 17280000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment14", 14, 86400000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment15", 15, 432000000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment16", 16, 2592000000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment17", 17, 15552000000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment18", 18, 93312000000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment19", 19, 559872000000, false, false));
    m_LaboPieceVector.push_back(new LaboPiece("Equipment20", 20, 3359232000000, false, false));
}

void Labo::lvlUpLaboPiece(unsigned int id) {
    m_ptr_stats->incrementSpentMoney(m_LaboPieceVector.at(id)->getPrice());
    if(m_LaboPieceVector.at(id)->getLevel() > 0)
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
    for(unsigned int i = 0; i < m_LaboPieceVector.size() -1; i++ ){
        if(m_LaboPieceVector.at(i)->isBought())
            m_YPS = m_YPS + m_LaboPieceVector.at(i)->getYPS();
    }
    m_YPS *= m_YPSBonus;
    m_YPS *= m_restartBonus;
}

void Labo::updateCPS() {
    double percentage = 1;
    m_CPS = (unsigned long long) (percentage * m_LaboPieceVector.at(0)->getYPS());
    for(unsigned int i = 1; i < m_LaboPieceVector.size(); i++ ){
        if(m_LaboPieceVector.at(i)->isBought()) {
            percentage = percentage - (i / 2) / 100;

            m_CPS = (unsigned long long) (percentage * m_LaboPieceVector.at(i)->getYPS());
        }
    }
    m_CPS *= m_CPSBonus;
    m_CPS *= m_restartBonus;
}


void Labo::restart(){
    m_ptr_stats->setActualMoney(0);
    m_money = 0;
    m_ptr_stats->incrementNbReset();
    m_restartBonus *= 1.1;
    m_reputationPointOwned += m_reputationPointWaiting;
    m_reputationPointWaiting = 0;
    m_ptr_stats->incrementActualReputation(m_reputationPointOwned);
    m_ptr_stats->incrementTotalReputation(m_reputationPointOwned);
    initLaboPieceVector();
    m_YPS = 0;
    m_CPS = 1;
    updateYPS();
    updateCPS();
    if(m_evolutionLevel > m_ptr_stats->getM_nbEvoMax()){
        m_ptr_stats->setNbEvoMax(m_evolutionLevel);
    }
    m_evolutionLevel = 1;
}

void Labo::evolution() {
    unsigned long long moneyGain = 0;
    if(m_evolutionLevel == 5 || m_evolutionLevel == 10 ||
            m_evolutionLevel == 15 || m_evolutionLevel == 20){
        m_reputationPointWaiting += 5 * m_evolutionLevel;
    }
    if(m_year >= m_ptr_monster->getAnnee()){
        // TODO : create function to auto-generate year of a monster
        m_evolutionLevel++;
        if(m_evolutionLevel > m_ptr_stats->getM_nbEvoMax()){
            m_ptr_stats->incrementNbEvoMax();
        }
        m_ptr_monster->setAnnee(m_year + 10 * m_YPS * m_YPS + 50 * m_evolutionLevel * m_evolutionLevel);
    }
    for(unsigned int i = 1; i < m_LaboPieceVector.size(); i++ ){
        if(m_LaboPieceVector.at(i)->isBought())
            moneyGain = m_LaboPieceVector.at(i)->getPrice();
    }
    m_money += moneyGain * 3;

}

/**
 * Grant (YPS of the last item) / 10 money each sec
 * Upload also the time
 */
void Labo::grant(){
    for(unsigned int i = 1; i < m_LaboPieceVector.size()-2; i++ ){
        if(m_LaboPieceVector.at(i)->isBought()){
            moneyGain = m_LaboPieceVector.at(i)->getYPS() / 10;
        }
        if(moneyGain == 0) moneyGain += 1;
    }
    m_money = m_money + moneyGain;
    m_year += m_YPS;
    updateCPS();
    m_ptr_stats->incrementSpentTime();
    m_ptr_stats->setActualMoney(m_money);
    m_ptr_stats->setTotalMoney(m_money);
}

void Labo::click() {
    m_year += m_CPS;
    m_ptr_stats->incrementNbClick();
}
unsigned long long Labo::getM_year(){
    return m_year;
}
unsigned long long Labo::getMoney(){
    return m_money;
}

void Labo::setMoney(unsigned long long money){
    m_money = money;
}

unsigned long long Labo::getCPS(){
    return m_CPS;
}
unsigned long long Labo::getYPS(){
    return m_YPS;
}
unsigned long long Labo::getReputationPointWaiting(){
    return m_reputationPointWaiting;
}
unsigned long long Labo::getReputationPointOwned(){
    return m_reputationPointOwned;
}
unsigned long long Labo::getEvolutionLevel(){
    return m_evolutionLevel;
}
unsigned long long Labo::getMoneyGain(){
    return moneyGain;
}

void Labo::isPurchasablePiece(){
    for (int i = 1; i < m_LaboPieceVector.size(); ++i) {
        if(m_money >= m_LaboPieceVector.at(i)->getPrice() && m_LaboPieceVector.at(i-1)->isBought()){
            m_LaboPieceVector.at(i)->setBuyable();
        }
    }
}
Monster* Labo::getM_ptr_monster(){
    return m_ptr_monster;
}
Stats* Labo::getM_ptr_stats(){
    return m_ptr_stats;
}

std::vector<LaboPiece *> Labo::getM_LaboPieceVector() {
    return m_LaboPieceVector;
}
void Labo::incrementEvolutionLevel(){
    m_evolutionLevel++;
}
