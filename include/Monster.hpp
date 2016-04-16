//
// Created by Lucas on 16/04/2016.
//

#ifndef LUDUMDARE1604_MONSTER_HPP
#define LUDUMDARE1604_MONSTER_HPP


class Monster {
private:
    unsigned long long m_annee;
public:
    Monster();
    ~Monster();
    void setAnnee(unsigned long long annee);
    unsigned long long getAnnee();
};


#endif //LUDUMDARE1604_MONSTER_HPP
