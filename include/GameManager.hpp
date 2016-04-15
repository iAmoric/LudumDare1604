//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_GAME_MANAGER_HPP
#define DEF_GAME_MANAGER_HPP

#include "Manager.hpp"
#include <vector>

#include <string>

class GameManager : public Manager {

private:
    bool m_debug;


public:
    // Constructor
    GameManager(bool debug);

    // Destructor
    ~GameManager();

};


#endif // DEF_GAME_MANAGER_HPP
