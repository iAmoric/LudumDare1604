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

		NPanel m_monster;

		AnimatableObject m_loading;
		AnimatableObject m_bulle;
		AnimatableObject m_ordi;

	bool m_bool;


	public:
		// Constructor
		LaboratoryRoom(bool debug, ManagerGroup * ptr_managerGroup);

		// Destructor
		~LaboratoryRoom();

		// Methods
		//Cette méthode doit être présente dans chaque 'fenetre'
		virtual void update(sf::RenderWindow * window, 
							sf::Event * e, double frameTime);
		void displayAnimatableObject();
};

#endif // DEF_LABORATORY_ROOM_HPP