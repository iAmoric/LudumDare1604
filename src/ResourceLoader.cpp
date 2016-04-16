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


	// Path
	const std::string pathLogin = "../res/texture/menu/login/";
	const std::string pathAnimation = "../res/animation/";

	// Loading ...
	//Les textures sont chargés en mémoire ici
	//On peut y accéder grace à leur ID (1er parametres)
	a_tm.addTexture("topBarLogMenu", pathLogin + "topBarLogMenu.png");
	a_tm.addTexture("topBarOptButton_1", pathLogin + "topBarOptionButton_1.png");
	a_tm.addTexture("topBarOptButton_2", pathLogin + "topBarOptionButton_2.png");

	a_tm.addTexture("topBarOptButton_3", pathLogin + "topBarOptionButton_1.png");
	a_tm.addTexture("topBarOptButton_4", pathLogin + "topBarOptionButton_2.png");
	a_tm.addTexture("exitPanel", pathLogin + "exitPanel.png");

	a_tm.addTexture("topBarExitButton_1", pathLogin + "topBarExitButton_1.png");
	a_tm.addTexture("topBarExitButton_2", pathLogin + "topBarExitButton_2.png");
	a_tm.addTexture("loginBackground", pathLogin + "background.png");
	a_tm.addTexture("optionPane", pathLogin + "optionPane.png");
	a_tm.addTexture("optionPanel", pathLogin + "optionPanel.png");
	a_tm.addTexture("simplePanel", pathLogin + "simplePanel.png");
	a_tm.addTexture("connectButton1", pathLogin + "connect_1.png");
	a_tm.addTexture("connectButton2", pathLogin + "connect_2.png");
	a_tm.addTexture("volume_1", pathLogin + "volume_1.png");
	a_tm.addTexture("volume_2", pathLogin + "volume_2.png");
	a_tm.addTexture("volumeOff_1", pathLogin + "volumeOff_1.png");
	a_tm.addTexture("volumeOff_2", pathLogin + "volumeOff_2.png");
	a_tm.addTexture("textBox", pathLogin + "textBox.png");
    a_tm.addTexture("textBoxCursor", pathLogin + "curseurTextBox.png");
	a_tm.addTexture("nemesis", pathLogin + "background_login.png");
	a_tm.addTexture("errorPanel", pathLogin + "ErrorPanel.png");
	a_tm.addTexture("bibouPanel", pathLogin + "bibouPanel.png");
	a_tm.addTexture("paperSwordTitlePanel", pathLogin + "paperSwordTitleFull.png");
	a_tm.addTexture("logoSmall", pathLogin + "paperSwordTitleSmall.png");

	/* Equipments to buy */
	a_tm.addTexture("equipment1", pathLogin + "1test_tube.png"); //
	a_tm.addTexture("equipment2", pathLogin + "2test_tubes.png"); // à mettre à la place du 1
	a_tm.addTexture("equipment3", pathLogin + "coffee.png"); //
	a_tm.addTexture("equipment4", pathLogin + "3test_tubes.png"); // à mettre à la place du 2
	a_tm.addTexture("equipment5", pathLogin + "4test_tubes.png"); // à mettre à la place du 4
	a_tm.addTexture("equipment6", pathLogin + "purple_balloon.png"); //
	a_tm.addTexture("equipment7", pathLogin + "heanting_mantle.png"); // à mettre à la place du 6
	a_tm.addTexture("equipment8", pathLogin + "1flask.png"); //
	a_tm.addTexture("equipment9", pathLogin + "2flasks.png"); // à mettre à la place du 8
	a_tm.addTexture("equipment10", pathLogin + "cool_mantle_balloon.png");//
	a_tm.addTexture("equipment11", pathLogin + "pink_flask.png"); //
	a_tm.addTexture("equipment12", pathLogin + "heanting_mantle_balloon.png.png"); // à mettre à la place du 10
	a_tm.addTexture("equipment13", pathLogin + "5test_tube.png"); // à mettre à la place du 5
	a_tm.addTexture("equipment14", pathLogin + "6test_tube.png"); // à mettre à la place du 13
	a_tm.addTexture("equipment15", pathLogin + "7test_tube.png"); // à mettre à la place du 14
	a_tm.addTexture("equipment16", pathLogin + "8test_tube.png"); // à mettre à la place du 15
	a_tm.addTexture("equipment17", pathLogin + "1test_tube.png");
	a_tm.addTexture("equipment18", pathLogin + "1test_tube.png");
	a_tm.addTexture("equipment19", pathLogin + "microscope.png"); //
	a_tm.addTexture("equipment20", pathLogin + "1test_tube.png");

	a_tm.addTexture("loading", pathAnimation + "loading.png");


	a_mm.setState(true);
	a_tm.setState(true);
	a_tarm.setState(true);
	a_optm.setState(true);
    a_gm.setState(true);


	if(m_debug) {
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
ManagerGroup * ResourceLoader::getManager() {
	return &m_managerGroup;
}