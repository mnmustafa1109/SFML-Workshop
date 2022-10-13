#include <SFML/Graphics.hpp>
#include "main.hpp"

int App() {
    const unsigned int width = (DEFAULT_WIDTH * DEFAULT_RESX);
    const unsigned int height = (DEFAULT_HEIGHT * DEFAULT_RESY);
    const sf::Vector2u size(width, height);
    sf::RenderWindow window(sf::VideoMode(size), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}