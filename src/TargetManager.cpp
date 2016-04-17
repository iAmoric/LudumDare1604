/*!
 * \file TargetManager.cpp
 * \brief Handle target choice
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#include "TargetManager.hpp"


TargetManager::TargetManager(bool debug) : Manager() {
	m_debug = debug;

	m_onLaboratoryRoom = false;
	m_onHomePage = false;

}

TargetManager::~TargetManager() {
	// None
}


void TargetManager::exit() {
	handleTarget();
}


void TargetManager::handleTarget() {
	m_onLaboratoryRoom = false;
	m_onHomePage = false;
}

bool TargetManager::isExit() {
	return (m_onLaboratoryRoom || m_onHomePage);
}

bool TargetManager::isHomePage(){
	return m_onHomePage;
}

bool TargetManager::isLaboratoryRoom(){
	return m_onLaboratoryRoom;
}

void TargetManager::isOnLaboratoryRoom(){
	handleTarget();
	m_onLaboratoryRoom = true;
}

void TargetManager::isOnHomePage(){
	handleTarget();
	m_onHomePage = true;
}