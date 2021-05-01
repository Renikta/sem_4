#include "GameHeader_e.h"

int main () {
    //Координаты спрайта
    float x = 100;
    float y = 100;
    float d_x = 50;
    float d_y = 50;

    sf::RenderWindow window(sf::VideoMode(1200, 900), "My window");

    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();

    sf::Image heroimage;
    heroimage.loadFromFile("images/main_hero.png");

    sf::Texture herotexture;
    herotexture.loadFromImage(heroimage);

    sf::Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(x, y);
    herosprite.setScale(0.9, 0.9);


    while (window.isOpen()) {
        sf::Time time = clock.getElapsedTime();
        clock.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            herosprite.move(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            herosprite.move(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            herosprite.move(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            herosprite.move(0, 1);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(255, 255, 255));
        window.draw(herosprite);
        window.display();
    }

    return 0;
}
