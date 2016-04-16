//
// Created by Jehan on 16/04/2016.
//

#ifndef CLIENT_STATS_HPP
#define CLIENT_STATS_HPP

#include <SFML/System/Time.hpp>

class Stats{
protected:
    //Other stats
    unsigned long long m_nbClick;
    int m_nbReset;
    int m_nbEvoMax;
    sf::Time m_spentTime;

    //Money
    unsigned long long m_actualMoney;
    unsigned long long m_totalMoney;
    unsigned long long m_spentMoney;

    //Reputation
    long m_actualReputation;
    long m_totalReputation;
    long m_spentReputation;
public:
    Stats();
    ~Stats();
    /* Setter */
    //Money
    void setActualMoney(unsigned long long money);
    void incrementActualMoney(unsigned long long money);
    void incrementTotalMoney(unsigned long long money);
    void incrementSpentMoney(unsigned long long money);
    //Other stats
    void incrementNbClick();
    void incrementSpentTime();
    void incrementNbReset();
    void setNbEvoMax(int nbEvoMax);
    //Reputation
    void setActualReputation(long actualReputation);
    void incrementActualReputation();
    void incrementTotalReputation();
    void incrementSpentReputation();
    /* Getter */
    //Money
    unsigned long long getM_actualMoney();
    unsigned long long getM_totalMoney();
    unsigned long long getM_spentMoney();
    //Other stats
    unsigned long long getM_nbClick();
    sf::Time getM_spentTime();
    int getM_nbReset();
    int getM_nbEvoMax();
    //Reputation
    long getM_actualReputation();
    long getM_totalReputation();
    long getM_spentReputation();

};
#endif //CLIENT_STATS_HPP
