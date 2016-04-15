
//Les includes nécessaires
#include "ResourceLoader.hpp"
#include "SplashScreen.hpp"
#include "LoginMenu.hpp"

int main(int argc, char ** argv)
{

    // Checking args
    if(argc > 1) return FAILURE;
    std::cout << "\nRunning program : " << argv[0] << "\n" << std::endl;

    // Starting load of heavy resources
    // Launching thread
    ResourceLoader rLoader(DEBUG);
    rLoader.start();

    // Creating window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    WINDOW_NAME, sf::Style::None);

    // Window framerate - Default : 120 fps
    window.setFramerateLimit(WINDOW_FPS);

    // Starting some videos while loading res
    SplashScreen splash(DEBUG);
    //splash.start(&window);

    // Getting loaded resources
    // Wait if not finished
    while(!rLoader.getLoadState()) sf::sleep(sf::milliseconds(WAIT_TIME));
    ManagerGroup * managerGroup = rLoader.getManager();

    // Creating menu
    LoginMenu loginMenu(DEBUG, managerGroup);
    //Les autres fenetres du jeu sont instanciées ici aussi


    // Setting main target
    managerGroup->ptr_targetManager->isOnLoginMenu();

    //Boucle de jeu
    sf::Clock clock;
    while (window.isOpen())
    {   
        // Exiting program
        if(!managerGroup->ptr_targetManager->isExit()) {
            managerGroup->ptr_musicManager->stopPlaylist();
            window.close();
            continue;
        }

        //Horloge de jeu
        double elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart().asMilliseconds();
        window.clear();

        //Boucle des évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Updating game logic
        loginMenu.update(&window, &event, elapsedTime);
       //Les autres 'fenetres' sont actualisées à ce moment aussi
        managerGroup->ptr_musicManager->update();

        window.display();
    }

    return SUCCESS;
}