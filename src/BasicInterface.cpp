/*!
 * \file BasicInterface.cpp
 * \brief Super class for interface
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "BasicInterface.hpp"

/*!
 * \brief Constructor
 * \param ptr_managerGroup
 */
BasicInterface::BasicInterface(bool debug,
							   ManagerGroup * ptr_managerGroup) : Updatable(),
																  m_inputHandler(debug)

{
	m_bool = false;
	m_debug = debug;
	m_optionActive = false;
	m_exitActive = false;
	m_ptr_managerGroup = ptr_managerGroup;

	// Setting up aliases
	TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;

	if (!m_fontLabel.loadFromFile("../res/font/Roboto-Regular.ttf"))
	{
		std::cout << "Probleme dans le chargement des textures" << std::endl;
	}

	m_smallTitleLogo.create("smallTitleLogo", 15, 5,
							 a_tm.getTexture("logoSmall"));
	// Creating m_contentPane
	m_contentPane.create("mainPanel", 0, 0,
						 a_tm.getTexture("loginBackground"));

	// Adding buttons
	m_optButton.create("optButton", 780, 5,
					   a_tm.getTexture("topBarOptButton_1"),
					   a_tm.getTexture("topBarOptButton_2"));

	m_musicButton.create("volumeButton", 905,92,
						 a_tm.getTexture("volume_1"),
						 a_tm.getTexture("volume_2"));

	m_soundButton.create("soundButton", 905,167,
						 a_tm.getTexture("volume_1"),
						 a_tm.getTexture("volume_2"));


	m_exitButton.create("exitButton", 900, 5,
						a_tm.getTexture("topBarExitButton_1"),
						a_tm.getTexture("topBarExitButton_2"));

	//Adding labels
	m_volumeLabel.create("volumeLabel", 730, 100, 16, &m_fontLabel,
						 L"Volume de la musique",
						 sf::Color::White);

	m_soundLabel.create("soundLabel", 730, 175, 16, &m_fontLabel,
						 L"Volume des effets",
						 sf::Color::White);

	//m_titleLabel.create("monSuperLabel", 10, 10, 20, &m_fontLabel,
	//					L"Paper Sword : Online",
	//					sf::Color(232,200,20));

	m_errorPanel.create("ErrorPanel", 332, 685,
						ptr_managerGroup->ptr_textureManager->getTexture("errorPanel"));

	m_connectionErrorLabel.create("connectionErrorLabel", 410, 705, 12, &m_fontLabel,
								  L"Un problème de connexion est survenue.\n"
										  "  Vérifiez votre connnexion et réessayez.",
								  sf::Color::White);


	m_loading.create("loading", 487, 700,
					 ptr_managerGroup->ptr_textureManager->getTexture("loading"), true, 0.1, 49, 49, 8);
	m_loading.setVisible(false);


	// Creating optionPanel
	m_optionPanel.create("optionPanel", 710, 55,
						 a_tm.getTexture("optionPanel"));



	m_errorPanel.addComponent(&m_connectionErrorLabel);
	m_errorPanel.setVisible(false);
	//getContentPane()->addComponent(&m_exitPanel);
	getContentPane()->addComponent(&m_errorPanel);
	getContentPane()->addComponent(&m_smallTitleLogo);
    getContentPane()->addComponent(&m_titleLabel);
	getContentPane()->addComponent(&m_loading);
	m_optionPanel.addComponent(&m_volumeLabel);
	m_optionPanel.addComponent(&m_soundLabel);
	m_optionPanel.addComponent(&m_musicButton);
	m_optionPanel.addComponent(&m_soundButton);

	m_topBar.addComponent(&m_optButton);
	m_topBar.addComponent(&m_exitButton);

	m_interface.push_back(&m_contentPane);
	m_interface.push_back(&m_topBar);
}

/*!
 * \brief Destructor
 */
BasicInterface::~BasicInterface() {
	// None
}

/*!
 * Call an error connection on the error panel
 */
void BasicInterface::errorConnection() {
	m_connectionErrorLabel.setText(L"Un problème de connexion est survenu.\n"
										   "  Vérifiez votre connnexion et réessayez.");
	m_errorPanel.setVisible(true);
}

/*!
 * Call an error pseudo on the error panel
 */
void BasicInterface::errorPseudo(){
	m_connectionErrorLabel.setText(L"  Vous n'avez pas saisi votre pseudo.\n"
										   "Saisissez votre pseudo et réessayez.");
	m_errorPanel.setVisible(true);
}

void BasicInterface::errorGoInGame(){
	m_connectionErrorLabel.setText(L"  Une erreur s'est produite.\n"
										   "Vous ne pouvez pas rejoindre le jeu.");
	m_errorPanel.setVisible(true);
}

void BasicInterface::errorCharacterSelection(){
	m_connectionErrorLabel.setText(L"  Une erreur s'est produite.\n"
										   "Vous ne pouvez pas choisir ce personnage.");
	m_errorPanel.setVisible(true);
}

/*!
 * Call an error warmup is full on the error panel
 */
