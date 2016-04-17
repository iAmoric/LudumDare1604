/*!
 * \file resourceLoader.cpp
 * \brief Load all resources in a thread
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#include "ResourceLoader.hpp"

/*!
 * \brief Constructor
 * \param debug the debug mode
 */
ResourceLoader::ResourceLoader(bool debug) : m_managerGroup(),
                                             m_thread(&ResourceLoader::load, this) {
    m_debug = debug;


    //Instancie les différents manager
    m_managerGroup.ptr_musicManager = new MusicManager(m_debug); //The default volume
    m_managerGroup.ptr_textureManager = new TextureManager(m_debug);
    m_managerGroup.ptr_targetManager = new TargetManager(m_debug);
    m_managerGroup.ptr_optionManager = new OptionManager(m_debug);
    m_managerGroup.ptr_gameManager = new GameManager(m_debug);

    m_managerGroup.ptr_musicManager->setState(false);
    m_managerGroup.ptr_textureManager->setState(false);
    m_managerGroup.ptr_targetManager->setState(false);
    m_managerGroup.ptr_optionManager->setState(false);
    m_managerGroup.ptr_gameManager->setState(false);
}

/*!
 * \brief Destructor
 */
ResourceLoader::~ResourceLoader() {
    // None
}

/*!
 * \brief Load all ressource in a thread
 * \brief to not lock the main thread
 */
