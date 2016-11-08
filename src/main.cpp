#include <SFML/Graphics.hpp>
#include "player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    
    Bullet bullet("assets/bullet.png", 2.0f);
    bullet.setPosition(0, 0);
    
    Player player(&window, "assets/player.png", 1, &bullet);
    player.setPosition(window.getSize().x/2, window.getSize().y/2);


    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        player.update();

        window.clear(sf::Color::Blue);
        window.draw(player);
        window.display();
    }
    return 0;
}
