//
// Created by Jehan on 16/04/2016.
//

#ifndef CLIENT_LABOPIECE_HPP
#define CLIENT_LABOPIECE_HPP

#include <string>

class LaboPiece{
protected:
    std::string m_name;
    int m_nbLaboPiece;
    float m_coef;
    bool m_isClickPiece;
    bool m_isBuy;
    bool m_isBuyable;
    long m_price;
    long m_YPS;
    int m_level;
public:
    LaboPiece(std::string name, int nbLaboPiece,
              float coef, long price, bool isClickPiece);
    ~LaboPiece();
    void nextLvl();
};


#endif //CLIENT_LABOPIECE_HPP
