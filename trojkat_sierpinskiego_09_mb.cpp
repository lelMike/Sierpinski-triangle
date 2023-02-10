#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000, 800), "SFML works!");
    CircleShape point1(.5f);
    point1.setFillColor(Color::Red);
    srand(time(NULL));

    window.clear();
    int posxy[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    for(int i=0; i < 3; i++){
        int x = (rand())%1000;
        int y = (rand())%800;
        while (x == posxy[0][0] || x == posxy[1][0] || x == posxy[2][0]){
            int x = (rand())%1000;
        }
        while (y == posxy[0][0] || y == posxy[1][0] || y == posxy[2][0]){
            int y = (rand())%1000;
        }
        posxy[i][0] = x; posxy[i][1] = y;
    }

    int n; std::cin >> n;

    int last_pointx, last_pointy;
    int which_letter = rand()%3;
    int rand_x = (rand())%1000;
    int rand_y = (rand())%800;

    int new_pointx = (posxy[which_letter][0] + rand_x)/2;
    int new_pointy = (posxy[which_letter][1] + rand_y)/2;

    point1.setPosition(new_pointx, new_pointy);
    window.draw(point1);
    last_pointx = new_pointx;
    last_pointy = new_pointy;

    for(int i = 0; i < (n - 1); i++){
        which_letter = rand()%3;
        rand_x = (rand())%1000;
        rand_y = (rand())%800;

        new_pointx = (posxy[which_letter][0] + last_pointx)/2;
        new_pointy = (posxy[which_letter][1] + last_pointy)/2;

        point1.setPosition(new_pointx, new_pointy);
        window.draw(point1);
        last_pointx = new_pointx;
        last_pointy = new_pointy;

    }

    window.display();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    }

    return 0;
}
