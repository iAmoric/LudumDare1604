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
    NButton m_buttonPlay;
    NButton m_helpButton;
    AnimatableObject m_searchBar;
    AnimatableObject m_searchBarLoop;

public:
    HomePage(bool debug, ManagerGroup *ptr_managerGroup);
    ~HomePage();

    virtual void update(sf::RenderWindow * window,
                        sf::Event * e, double frameTime);

    void checkStateAnimation();

};


#endif // DEF_HOME_PAGE_HPP
