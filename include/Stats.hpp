//
// Created by Jehan on 16/04/2016.
//

#ifndef CLIENT_STATS_HPP
#define CLIENT_STATS_HPP

class Stats{
protected:
    int m_nbClick;
    int m_nbReset;
    int m_nbEvoMax;
    long spentTime;

    //Money
    long actualMoney;
    long totalMoney;
    long spentMoney;

    //Reputation
    long actualReputation;
    long totalReputation;
    long spentReputation;
public:
    Stats();
    ~Stats();
};
#endif //CLIENT_STATS_HPP
