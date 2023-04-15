#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing Mushroom");

	sf::Texture mushroomTexture;
	mushroomTexture.loadFromFile("mushroom.png");
	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2u size = mushroomTexture.getSize();
	mushroom.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.4f, 0.4f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (mushroom.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0 ||
			(mushroom.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
		{
			// Reverse the direction on x-Axis
			increment.x = -increment.x;
		}

		if (mushroom.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0 ||
			(mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
		{
			// Reverse the direction on y-Axis
			increment.y = -increment.y;
		}

		mushroom.setPosition(mushroom.getPosition() + increment);

		window.clear(sf::Color(16, 16, 16, 255)); // Dark gray
		window.draw(mushroom); // Drawing our Sprite
		window.display();
	}
	return 0;
}