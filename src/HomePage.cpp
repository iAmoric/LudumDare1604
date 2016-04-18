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

    //m_animationTransition.setVisible(false);
}

HomePage::~HomePage(){

}

void HomePage::update(sf::RenderWindow *window,
                            sf::Event *e, double frameTime) {

    //Si on est pas sur la fenetre, on return
    if (!m_ptr_managerGroup->ptr_targetManager->isHomePage())
        return;

    checkStateAnimation();
    checkStateAnimationTransition();

    if (m_inputHandler.getComponentId() == "playButton"){
        m_animationTransition.create("animationTransition", 0, 0,
                                     m_ptr_managerGroup->ptr_textureManager->getTexture("animationTransition"),
                                     false, 0.05, 640, 960, 12);
        getContentPane()->addComponent(&m_animationTransition);

    }

    if (m_inputHandler.getComponentId() == "helpButton"){
        m_credit.create("credit", 46, 163,
                        m_ptr_managerGroup->ptr_textureManager->getTexture("credit"),
                        true, 1, 216, 189, 5);
        getContentPane()->addComponent(&m_credit);
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

void HomePage::checkStateAnimationTransition() {
    if (m_animationTransition.isStopped()){
        //m_animationTransition.setVisible(false);
        m_ptr_managerGroup->ptr_targetManager->isOnLaboratoryRoom();
    }
}

