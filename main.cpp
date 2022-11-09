#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp> //Библиотека SFML;
using namespace std;
using namespace sf; // Пространство имён SFML;
unsigned short Width = 800, Height = 600;
int main()
{
    ContextSettings settings; 
    settings.antialiasingLevel = 8;
    RenderWindow window (VideoMode(Width,Height), "Moon shine", Style::Default, settings);
    
    float alpha = 0, k, R = 100, r, y;
    
    Vertex line[] ={
		Vertex(Vector2f(390.f, 240.f), Color(238, 191, 137)),  
		Vertex(Vector2f(470.f, 150.f), Color(238, 191, 137))  
	};
	
	CircleShape circle(100.f, 100);  
	circle.setFillColor(Color(84, 67, 48));  
	
	circle.move(300, 200);  
		
	window.draw(circle);  
	
 	
    while(window.isOpen()) 
    {
        Event event; 
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed) 
				window.close();
        }
        window.clear(Color::Black); 
		
		window.draw(circle);
		
		if (alpha >= M_PI*2)
			alpha -= M_PI*2;
			
		if(alpha < M_PI){
			k = cos(alpha);
			for(float i = 0; i < M_PI; i+=0.01){
				r = R * sin(i);
				y = 300 + R * cos(i);
				
				line[0].position = Vector2f(400 - r, y);
				line[1].position = Vector2f(400 + r * k, y);
				
				window.draw(line, 2, Lines);
			}
		}
		else{
			k = cos(alpha);
			for(float i = 0; i < M_PI; i+=0.01){
				r = R * sin(i);
				y = 300 + R * cos(i);
				
				line[0].position = Vector2f(400 + r, y);
				line[1].position = Vector2f(400 - r * k, y);
				
				window.draw(line, 2, Lines);
			}
		}
		
		window.display(); 
		alpha += 0.0001;
    }
    return 0; 
}