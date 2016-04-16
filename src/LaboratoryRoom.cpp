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

    /* Font */
    if (!m_fontLabel.loadFromFile("../res/font/IndieFlower.ttf"))
    {
        std::cout << "Probleme dans le chargement des textures" << std::endl;
    }

    /* Screen */
    m_screen.create("screen", 186, 378,
                    ptr_managerGroup->ptr_textureManager->getTexture("screen"));
    getContentPane()->addComponent(&m_screen);

    m_iconBank.create("bank-icon", 188, 410,
                    ptr_managerGroup->ptr_textureManager->getTexture("bank-icon"));
    getContentPane()->addComponent(&m_iconBank);
    m_labelBank.create("labelBank", 212, 405, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelBank);

    m_iconClick.create("click-icon", 188, 462,
                    ptr_managerGroup->ptr_textureManager->getTexture("click-icon"));
    getContentPane()->addComponent(&m_iconClick);
    m_labelClick.create("labelBank", 212, 457, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelClick);

    m_iconMoney.create("money-icon", 188, 436,
                    ptr_managerGroup->ptr_textureManager->getTexture("money-icon"));
    getContentPane()->addComponent(&m_iconMoney);
    m_labelMoney.create("labelMoney", 212, 431, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelMoney);

    m_iconReputation.create("reputation-icon", 295, 410,
                    ptr_managerGroup->ptr_textureManager->getTexture("reputation-icon"));
    getContentPane()->addComponent(&m_iconReputation);
    m_labelReputation.create("labelReputation", 319, 405, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelReputation);

    m_iconResearch.create("research-icon", 295, 384,
                    ptr_managerGroup->ptr_textureManager->getTexture("research-icon"));
    getContentPane()->addComponent(&m_iconResearch);
    m_labelResearch.create("labelResearch", 319, 379, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelResearch);

    m_iconTime.create("time-icon",  188, 384,
                    ptr_managerGroup->ptr_textureManager->getTexture("time-icon"));
    getContentPane()->addComponent(&m_iconTime);
    m_labelTime.create("labelTime", 212, 379, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelTime);


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

    m_subTabEquipmentPanel1.create("subTabEquipmentPanel1", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_tabEquipmentPanel.addComponent(&m_subTabEquipmentPanel1);

    m_subTabEquipmentPanel2.create("subTabEquipmentPanel2", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_tabEquipmentPanel.addComponent(&m_subTabEquipmentPanel2);


    /* Button */
    //onglets
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

    //fleches
    m_arrowRightButton.create("arrowRightButton", 920, 400,
                             ptr_managerGroup->ptr_textureManager->getTexture("arrowRight"),
                             ptr_managerGroup->ptr_textureManager->getTexture("arrowRightPress"));
    m_subTabEquipmentPanel1.addComponent(&m_arrowRightButton);

    m_arrowLeftButton.create("arrowLeftButton", 920, 400,
                             ptr_managerGroup->ptr_textureManager->getTexture("arrowLeft"),
                             ptr_managerGroup->ptr_textureManager->getTexture("arrowLeftPress"));
    m_subTabEquipmentPanel2.addComponent(&m_arrowLeftButton);

    //Boutons sousPanels 1
    int down = 0;
    m_buttonEquipment1.create("buttonEquipment1", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button1"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button1Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment1);
    down++;

    m_buttonEquipment2.create("buttonEquipment2", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment2);
    down++;

    m_buttonEquipment3.create("buttonEquipment3", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment3);
    down++;

    m_buttonEquipment4.create("buttonEquipment4", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment4);
    down++;
    m_buttonEquipment5.create("buttonEquipment5", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button5"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button5Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment5);
    down=0;

    m_buttonEquipment6.create("buttonEquipment6", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button6"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button6Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment6);
    down++;

    m_buttonEquipment7.create("buttonEquipment7", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button7"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button7Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment7);
    down++;

    m_buttonEquipment8.create("buttonEquipment8", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button8"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button8Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment8);
    down++;

    m_buttonEquipment9.create("buttonEquipment9", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button1"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button1Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment9);
    down++;

    m_buttonEquipment10.create("buttonEquipment10", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));
    m_subTabEquipmentPanel1.addComponent(&m_buttonEquipment10);

    //Boutons sousPanels 2
    down = 0;
    m_buttonEquipment11.create("buttonEquipment11", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment11);
    down++;

    m_buttonEquipment12.create("buttonEquipment12", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment12);
    down++;

    m_buttonEquipment13.create("buttonEquipment13", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button5"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button5Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment13);
    down++;

    m_buttonEquipment14.create("buttonEquipment14", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button6"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button6Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment14);
    down++;
    m_buttonEquipment15.create("buttonEquipment15", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button7"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button7Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment15);
    down=0;

    m_buttonEquipment16.create("buttonEquipment16", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button8"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button8Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment16);
    down++;

    m_buttonEquipment17.create("buttonEquipment17", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button1"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button1Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment17);
    down++;

    m_buttonEquipment18.create("buttonEquipment18", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment18);
    down++;

    m_buttonEquipment19.create("buttonEquipment19", 740, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment19);
    down++;

    m_buttonEquipment20.create("buttonEquipment20", 740, 90+60*down,
                               ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                               ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));
    m_subTabEquipmentPanel2.addComponent(&m_buttonEquipment20);


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
    m_subTabEquipmentPanel2.setVisible(false);
    m_tabStatsPanel.setVisible(false);
    m_tabScientistPanel.setVisible(false);
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

    Units unit = Units(m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_year());
    m_labelTime.setText(unit.toWString());

    unit = Units(m_ptr_managerGroup->ptr_gameManager->getLabo()->getYPS());
    m_labelResearch.setText(unit.toWString());

    unit = Units(m_ptr_managerGroup->ptr_gameManager->getLabo()->getCPS());
    m_labelClick.setText(unit.toWString());

    unit = Units(m_ptr_managerGroup->ptr_gameManager->getLabo()->getMoney());
    m_labelBank.setText(unit.toWString());

    unit = Units(m_ptr_managerGroup->ptr_gameManager->getLabo()->getMoneyGain());
    m_labelMoney.setText(unit.toWString());

    unit = Units(m_ptr_managerGroup->ptr_gameManager->getLabo()->getReputationPointOwned());
    m_labelReputation.setText(unit.toWString());


    if (m_inputHandler.getComponentId() == "tabStatsButton"){
        displayStatsPanel();
    }

    if (m_inputHandler.getComponentId() == "tabEquipmentButton"){
        displayEquipmentPanel();
    }

    if (m_inputHandler.getComponentId() == "tabScientistButton"){
        displayScientistPanel();
    }

    if (m_inputHandler.getComponentId() == "arrowLeftButton"){
        m_subTabEquipmentPanel2.setVisible(false);
        m_subTabEquipmentPanel1.setVisible(true);
    }

    if (m_inputHandler.getComponentId() == "arrowRightButton"){
        m_subTabEquipmentPanel1.setVisible(false);
        m_subTabEquipmentPanel2.setVisible(true);
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



