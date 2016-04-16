//
// Created by Jehan on 16/04/2016.
//

#ifndef CLIENT_SCIENTIFIC_HPP
#define CLIENT_SCIENTIFIC_HPP

#include <string>

class Scientific{
protected:
    std::string m_name;
    bool m_isBuy;
    bool m_isBuyable;
    unsigned long long m_price;
    int m_level;
    int m_type;
public:
    Scientific(std::string name, unsigned long long price, int type);
    ~Scientific();
    void nextLvl();
};

#endif //CLIENT_SCIENTIFIC_HPP
