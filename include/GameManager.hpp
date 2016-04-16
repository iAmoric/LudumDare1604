//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_GAME_MANAGER_HPP
#define DEF_GAME_MANAGER_HPP

#include "Manager.hpp"
#include "Labo.hpp"

class GameManager : public Manager {

private:
    bool m_debug;
    Labo* m_labo;

public:
    // Constructor
    GameManager(bool debug);

    // Destructor
    ~GameManager();

    Labo* getLabo();

};


#endif // DEF_GAME_MANAGER_HPP
