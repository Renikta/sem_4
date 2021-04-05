#include <SFML\Audio.hpp>

int main()
{
    sf::Music music;
    if (!music.openFromFile("music.ogg"))
        return -1;
    music.play();

    while(window.isOpen())
    {

    }
}
