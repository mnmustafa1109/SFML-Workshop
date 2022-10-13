#include "App.h"
#include <SFML/Graphics.hpp>


const unsigned int App::DEFAULT_WIDTH = 400;
const unsigned int App::DEFAULT_HEIGHT = 300;
const unsigned int App::DEFAULT_RESX = 2;
const unsigned int App::DEFAULT_RESY = 2;

void App::setWindow(sf::RenderWindow *w)
{
	_window = w;
}

App::~App()
{
	_window = nullptr;
}

App::App()
{
}

void App::display()
{
	if (_window != nullptr)
	{
		// activate the opengl context
		_window->setActive(true);

		// rendering loop
		while (_window->isOpen())
		{
			// draw here
			_window->display();
		}
	}
}

void App::run()
{
	// deactivate the opengl context
	_window->setActive(false);

	// dynamics loop : dispatch events to controllers
	while (_window->isOpen())
	{
		// events dispatching
		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
	
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					int posx = event.mouseButton.x;
					int posy = event.mouseButton.y;
					printf("right mouse clicked.\nx=%d, y=%d\n", posx, posy);
				}
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					int posx = event.mouseButton.x;
					int posy = event.mouseButton.y;
					printf("left mouse clicked.\nx=%d, y=%d\n", posx, posy);
				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
			}
		}
	}
}

