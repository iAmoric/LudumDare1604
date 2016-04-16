//
// Created by Jehan on 16/04/2016.
//

#include "LaboPiece.hpp"

LaboPiece::LaboPiece(std::string name, int nbLaboPiece, float coef, long price, bool isClickPiece) {
    m_name = name;
    m_nbLaboPiece = nbLaboPiece;
    m_coef = coef;
    m_isClickPiece = isClickPiece;
    m_isBuy = isClickPiece;
    m_isBuyable = false;
    m_price = price; //TODO To define
    m_YPS = price * 1,5; //TODO To define
    m_level = 0;
}


LaboPiece::~LaboPiece() {

}

//TODO To define
void LaboPiece::nextLvl() {
    m_level++;
    m_price = (long) (1.5 * m_price);
}
