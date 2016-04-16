//
// Created by Jehan on 16/04/2016.
//

#include "Stats.hpp"

Stats::Stats() {
    m_nbClick, m_nbReset, m_spentTime,
            m_actualMoney, m_totalMoney, m_spentMoney,
            m_actualReputation, m_totalReputation, m_spentReputation = 0;
    m_nbEvoMax = 1;
}

Stats::~Stats() {

}
/* Setter */
//Money
void Stats::setActualMoney(unsigned long long money) {
    m_actualMoney = money;
}
void Stats::incrementActualMoney(unsigned long long money) {
    m_actualMoney += money;
}
void Stats::incrementTotalMoney(unsigned long long money) {
    m_totalMoney += money;
}
void Stats::incrementSpentMoney(unsigned long long money) {
    m_spentMoney += money;
}

void Stats::incrementNbClick() {
    m_nbClick++;
}
void Stats::incrementSpentTime(){
    m_spentTime += sf::seconds(1);
}
void Stats::incrementNbReset(){
    m_nbReset++;
}
void Stats::setNbEvoMax(int nbEvoMax) {
    m_nbEvoMax = nbEvoMax;
}
//Reputation
void Stats::setActualReputation(long actualReputation) {
    m_actualReputation = actualReputation;
}
void Stats::incrementActualReputation() {
    m_actualReputation++;
}
void Stats::incrementTotalReputation() {
    m_totalReputation++;
}
void Stats::incrementSpentReputation() {
    m_spentReputation++;
}
/* Getter */
unsigned long long Stats::getM_nbClick() {
    return m_nbClick;
}
int Stats::getM_nbReset() {
    return m_nbReset;
}

int Stats::getM_nbEvoMax() {
    return m_nbEvoMax;
}

sf::Time Stats::getM_spentTime() {
    return m_spentTime;
}

unsigned long long Stats::getM_actualMoney() {
    return m_actualMoney;
}

unsigned long long Stats::getM_totalMoney() {
    return m_totalMoney;
}

unsigned long long Stats::getM_spentMoney() {
    return m_spentMoney;
}

long Stats::getM_actualReputation() {
    return m_actualReputation;
}

long Stats::getM_totalReputation() {
    return m_totalReputation;
}

long Stats::getM_spentReputation() {
    return m_spentReputation;
}





