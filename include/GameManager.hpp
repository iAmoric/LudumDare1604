//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_GAME_MANAGER_HPP
#define DEF_GAME_MANAGER_HPP

#include "Manager.hpp"
#include "Player.hpp"

class GameManager : public Manager {

private:
    bool m_debug;
    Player* m_player;

public:
    // Constructor
    GameManager(bool debug);

    // Destructor
    ~GameManager();

    Player* getPlayer();

};


#endif // DEF_GAME_MANAGER_HPP
