//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_GAME_MANAGER_HPP
#define DEF_GAME_MANAGER_HPP

#include "Manager.hpp"
#include "Labo.hpp"
#include "Units.hpp"

class GameManager : public Manager {

private:
    bool m_debug;
    Labo* m_labo;
    Units* m_units;

public:
    // Constructor
    GameManager(bool debug);

    // Destructor
    ~GameManager();

    Labo* getLabo();
    Units* getUnits();

};


#endif // DEF_GAME_MANAGER_HPP
