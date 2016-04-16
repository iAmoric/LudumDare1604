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

    /* Musique */
    ptr_managerGroup->ptr_musicManager->
            createPlaylist("playlistMenu", true, 1.2);
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->play();

    /* Monster */
    m_monster.create("monster", 140, 140,
                     ptr_managerGroup->ptr_textureManager->getTexture("monster"));
    getContentPane()->addComponent(&m_monster);

    /* Background */
    m_background.create("background", 0, 0,
                     ptr_managerGroup->ptr_textureManager->getTexture("background"));
    getContentPane()->addComponent(&m_background);

    /* Button */
    m_tabStatsButton.create("tabStatsButton", 845, 400,
                            ptr_managerGroup->ptr_textureManager->getTexture("tabStatsButton"),
                            ptr_managerGroup->ptr_textureManager->getTexture("tabStatsButton"));
    getContentPane()->addComponent(&m_tabStatsButton);

    m_tabScientistButton.create("tabScientistButton", 792, 400,
                            ptr_managerGroup->ptr_textureManager->getTexture("tabScientistButton"),
                            ptr_managerGroup->ptr_textureManager->getTexture("tabScientistButton"));
    getContentPane()->addComponent(&m_tabScientistButton);

    m_tabEquipmentButton.create("tabEquipmentButton", 740, 400,
                            ptr_managerGroup->ptr_textureManager->getTexture("tabEquipmentButton"),
                            ptr_managerGroup->ptr_textureManager->getTexture("tabEquipmentButton"));
    getContentPane()->addComponent(&m_tabEquipmentButton);

    /* Equipment */
    m_equipment1.create("equipement_1", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment1"));
    getContentPane()->addComponent(&m_equipment1);

    m_equipment2.create("equipement_2", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment2"));
    getContentPane()->addComponent(&m_equipment2);

    m_equipment3.create("equipement_3", 170, 520,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment3"));
    getContentPane()->addComponent(&m_equipment3);

    m_equipment4.create("equipement_4", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment4"));
    getContentPane()->addComponent(&m_equipment4);

    m_equipment5.create("equipement_5", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment5"));
    getContentPane()->addComponent(&m_equipment5);

    m_equipment6.create("equipement_6", 860, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment6"));
    getContentPane()->addComponent(&m_equipment6);

    m_equipment7.create("equipement_7", 860, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment7"));
    getContentPane()->addComponent(&m_equipment7);

    m_equipment8.create("equipement_8", 490, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment8"));
    getContentPane()->addComponent(&m_equipment8);

    m_equipment9.create("equipement_9", 490, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment9"));
    getContentPane()->addComponent(&m_equipment9);

    m_equipment10.create("equipement_10", 760, 490,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment10"));
    getContentPane()->addComponent(&m_equipment10);

    m_equipment11.create("equipement_11", 520, 492,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment11"));
    getContentPane()->addComponent(&m_equipment11);

    m_equipment12.create("equipement_12", 760, 490,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment12"));
    getContentPane()->addComponent(&m_equipment12);

    m_equipment13.create("equipement_13", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment13"));
    getContentPane()->addComponent(&m_equipment13);

    m_equipment14.create("equipement_14", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment14"));
    getContentPane()->addComponent(&m_equipment14);

    m_equipment15.create("equipement_15", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment15"));
    getContentPane()->addComponent(&m_equipment15);

    m_equipment16.create("equipement_16", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment16"));
    getContentPane()->addComponent(&m_equipment16);

    m_equipment17.create("equipement_17", 690, 435,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment17"));
    getContentPane()->addComponent(&m_equipment17);

    m_equipment18.create("equipement_18", 510, 10,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment18"));
    getContentPane()->addComponent(&m_equipment18);

    m_equipment19.create("equipement_19", 610, 450,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment19"));
    getContentPane()->addComponent(&m_equipment19);

    m_equipment20.create("equipement_20", 170, 507,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment20"));
    getContentPane()->addComponent(&m_equipment20);

    /* Animation */
    m_bulle.create("bulle", 27, 400,
                   ptr_managerGroup->ptr_textureManager->getTexture("bulle"),true, 0.1, 75, 60, 15);
    getContentPane()->addComponent(&m_bulle);

    m_flamme1.create("flamme1", 902, 520,
                    ptr_managerGroup->ptr_textureManager->getTexture("flamme1"),true, 0.1, 12, 5, 5);
    getContentPane()->addComponent(&m_flamme1);

    m_flamme2.create("flamme2", 804, 555,
                    ptr_managerGroup->ptr_textureManager->getTexture("flamme2"),true, 0.1, 12, 5, 5);
    getContentPane()->addComponent(&m_flamme2);

    m_ordi.create("ordi", 377, 443,
                   ptr_managerGroup->ptr_textureManager->getTexture("ordi"),true, 0.5, 69, 92, 3);
    getContentPane()->addComponent(&m_ordi);

    /* Init visible*/
    m_equipment1.setVisible(false);
    m_equipment2.setVisible(false);
    m_equipment3.setVisible(false);
    m_equipment4.setVisible(false);
    m_equipment5.setVisible(false);
    m_equipment6.setVisible(false);
    m_equipment7.setVisible(true);
    m_equipment8.setVisible(false);
    m_equipment9.setVisible(true);
    m_equipment10.setVisible(false);
    m_equipment11.setVisible(true);
    m_equipment12.setVisible(true);
    m_equipment13.setVisible(false);
    m_equipment14.setVisible(false);
    m_equipment15.setVisible(false);
    m_equipment16.setVisible(true);
    m_equipment17.setVisible(true);
    m_equipment19.setVisible(true);
    m_equipment20.setVisible(true);

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




