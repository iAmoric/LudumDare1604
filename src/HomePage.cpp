//
// Created by Lucas on 16/04/2016.
//

#include "HomePage.hpp"


HomePage::HomePage(bool debug, ManagerGroup *ptr_managerGroup) :
        BasicInterface(debug, ptr_managerGroup) {


    m_contentPane.setSprite(ptr_managerGroup->ptr_textureManager->getTexture("HomePagebackground"));


    m_animatedPlay.create("animatedPlay", 282, 180,
                          ptr_managerGroup->ptr_textureManager->getTexture("animatedPlay"),
                          true, 0.05,170, 170, 8);
    getContentPane()->addComponent(&m_animatedPlay);

    m_buttonPlay.create("playButton", 319, 215,
                        ptr_managerGroup->ptr_textureManager->getTexture("playButtonPress"),
                        ptr_managerGroup->ptr_textureManager->getTexture("playButton"));
    getContentPane()->addComponent(&m_buttonPlay);

    m_helpButton.create("helpButton", 45, 280,
                        ptr_managerGroup->ptr_textureManager->getTexture("helpButton"),
                        ptr_managerGroup->ptr_textureManager->getTexture("helpButtonPress"));
    getContentPane()->addComponent(&m_helpButton);

    m_searchBar.create("searchBar", 85, 80,
                       ptr_managerGroup->ptr_textureManager->getTexture("searchBar"),
                       false, 0.2, 47, 545, 18);
    getContentPane()->addComponent(&m_searchBar);

    m_searchBarLoop.create("searchBarLoop", 85, 80,
                           ptr_managerGroup->ptr_textureManager->getTexture("searchBarLoop"),
                           true, 0.5, 47, 545, 2);
    getContentPane()->addComponent(&m_searchBarLoop);
    m_searchBarLoop.setVisible(false);
}

HomePage::~HomePage(){

}

void HomePage::update(sf::RenderWindow *window,
                            sf::Event *e, double frameTime) {

    //Si on est pas sur la fenetre, on return
    if (!m_ptr_managerGroup->ptr_targetManager->isHomePage())
        return;

    checkStateAnimation();

    if (m_inputHandler.getComponentId() == "playButton"){
        m_ptr_managerGroup->ptr_targetManager->isOnLaboratoryRoom();
    }

    // Basic Interface updating
    basicInput(e, frameTime);


    // Drawing all content
    basicDraw(window);
}

void HomePage::checkStateAnimation() {
    if(m_searchBar.isStopped()){
        m_searchBar.setVisible(false);
        m_searchBarLoop.setVisible(true);
    }
}