void BasicInterface::errorWarmUpFull(){
	m_connectionErrorLabel.setText(L"  Impossible de rejoindre le WarmUp.\n"
										   "  Il est sûrement complet.");
	m_errorPanel.setVisible(true);
}


void BasicInterface::displayAnimation(){
	if (m_bool){
		if(m_debug)
			std::cout << "Animation Off!" << std::endl;
		m_bool = false;
		m_loading.setVisible(false);
	}
	else{
		if (m_debug)
			std::cout << "Animation On!" << std::endl;
		m_bool = true;
		m_loading.setVisible(true);
	}
}

void BasicInterface::waitingPlayers(){
	m_connectionErrorLabel.setText(L"        En attente des autres joueurs...");
	m_errorPanel.setVisible(true);
}


void BasicInterface::noError(){
	m_errorPanel.setVisible(false);
	m_errorPanel.setVisible(false);
}

void BasicInterface::setBackground(sf::Texture * backgroundImg){
	m_contentPane.create("mainPanel", 0, 0,
						 backgroundImg);
}

/*!
 * \brief Draw all object on the window
 * \param window The surface to draw
 * \param visualObjectList The list of object to draw
 */
void BasicInterface::basicDraw(sf::RenderWindow * window) {

	// Polymorphisme !
	for(unsigned int i = 0; i < m_interface.size(); i++)
		m_interface[i]->draw(window);
}

/*!
 * \brief Update all component
 * \param frameTime Time elapsed since last frame
 */
void BasicInterface::updateInterface(double frameTime) {

	// Polymorphisme !
	for(unsigned int i = 0; i < m_interface.size(); i++)
		m_interface[i]->update(frameTime);
}

/*!
 * \brief Handle inputs of the basics interface
 * \param e The current event to handle
 * \param frameTime TimeElapsed since last iteration
 */
void BasicInterface::basicInput(sf::Event * e, double frameTime) {

	// Updating components
	updateInterface(frameTime);

	// Check for interface event
	// Check for contentPane event
	// m_inputHandler.handleInput(e, &m_contentPane);

	// Check for topBar event
	m_inputHandler.handleInput(e, &m_topBar, false);

	if(m_inputHandler.getComponentId() != "NULL") {

		// Exiting game !
		if(m_inputHandler.getComponentId() == "exitButton") {

			m_ptr_managerGroup->ptr_targetManager->exit();

		}
			// Option menu
		else if(m_inputHandler.getComponentId() == "optButton") {
			if(!m_optionActive)
			{
				m_optionActive = true;
				m_interface.push_back(&m_optionPanel);
			}
			else
			{
				m_optionActive = false;
				m_interface.pop_back();
			}
		}
	}

	// Check for optionPane event
	if(m_optionActive) {
		m_inputHandler.handleInput(e, &m_optionPanel, false);

		if(m_inputHandler.getComponentId() != "NULL") {
			if(m_inputHandler.getComponentId() == "volumeButton")
			{
				TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;

				if(m_ptr_managerGroup->ptr_musicManager->getMusicVolume()>0)
				{
					m_ptr_managerGroup->ptr_musicManager->setMusicVolume(0);
					m_musicButton.setSprite(a_tm.getTexture("volumeOff_1"),
											a_tm.getTexture("volumeOff_2"));

					std::cout << "Music volume : On" << std::endl;
				}
				else
				{
					m_ptr_managerGroup->ptr_musicManager->setMusicVolume(50);
					m_musicButton.setSprite(a_tm.getTexture("volume_1"),
											a_tm.getTexture("volume_2"));

					std::cout << "Music volume : Off" << std::endl;
				}


			}
			else if(m_inputHandler.getComponentId() == "soundButton"){

				TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;


				if(m_ptr_managerGroup->ptr_musicManager->getSoundVolume()>0)
				{
					m_ptr_managerGroup->ptr_musicManager->setSoundVolume(0);
					m_soundButton.setSprite(a_tm.getTexture("volumeOff_1"),
											a_tm.getTexture("volumeOff_2"));

					std::cout << "Sound volume : On" << std::endl;
				}
				else
				{
					m_ptr_managerGroup->ptr_musicManager->setSoundVolume(50);
					m_soundButton.setSprite(a_tm.getTexture("volume_1"),
											a_tm.getTexture("volume_2"));

					std::cout << "Sound volume : Off" << std::endl;
				}

			}
		}
	}


	//Check for contentPane Event
	m_inputHandler.handleInput(e, &m_contentPane, true);
}

/*!
 * \brief Allow the acces on the main panel
 * \return m_contentPane The reference on the main panel
 */
NPanel * BasicInterface::getContentPane() {
	return &m_contentPane;
}

/*!
 * \brief Allow the acces on the top bar
 * \return m_topBar The reference on the top bar
 */
NPanel * BasicInterface::getTopBar() {
	return &m_topBar;
}

/*!
 * \brief Replace the current main panel
 * \param pane The pointeur on the panel
 * \return None
 */
void BasicInterface::setContentPane(NPanel * pane) {
	m_contentPane = *pane;
}