#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    sf::Window window(sf::VideoMode(600, 600), "My OpenGL window", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    GLenum res = glewInit();
    cout << res << endl;
    if (GLEW_OK != glewInit()) {
        cout << "glew init failed\n";
        exit(0);
    }
    vector<GLfloat> vertices{
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        window.display();
    }

    return 0;
}