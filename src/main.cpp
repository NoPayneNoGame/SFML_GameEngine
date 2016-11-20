#include <SFML/Graphics.hpp>
#include "game.h"
#include "testscene.h"


int main()
{
    int exitCode;

    Game* game = Game::instance();
   
    game->setFirstScene(new TestScene("Test"));

    exitCode = game->run();
    
    std::cout << "Exiting with code: " << exitCode << std::endl;
    
    return exitCode;
}
