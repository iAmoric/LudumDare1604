/*!
 * \file LoginMenu.cpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "LoginMenu.hpp"

/*!
 * \brief Constructor
 */
//Login menu hérite de BasicInterface
LoginMenu::LoginMenu(bool debug, ManagerGroup *ptr_managerGroup) :
        BasicInterface(debug, ptr_managerGroup) {

    //Création de la musique pour la 'fenetre'
    ptr_managerGroup->ptr_musicManager->
            createPlaylist("playlistMenu", true, 1.2);
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->play();

    //Chargement des polices d'écritures
    if (!m_fontLabel.loadFromFile("../res/font/Quicksand.ttf") ||
        !m_fontTextbox.loadFromFile("../res/font/LucidaTypewriterRegular.ttf")) {
        std::cerr << "Probleme dans le chargement des fonts" << std::endl;
    }

    //Création des éléments
    //Chaque élement possède un ID, une position x, y
    //D'autres paramètres peuvent se rajouter suivant le type d'élement
    //Se référer aux hpp pour connaitres les paramètres nécessaires
    //Il n'y a pas de position relative, tout est absolu

    //Bouton
    //Possède un id, une position et deux texture : une normal et une au clic
    m_connectButton.create("connectButton", 442, 570,
                           ptr_managerGroup->ptr_textureManager->getTexture("connectButton1"),
                           ptr_managerGroup->ptr_textureManager->getTexture("connectButton2"));

    //Panel
    //C'est en gros une image fixe. On peut 'ajouter' d'autres composant au panel
    //Et donc par exemple si le panel est caché les autres composant contenu dedans
    //seront aussi cachés
    //Possède un ID, une position et une texture
    m_bibouPanel.create("bibouPanel", 0, 400,
                        ptr_managerGroup->ptr_textureManager->getTexture("bibouPanel"));

    //Un champ de texte
    //Possède un ID, une position, une texture 'cadre', une texture pour le curseur,
    //une police d'écriture (régulière), une taille de police, le délais de clignotement du curseur,
    //un texte écrit par défaut, le nombre max de caractère qu'il est possible d'écrire, et une
    //couleur de police
    m_textFieldLogin.create("textFieldLogin", 412, 500,
                            ptr_managerGroup->ptr_textureManager->getTexture("textBox"),
                            ptr_managerGroup->ptr_textureManager->getTexture("textBoxCursor"),
                            &m_fontTextbox,
                            15, 0.5, "Votre pseudo", 15, sf::Color(196, 130, 56));

    //Un autre panel
    m_paperSwordTitlePanel.create("paperSwordTitlePanel", 309, 50,
                                  ptr_managerGroup->ptr_textureManager->getTexture("paperSwordTitlePanel"));


    //Ajout des éléments à la fenetre
    //Un élément NPanel peut lui même contenir des éléments
    getContentPane()->addComponent(&m_bibouPanel);
    getContentPane()->addComponent(&m_paperSwordTitlePanel);
    getContentPane()->addComponent(&m_textFieldLogin);
    getContentPane()->addComponent(&m_connectButton);
}

/*!
 * \brief Constructor
 */
LoginMenu::~LoginMenu() {
    // TODO
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
//Méthode appellé à chaque tour de boucle, elle gère les évènements
void LoginMenu::update(sf::RenderWindow *window,
                       sf::Event *e, double frameTime) {

    //Si on est pas sur la fenetre, on return
    if (!m_ptr_managerGroup->ptr_targetManager->isLoginMenu())
        return;

    // Basic Interface updating
    basicInput(e, frameTime);

    //Si on clique sur le bouton qui a l'ID "connectButton"
    if (m_inputHandler.getComponentId() == "connectButton") {
        if (m_debug)
            std::cout << "CLIC ! " << std::endl;
        displayAnimation();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        if (m_debug)
            std::cout << "Entree ! " << std::endl;
    }


    // Drawing all content
    basicDraw(window);
}




