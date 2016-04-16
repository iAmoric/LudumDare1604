/*!
 * \file LoginMenu.cpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "LaboratoryRoom.hpp"

/*!
 * \brief Constructor
 */
//Login menu hérite de BasicInterface
LaboratoryRoom::LaboratoryRoom(bool debug, ManagerGroup *ptr_managerGroup) :
        BasicInterface(debug, ptr_managerGroup) {

    //Création de la musique pour la 'fenetre'
    ptr_managerGroup->ptr_musicManager->
            createPlaylist("playlistMenu", true, 1.2);
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->play();


    m_equipment1.create("equipement_1", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment1"));
    getContentPane()->addComponent(&m_equipment1);

    m_equipment2.create("equipement_2", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment2"));
    getContentPane()->addComponent(&m_equipment2);

    m_equipment3.create("equipement_3", 500, 500,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment3"));
    getContentPane()->addComponent(&m_equipment3);

    m_equipment4.create("equipement_4", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment4"));
    getContentPane()->addComponent(&m_equipment4);

    m_equipment5.create("equipement_5", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment5"));
    getContentPane()->addComponent(&m_equipment5);

    m_equipment13.create("equipement_13", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment13"));
    getContentPane()->addComponent(&m_equipment13);

    m_equipment14.create("equipement_14", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment14"));
    getContentPane()->addComponent(&m_equipment14);

    m_equipment14.create("equipement_14", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment14"));
    getContentPane()->addComponent(&m_equipment14);

    m_equipment15.create("equipement_15", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment15"));
    getContentPane()->addComponent(&m_equipment15);

    m_equipment16.create("equipement_16", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment16"));
    getContentPane()->addComponent(&m_equipment16);

    m_bulle.create("bulle", 150, 200,
                   ptr_managerGroup->ptr_textureManager->getTexture("bulle"),true, 0.1, 75, 60, 15);
    getContentPane()->addComponent(&m_bulle);

    m_ordi.create("ordi", 377, 443,
                   ptr_managerGroup->ptr_textureManager->getTexture("ordi"),true, 0.5, 69, 92, 3);
    getContentPane()->addComponent(&m_ordi);


    m_equipment1.setVisible(false);
    m_equipment2.setVisible(false);
    m_equipment3.setVisible(true);
    m_equipment4.setVisible(false);
    m_equipment5.setVisible(false);
    m_equipment13.setVisible(false);
    m_equipment14.setVisible(false);
    m_equipment15.setVisible(false);
    m_equipment16.setVisible(true);

}

/*!
 * \brief Constructor
 */
LaboratoryRoom::~LaboratoryRoom() {
    // TODO
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
//Méthode appellé à chaque tour de boucle, elle gère les évènements
void LaboratoryRoom::update(sf::RenderWindow *window,
                       sf::Event *e, double frameTime) {

    //Si on est pas sur la fenetre, on return
    if (!m_ptr_managerGroup->ptr_targetManager->isLoginMenu())
        return;

    // Basic Interface updating
    basicInput(e, frameTime);


    // Drawing all content
    basicDraw(window);
}




