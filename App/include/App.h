#ifndef APP_H
#define APP_H

namespace sf
{
	class RenderWindow;
};

class App
{


private:
	sf::RenderWindow* _window = nullptr;

public:
	static const unsigned int DEFAULT_WIDTH;
	static const unsigned int DEFAULT_HEIGHT;
	static const unsigned int DEFAULT_RESX;
	static const unsigned int DEFAULT_RESY;
	App();
	virtual ~App();
	void setWindow(sf::RenderWindow*);
	void run();
	void display();
};
#endif // !APP_H
