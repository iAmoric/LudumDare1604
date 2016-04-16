//
// Created by Jehan on 16/04/2016.
//

#include "LaboPiece.hpp"

LaboPiece::LaboPiece(std::string name, int nbLaboPiece, float coef, unsigned long long price, bool isBuyable) {
    m_name = name;
    m_nbLaboPiece = nbLaboPiece;
    m_coef = coef;
    m_isBuy = false;
    m_isBuyable = false;
    m_price = price; //TODO To define
    m_YPS = price * 1,5; //TODO To define
    m_level = 0;
}


LaboPiece::~LaboPiece() {

}

//TODO To define
void LaboPiece::nextLvl() {
    m_YPS *=1.5;
    m_level++;
    m_price = (unsigned long long) (1.3 * m_price);
}

unsigned long long LaboPiece::getYPS(){
    return m_YPS;
}