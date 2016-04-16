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

using std::runtime_error;
using std::string;
using std::vector;
using std::wstring;

/*
 * \brief Constructor (unite en notation scientifique)
 * \param chiffre
 * \param nom_unite
 */
Units::Units(unsigned long long chiffre) {
    m_chiffre = chiffre;
    m_tableauLettre[0] = ' ';
    for (int i = 1; i < 26; ++i) {
        m_tableauLettre[i] = (char)(65+i);
    }
    longToUnits();
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
std::wstring Units::toWString(){
    int position = m_tab_nom_unite.size();
    std::string string;
    string = cast::toString(m_tab_nom_unite.at(position-1)) + m_tableauLettre[position-1];


    return utf8toUtf16(string);
}

wstring Units::utf8toUtf16(const string & str)
{
    if (str.empty())
        return wstring();

    size_t charsNeeded = ::MultiByteToWideChar(CP_UTF8, 0,
                                               str.data(), (int)str.size(), NULL, 0);
    if (charsNeeded == 0)
        throw runtime_error("Failed converting UTF-8 string to UTF-16");

    vector<wchar_t> buffer(charsNeeded);
    int charsConverted = ::MultiByteToWideChar(CP_UTF8, 0,
                                               str.data(), (int)str.size(), &buffer[0], buffer.size());
    if (charsConverted == 0)
        throw runtime_error("Failed converting UTF-8 string to UTF-16");

    return wstring(&buffer[0], charsConverted);
}
