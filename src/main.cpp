#include <SFML/Graphics.hpp>
#include "game.h"
#include "testscene.h"


int main()
{
    std::cout << "Hello" << std::endl;
    int exitCode;

    Game* game = Game::instance();
    std::cout << game << std::endl;
   
    game->setFirstScene(new TestScene("Test"));

    exitCode = game->run();
    
    return exitCode;
}
