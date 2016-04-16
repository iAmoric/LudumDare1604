//
// Created by Jehan on 16/04/2016.
//

#include "LaboPiece.hpp"

LaboPiece::LaboPiece(std::string name, int nbLaboPiece, unsigned long long price, bool isBuyable,bool isBought) {
    m_name = name;
    m_nbLaboPiece = nbLaboPiece;
    m_isBought = false;
    m_isBuyable = false;
    m_price = price;
    m_YPS = (unsigned long long) (price * 0.2); //TODO To define
    m_level = 0;
}


LaboPiece::~LaboPiece() {

}

//TODO To define
void LaboPiece::nextLvl() {
    m_level++;
    m_price = (unsigned long long) (1.3 * m_price);
    m_YPS = (unsigned long long) (0.2 * m_price);
}

unsigned long long LaboPiece::getYPS(){
    return m_YPS;
}

void LaboPiece::setBuyable(){
    m_isBuyable = true;
}

bool LaboPiece::isBuyable(){
    return m_isBuyable;
}

unsigned long long LaboPiece::getPrice(){
    return m_price;
}
void LaboPiece::setBought() {
    m_isBought = true;
}
bool LaboPiece::isBought(){
    return m_isBought;
}