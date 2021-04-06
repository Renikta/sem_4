#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void poligon(float N) {
    int x0 = 400;
    int y0 = 300;
    int R = 200;
    float alpha = 2 * 3.14 / N;

    sf::RenderWindow window(sf::VideoMode(800, 600), "sfml-Graphics");
    sf::ConvexShape convex;
    convex.setPointCount(N);
    convex.setFillColor(sf::Color(150, 50, 250));

    sf::CircleShape circle1(R);
    circle1.setFillColor(sf::Color(0, 0, 0));
    circle1.setPosition(200, 100);
    circle1.setOutlineThickness(2);
    circle1.setOutlineColor(sf::Color(250, 240, 60));

    sf::CircleShape circle2(R * cos(3.14 / N));
    circle2.setFillColor(sf::Color(150, 50, 250));
    circle2.setPosition(x0 - R * cos(3.14 / N), y0 - R * cos(3.14 / N));
    circle2.setOutlineThickness(2);
    circle2.setOutlineColor(sf::Color(250, 240, 60));

    for (int i = 0; i < N; i++) {
        std::cout << "Точка №" << i << "  x: " << R * sin(i * alpha) << "  y:  " << R * cos(i * alpha) << std::endl;
        convex.setPoint(i, sf::Vector2f(x0 - R * sin(i * alpha), y0 - R * cos(i * alpha)));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle1);
        window.draw(convex);
        window.draw(circle2);
        window.display();
    }
}

int main() {
    int N = 0;
    std::cout << "Введите число сторон правильного многоугольника: ";
    std::cin >> N;
    std::cout << std::endl;
    poligon(N);
    return 0;
}
