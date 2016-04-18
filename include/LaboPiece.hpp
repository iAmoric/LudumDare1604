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
    bool m_isBought;
    bool m_isBuyable;
    unsigned long long m_price;
    unsigned long long m_YPS;
    unsigned long long m_YPSNextLvl;
    int m_level;
public:
    LaboPiece(std::string name, int nbLaboPiece,
              unsigned long long price, bool isBuyable, bool isBought);
    ~LaboPiece();

    void nextLvl();
    unsigned long long getYPS();
    unsigned long long getYPSNextLvl();
    void setBuyable();
    void setBought();
    bool isBuyable();
    bool isBought();
    int getLevel();


    unsigned long long int getPrice();
};


#endif //CLIENT_LABOPIECE_HPP
