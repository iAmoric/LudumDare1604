//
// Created by Roland on 16-Apr-16.
//
/*
 * Units constitué d'un long + un string
 * String = puissance
 * long = valeur d'int
 */
#include <bits/stringfwd.h>
#include <Patch.hpp>
#include "Units.hpp"

/*
 * \brief Constructor (unite en notation scientifique)
 * \param chiffre
 * \param nom_unite
 */
Units::Units(unsigned long long chiffre) {
    m_chiffre = chiffre;
    for (int i = 0; i < 26; ++i) {
        m_tableauLettre[i] = (char)(65+i);
    }
}
/*
 * \brief Destructor
 */
Units::~Units() {
}
/*
 * \brief Change a long to a Units
 * \param
 */
void Units::longToUnits(){
    unsigned long long tamponReste = m_chiffre;
    unsigned long long tamponQuotient = m_chiffre;
    while(tamponQuotient >= 1000){
        tamponReste = tamponQuotient%1000;
        tamponQuotient -= tamponReste;
        tamponQuotient = tamponQuotient/1000;
        m_tab_nom_unite.push_back(tamponReste);
    }
    m_tab_nom_unite.push_back(tamponQuotient);
}
std::string Units::toString(){
    int position = m_tab_nom_unite.size();
    std::string string;
    string = cast::toString(m_tab_nom_unite.at(position)) + m_tableauLettre[position-1];
    return string;
}

