#include <SFML/Graphics.hpp>

int main() {
    // Criação da janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle Example");

    // Criação do círculo
    sf::CircleShape circle(50.0f); // Círculo com raio de 50 pixels
    circle.setFillColor(sf::Color::Green); // Cor de preenchimento: Verde
    circle.setPosition(375.0f, 275.0f); // Posição do círculo (centralizado)

    // Loop principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpar a janela
        window.clear(sf::Color::Black);

        // Desenhar o círculo
        window.draw(circle);

        // Exibir os desenhos na janela
        window.display();
    }

    return 0;
}
