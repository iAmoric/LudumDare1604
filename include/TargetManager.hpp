/*!
 * \file TargetManager.hpp
 * \brief Handle target choice
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#ifndef DEF_TARGER_MANAGER_HPP
#define DEF_TARGER_MANAGER_HPP

#include "Manager.hpp"

class TargetManager : public Manager
{
	private:
		bool m_onLaboratoryRoom;
		bool m_onHomePage;


		// Method
		void handleTarget();
		
	public:
		// Constructor
		TargetManager(bool debug);

		// Destructor
		~TargetManager();

		// Method
		void exit();

		// Getters
		bool isExit();
		bool isLaboratoryRoom();
		bool isHomePage();


		// Setters
		void isOnLaboratoryRoom();
		void isOnHomePage();
};

#endif // DEF_TARGER_MANAGER_HPP