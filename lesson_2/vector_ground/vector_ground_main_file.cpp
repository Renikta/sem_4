#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

#define WIN_width 1700
#define WIN_height 900
#define lines_length 17
#define lines_width 2


struct corpuscle {
    corpuscle(int diameter, float electric_charge, float x, float y):
        electric_charge(electric_charge), x(x), y(y), circle(sf::CircleShape(diameter)) {

            circle.setOrigin(diameter / 2, diameter / 2);
            circle.setPosition(x, y);

            if (electric_charge > 0)
                circle.setFillColor(sf::Color(255, 255, 51));
            if (electric_charge < 0)
                circle.setFillColor(sf::Color(0, 204, 255));
    };

    float electric_charge;
    float x;
    float y;
    sf::CircleShape circle;
    void Draw(sf::RenderWindow& window);
};
void corpuscle::Draw(sf::RenderWindow& window) {
    window.draw(circle);
}

struct force_lines {
    force_lines(float x, float y, float angle):
        x(x), y(y), angle(angle) {

        line = sf::RectangleShape(sf::Vector2f(lines_length, lines_width));
        line.setFillColor(sf::Color(204, 204, 204));

        line.setOrigin(lines_length / 2, lines_width / 2);
        line.setPosition(x, y);
        line.setRotation(angle * 180 / 3.14);
    };
    float x;
    float y;
    float angle;
    sf::RectangleShape line;
    void Draw(sf::RenderWindow& window);
};
void force_lines::Draw(sf::RenderWindow& window) {
    window.draw(line);
}

std::vector<force_lines> counting_power_lines(std::vector<corpuscle>& corpuscles) {
        std::vector<force_lines> resulting_lines;

        for(int i = 0; i < 1700; i += 30) {
            for(int j = 0; j < 900; j += 30) {
                    float pos_x, pos_y;
                    float electric_field_strength;

                    sf::Vector2f E(0, 0);
                    for (auto& element : corpuscles) {
                        pos_x = i - element.x;
                        pos_y = j - element.y;

                        electric_field_strength = element.electric_charge / (std::pow((pos_x*pos_x + pos_y*pos_y), 2));
                        sf::Vector2f E_elem(pos_x * electric_field_strength, pos_y * electric_field_strength);
                        E = E + E_elem;
                    }
                    force_lines lines(i, j, std::atan2(E.x, E.y));
                    resulting_lines.push_back(lines);
            }
        }
        return resulting_lines;
}


int main() {
    sf::RenderWindow window(sf::VideoMode(1700, 900), "vector_ground");
    std::vector<corpuscle> corpuscles;

    while (window.isOpen())
    {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            corpuscle c(7, -1500, mousePosition.x, mousePosition.y);
            corpuscles.push_back(c);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            corpuscle c(7, 1500, mousePosition.x, mousePosition.y);
            corpuscles.push_back(c);
        }
        auto lines = counting_power_lines(corpuscles);


        for (auto& elem : corpuscles) {
            elem.Draw(window);
        }


        for(auto& elem : lines) {
            elem.Draw(window);
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
        window.clear();
    }
    return 0;
}
