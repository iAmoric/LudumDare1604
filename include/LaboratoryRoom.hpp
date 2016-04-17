/*!
 * \file LoginMenu.hpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_LABORATORY_ROOM_HPP
#define DEF_LABORATORY_ROOM_HPP

#include "BasicInterface.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "patch.hpp"

//LoginMenu hérite de BasicInterface
class LaboratoryRoom : public BasicInterface
{
private:
	NPanel m_background;
	AnimatableObject m_equipment1;
	AnimatableObject m_equipment2;
	NPanel m_equipment3Panel;
	NPanel m_equipment3;
	AnimatableObject m_equipment4;
	AnimatableObject m_equipment5;
	AnimatableObject m_equipment6;
	AnimatableObject m_equipment7;
	AnimatableObject m_equipment8;
	AnimatableObject m_equipment9;
	AnimatableObject m_equipment10;
	AnimatableObject m_equipment11;
	AnimatableObject m_equipment12;
	AnimatableObject m_equipment13;
	AnimatableObject m_equipment14;
	AnimatableObject m_equipment15;
	AnimatableObject m_equipment16;
	AnimatableObject m_equipment17;
	NPanel m_equipment18;
	NPanel m_equipment19;
	AnimatableObject m_equipment20;

	NPanel m_tabScientistPanel;
	NPanel m_tabEquipmentPanel;
	NPanel m_tabStatsPanel;
	NPanel m_subTabEquipmentPanel1;
	NPanel m_subTabEquipmentPanel2;
	NPanel m_scientistJeannePanel;
	NPanel m_scientistSergePanel;
	NLabel m_scientistJeanneCost;
	NLabel m_scientistSergeCost;
	NPanel m_reputationPanel1;
	NPanel m_reputationPanel2;


	NPanel m_bannerPanel;
	sf::Font m_fontLabel;

	NButton m_resetButton;

	//Label for stats' panel
	NLabel m_nbClick;
	NLabel m_nbReset;
	NLabel m_nbEvoMax;
	NLabel m_spentTime;
	NLabel m_actualMoney;
	NLabel m_totalMoney;
	NLabel m_spentMoney;
	NLabel m_actualReputation;
	NLabel m_totalReputation;
	NLabel m_spentReputation;

	//Second part of the stats
	NPanel m_panelYear;
	NLabel m_year;
	NPanel m_panelMoney;
	NLabel m_money;
	NPanel m_panelMoneyPS;
	NLabel m_moneyPS;
	NPanel m_panelClickPS;
	NLabel m_clickPS;
	NPanel m_panelYearPS;
	NLabel m_yearPS;
	NPanel m_panelReputation;
	NLabel m_reputation;
	NLabel m_labelLevel;
	NLabel m_suppReputation;

	NPanel m_panelTutorial;
	NLabel m_tutorial;

	NPanel m_panelGoldEquipment1;
	NPanel m_panelGoldEquipment2;
	NPanel m_panelGoldEquipment3;
	NPanel m_panelGoldEquipment4;
	NPanel m_panelGoldEquipment5;
	NPanel m_panelGoldEquipment6;
	NPanel m_panelGoldEquipment7;
	NPanel m_panelGoldEquipment8;
	NPanel m_panelGoldEquipment9;
	NPanel m_panelGoldEquipment10;
	NPanel m_panelGoldEquipment11;
	NPanel m_panelGoldEquipment12;
	NPanel m_panelGoldEquipment13;
	NPanel m_panelGoldEquipment14;
	NPanel m_panelGoldEquipment15;
	NPanel m_panelGoldEquipment16;
	NPanel m_panelGoldEquipment17;
	NPanel m_panelGoldEquipment18;
	NPanel m_panelGoldEquipment19;
	NPanel m_panelGoldEquipment20;

	NButton m_monster;
	NButton m_tabStatsButton;
	NButton m_tabScientistButton;
	NButton m_tabEquipmentButton;
	NButton m_arrowLeftButton;
	NButton m_arrowRightButton;
	NButton m_buttonEquipment1;
	NButton m_buttonEquipment2;
	NButton m_buttonEquipment3;
	NButton m_buttonEquipment4;
	NButton m_buttonEquipment5;
	NButton m_buttonEquipment6;
	NButton m_buttonEquipment7;
	NButton m_buttonEquipment8;
	NButton m_buttonEquipment9;
	NButton m_buttonEquipment10;
	NButton m_buttonEquipment11;
	NButton m_buttonEquipment12;
	NButton m_buttonEquipment13;
	NButton m_buttonEquipment14;
	NButton m_buttonEquipment15;
	NButton m_buttonEquipment16;
	NButton m_buttonEquipment17;
	NButton m_buttonEquipment18;
	NButton m_buttonEquipment19;
	NButton m_buttonEquipment20;
	NButton m_buyButtonJeanne;
	NButton m_buyButtonSerge;
	NButton m_closePopupButton;

	NLabel m_labelEquipment1;
	NLabel m_labelEquipment2;
	NLabel m_labelEquipment3;
	NLabel m_labelEquipment4;
	NLabel m_labelEquipment5;
	NLabel m_labelEquipment6;
	NLabel m_labelEquipment7;
	NLabel m_labelEquipment8;
	NLabel m_labelEquipment9;
	NLabel m_labelEquipment10;
	NLabel m_labelEquipment11;
	NLabel m_labelEquipment12;
	NLabel m_labelEquipment13;
	NLabel m_labelEquipment14;
	NLabel m_labelEquipment15;
	NLabel m_labelEquipment16;
	NLabel m_labelEquipment17;
	NLabel m_labelEquipment18;
	NLabel m_labelEquipment19;
	NLabel m_labelEquipment20;

	NLabel m_labelEquipment1Price;
	NLabel m_labelEquipment2Price;
	NLabel m_labelEquipment3Price;
	NLabel m_labelEquipment4Price;
	NLabel m_labelEquipment5Price;
	NLabel m_labelEquipment6Price;
	NLabel m_labelEquipment7Price;
	NLabel m_labelEquipment8Price;
	NLabel m_labelEquipment9Price;
	NLabel m_labelEquipment10Price;
	NLabel m_labelEquipment11Price;
	NLabel m_labelEquipment12Price;
	NLabel m_labelEquipment13Price;
	NLabel m_labelEquipment14Price;
	NLabel m_labelEquipment15Price;
	NLabel m_labelEquipment16Price;
	NLabel m_labelEquipment17Price;
	NLabel m_labelEquipment18Price;
	NLabel m_labelEquipment19Price;
	NLabel m_labelEquipment20Price;

	NLabel m_labelEquipment1Name;
	NLabel m_labelEquipment2Name;
	NLabel m_labelEquipment3Name;
	NLabel m_labelEquipment4Name;
	NLabel m_labelEquipment5Name;
	NLabel m_labelEquipment6Name;
	NLabel m_labelEquipment7Name;
	NLabel m_labelEquipment8Name;
	NLabel m_labelEquipment9Name;
	NLabel m_labelEquipment10Name;
	NLabel m_labelEquipment11Name;
	NLabel m_labelEquipment12Name;
	NLabel m_labelEquipment13Name;
	NLabel m_labelEquipment14Name;
	NLabel m_labelEquipment15Name;
	NLabel m_labelEquipment16Name;
	NLabel m_labelEquipment17Name;
	NLabel m_labelEquipment18Name;
	NLabel m_labelEquipment19Name;
	NLabel m_labelEquipment20Name;

	NPanel m_panelEquipment1Global;
	NPanel m_panelEquipment2Global;
	NPanel m_panelEquipment3Global;
	NPanel m_panelEquipment4Global;
	NPanel m_panelEquipment5Global;
	NPanel m_panelEquipment6Global;
	NPanel m_panelEquipment7Global;
	NPanel m_panelEquipment8Global;
	NPanel m_panelEquipment9Global;
	NPanel m_panelEquipment10Global;
	NPanel m_panelEquipment11Global;
	NPanel m_panelEquipment12Global;
	NPanel m_panelEquipment13Global;
	NPanel m_panelEquipment14Global;
	NPanel m_panelEquipment15Global;
	NPanel m_panelEquipment16Global;
	NPanel m_panelEquipment17Global;
	NPanel m_panelEquipment18Global;
	NPanel m_panelEquipment19Global;
	NPanel m_panelEquipment20Global;

    NPanel m_screen;
    NLabel m_labelBank;
    NPanel m_iconBank;
    NLabel m_labelClick;
    NPanel m_iconClick;
    NLabel m_labelMoney;
    NPanel m_iconMoney;
    NLabel m_labelReputation;
    NPanel m_iconReputation;
    NLabel m_labelResearch;
    NPanel m_iconResearch;
    NLabel m_labelTime;
    NPanel m_iconTime;
	NLabel m_labelSlash;
	NLabel m_labelMonsterYears;

    AnimatableObject m_loading;
    AnimatableObject m_bulle;
    AnimatableObject m_flamme1;
    AnimatableObject m_flamme2;
    AnimatableObject m_ordi;
	AnimatableObject m_coffeeSmoke;
	AnimatableObject m_clickAnimation1;
	AnimatableObject m_clickAnimation2;
	AnimatableObject m_clickAnimation3;
	AnimatableObject m_whiteBoardAnimation;
	AnimatableObject m_popupOnAnimation;
	AnimatableObject m_popupOffAnimation;
	AnimatableObject m_evolutionAnimation;

	int m_NbMonster;
    double m_timeElapsed;
	std::wstring txtFirstConnect;
	std::wstring txtFirstEvolution;
	std::wstring txtFirstCanReset;
	std::wstring txtFirstReset;
	std::wstring txtFirstReputation;
	std::wstring txtEndGame;


    bool m_bool;
	Labo* getLabo();

	std::string m_targetPanel;

	bool firstConnect;
	bool firstEvolution;
	bool firstCanReset;
	bool firstReset;
	bool firstReputation;
	bool endGame;

public:
    // Constructor
    LaboratoryRoom(bool debug, ManagerGroup *ptr_managerGroup);

    // Destructor
    ~LaboratoryRoom();

    // Methods
    //Cette méthode doit être présente dans chaque 'fenetre'
    virtual void update(sf::RenderWindow *window,
                        sf::Event *e, double frameTime);

    void undisplayAllTabs();

    void displayStatsPanel();

    void displayEquipmentPanel();

    void displayScientistPanel();

	void checkStateWhiteBoardAnimation();

	void checkStateClickAnimation();

	void checkStateEvolutionAnimation();

	void undisplayClickAnimation();

	void checkStatePopupOnAnimation();

	void checkStatePopupOffAnimation();

	void resetLabo();
};

#endif // DEF_LABORATORY_ROOM_HPP