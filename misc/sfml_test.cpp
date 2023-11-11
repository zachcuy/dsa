#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  // Create a SFML window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Bar Chart");

  // Example data points
  std::vector<float> dataPoints{1, 3, 2, 5, 25, 24, 5};
  float maxHeight = window.getSize().y * 0.8f;  // 80% of window height
  float maxValue = *std::max_element(dataPoints.begin(), dataPoints.end());
  for (auto &value : dataPoints) {
    value = (value / maxValue) * maxHeight;
  }

  // Calculate bar width (leaving some space between bars)
  float barWidth = window.getSize().x / (dataPoints.size() * 1.2f);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();

    // Draw bars
    for (size_t i = 0; i < dataPoints.size(); ++i) {
      sf::RectangleShape bar(sf::Vector2f(barWidth, dataPoints[i]));

      // Set the position of the bar
      bar.setPosition(i * barWidth * 1.2f, window.getSize().y - dataPoints[i]);

      // Set bar color (optional)
      bar.setFillColor(sf::Color::Green);

      window.draw(bar);
    }

    window.display();
  }

  return 0;
}
