//
// Created by Lucas on 16/04/2016.
//

#ifndef CLIENT_PLAYER_HPP
#define CLIENT_PLAYER_HPP

#include "Labo.hpp"

class Player {
private:
    unsigned long long m_money;
    unsigned long long m_YPS;
    unsigned long long m_YPC;
    unsigned long long m_totalMoney;
    unsigned long long m_maxYPS;
    unsigned long long m_maxYPC;

    Labo laboratory;

public:
    Player();
    ~Player();


};


#endif //CLIENT_PLAYER_HPP
