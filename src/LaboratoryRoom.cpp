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

    /*Timer */
    m_timeElapsed = 0;

    /* Monster */
    m_monster.create("monster", 140, 140,
                     ptr_managerGroup->ptr_textureManager->getTexture("monster_1"),
                     ptr_managerGroup->ptr_textureManager->getTexture("monster_1"));
    getContentPane()->addComponent(&m_monster);

    /* Background */
    m_background.create("background", 0, 0,
                     ptr_managerGroup->ptr_textureManager->getTexture("background"));
    getContentPane()->addComponent(&m_background);

    /* Panels */
    m_tabStatsPanel.create("tabStatsPanel", 2000, 2000,
                           ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    getContentPane()->addComponent(&m_tabStatsPanel);

    m_tabScientistPanel.create("tabScientistPanel", 2000, 2000,
                               ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    getContentPane()->addComponent(&m_tabScientistPanel);

    m_tabEquipmentPanel.create("tabEquipmentPanel", 2000, 2000,
                               ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    getContentPane()->addComponent(&m_tabEquipmentPanel);

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
/*
    int down = 0;
    m_buttonEquipment1.create("buttonEquipment1", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button1"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button1Press"));

    down++;

    m_buttonEquipment2.create("buttonEquipment2", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));

    down++;

    m_buttonEquipment3.create("buttonEquipment3", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));

    down++;

    m_buttonEquipment4.create("buttonEquipment4", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));

    down++;

    down=0;
    m_buttonEquipment5.create("buttonEquipment5", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button5"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button5Press"));

    down++;

    m_buttonEquipment6.create("buttonEquipment6", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button6"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button6Press"));

    down++;

    m_buttonEquipment7.create("buttonEquipment7", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button7"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button7Press"));
    down++;

    m_buttonEquipment8.create("buttonEquipment8", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button8"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button8Press"));
    down++;

    m_buttonEquipment9.create("buttonEquipment9", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button9"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button9Press"));
    down++;

    m_buttonEquipment10.create("buttonEquipment10", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button10"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button10Press"));
*/

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
    m_bulle.create("bulle", 28, 400,
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

    m_coffeeSmoke.create("coffeeSmoke", 195, 475,
                  ptr_managerGroup->ptr_textureManager->getTexture("coffeeSmoke"),true, 0.1, 60, 50, 20);
    getContentPane()->addComponent(&m_coffeeSmoke);


    /* Init visible*/
    m_equipment1.setVisible(false);
    m_equipment2.setVisible(false);
    m_equipment3.setVisible(true);
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
    m_equipment20.setVisible(false);

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
    m_timeElapsed += frameTime;
    if(m_timeElapsed >= frameTime){
        m_ptr_managerGroup->ptr_gameManager->getLabo()->grant();
        m_timeElapsed = 0;
    }


    if (m_inputHandler.getComponentId() == "tabStatsButton"){
        displayStatsPanel();
    }

    if (m_inputHandler.getComponentId() == "tabEquipmentButton"){
        displayEquipmentPanel();
    }

    if (m_inputHandler.getComponentId() == "tabScientistButton"){
        displayScientistPanel();
    }
    // Basic Interface updating
    basicInput(e, frameTime);


    // Drawing all content
    basicDraw(window);
}

void LaboratoryRoom::undisplayAllTabs(){
    m_tabEquipmentPanel.setVisible(false);
    m_tabScientistPanel.setVisible(false);
    m_tabStatsPanel.setVisible(false);
}

void LaboratoryRoom::displayStatsPanel(){
    undisplayAllTabs();
    m_tabStatsPanel.setVisible(true);
}

void LaboratoryRoom::displayEquipmentPanel(){
    undisplayAllTabs();
    m_tabEquipmentPanel.setVisible(true);
}

void LaboratoryRoom::displayScientistPanel(){
    undisplayAllTabs();
    m_tabScientistPanel.setVisible(true);
}



