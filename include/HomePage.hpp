//
// Created by Lucas on 16/04/2016.
//

#ifndef DEF_HOME_PAGE_HPP
#define DEF_HOME_PAGE_HPP

#include "BasicInterface.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class HomePage : public BasicInterface {
private:
    bool m_bool;
    NPanel m_background;
    AnimatableObject m_animatedPlay;
    AnimatableObject m_credit;
    NButton m_buttonPlay;
    NButton m_helpButton;
    NButton m_musicSound;
    AnimatableObject m_searchBar;
    AnimatableObject m_searchBarLoop;
    AnimatableObject m_animationTransition;

public:
    HomePage(bool debug, ManagerGroup *ptr_managerGroup);
    ~HomePage();

    virtual void update(sf::RenderWindow * window,
                        sf::Event * e, double frameTime);

    void checkStateAnimation();
    void checkStateAnimationTransition();

};


#endif // DEF_HOME_PAGE_HPP
