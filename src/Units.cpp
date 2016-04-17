//
// Created by Roland on 16-Apr-16.
//
/*
 * Units constitu� d'un long + un string
 * String = puissance
 * long = valeur d'int
 */
#include <bits/stringfwd.h>
#include <Patch.hpp>
#include "Units.hpp"
#include <stdexcept>
#include <vector>
#include <windows.h>
#include <iostream>

using std::runtime_error;
using std::string;
using std::vector;
using std::wstring;

/*
 * \brief Constructor (unite en notation scientifique)
 * \param chiffre
 * \param nom_unite
 */
Units::Units() {
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
    long tamponReste = 0;
    unsigned long long tamponQuotient = m_chiffre;
    while(tamponQuotient >= 1000){
        tamponReste = (long)tamponQuotient%1000;
        tamponQuotient -= tamponReste;
        tamponQuotient = tamponQuotient/1000;
        m_tab_nom_unite.push_back(tamponReste);
    }
    m_tab_nom_unite.push_back(tamponQuotient);
}
std::wstring Units::toWString(){
    unsigned int position = m_tab_nom_unite.size();
    std::string string;
    std::string nb = " ";

    if(m_tab_nom_unite.size() == 1){
        string = cast::toString(m_tab_nom_unite.at(position-1));
    }
    else if(m_tab_nom_unite.at(position-1) > 100){
        string = cast::toString(m_tab_nom_unite.at(position-1)) + m_tableauLettre[position-1];
    }
    else{
        if(m_tab_nom_unite.at(position-2) < 100) nb = " 0";
        else if (m_tab_nom_unite.at(position-2) < 10) nb = " 00";
        string = cast::toString(m_tab_nom_unite.at(position-1)) + nb +
                cast::toString(m_tab_nom_unite.at(position-2)) + m_tableauLettre[position-1];
    }

    return utf8toUtf16(string);
}

wstring Units::utf8toUtf16(const string & str)
{
    if (str.empty())
        return wstring();

    size_t charsNeeded = (size_t)::MultiByteToWideChar(CP_UTF8, 0,
                                               str.data(), (int)str.size(), NULL, 0);
    if (charsNeeded == 0)
        throw runtime_error("Failed converting UTF-8 string to UTF-16");

    vector<wchar_t> buffer(charsNeeded);
    unsigned int charsConverted = (unsigned int)::MultiByteToWideChar(CP_UTF8, 0,
                                               str.data(), (int)str.size(), &buffer[0], buffer.size());
    if (charsConverted == 0)
        throw runtime_error("Failed converting UTF-8 string to UTF-16");

    return wstring(&buffer[0], charsConverted);
}


void Units::setNumber(unsigned long long number){
    m_tab_nom_unite.clear();
    m_chiffre = number;
    m_tableauLettre[0] = ' ';
    for (int i = 1; i < 26; ++i) {
        m_tableauLettre[i] = (char)(65+i);
    }
    longToUnits();
}
