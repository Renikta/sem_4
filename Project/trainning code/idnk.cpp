#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 900), "IDNK what is it");
	sf::Clock clock;
	float CurrentFrame = 0;

    sf::Image heroimage;
    heroimage.loadFromFile("images/hero_1.png");

    sf::Texture herotexture;
    herotexture.loadFromImage(heroimage);

    sf::Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(sf::IntRect(0, 0, 233.75, 283.25));
    herosprite.setPosition(900, 450);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/1000;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(sf::IntRect(242 * int(CurrentFrame), 566.5, 233.75, 283.25));
			herosprite.move((-0.1) * time, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(sf::IntRect(242 * int(CurrentFrame), 849.75, 233.75, 283.25));
			herosprite.move((0.1) * time, 0);
		}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(sf::IntRect(242 * int(CurrentFrame), 283.25, 233.75, 283.25));
			herosprite.move(0, (-0.1) * time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame -= 4;
            herosprite.setTextureRect(sf::IntRect(242 * int(CurrentFrame), 0, 233.75, 283.25));
			herosprite.move(0, (0.1) * time);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            herosprite.setColor(sf::Color::Red);
        }

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}
