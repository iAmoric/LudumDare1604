//
// Created by Jehan on 16/04/2016.
//

#include "Scientific.hpp"

Scientific::Scientific(std::string name, long price, int type) {
    m_name = name;
    m_price = price;
    m_type = type;
    m_isBuy = false;
    m_isBuyable = false;
    m_level = 0;
}

Scientific::~Scientific() {

}

void Scientific::nextLvl() {
    m_level++;
}
