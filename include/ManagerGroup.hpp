/*!
 * \file ManagerGroup.hpp
 * \brief Store all managers
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#ifndef DEF_MANAGER_GROUP_HPP
#define DEF_MANAGER_GROUP_HPP

#include "MusicManager.hpp"
#include "OptionManager.hpp"
#include "TargetManager.hpp"
#include "TextureManager.hpp"
#include "GameManager.hpp"

class ManagerGroup
{
	public:
		// Constructor
		ManagerGroup();

		// Destructor
		~ManagerGroup();

		// Token
		GameManager * ptr_gameManager;
		MusicManager * ptr_musicManager;
		TextureManager * ptr_textureManager;
		TargetManager * ptr_targetManager;
		OptionManager * ptr_optionManager;
};

#endif // DEF_MANAGER_GROUP_HPP