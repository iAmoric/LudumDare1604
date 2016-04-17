/*!
 * \file TargetManager.cpp
 * \brief Handle target choice
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#include "TargetManager.hpp"

/*!
 * \brief Constructor
 */
TargetManager::TargetManager(bool debug) : Manager() {
	m_debug = debug;

	m_onLaboratoryRoom = false;
	m_onHomePage = false;

}

/*!
 * \brief Destructor
 */
TargetManager::~TargetManager() {
	// None
}

/*!
 * \brief Set all targets to false
 */
void TargetManager::exit() {
	handleTarget();
}

/*!
 * \brief Set all target to false
 */
void TargetManager::handleTarget() {
	m_onLaboratoryRoom = false;
	m_onHomePage = false;
}

/*!
 * \return true if all target are on false
 */
bool TargetManager::isExit() {
	return (m_onLaboratoryRoom || m_onHomePage);
}

/*!
 * \return m_onLoginMenu target state
 */
bool TargetManager::isHomePage(){
	return m_onHomePage;
}

/*!
 * \return m_onLobby target state
 */
bool TargetManager::isLaboratoryRoom(){
	return m_onLaboratoryRoom;
}


/*!
 * \set m_onLobby target state to true
 */
void TargetManager::isOnLaboratoryRoom(){
	handleTarget();
	m_onLaboratoryRoom = true;
}



/*!
 * \return m_onLoginMenu target state
 */
void TargetManager::isOnHomePage(){
	handleTarget();
	m_onHomePage = true;
}