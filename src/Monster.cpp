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

void Monster::setEvolution(unsigned long long nb){
    switch (nb){
        case 1:
            m_annee = 30;
            break;
        case 2:
            m_annee = 150;
            break;
        case 3:
            m_annee = 500;
            break;
        case 4:
            m_annee = 2025;
            break;
        case 5:
            m_annee = 13230;
            break;
        case 6:
            m_annee = 112130;
            break;
        case 7:
            m_annee = 1686960;
            break;
        case 8:
            m_annee = 26911140;
            break;
        case 9:
            m_annee = 430564290;
            break;
        case 10:
            m_annee = 6889703610;
            break;
        case 11:
            m_annee = 168371721355;
            break;
        case 12:
            m_annee = 4205422092955;
            break;
        case 13:
            m_annee = 24390673937180;
            break;
        case 14:
            m_annee = 529021969942080;
            break;
        case 15:
            m_annee = 13144804369947700;
            break;
        case 16:
            m_annee = 76223716369954100;
            break;
        case 17:
            m_annee = 454697188369961000;
            break;
        case 18:
            m_annee = 2725538020369970000;
            break;
        case 19:
            m_annee = 16350583012370000000;
            break;
        default:
            break;
    }

}

unsigned long long Monster::getAnnee() {
    return m_annee;
}