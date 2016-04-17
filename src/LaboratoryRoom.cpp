/*!
 * \file LoginMenu.cpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include <Patch.hpp>
#include "LaboratoryRoom.hpp"

/*!
 * \brief Constructor
 */
//Login menu hérite de BasicInterface
LaboratoryRoom::LaboratoryRoom(bool debug, ManagerGroup *ptr_managerGroup) :
        BasicInterface(debug, ptr_managerGroup) {

    /* Musique */
    ptr_managerGroup->ptr_musicManager->
            createPlaylist("playlistMenu", true, 1.0);
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->addMusic("../res/music/menu/Blue_Illusions.wav");
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->play();

    /* Font */
    if (!m_fontLabel.loadFromFile("../res/font/IndieFlower.ttf")) {
        std::cerr << "Issue with font downloading" << std::endl;
    }

    /* background */
    m_contentPane.setSprite(ptr_managerGroup->ptr_textureManager->getTexture("background"));

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
    m_labelClick.create("labelClick", 212, 457, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelClick);

    m_iconMoney.create("money-icon", 188, 436,
                    ptr_managerGroup->ptr_textureManager->getTexture("money-icon"));
    getContentPane()->addComponent(&m_iconMoney);
    m_labelMoney.create("labelMoney", 212, 431, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelMoney);

    m_iconReputation.create("reputation-icon", 284, 441,
                    ptr_managerGroup->ptr_textureManager->getTexture("reputation-icon"));
    getContentPane()->addComponent(&m_iconReputation);
    m_labelReputation.create("labelReputation", 310, 436, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelReputation);

    m_labelSlash.create("labelSlash", 300, 379, 20, &m_fontLabel, L"/", sf::Color::Black);
    getContentPane()->addComponent(&m_labelSlash);
    m_labelMonsterYears.create("labelMonsterYears", 310, 379, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelMonsterYears);

    m_iconResearch.create("research-icon", 284, 410,
                    ptr_managerGroup->ptr_textureManager->getTexture("research-icon"));
    getContentPane()->addComponent(&m_iconResearch);
    m_labelResearch.create("labelResearch", 310, 405, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelResearch);

    m_iconTime.create("time-icon",  188, 384,
                    ptr_managerGroup->ptr_textureManager->getTexture("time-icon"));
    getContentPane()->addComponent(&m_iconTime);
    m_labelTime.create("labelTime", 212, 379, 20, &m_fontLabel, L"0", sf::Color::Black);
    getContentPane()->addComponent(&m_labelTime);

    /*Timer */
    m_timeElapsed = 0;

    /* Monster */
    m_NbMonster = 1;
    m_monster.create("monster", 140, 140,
                     ptr_managerGroup->ptr_textureManager->getTexture("monster_"+cast::toString(m_NbMonster)),
                     ptr_managerGroup->ptr_textureManager->getTexture("monster_"+cast::toString(m_NbMonster)));
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

    m_equipment3Panel.create("equipment3Panel", 2000, 2000,
                             ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    getContentPane()->addComponent(&m_equipment3Panel);


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
    m_panelEquipment1Global.create("panelEquipment1Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment1.create("buttonEquipment1", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button1"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button1Press"));
    m_panelEquipment1Global.addComponent(&m_buttonEquipment1);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(0)->getPrice());
    std::wstring informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(0)->getYPS());
    std::wstring informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment1Price.create("labelEquipment1Price", 508, 88+60*down, 22,
                             &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment1Name.create("labelEquipment1Name", 585, 91+60*down, 18,
                                 &m_fontLabel, L"Orange Juice", sf::Color::Black);
    std::wstring informationsEquipment1 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(0)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment1.create("labelEquipment1Name", 508, 118+60*down, 20,
                                 &m_fontLabel, informationsEquipment1, sf::Color::Black);
    m_panelGoldEquipment1.create("gold1", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment1Global.addComponent(&m_panelGoldEquipment1);
    m_panelEquipment1Global.addComponent(&m_labelEquipment1Price);
    m_panelEquipment1Global.addComponent(&m_labelEquipment1Name);
    m_panelEquipment1Global.addComponent(&m_labelEquipment1);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment1Global);
    down++;

    m_panelEquipment2Global.create("panelEquipment2Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment2.create("buttonEquipment2", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));
    m_panelEquipment2Global.addComponent(&m_buttonEquipment2);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(1)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(1)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment2Price.create("labelEquipment2Price", 508, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment2Name.create("labelEquipment2Name", 585, 91+60*down, 18,
                                 &m_fontLabel, L"Grass Juice", sf::Color::Black);
    std::wstring informationsEquipment2 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(1)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment2.create("labelEquipment2Name", 508, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment2, sf::Color::Black);
    m_panelGoldEquipment2.create("gold2", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment2Global.addComponent(&m_panelGoldEquipment2);
    m_panelEquipment2Global.addComponent(&m_labelEquipment2Price);
    m_panelEquipment2Global.addComponent(&m_labelEquipment2Name);
    m_panelEquipment2Global.addComponent(&m_labelEquipment2);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment2Global);
    down++;

    m_panelEquipment3Global.create("panelEquipment3Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment3.create("buttonEquipment3", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));
    m_panelEquipment3Global.addComponent(&m_buttonEquipment3);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(2)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(2)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment3Price.create("labelEquipment3Price", 508, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment3Name.create("labelEquipment3Name", 585, 91+60*down, 18,
                                 &m_fontLabel, L"Coffee", sf::Color::Black);
    std::wstring informationsEquipment3 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(2)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment3.create("labelEquipment3Name", 508, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment3, sf::Color::Black);
    m_panelGoldEquipment3.create("gold3", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment3Global.addComponent(&m_panelGoldEquipment3);
    m_panelEquipment3Global.addComponent(&m_labelEquipment3Price);
    m_panelEquipment3Global.addComponent(&m_labelEquipment3Name);
    m_panelEquipment3Global.addComponent(&m_labelEquipment3);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment3Global);
    down++;

    m_panelEquipment4Global.create("panelEquipment4Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment4.create("buttonEquipment4", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));
    m_panelEquipment4Global.addComponent(&m_buttonEquipment4);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(3)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(3)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment4Price.create("labelEquipment4Price", 508, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment4Name.create("labelEquipment4Name", 585, 91+60*down, 18,
                                 &m_fontLabel, L"Love Potion", sf::Color::Black);
    std::wstring informationsEquipment4 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(3)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment4.create("labelEquipment4Name", 508, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment4, sf::Color::Black);
    m_panelGoldEquipment4.create("gold4", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment4Global.addComponent(&m_panelGoldEquipment4);
    m_panelEquipment4Global.addComponent(&m_labelEquipment4Price);
    m_panelEquipment4Global.addComponent(&m_labelEquipment4Name);
    m_panelEquipment4Global.addComponent(&m_labelEquipment4);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment4Global);
    down++;

    m_panelEquipment5Global.create("panelEquipment5Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment5.create("buttonEquipment5", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button5"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button5Press"));
    m_panelEquipment5Global.addComponent(&m_buttonEquipment5);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(4)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(4)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment5Price.create("labelEquipment5Price", 508, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment5Name.create("labelEquipment5Name", 585, 91+60*down, 18,
                                 &m_fontLabel, L"Sea Water", sf::Color::Black);
    std::wstring informationsEquipment5 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(4)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment5.create("labelEquipment5Name", 508, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment5, sf::Color::Black);
    m_panelGoldEquipment5.create("gold5", 560, 95+60*down,
                                ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment5Global.addComponent(&m_panelGoldEquipment5);
    m_panelEquipment5Global.addComponent(&m_labelEquipment5Price);
    m_panelEquipment5Global.addComponent(&m_labelEquipment5Name);
    m_panelEquipment5Global.addComponent(&m_labelEquipment5);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment5Global);
    down=0;

    m_panelEquipment6Global.create("panelEquipment6Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment6.create("buttonEquipment6", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button6"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button6Press"));
    m_panelEquipment6Global.addComponent(&m_buttonEquipment6);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(5)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(5)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment6Price.create("labelEquipment6Price", 738, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment6Name.create("labelEquipment6Name", 815, 91+60*down, 18,
                                 &m_fontLabel, L"Unicorn Blood", sf::Color::Black);
    std::wstring informationsEquipment6 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(5)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment6.create("labelEquipment6Name", 738, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment6, sf::Color::Black);
    m_panelGoldEquipment6.create("gold6", 790, 95+60*down,
                                ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment6Global.addComponent(&m_panelGoldEquipment6);
    m_panelEquipment6Global.addComponent(&m_labelEquipment6Price);
    m_panelEquipment6Global.addComponent(&m_labelEquipment6Name);
    m_panelEquipment6Global.addComponent(&m_labelEquipment6);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment6Global);
    down++;

    m_panelEquipment7Global.create("panelEquipment7Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment7.create("buttonEquipment7", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button7"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button7Press"));
    m_panelEquipment7Global.addComponent(&m_buttonEquipment7);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(6)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(6)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment7Price.create("labelEquipment7Price", 738, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment7Name.create("labelEquipment7Name", 815, 91+60*down, 18,
                                 &m_fontLabel, L"Mercury", sf::Color::Black);
    std::wstring informationsEquipment7 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(6)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment7.create("labelEquipment7Name", 738, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment7, sf::Color::Black);
    m_panelGoldEquipment7.create("gold7", 790, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment7Global.addComponent(&m_panelGoldEquipment7);
    m_panelEquipment7Global.addComponent(&m_labelEquipment7Price);
    m_panelEquipment7Global.addComponent(&m_labelEquipment7Name);
    m_panelEquipment7Global.addComponent(&m_labelEquipment7);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment7Global);
    down++;

    m_panelEquipment8Global.create("panelEquipment8Global", 2000, 2000,
                                   ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment8.create("buttonEquipment8", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button8"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button8Press"));
    m_panelEquipment8Global.addComponent(&m_buttonEquipment8);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(7)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(7)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment8Price.create("labelEquipment8Price", 738, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment8Name.create("labelEquipment8Name", 815, 91+60*down, 18,
                                 &m_fontLabel, L"Witch Blood", sf::Color::Black);
    std::wstring informationsEquipment8 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(7)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment8.create("labelEquipment8Name", 738, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment8, sf::Color::Black);
    m_panelGoldEquipment8.create("gold8", 790, 95+60*down,
                                ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment8Global.addComponent(&m_panelGoldEquipment8);
    m_panelEquipment8Global.addComponent(&m_labelEquipment8Price);
    m_panelEquipment8Global.addComponent(&m_labelEquipment8Name);
    m_panelEquipment8Global.addComponent(&m_labelEquipment8);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment8Global);
    down++;

    m_panelEquipment9Global.create("panelEquipment9Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment9.create("buttonEquipment9", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button1"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button1Press"));
    m_panelEquipment9Global.addComponent(&m_buttonEquipment9);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(8)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(8)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment9Price.create("labelEquipment9Price", 738, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment9Name.create("labelEquipment9Name", 815, 91+60*down, 18,
                                 &m_fontLabel, L"Bloody Mary", sf::Color::Black);
    std::wstring informationsEquipment9 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(8)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment9.create("labelEquipment9Name", 738, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment9, sf::Color::Black);
    m_panelGoldEquipment9.create("gold9", 790, 95+60*down,
                                ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment9Global.addComponent(&m_panelGoldEquipment9);
    m_panelEquipment9Global.addComponent(&m_labelEquipment9Price);
    m_panelEquipment9Global.addComponent(&m_labelEquipment9Name);
    m_panelEquipment9Global.addComponent(&m_labelEquipment9);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment9Global);
    down++;

    m_panelEquipment10Global.create("panelEquipment10Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment10.create("buttonEquipment10", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));
    m_panelEquipment10Global.addComponent(&m_buttonEquipment10);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(9)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(9)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment10Price.create("labelEquipment10Price", 738, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment10Name.create("labelEquipment10Name", 815, 91+60*down, 18,
                                 &m_fontLabel, L"Mana Potion", sf::Color::Black);
    std::wstring informationsEquipment10 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(9)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment10.create("labelEquipment10Name", 738, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment10, sf::Color::Black);
    m_panelGoldEquipment10.create("gold10", 790, 95+60*down,
                                ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment10Global.addComponent(&m_panelGoldEquipment10);
    m_panelEquipment10Global.addComponent(&m_labelEquipment10Price);
    m_panelEquipment10Global.addComponent(&m_labelEquipment10Name);
    m_panelEquipment10Global.addComponent(&m_labelEquipment10);
    m_subTabEquipmentPanel1.addComponent(&m_panelEquipment10Global);

    //Boutons sousPanels 2
    down = 0;
    m_panelEquipment11Global.create("panelEquipment11Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment11.create("buttonEquipment11", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));
    m_panelEquipment11Global.addComponent(&m_buttonEquipment11);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(10)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(10)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment11Price.create("labelEquipment11Price", 508, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment11Name.create("labelEquipment11Name", 585, 91+60*down, 18,
                                 &m_fontLabel, L"Phenolphthalein", sf::Color::Black);
    std::wstring informationsEquipment11 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(10)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment11.create("labelEquipment11Name", 508, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment11, sf::Color::Black);
    m_panelGoldEquipment11.create("gold11", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment11Global.addComponent(&m_panelGoldEquipment11);
    m_panelEquipment11Global.addComponent(&m_labelEquipment11Price);
    m_panelEquipment11Global.addComponent(&m_labelEquipment11Name);
    m_panelEquipment11Global.addComponent(&m_labelEquipment11);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment11Global);
    down++;

    m_panelEquipment12Global.create("panelEquipment12Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment12.create("buttonEquipment12", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));
    m_panelEquipment12Global.addComponent(&m_buttonEquipment12);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(11)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(11)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment12Price.create("labelEquipment12Price", 508, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment12Name.create("labelEquipment12Name", 585, 91+60*down, 18,
                                 &m_fontLabel, L"Heal Potion", sf::Color::Black);
    std::wstring informationsEquipment12 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(11)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment12.create("labelEquipment12Name", 508, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment12, sf::Color::Black);
    m_panelGoldEquipment12.create("gold12", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment12Global.addComponent(&m_panelGoldEquipment12);
    m_panelEquipment12Global.addComponent(&m_labelEquipment12Price);
    m_panelEquipment12Global.addComponent(&m_labelEquipment12Name);
    m_panelEquipment12Global.addComponent(&m_labelEquipment12);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment12Global);
    down++;

    m_panelEquipment13Global.create("panelEquipment13Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment13.create("buttonEquipment13", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button5"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button5Press"));
    m_panelEquipment13Global.addComponent(&m_buttonEquipment13);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(12)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(12)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment13Price.create("labelEquipment13Price", 508, 88+60*down, 22,
                                   &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment13Name.create("labelEquipment13Name", 585, 91+60*down, 18,
                                  &m_fontLabel, L"KMnO4", sf::Color::Black);
    std::wstring informationsEquipment13 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(12)->getLevel()) + L"   "
                                           + informationEquipmentYPS;
    m_labelEquipment13.create("labelEquipment13Name", 508, 118+60*down, 20,
                              &m_fontLabel, informationsEquipment13, sf::Color::Black);
    m_panelGoldEquipment13.create("gold13", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment13Global.addComponent(&m_panelGoldEquipment13);
    m_panelEquipment13Global.addComponent(&m_labelEquipment13Price);
    m_panelEquipment13Global.addComponent(&m_labelEquipment13Name);
    m_panelEquipment13Global.addComponent(&m_labelEquipment13);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment13Global);
    down++;

    m_panelEquipment14Global.create("panelEquipment14Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment14.create("buttonEquipment14", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button6"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button6Press"));
    m_panelEquipment14Global.addComponent(&m_buttonEquipment14);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(13)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(13)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment14Price.create("labelEquipment14Price", 508, 88+60*down, 22,
                                   &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment14Name.create("labelEquipment14Name", 585, 91+60*down, 18,
                                  &m_fontLabel, L"Black Matter", sf::Color::Black);
    std::wstring informationsEquipment14 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(13)->getLevel()) + L"   "
                                           + informationEquipmentYPS;
    m_labelEquipment14.create("labelEquipment14Name", 508, 118+60*down, 20,
                              &m_fontLabel, informationsEquipment14, sf::Color::Black);
    m_panelGoldEquipment14.create("gold14", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment14Global.addComponent(&m_panelGoldEquipment14);
    m_panelEquipment14Global.addComponent(&m_labelEquipment14Price);
    m_panelEquipment14Global.addComponent(&m_labelEquipment14Name);
    m_panelEquipment14Global.addComponent(&m_labelEquipment14);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment14Global);
    down++;


    m_panelEquipment15Global.create("panelEquipment15Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment15.create("buttonEquipment15", 500, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button7"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button7Press"));
    m_panelEquipment15Global.addComponent(&m_buttonEquipment15);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(14)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(14)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment15Price.create("labelEquipment15Price", 508, 88+60*down, 22,
                                   &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment15Name.create("labelEquipment15Name", 585, 91+60*down, 18,
                                  &m_fontLabel, L"Brake Fluid", sf::Color::Black);
    std::wstring informationsEquipment15 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(14)->getLevel()) + L"   "
                                           + informationEquipmentYPS;
    m_labelEquipment15.create("labelEquipment15Name", 508, 118+60*down, 20,
                              &m_fontLabel, informationsEquipment15, sf::Color::Black);
    m_panelGoldEquipment15.create("gold15", 560, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment15Global.addComponent(&m_panelGoldEquipment15);
    m_panelEquipment15Global.addComponent(&m_labelEquipment15Price);
    m_panelEquipment15Global.addComponent(&m_labelEquipment15Name);
    m_panelEquipment15Global.addComponent(&m_labelEquipment15);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment15Global);
    down=0;

    m_panelEquipment16Global.create("panelEquipment16Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment16.create("buttonEquipment16", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button8"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button8Press"));
    m_panelEquipment16Global.addComponent(&m_buttonEquipment16);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(15)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(15)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment16Price.create("labelEquipment16Price", 738, 88+60*down, 22,
                                  &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment16Name.create("labelEquipment16Name", 815, 91+60*down, 18,
                                 &m_fontLabel, L"Nitrogen", sf::Color::Black);
    std::wstring informationsEquipment16 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(15)->getLevel()) + L"   "
                                          + informationEquipmentYPS;
    m_labelEquipment16.create("labelEquipment16Name", 738, 118+60*down, 20,
                             &m_fontLabel, informationsEquipment16, sf::Color::Black);
    m_panelGoldEquipment16.create("gold16", 790, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment16Global.addComponent(&m_panelGoldEquipment16);
    m_panelEquipment16Global.addComponent(&m_labelEquipment16Price);
    m_panelEquipment16Global.addComponent(&m_labelEquipment16Name);
    m_panelEquipment16Global.addComponent(&m_labelEquipment16);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment16Global);
    down++;

    m_panelEquipment17Global.create("panelEquipment17Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment17.create("buttonEquipment17", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button1"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button1Press"));
    m_panelEquipment17Global.addComponent(&m_buttonEquipment17);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(16)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(16)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment17Price.create("labelEquipment17Price", 738, 88+60*down, 22,
                                   &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment17Name.create("labelEquipment17Name", 815, 91+60*down, 18,
                                  &m_fontLabel, L"Osmium", sf::Color::Black);
    std::wstring informationsEquipment17 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(16)->getLevel()) + L"   "
                                           + informationEquipmentYPS;
    m_labelEquipment17.create("labelEquipment17Name", 738, 118+60*down, 20,
                              &m_fontLabel, informationsEquipment17, sf::Color::Black);
    m_panelGoldEquipment17.create("gold17", 790, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment17Global.addComponent(&m_panelGoldEquipment17);
    m_panelEquipment17Global.addComponent(&m_labelEquipment17Price);
    m_panelEquipment17Global.addComponent(&m_labelEquipment17Name);
    m_panelEquipment17Global.addComponent(&m_labelEquipment17);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment17Global);
    down++;

    m_panelEquipment18Global.create("panelEquipment18Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment18.create("buttonEquipment18", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));
    m_panelEquipment18Global.addComponent(&m_buttonEquipment18);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(17)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(17)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment18Price.create("labelEquipment18Price", 738, 88+60*down, 22,
                                   &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment18Name.create("labelEquipment18Name", 815, 91+60*down, 18,
                                  &m_fontLabel, L"Science Medal", sf::Color::Black);
    std::wstring informationsEquipment18 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(17)->getLevel()) + L"   "
                                           + informationEquipmentYPS;
    m_labelEquipment18.create("labelEquipment18Name", 738, 118+60*down, 20,
                              &m_fontLabel, informationsEquipment18, sf::Color::Black);
    m_panelGoldEquipment18.create("gold18", 790, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment18Global.addComponent(&m_panelGoldEquipment18);
    m_panelEquipment18Global.addComponent(&m_labelEquipment18Price);
    m_panelEquipment18Global.addComponent(&m_labelEquipment18Name);
    m_panelEquipment18Global.addComponent(&m_labelEquipment18);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment18Global);
    down++;

    m_panelEquipment19Global.create("panelEquipment19Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment19.create("buttonEquipment19", 730, 90+60*down,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));
    m_panelEquipment19Global.addComponent(&m_buttonEquipment19);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(18)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(18)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment19Price.create("labelEquipment19Price", 738, 88+60*down, 22,
                                   &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment19Name.create("labelEquipment19Name", 815, 91+60*down, 18,
                                  &m_fontLabel, L"Microscope", sf::Color::Black);
    std::wstring informationsEquipment19 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(18)->getLevel()) + L"   "
                                           + informationEquipmentYPS;
    m_labelEquipment19.create("labelEquipment19Name", 738, 118+60*down, 20,
                              &m_fontLabel, informationsEquipment19, sf::Color::Black);
    m_panelGoldEquipment19.create("gold19", 790, 95+60*down,
                                 ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment19Global.addComponent(&m_panelGoldEquipment19);
    m_panelEquipment19Global.addComponent(&m_labelEquipment19Price);
    m_panelEquipment19Global.addComponent(&m_labelEquipment19Name);
    m_panelEquipment19Global.addComponent(&m_labelEquipment19);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment19Global);
    down++;

    m_panelEquipment20Global.create("panelEquipment20Global", 2000, 2000,
                                    ptr_managerGroup->ptr_textureManager->getTexture("close_1"));
    m_buttonEquipment20.create("buttonEquipment20", 730, 90+60*down,
                               ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                               ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));
    m_panelEquipment20Global.addComponent(&m_buttonEquipment20);
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(19)->getPrice());
    informationEquipmentPrice = ptr_managerGroup->ptr_gameManager->getUnits()->toWString();
    ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(19)->getYPS());
    informationEquipmentYPS = ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS ";
    m_labelEquipment20Price.create("labelEquipment20Price", 738, 88+60*down, 22,
                                   &m_fontLabel, informationEquipmentPrice, sf::Color::White);
    m_labelEquipment20Name.create("labelEquipment20Name", 815, 91+60*down, 18,
                                  &m_fontLabel, L"Beer", sf::Color::Black);
    std::wstring informationsEquipment20 = L"level " + cast::toWstring(ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(19)->getLevel()) + L"   "
                                           + informationEquipmentYPS;
    m_labelEquipment20.create("labelEquipment20Name", 738, 118+60*down, 20,
                              &m_fontLabel, informationsEquipment20, sf::Color::Black);
    m_panelGoldEquipment20.create("gold20", 790, 95+60*down,
                                  ptr_managerGroup->ptr_textureManager->getTexture("gold"));
    m_panelEquipment20Global.addComponent(&m_panelGoldEquipment20);
    m_panelEquipment20Global.addComponent(&m_labelEquipment20Price);
    m_panelEquipment20Global.addComponent(&m_labelEquipment20Name);
    m_panelEquipment20Global.addComponent(&m_labelEquipment20);
    m_subTabEquipmentPanel2.addComponent(&m_panelEquipment20Global);

    m_resetButton.create("resetButton", 260, 535,
                         ptr_managerGroup->ptr_textureManager->getTexture("resetButton"),
                         ptr_managerGroup->ptr_textureManager->getTexture("resetButton"));
    getContentPane()->addComponent(&m_resetButton);

    //Boutons scientists
    m_scientistJeannePanel.create("jeannePanel", 500, 83,
                              ptr_managerGroup->ptr_textureManager->getTexture("jeannePanel"));
    m_tabScientistPanel.addComponent(&m_scientistJeannePanel);

    m_scientistSergePanel.create("sergePanel", 750, 83,
                              ptr_managerGroup->ptr_textureManager->getTexture("sergePanel"));
    m_tabScientistPanel.addComponent(&m_scientistSergePanel);

    m_buyButtonJeanne.create("buyButtonJeanne", 560,350,
                             ptr_managerGroup->ptr_textureManager->getTexture("button2"),
                             ptr_managerGroup->ptr_textureManager->getTexture("button2Press"));
    m_tabScientistPanel.addComponent(&m_buyButtonJeanne);

    m_buyButtonSerge.create("buyButtonSerge", 800,350,
                             ptr_managerGroup->ptr_textureManager->getTexture("button4"),
                             ptr_managerGroup->ptr_textureManager->getTexture("button4Press"));
    m_tabScientistPanel.addComponent(&m_buyButtonSerge);

    /* Label */
    //First part of the stats
    m_nbClick.create("nbClick",500,80,15,&m_fontLabel
            ,L"Number of click : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_nbClick())
            , sf::Color::Black);
    m_nbReset.create("nbReset",500,95,15,&m_fontLabel
            ,L"Number of reset : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_nbReset())
            , sf::Color::Black);
    m_nbEvoMax.create("nbEvoMax",500,110,15,&m_fontLabel
            ,L"Maximum level achieved : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_nbEvoMax())
            , sf::Color::Black);
    m_spentTime.create("spentTime",500,125,15,&m_fontLabel
            ,L"Time spent : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_spentTime().asSeconds())
            , sf::Color::Black);
    m_actualMoney.create("actualMoney",500,140,15,&m_fontLabel
            ,L"Actual amount of money : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_actualMoney())
            , sf::Color::Black);
    m_totalMoney.create("totalMoney",500,155,15,&m_fontLabel
            ,L"Total amount of money obtained in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_totalMoney())
            , sf::Color::Black);
    m_spentMoney.create("spentMoney",500,170,15,&m_fontLabel
            ,L"Total amount of money spent in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_spentMoney())
            , sf::Color::Black);
    m_actualReputation.create("actualReputation",500,185,15,&m_fontLabel
            ,L"Actual reputation : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_actualReputation())
            , sf::Color::Black);
    m_totalReputation.create("totalReputation",500,200,15,&m_fontLabel
            ,L"Total reputation earned in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_totalReputation())
            , sf::Color::Black);
    m_spentReputation.create("nbClick",500,215,15,&m_fontLabel
            ,L"Total reputation spent in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_spentReputation())
            , sf::Color::Black);
    m_tabStatsPanel.addComponent(&m_nbClick);
    m_tabStatsPanel.addComponent(&m_nbReset);
    m_tabStatsPanel.addComponent(&m_nbEvoMax);
    m_tabStatsPanel.addComponent(&m_spentTime);
    m_tabStatsPanel.addComponent(&m_actualMoney);
    m_tabStatsPanel.addComponent(&m_totalMoney);
    m_tabStatsPanel.addComponent(&m_spentMoney);
    m_tabStatsPanel.addComponent(&m_actualReputation);
    m_tabStatsPanel.addComponent(&m_totalReputation);
    m_tabStatsPanel.addComponent(&m_spentReputation);

    //Second part of the stats
    m_panelYear.create("imgYear",500,250,ptr_managerGroup->ptr_textureManager->getTexture("time-icon"));
    m_year.create("labelYear",525,252,15,&m_fontLabel
            ,cast::toWstring("Actual year / years to evolve")
            , sf::Color::Black);
    m_panelMoney.create("imgMoney",738,250,ptr_managerGroup->ptr_textureManager->getTexture("bank-icon"));
    m_money.create("labelMoney",768,252,15,&m_fontLabel
            ,cast::toWstring("Money you have")
            , sf::Color::Black);
    m_panelMoneyPS.create("imgMoneyPS",500,350,ptr_managerGroup->ptr_textureManager->getTexture("money-icon"));
    m_moneyPS.create("labelMoneyPS",525,352,15,&m_fontLabel
            ,cast::toWstring("Money earned per second")
            , sf::Color::Black);
    m_panelClickPS.create("imgClickPS",500,300,ptr_managerGroup->ptr_textureManager->getTexture("click-icon"));
    m_clickPS.create("labelClickPS",525,302,15,&m_fontLabel
            ,cast::toWstring("Years earned by a click")
            , sf::Color::Black);
    m_panelYearPS.create("imgYearPS",735,300,ptr_managerGroup->ptr_textureManager->getTexture("research-icon"));
    m_yearPS.create("labelYearPS",760,302,15,&m_fontLabel
            ,cast::toWstring("Years earned per second")
            , sf::Color::Black);
    m_panelReputation.create("imgReputation",735,350,ptr_managerGroup->ptr_textureManager->getTexture("reputation-icon"));
    m_reputation.create("labelReputation",760,344,15,&m_fontLabel
            ,cast::toWstring("Reputation you'll\nwin on reset")
            , sf::Color::Black);

    m_tabStatsPanel.addComponent(&m_panelYear);
    m_tabStatsPanel.addComponent(&m_year);
    m_tabStatsPanel.addComponent(&m_panelMoney);
    m_tabStatsPanel.addComponent(&m_money);
    m_tabStatsPanel.addComponent(&m_panelMoneyPS);
    m_tabStatsPanel.addComponent(&m_moneyPS);
    m_tabStatsPanel.addComponent(&m_panelClickPS);
    m_tabStatsPanel.addComponent(&m_clickPS);
    m_tabStatsPanel.addComponent(&m_panelYearPS);
    m_tabStatsPanel.addComponent(&m_yearPS);
    m_tabStatsPanel.addComponent(&m_panelReputation);
    m_tabStatsPanel.addComponent(&m_reputation);
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
                         ptr_managerGroup->ptr_textureManager->getTexture("coffeeSmoke"),true, 0.27, 60, 50, 20);

    m_clickAnimation1.create("clickAnimation1", 150, 145,
                             ptr_managerGroup->ptr_textureManager->getTexture("clickAnimation1"),false, 0.05, 192, 192, 3);
    getContentPane()->addComponent(&m_clickAnimation1);
    m_clickAnimation1.setVisible(false);

    m_clickAnimation2.create("clickAnimation2", 150, 150,
                             ptr_managerGroup->ptr_textureManager->getTexture("clickAnimation2"),false, 0.05, 192, 192, 7);
    getContentPane()->addComponent(&m_clickAnimation2);
    m_clickAnimation2.setVisible(false);

    m_whiteBoardAnimation.create("whiteBoardAnimation", 494, 82,
                                 ptr_managerGroup->ptr_textureManager->getTexture("whiteBoardAnimation"),false, 0.04, 336, 448, 21);
    getContentPane()->addComponent(&m_whiteBoardAnimation);
    m_whiteBoardAnimation.setVisible(false);

    m_evolutionAnimation.create("evolvAnimation", 100, 95,
                                ptr_managerGroup->ptr_textureManager->getTexture("evolvAnimation"),false, 0.06, 300, 300, 14);
    m_evolutionAnimation.setVisible(false);
    getContentPane()->addComponent(&m_evolutionAnimation);

    /* Equipment */
    m_equipment1.create("equipement_1", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment1"), true, 0.2, 79, 120, 3);
    getContentPane()->addComponent(&m_equipment1);

    m_equipment2.create("equipement_2", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment2"), true, 0.2, 79, 120, 2);
    getContentPane()->addComponent(&m_equipment2);

    m_equipment3.create("equipement_3", 170, 520,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment3"));
    m_equipment3Panel.addComponent(&m_equipment3);
    m_equipment3Panel.addComponent(&m_coffeeSmoke);
    getContentPane()->addComponent(&m_equipment3Panel);

    m_equipment4.create("equipement_4", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment4"), true, 0.2, 79, 120, 2);
    getContentPane()->addComponent(&m_equipment4);

    m_equipment5.create("equipement_5", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment5"), true, 0.2, 79, 120, 3);
    getContentPane()->addComponent(&m_equipment5);

    m_equipment6.create("equipement_6", 860, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment6"), true, 0.2, 109, 80, 2);
    getContentPane()->addComponent(&m_equipment6);

    m_equipment7.create("equipement_7", 860, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment7"), true, 0.2, 100, 90, 2);
    getContentPane()->addComponent(&m_equipment7);

    m_equipment8.create("equipement_8", 490, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment8"), true, 0.2, 89, 120, 3);
    getContentPane()->addComponent(&m_equipment8);

    m_equipment9.create("equipement_9", 490, 440,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment9"), true, 0.2, 89, 120, 3);
    getContentPane()->addComponent(&m_equipment9);

    m_equipment10.create("equipement_10", 760, 490,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment10"), true, 0.2, 84, 95, 2);
    getContentPane()->addComponent(&m_equipment10);

    m_equipment11.create("equipement_11", 520, 492,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment11"), true, 0.2, 85, 70, 2);
    getContentPane()->addComponent(&m_equipment11);

    m_equipment12.create("equipement_12", 760, 490,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment12"), true, 0.2, 84, 95, 3);
    getContentPane()->addComponent(&m_equipment12);

    m_equipment13.create("equipement_13", 25, 470,
                        ptr_managerGroup->ptr_textureManager->getTexture("equipment13"), true, 0.2, 79, 120, 2);
    getContentPane()->addComponent(&m_equipment13);

    m_equipment14.create("equipement_14", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment14"), true, 0.2, 79, 120, 2);
    getContentPane()->addComponent(&m_equipment14);

    m_equipment15.create("equipement_15", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment15"), true, 0.2, 79, 120, 2);
    getContentPane()->addComponent(&m_equipment15);

    m_equipment16.create("equipement_16", 25, 470,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment16"), true, 0.2, 79, 120, 3);
    getContentPane()->addComponent(&m_equipment16);

    m_equipment17.create("equipement_17", 690, 435,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment17"), true, 0.2, 115, 50, 3);
    getContentPane()->addComponent(&m_equipment17);

    m_equipment18.create("equipement_18", 510, 10,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment18"));
    getContentPane()->addComponent(&m_equipment18);

    m_equipment19.create("equipement_19", 610, 450,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment19"));
    getContentPane()->addComponent(&m_equipment19);

    m_equipment20.create("equipement_20", 170, 507,
                         ptr_managerGroup->ptr_textureManager->getTexture("equipment20"), true, 0.1, 83, 70, 3);
    getContentPane()->addComponent(&m_equipment20);

    /* Banner */
    m_bannerPanel.create("bannerPanel", 115, 33,
                         ptr_managerGroup->ptr_textureManager->getTexture("banner"));
    getContentPane()->addComponent(&m_bannerPanel);

    m_labelLevel.create("levelLabel", 170, 55, 26,
                        &m_fontLabel, L"Evolution 1", sf::Color::White);
    getContentPane()->addComponent(&m_labelLevel);

    m_popupOnAnimation.create("popUpOn", 0, 0,
                              ptr_managerGroup->ptr_textureManager->getTexture("popUpOn"),false, 0.1, 640, 960, 5);
    getContentPane()->addComponent(&m_popupOnAnimation);
    m_popupOnAnimation.setVisible(false);

    m_popupOffAnimation.create("popUpOff", 0, 0,
                               ptr_managerGroup->ptr_textureManager->getTexture("popUpOff"),false, 0.1, 640, 960, 5);
    getContentPane()->addComponent(&m_popupOffAnimation);
    m_popupOffAnimation.setVisible(false);

    m_closePopupButton.create("closePopupButton", 550, 500,
                              ptr_managerGroup->ptr_textureManager->getTexture("button3"),
                              ptr_managerGroup->ptr_textureManager->getTexture("button3Press"));
    getContentPane()->addComponent(&m_closePopupButton);
    m_closePopupButton.setVisible(true);

    /* Init visible*/
    m_equipment1.setVisible(false);
    m_equipment2.setVisible(false);         //Remplace le 1
    m_equipment3Panel.setVisible(true);
    m_equipment4.setVisible(false);         //Remplace le 2
    m_equipment5.setVisible(false);         //Remplace le 4
    m_equipment6.setVisible(false);
    m_equipment7.setVisible(false);         //Remplace le 6
    m_equipment8.setVisible(false);
    m_equipment9.setVisible(false);         //Remplace le 8
    m_equipment10.setVisible(false);
    m_equipment11.setVisible(false);
    m_equipment12.setVisible(false);        //Remplace le 10
    m_equipment13.setVisible(false);        //Remplace le 5
    m_equipment14.setVisible(false);        //Remplace le 13
    m_equipment15.setVisible(false);        //Remplace le 14
    m_equipment16.setVisible(false);        //Remplace le 15
    m_equipment17.setVisible(false);
    m_equipment18.setVisible(false);
    m_equipment19.setVisible(false);
    m_equipment20.setVisible(false);        //Remplace le 3
    m_subTabEquipmentPanel2.setVisible(false);
    m_tabStatsPanel.setVisible(false);
    m_tabScientistPanel.setVisible(false);
    m_flamme1.setVisible(false);    //
    m_flamme2.setVisible(false);    //
    m_bulle.setVisible(false);  //

    m_targetPanel = "tabEquipmentPanel";

    firstConnect = true;
    firstEvolution = true;
    firstCanReset = true;
    firstReputation = true;
    firstReset = true;
}

LaboratoryRoom::~LaboratoryRoom() {
    // None
}

void LaboratoryRoom::update(sf::RenderWindow *window,
                       sf::Event *e, double frameTime) {

    if (!m_ptr_managerGroup->ptr_targetManager->isLaboratoryRoom())
        return;

    if (firstConnect){
        firstConnect=false;
        //TODO : setText sur le panel & afficher le panel
        m_popupOnAnimation.setVisible(true);
        m_popupOnAnimation.play();
    }



    m_timeElapsed += frameTime;
    if(m_timeElapsed >= 1){
        m_ptr_managerGroup->ptr_gameManager->getLabo()->grant();
        m_timeElapsed = 0;
        m_spentTime.setText(L"Time spent : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_spentTime().asSeconds()));
    }
    checkStateWhiteBoardAnimation();
    checkStateClickAnimation();
    checkStateEvolutionAnimation();
    checkStatePopupOnAnimation();
    checkStatePopupOffAnimation();

    m_nbClick.setText(L"Number of click : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_nbClick()));
    m_nbReset.setText(L"Number of reset : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_nbReset()));
    m_nbEvoMax.setText(L"Maximum level achieved : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_nbEvoMax()));
    m_spentMoney.setText(L"Total amount of money spent in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_spentMoney()));
    m_totalReputation.setText(L"Total reputation earned in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_totalReputation()));
    m_spentReputation.setText(L"Total reputation spent in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_spentReputation()));
    m_actualMoney.setText(L"Actual amount of money : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_actualMoney()));
    m_totalMoney.setText(L"Total amount of money obtained in your whole life : " + cast::toWstring(getLabo()->getM_ptr_stats()->getM_totalMoney()));
    m_actualReputation.setText(L"Actual reputation : " +
                                       cast::toWstring(getLabo()->getM_ptr_stats()->getM_totalReputation())
    +L" (+"+cast::toWstring(getLabo()->getReputationPointWaiting()) + L" if you quit the lab now)");

    Units unit = Units();
    unit.setNumber(m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_year());
        m_labelTime.setText(unit.toWString());

    unit.setNumber(m_ptr_managerGroup->ptr_gameManager->getLabo()->getYPS());
       m_labelResearch.setText(unit.toWString());

    unit.setNumber(m_ptr_managerGroup->ptr_gameManager->getLabo()->getCPS());
        m_labelClick.setText(unit.toWString());

    unit.setNumber(m_ptr_managerGroup->ptr_gameManager->getLabo()->getMoney());
        m_labelBank.setText(unit.toWString());

    unit.setNumber(m_ptr_managerGroup->ptr_gameManager->getLabo()->getMoneyGain());
        m_labelMoney.setText(unit.toWString());

    unit.setNumber(m_ptr_managerGroup->ptr_gameManager->getLabo()->getReputationPointOwned());
        m_labelReputation.setText(unit.toWString());
    unit.setNumber(m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_ptr_monster()->getAnnee());
    m_labelMonsterYears.setText(unit.toWString());

    if (getLabo()->getM_year() >=
        getLabo()->getM_ptr_monster()->getAnnee()) {
        if (getLabo()->getEvolutionLevel()<25) {
            if (firstEvolution){
                firstEvolution=false;
                //TODO : setText sur le panel & afficher le panel
                m_popupOnAnimation.setVisible(true);
                m_popupOnAnimation.play();
            }
            getLabo()->evolution();
            m_monster.setVisible(false);
            m_evolutionAnimation.setVisible(true);
            m_evolutionAnimation.play();
            m_labelLevel.setText(L"Evolution " + cast::toWstring(getLabo()->getEvolutionLevel()));
            m_monster.setSprite(m_ptr_managerGroup->ptr_textureManager->getTexture("monster_"+cast::toString(getLabo()->getEvolutionLevel())),
                                m_ptr_managerGroup->ptr_textureManager->getTexture("monster_"+cast::toString(getLabo()->getEvolutionLevel())));
        }
    }
    if (m_inputHandler.getComponentId() == "monster"){
        int anim = 1+ rand() % 2;
        switch(anim){
            case 1 :
                undisplayClickAnimation();
                m_clickAnimation1.setVisible(true);
                m_clickAnimation1.play();
                break;
            case 2 :
                undisplayClickAnimation();
                m_clickAnimation2.setVisible(true);
                m_clickAnimation2.play();
                break;
        }
        m_ptr_managerGroup->ptr_gameManager->getLabo()->click();
    }

    if (m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_year() >=
        m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_ptr_monster()->getAnnee()) {
        m_NbMonster++;
        if (m_NbMonster<=25) {
            m_monster.setSprite(m_ptr_managerGroup->ptr_textureManager->getTexture("monster_"+cast::toString(m_NbMonster)),
                                m_ptr_managerGroup->ptr_textureManager->getTexture("monster_"+cast::toString(m_NbMonster)));
        }
    }


    if (m_inputHandler.getComponentId() == "tabStatsButton"){
        if (m_targetPanel!="tabStatsPanel") {
            m_targetPanel = "tabStatsPanel";
            m_whiteBoardAnimation.setVisible(true);
            m_whiteBoardAnimation.play();
        }
        //displayStatsPanel();
    }

    if (m_inputHandler.getComponentId() == "tabEquipmentButton"){
        if (m_targetPanel!="tabEquipmentPanel") {
            m_targetPanel = "tabEquipmentPanel";
            m_whiteBoardAnimation.setVisible(true);
            m_whiteBoardAnimation.play();
        }
        //displayEquipmentPanel();
    }

    if (m_inputHandler.getComponentId() == "tabScientistButton"){
        if (m_targetPanel!="tabScientistPanel") {
            m_targetPanel = "tabScientistPanel";
            m_whiteBoardAnimation.setVisible(true);
            m_whiteBoardAnimation.play();
        }

        //displayScientistPanel();
    }

    if (m_inputHandler.getComponentId() == "arrowLeftButton"){
        m_subTabEquipmentPanel2.setVisible(false);
        m_subTabEquipmentPanel1.setVisible(true);
    }

    if (m_inputHandler.getComponentId() == "closePopupButton"){
        m_closePopupButton.setVisible(false);
        m_popupOnAnimation.setVisible(false);
        //TODO : setVisible(false) pour le panel contenant les explications
        m_popupOffAnimation.setVisible(true);
        m_popupOffAnimation.play();
    }

    if (m_inputHandler.getComponentId() == "resetButton")
        resetLabo();

    if (m_inputHandler.getComponentId() == "arrowRightButton"){
        m_subTabEquipmentPanel1.setVisible(false);
        m_subTabEquipmentPanel2.setVisible(true);
    }
    /* put the arrow only when the player have enought money to purchase the 11th equipment */
    if (!m_panelEquipment11Global.isVisible()) {
        m_arrowRightButton.setVisible(false);
    } else {
        m_arrowRightButton.setVisible(true);
    }

    /* verifying money to buy equipment */
    m_panelEquipment2Global.setVisible(false);
    m_panelEquipment3Global.setVisible(false);
    m_panelEquipment4Global.setVisible(false);
    m_panelEquipment5Global.setVisible(false);
    m_panelEquipment6Global.setVisible(false);
    m_panelEquipment7Global.setVisible(false);
    m_panelEquipment8Global.setVisible(false);
    m_panelEquipment9Global.setVisible(false);
    m_panelEquipment10Global.setVisible(false);
    m_panelEquipment11Global.setVisible(false);

    if (getLabo()->getM_LaboPieceVector().at(0)->getPrice() > getLabo()->getMoney()) {
        m_buttonEquipment1.setEnabled(false);
    } else {
        m_buttonEquipment1.setEnabled(true);
    }
    if (getLabo()->getM_LaboPieceVector().at(0)->getLevel()!=0) {
        m_panelEquipment2Global.setVisible(true);
    }
    m_buttonEquipment2.setEnabled(getLabo()->getM_LaboPieceVector().at(1)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(1)->getLevel()!=0) {
        m_panelEquipment3Global.setVisible(true);
    }
    m_buttonEquipment3.setEnabled(getLabo()->getM_LaboPieceVector().at(2)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(2)->getLevel()!=0) {
        m_panelEquipment4Global.setVisible(true);
    }
    m_buttonEquipment4.setEnabled(getLabo()->getM_LaboPieceVector().at(3)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(3)->getLevel()!=0) {
        m_panelEquipment5Global.setVisible(true);
    }
    m_buttonEquipment5.setEnabled(getLabo()->getM_LaboPieceVector().at(4)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(4)->getLevel()!=0) {
        m_panelEquipment6Global.setVisible(true);
    }
    m_buttonEquipment6.setEnabled(getLabo()->getM_LaboPieceVector().at(5)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(5)->getLevel()!=0) {
        m_panelEquipment7Global.setVisible(true);
    }
    m_buttonEquipment7.setEnabled(getLabo()->getM_LaboPieceVector().at(6)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(6)->getLevel()!=0) {
        m_panelEquipment8Global.setVisible(true);
    }
    m_buttonEquipment8.setEnabled(getLabo()->getM_LaboPieceVector().at(7)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(7)->getLevel()!=0) {
        m_panelEquipment9Global.setVisible(true);
    }
    m_buttonEquipment9.setEnabled(getLabo()->getM_LaboPieceVector().at(8)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(8)->getLevel()!=0) {
        m_panelEquipment10Global.setVisible(true);
    }
    m_buttonEquipment10.setEnabled(getLabo()->getM_LaboPieceVector().at(9)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(9)->getLevel()!=0) {
        m_panelEquipment11Global.setVisible(true);
    }
    m_buttonEquipment11.setEnabled(getLabo()->getM_LaboPieceVector().at(10)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(10)->getLevel()!=0) {
        m_panelEquipment12Global.setVisible(true);
    }
    m_buttonEquipment12.setEnabled(getLabo()->getM_LaboPieceVector().at(11)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(11)->getLevel()!=0) {
        m_panelEquipment13Global.setVisible(true);
    }
    m_buttonEquipment13.setEnabled(getLabo()->getM_LaboPieceVector().at(12)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(12)->getLevel()!=0) {
        m_panelEquipment14Global.setVisible(true);
    }
    m_buttonEquipment14.setEnabled(getLabo()->getM_LaboPieceVector().at(13)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(13)->getLevel()!=0) {
        m_panelEquipment15Global.setVisible(true);
    }
    m_buttonEquipment15.setEnabled(getLabo()->getM_LaboPieceVector().at(14)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(14)->getLevel()!=0) {
        m_panelEquipment16Global.setVisible(true);
    }
    m_buttonEquipment16.setEnabled(getLabo()->getM_LaboPieceVector().at(15)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(15)->getLevel()!=0) {
        m_panelEquipment17Global.setVisible(true);
    }
    m_buttonEquipment17.setEnabled(getLabo()->getM_LaboPieceVector().at(16)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(16)->getLevel()!=0) {
        m_panelEquipment18Global.setVisible(true);
    }
    m_buttonEquipment18.setEnabled(getLabo()->getM_LaboPieceVector().at(17)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(17)->getLevel()!=0) {
        m_panelEquipment19Global.setVisible(true);
    }
    m_buttonEquipment19.setEnabled(getLabo()->getM_LaboPieceVector().at(18)->getPrice() < getLabo()->getMoney());

    if (getLabo()->getM_LaboPieceVector().at(18)->getLevel()!=0) {
        m_panelEquipment20Global.setVisible(true);
    }
    m_buttonEquipment20.setEnabled(getLabo()->getM_LaboPieceVector().at(19)->getPrice() < getLabo()->getMoney());


    if (m_inputHandler.getComponentId() == "buttonEquipment1"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(0)->getPrice() &&
                getLabo()->getM_LaboPieceVector().at(0)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(0)->getPrice());
            getLabo()->lvlUpLaboPiece(0);
            if (!m_equipment2.isVisible() || !m_equipment4.isVisible() ||
                !m_equipment5.isVisible() || !m_equipment13.isVisible() ||
                !m_equipment14.isVisible() || !m_equipment15.isVisible() || !m_equipment16.isVisible()) {
                m_equipment1.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(0)->getPrice());
            m_labelEquipment1Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(0)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(0)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment1.setText(informationsEquipment);
        }

    }

    if (m_inputHandler.getComponentId() == "buttonEquipment2"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(1)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(1)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(1)->getPrice());
            getLabo()->lvlUpLaboPiece(1);
            if (!m_equipment4.isVisible() || !m_equipment5.isVisible() || !m_equipment13.isVisible() ||
                !m_equipment14.isVisible() || !m_equipment15.isVisible() || !m_equipment16.isVisible()) {
                m_equipment1.setVisible(false);
                m_equipment2.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(1)->getPrice());
            m_labelEquipment2Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(1)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(1)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment2.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment3"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(2)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(2)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(2)->getPrice());
            getLabo()->lvlUpLaboPiece(2);
            if (!m_equipment20.isVisible()) {
                m_equipment3Panel.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(2)->getPrice());
            m_labelEquipment3Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(2)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(2)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment3.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment4"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(3)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(3)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(3)->getPrice());
            getLabo()->lvlUpLaboPiece(3);
            if (!m_equipment5.isVisible() || !m_equipment13.isVisible() ||
                !m_equipment14.isVisible() || !m_equipment15.isVisible() || !m_equipment16.isVisible()) {
                m_equipment2.setVisible(false);
                m_equipment4.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(3)->getPrice());
            m_labelEquipment4Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(3)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(3)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment4.setText(informationsEquipment);
        }
    }
    if (m_inputHandler.getComponentId() == "buttonEquipment5"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(4)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(4)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(4)->getPrice());
            getLabo()->lvlUpLaboPiece(4);
            if (!m_equipment13.isVisible() || !m_equipment14.isVisible() ||
                !m_equipment15.isVisible() || !m_equipment16.isVisible()) {
                m_equipment4.setVisible(false);
                m_equipment5.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(4)->getPrice());
            m_labelEquipment5Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(4)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(4)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment5.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment6"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(5)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(5)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(5)->getPrice());
            getLabo()->lvlUpLaboPiece(5);
            if (!m_equipment7.isVisible()) {
                m_equipment6.setVisible(true);
                m_flamme1.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(5)->getPrice());
            m_labelEquipment6Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(5)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(5)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment6.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment7"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(6)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(6)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(6)->getPrice());
            getLabo()->lvlUpLaboPiece(6);
            m_equipment6.setVisible(false);
            m_equipment7.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(6)->getPrice());
            m_labelEquipment7Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(6)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(6)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment7.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment8"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(7)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(7)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(7)->getPrice());
            getLabo()->lvlUpLaboPiece(7);
            if (!m_equipment9.isVisible()) {
                m_equipment8.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(7)->getPrice());
            m_labelEquipment8Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(7)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(7)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment8.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment9"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(8)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(8)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(8)->getPrice());
            getLabo()->lvlUpLaboPiece(8);
            m_equipment8.setVisible(false);
            m_equipment9.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(8)->getPrice());
            m_labelEquipment9Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(8)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(8)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment9.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment10"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(9)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(9)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(9)->getPrice());
            getLabo()->lvlUpLaboPiece(9);
            if (!m_equipment12.isVisible()) {
                m_equipment10.setVisible(true);
                m_flamme2.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(9)->getPrice());
            m_labelEquipment10Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(9)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(9)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment10.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment11"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(10)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(10)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(10)->getPrice());
            getLabo()->lvlUpLaboPiece(10);
            m_equipment11.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(10)->getPrice());
            m_labelEquipment11Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(10)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(10)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment11.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment12"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(11)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(11)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(11)->getPrice());
            getLabo()->lvlUpLaboPiece(11);
            m_equipment10.setVisible(false);
            m_equipment12.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(11)->getPrice());
            m_labelEquipment12Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(11)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(11)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment12.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment13"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(12)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(12)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(12)->getPrice());
            getLabo()->lvlUpLaboPiece(12);
        if (!m_equipment14.isVisible() || !m_equipment15.isVisible() || !m_equipment16.isVisible()) {
            m_equipment4.setVisible(false);
            m_equipment13.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(12)->getPrice());
            m_labelEquipment13Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(12)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(12)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment13.setText(informationsEquipment);
        }
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment14"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(13)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(13)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(13)->getPrice());
            getLabo()->lvlUpLaboPiece(13);
            if (!m_equipment15.isVisible() || !m_equipment16.isVisible()) {
                m_equipment13.setVisible(false);
                m_equipment14.setVisible(true);

                m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                        m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(13)->getPrice());
                m_labelEquipment14Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

                m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                        m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(13)->getYPS());
                std::wstring informationEquipmentYPS =
                        m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
                std::wstring informationsEquipment = L"level " + cast::toWstring(
                        m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(13)->getLevel()) +
                                                     L"   "
                                                     + informationEquipmentYPS;
                m_labelEquipment14.setText(informationsEquipment);
            }
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment15"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(14)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(14)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(14)->getPrice());
            getLabo()->lvlUpLaboPiece(14);
            if (!m_equipment16.isVisible()) {
                m_equipment14.setVisible(false);
                m_equipment15.setVisible(true);
            }

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(14)->getPrice());
            m_labelEquipment15Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(14)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(14)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment15.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment16"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(15)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(15)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(15)->getPrice());
            getLabo()->lvlUpLaboPiece(15);
            m_equipment15.setVisible(false);
            m_equipment16.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(15)->getPrice());
            m_labelEquipment16Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(15)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(15)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment16.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment17"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(16)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(16)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(16)->getPrice());
            getLabo()->lvlUpLaboPiece(16);
            m_equipment17.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(16)->getPrice());
            m_labelEquipment17Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(16)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(16)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment17.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment18"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(17)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(17)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(17)->getPrice());
            getLabo()->lvlUpLaboPiece(17);
            m_equipment18.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(17)->getPrice());
            m_labelEquipment18Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(17)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(17)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment18.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment19"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(18)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(18)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(18)->getPrice());
            getLabo()->lvlUpLaboPiece(18);
            m_equipment19.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(18)->getPrice());
            m_labelEquipment19Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(18)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(18)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment19.setText(informationsEquipment);
        }
    }

    if (m_inputHandler.getComponentId() == "buttonEquipment20"){
        if(getLabo()->getMoney() >= getLabo()->getM_LaboPieceVector().at(19)->getPrice() &&
           getLabo()->getM_LaboPieceVector().at(19)->getLevel() < 21) {
            getLabo()->setMoney(getLabo()->getMoney() - getLabo()->getM_LaboPieceVector().at(19)->getPrice());
            getLabo()->lvlUpLaboPiece(19);
            m_equipment3Panel.setVisible(false);
            m_equipment20.setVisible(true);

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(19)->getPrice());
            m_labelEquipment20Price.setText(m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString());

            m_ptr_managerGroup->ptr_gameManager->getUnits()->setNumber(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(19)->getYPS());
            std::wstring informationEquipmentYPS =
                    m_ptr_managerGroup->ptr_gameManager->getUnits()->toWString() + L" YPS";
            std::wstring informationsEquipment = L"level " + cast::toWstring(
                    m_ptr_managerGroup->ptr_gameManager->getLabo()->getM_LaboPieceVector().at(19)->getLevel()) + L"   "
                                                 + informationEquipmentYPS;
            m_labelEquipment20.setText(informationsEquipment);
        }
    }

    basicInput(e, frameTime);
    basicDraw(window);
}

Labo* LaboratoryRoom::getLabo(){
    return m_ptr_managerGroup->ptr_gameManager->getLabo();
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

void LaboratoryRoom::checkStateWhiteBoardAnimation(){
    if(m_whiteBoardAnimation.isStopped()){
        m_whiteBoardAnimation.setVisible(false);

        if (m_targetPanel == "tabScientistPanel")
            displayScientistPanel();
        if (m_targetPanel == "tabEquipmentPanel")
            displayEquipmentPanel();
        if (m_targetPanel == "tabStatsPanel")
            displayStatsPanel();
    }
}

void LaboratoryRoom::checkStateClickAnimation() {

    if (m_clickAnimation1.isStopped())
        m_clickAnimation1.setVisible(false);

    if (m_clickAnimation2.isStopped())
        m_clickAnimation2.setVisible(false);

}

void LaboratoryRoom::undisplayClickAnimation(){
    m_clickAnimation3.setVisible(false);
    m_clickAnimation2.setVisible(false);
}


void LaboratoryRoom::checkStateEvolutionAnimation() {
    if(m_evolutionAnimation.isStopped()){
        m_evolutionAnimation.setVisible(false);
        m_monster.setVisible(true);
    }
}

void LaboratoryRoom::checkStatePopupOnAnimation() {
    if(m_popupOnAnimation.isStopped()){
        m_closePopupButton.setVisible(true);
    }
}

void LaboratoryRoom::checkStatePopupOffAnimation() {
    if(m_popupOffAnimation.isStopped()){
        m_popupOffAnimation.setVisible(false);
        //m_closePopupButton.setVisible(false);
    }
}

void LaboratoryRoom::resetLabo() {
    getLabo()->restart();
    //TODO : vider la table
    //TODO : Remettre le sprite du monstre de départ
    //TODO : Remetre l'évolution à 1
}



