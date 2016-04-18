//
// Created by Lucas on 16/04/2016.
//

#ifndef LUDUMDARE1604_MONSTER_HPP
#define LUDUMDARE1604_MONSTER_HPP


class Monster {
private:
    unsigned long long m_annee;
public:
    Monster(unsigned long long annee);
    ~Monster();
    void setAnnee(unsigned long long annee);
    unsigned long long getAnnee();

    void setEvolution(unsigned long long int nb);
};


#endif //LUDUMDARE1604_MONSTER_HPP
