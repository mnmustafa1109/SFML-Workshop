#include <SFML/Graphics.hpp>
#include <thread>
#include "App.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
#ifdef __linux__
    // init X threads
    XInitThreads();
#endif
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;
    const unsigned int width = (App::DEFAULT_WIDTH * App::DEFAULT_RESX);
    const unsigned int height = (App::DEFAULT_HEIGHT * App::DEFAULT_RESY);
    const sf::Vector2u size(width, height);
    sf::RenderWindow window(sf::VideoMode(size), "SFML & CMAKE",
                            sf::Style::Titlebar | sf::Style::Close, settings);
    window.clear(sf::Color::Cyan);
    window.setFramerateLimit(120);
    bool success = window.setActive(false);
    App app;
    app.setWindow(&window);
    std::thread rendering_thread(&App::display, &app);
    app.run();
    rendering_thread.join();
    return 0;
}