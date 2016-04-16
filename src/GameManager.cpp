//
// Created by Lucas on 02/03/2016.
//

#include <GameManager.hpp>

/*!
 * \brief Constructor
 * \param debug The debug mode
 */
GameManager::GameManager(bool debug) : Manager(){
    m_debug = debug;
}

/**
 * \brief Destructor
 */
GameManager::~GameManager() {

}

Labo* GameManager::getLabo() {
    return m_labo;
}
