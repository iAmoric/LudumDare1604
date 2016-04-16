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

//LoginMenu hérite de BasicInterface
class LaboratoryRoom : public BasicInterface
{
	private:
		NPanel m_background;
		NPanel m_equipment1;
		NPanel m_equipment2;
		NPanel m_equipment3;
		NPanel m_equipment4;
		NPanel m_equipment5;
		NPanel m_equipment6;
		NPanel m_equipment7;
		NPanel m_equipment8;
		NPanel m_equipment9;
		NPanel m_equipment10;
		NPanel m_equipment11;
		NPanel m_equipment12;
		NPanel m_equipment13;
		NPanel m_equipment14;
		NPanel m_equipment15;
		NPanel m_equipment16;
		NPanel m_equipment17;
		NPanel m_equipment18;
		NPanel m_equipment19;
		NPanel m_equipment20;
		NPanel m_tabScientistPanel;
		NPanel m_tabEquipmentPanel;
		NPanel m_tabStatsPanel;
		NPanel m_subTabEquipmentPanel1;
		NPanel m_subTabEquipmentPanel2;

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


    NPanel m_screen;
    NPanel m_iconBank;
    NPanel m_iconClick;
    NPanel m_iconMoney;
    NPanel m_iconReputation;
    NPanel m_iconResearch;
    NPanel m_iconTime;

    AnimatableObject m_loading;
    AnimatableObject m_bulle;
    AnimatableObject m_flamme1;
    AnimatableObject m_flamme2;
    AnimatableObject m_ordi;

	AnimatableObject m_coffeeSmoke;

    double m_timeElapsed;

    bool m_bool;


public:
    // Constructor
    LaboratoryRoom(bool debug, ManagerGroup *ptr_managerGroup);

    // Destructor
    ~LaboratoryRoom();

		// Methods
		//Cette méthode doit être présente dans chaque 'fenetre'
		virtual void update(sf::RenderWindow * window, 
							sf::Event * e, double frameTime);
		void undisplayAllTabs();
		void displayStatsPanel();
		void displayEquipmentPanel();
		void displayScientistPanel();
};

#endif // DEF_LABORATORY_ROOM_HPP