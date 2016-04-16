//
// Created by Roland on 16-Apr-16.
//

#ifndef CLIENT_UNITS_HPP
#define CLIENT_UNITS_HPP


#include <vector>

class Units {
private:
    std::vector<long> m_tab_nom_unite;
    unsigned long long m_chiffre;
    char m_tableauLettre[26];
public:
    Units(unsigned long long chiffre);
    ~Units();
    void longToUnits();
    std::string toString();
};


#endif //CLIENT_UNITS_HPP
