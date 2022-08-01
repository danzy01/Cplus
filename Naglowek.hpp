#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <sstream>
using namespace sf;
using namespace std;

const int cell_size = 25;
const int  w_cnt = 10;
const int  h_cnt = 20;

Text text;
Font czcionka;

const sf::Color kolor[] = {
sf::Color::Green,sf::Color::Red,sf::Color::Blue,Color::Cyan,Color::Magenta,Color::Yellow,Color::Green };


class baza {
protected:
	int randd = 0;
	int cx = w_cnt / 2;
	int cy = 0;
public:
	baza() {}
	~baza() {}
	void los() {
		randd = rand() % 7, cx = w_cnt / 2, cy = 0;
	}

};

class klocki :protected baza {
private:

	//int tetromino[7][4][4];
	sf::RectangleShape cell;
	//sf::RenderWindow window;
public:


	klocki(RectangleShape& celll) :cell(celll) {}

	~klocki() {}

	void nowa();
	void czysciciel();
	void draw_block();
	bool kolizja();
	bool ruch_dl(int opcja);
	void rotacja();
	void dostep() {
		los();
	}
	void rys(RenderWindow& wind);
	void rys_sw(RenderWindow& window);
	void flaki(RenderWindow& window, Event& event, Clock& clock);
};
class swiat {
private:
	RectangleShape granica_praw, tablica;
public:
	swiat(RectangleShape& granica, RectangleShape& tab);
	~swiat() {}
	void swiat_rys(RenderWindow& window);
};
