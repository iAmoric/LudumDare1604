//
// Created by Lucas on 16/04/2016.
//

#include "Monster.hpp"

Monster::Monster(unsigned long long annee) {
    m_annee = annee;
}

Monster::~Monster() {

}

void Monster::setAnnee(unsigned long long annee) {
    m_annee = m_annee + annee;
}
unsigned long long Monster::getAnnee() {
    return m_annee;
}