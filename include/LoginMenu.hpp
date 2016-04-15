/*!
 * \file LoginMenu.hpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_LOGING_MENU_HPP
#define DEF_LOGING_MENU_HPP

#include "BasicInterface.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

//LoginMenu hérite de BasicInterface
class LoginMenu : public BasicInterface
{
	private:
		NButton m_connectButton;
		NLabel m_titleLabel;
		NTextField m_textFieldLogin;
		NPanel m_nemesisLogo;
		NPanel m_bibouPanel;
		NPanel m_paperSwordTitlePanel;

		sf::Font m_fontLabel;
        sf::Font m_fontTextbox;
		AnimatableObject m_loading;

		bool m_bool;


	public:
		// Constructor
		LoginMenu(bool debug, ManagerGroup * ptr_managerGroup);

		// Destructor
		~LoginMenu();

		// Methods
		//Cette méthode doit être présente dans chaque 'fenetre'
		virtual void update(sf::RenderWindow * window, 
							sf::Event * e, double frameTime);
		void displayAnimatableObject();
};

#endif // DEF_LOGING_MENU_HPP