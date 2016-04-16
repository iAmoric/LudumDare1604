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
    unsigned long long m_price;
    unsigned long long m_YPS;
    int m_level;
public:
    LaboPiece(std::string name, int nbLaboPiece,
              float coef, unsigned long long price, bool isClickPiece);
    ~LaboPiece();

    void nextLvl();
    unsigned long long getYPS();
};


#endif //CLIENT_LABOPIECE_HPP