void ResourceLoader::load() {
    // Aliases
	MusicManager& a_mm = *m_managerGroup.ptr_musicManager;
	TextureManager& a_tm = *m_managerGroup.ptr_textureManager;
	TargetManager& a_tarm = *m_managerGroup.ptr_targetManager;
	OptionManager& a_optm = *m_managerGroup.ptr_optionManager;
    GameManager& a_gm = *m_managerGroup.ptr_gameManager;


	/* Path */
	const std::string pathLogin = "../res/texture/menu/login/";
	const std::string pathAnimation = "../res/animation/";
	const std::string pathView = "../res/vues/";
	const std::string pathSprite = "../res/sprites/";
	const std::string pathMonster = "../res/monstres/";
	const std::string pathEquipment = "../res/equipment/";
	const std::string pathButton = "../res/buttons/";
	const std::string pathCharacter ="../res/buttons/";
    const std::string pathComputer ="../res/sprites/ordi/";

	/* Buttons */
	a_tm.addTexture("close_1", pathButton + "close.png");
	a_tm.addTexture("close_2", pathButton + "closePress.png");
	a_tm.addTexture("tabStatsButton", pathButton + "tabStatsButton.png");
	a_tm.addTexture("tabScientistButton", pathButton + "tabScientistButton.png");
	a_tm.addTexture("tabEquipmentButton", pathButton + "tabEquipmentButton.png");
	a_tm.addTexture("playButton", pathButton + "arrowIsSelected.png");
	a_tm.addTexture("playButtonPress", pathButton + "arrowIsNotSelected.png");
	a_tm.addTexture("helpButton", pathButton + "helpButton.png");
	a_tm.addTexture("helpButtonPress", pathButton + "helpButtonPress.png");

    /* Computer */
	a_tm.addTexture("HomePagebackground", pathView + "HomePagebackground.png");
    a_tm.addTexture("background", pathView + "background.png");
    a_tm.addTexture("screen", pathComputer + "screen.png");
    a_tm.addTexture("bank-icon", pathComputer + "bank-icon.png");
    a_tm.addTexture("click-icon", pathComputer + "click-icon.png");
    a_tm.addTexture("money-icon", pathComputer + "money-icon.png");
    a_tm.addTexture("reputation-icon", pathComputer + "reputation-icon.jpg");
    a_tm.addTexture("research-icon", pathComputer + "research-icon.png");
    a_tm.addTexture("time-icon", pathComputer + "time-icon.png");

	/* background */
	a_tm.addTexture("background", pathView + "background.png");

	/* Equipments to buy */
	a_tm.addTexture("equipment1", pathEquipment + "1test_tube.png");
	a_tm.addTexture("equipment2", pathEquipment + "2test_tubes.png"); // à mettre à la place du 1
	a_tm.addTexture("equipment3", pathEquipment + "coffee.png");
	a_tm.addTexture("equipment4", pathEquipment + "3test_tubes.png"); // à mettre à la place du 2
	a_tm.addTexture("equipment5", pathEquipment + "4test_tubes.png"); // à mettre à la place du 4
	a_tm.addTexture("equipment6", pathEquipment + "purple_balloon.png");
	a_tm.addTexture("equipment7", pathEquipment + "heanting_mantle.png"); // à mettre à la place du 6
	a_tm.addTexture("equipment8", pathEquipment + "1flask.png");
	a_tm.addTexture("equipment9", pathEquipment + "2flasks.png"); // à mettre à la place du 8
	a_tm.addTexture("equipment10", pathEquipment + "cool_mantle_balloon.png");
	a_tm.addTexture("equipment11", pathEquipment + "pink_flask.png");
	a_tm.addTexture("equipment12", pathEquipment + "heanting_mantle_balloon.png"); // à mettre à la place du 10
	a_tm.addTexture("equipment13", pathEquipment + "5test_tubes.png"); // à mettre à la place du 5
	a_tm.addTexture("equipment14", pathEquipment + "6test_tubes.png"); // à mettre à la place du 13
	a_tm.addTexture("equipment15", pathEquipment + "7test_tubes.png"); // à mettre à la place du 14
	a_tm.addTexture("equipment16", pathEquipment + "8test_tubes.png"); // à mettre à la place du 15
	a_tm.addTexture("equipment17", pathEquipment + "pink_burette.png");
	a_tm.addTexture("equipment18", pathEquipment + "medal.png");
	a_tm.addTexture("equipment19", pathEquipment + "microscope.png");
	a_tm.addTexture("equipment20", pathEquipment + "beer.png"); // à mettre à la place du 3

	/* Color Buttons */
	a_tm.addTexture("button1", pathButton + "yellow_button.png");
	a_tm.addTexture("button1Press", pathButton + "yellow_button_assombri.png");
	a_tm.addTexture("button2", pathButton + "orange_button.png");
	a_tm.addTexture("button2Press", pathButton + "orange_button_assombri.png");
	a_tm.addTexture("button3", pathButton + "red_button.png");
	a_tm.addTexture("button3Press", pathButton + "red_button_assombri.png");
	a_tm.addTexture("button4", pathButton + "purple_button.png");
	a_tm.addTexture("button4Press", pathButton + "purple_button_assombri.png");
	a_tm.addTexture("button5", pathButton + "blue_button.png");
	a_tm.addTexture("button5Press", pathButton + "blue_button_assombri.png");
	a_tm.addTexture("button6", pathButton + "lightGreen_button.png");
	a_tm.addTexture("button6Press", pathButton + "lightGreen_button_assombri.png");
	a_tm.addTexture("button7", pathButton + "darkGreen_button.png");
	a_tm.addTexture("button7Press", pathButton + "darkGreen_button_assombri.png");
	a_tm.addTexture("button8", pathButton + "black_button.png");
	a_tm.addTexture("button8Press", pathButton + "black_button_assombri.png");

	a_tm.addTexture("arrowLeftPress", pathButton + "arrowLeftPress.png");
	a_tm.addTexture("arrowLeft", pathButton + "arrowLeft.png");
	a_tm.addTexture("arrowRightPress", pathButton + "arrowRightPress.png");
	a_tm.addTexture("arrowRight", pathButton + "arrowRight.png");

	a_tm.addTexture("sergePanel", pathButton + "sergeButton.png");
	a_tm.addTexture("jeannePanel", pathButton + "jeanneButton.png");

	/* Monster */
	//Cellule
	a_tm.addTexture("monster_1", pathMonster + "cellule/cellule_1.png");
	a_tm.addTexture("monster_2", pathMonster + "cellule/cellule_2.png");
	a_tm.addTexture("monster_3", pathMonster + "cellule/cellule_3.png");
	a_tm.addTexture("monster_4", pathMonster + "cellule/cellule_4.png");
	a_tm.addTexture("monster_5", pathMonster + "cellule/cellule_5.png");
	//Eau
	a_tm.addTexture("monster_6", pathMonster + "eau/eau_1.png");
	a_tm.addTexture("monster_7", pathMonster + "eau/eau_2.png");
	a_tm.addTexture("monster_8", pathMonster + "eau/eau_3.png");
	a_tm.addTexture("monster_9", pathMonster + "eau/eau_4.png");
	a_tm.addTexture("monster_10", pathMonster + "eau/eau_5.png");
	//Terre
	a_tm.addTexture("monster_11", pathMonster + "terre/terre_1.png");
	a_tm.addTexture("monster_12", pathMonster + "terre/terre_2.png");
	a_tm.addTexture("monster_13", pathMonster + "terre/terre_3.png");
	a_tm.addTexture("monster_14", pathMonster + "terre/terre_4.png");
	a_tm.addTexture("monster_15", pathMonster + "terre/terre_5.png");
	//Air
	a_tm.addTexture("monster_16", pathMonster + "air/air_1.png");
	a_tm.addTexture("monster_17", pathMonster + "air/air_2.png");
	a_tm.addTexture("monster_18", pathMonster + "air/air_3.png");
	a_tm.addTexture("monster_19", pathMonster + "air/air_4.png");
	a_tm.addTexture("monster_20", pathMonster + "air/air_5.png");
	//Espace
	a_tm.addTexture("monster_21", pathMonster + "espace/espace_1.png");
	a_tm.addTexture("monster_22", pathMonster + "espace/espace_2.png");
	a_tm.addTexture("monster_23", pathMonster + "espace/espace_3.png");
	a_tm.addTexture("monster_24", pathMonster + "espace/espace_4.png");
	a_tm.addTexture("monster_25", pathMonster + "espace/espace_5.png");

	a_tm.addTexture("background", pathView + "background.png");

	/* animation */
	a_tm.addTexture("loading", pathAnimation + "loading.png");
	a_tm.addTexture("bulle", pathAnimation + "sprite_bulle.png");
	a_tm.addTexture("flamme1", pathAnimation + "animationFlamme_test.png");
	a_tm.addTexture("flamme2", pathAnimation + "animationFlamme_test.png");
	a_tm.addTexture("ordi", pathAnimation + "sprite_ordi.png");
	a_tm.addTexture("coffeeSmoke", pathAnimation + "sprite_coffeeSmook.png");
	a_tm.addTexture("animatedPlay", pathAnimation + "animatedPlay.png");
	a_tm.addTexture("searchBar", pathAnimation + "searchBar.png");
	a_tm.addTexture("searchBarLoop", pathAnimation + "searchBarLoop.png");
	a_tm.addTexture("clickAnimation1", pathAnimation + "clickAnimation1.png");
	a_tm.addTexture("clickAnimation2", pathAnimation + "clickAnimation2.png");
	a_tm.addTexture("clickAnimation3", pathAnimation + "clickAnimation3.png");

	/* Mouse */
	a_tm.addTexture("mouse", pathSprite + "mouse_pointer.png");

	/* Money Gold */
	a_tm.addTexture("gold", pathEquipment + "gold.png");

	a_mm.setState(true);
	a_tm.setState(true);
	a_tarm.setState(true);
	a_optm.setState(true);
    a_gm.setState(true);


    if (m_debug) {
        std::cout << "- Texture Manager successfully loaded" << std::endl;
        std::cout << "- Target Manager successfully loaded" << std::endl;
        std::cout << "- Option Manager successfully loaded" << std::endl;
        std::cout << "- Game Manager successfully loaded" << std::endl;
    }
}

/*!
 * \brief Launch the loading thread
 */
void ResourceLoader::start() {
    m_thread.launch();
}

/*!
 * \brief Stop the loading thead
 * \deprecated Please do not use this function
 */
void ResourceLoader::stop() {
    m_thread.terminate();
}

/*!
 * \brief Check if the load is up
 * \return True if all resources are loaded
 */
bool ResourceLoader::getLoadState() {
    return (
            m_managerGroup.ptr_musicManager->getState() &&
            m_managerGroup.ptr_textureManager->getState() &&
            m_managerGroup.ptr_targetManager->getState() &&
            m_managerGroup.ptr_optionManager->getState() &&
            m_managerGroup.ptr_gameManager->getState());
}

/*!
 * \brief Return all loaded resources
 * \return m_manager a pointer on all managers
 */
ManagerGroup *ResourceLoader::getManager() {
    return &m_managerGroup;
}