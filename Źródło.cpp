#include "funkcje.cpp"

using namespace sf;
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris!", sf::Style::Default);


	//T³o Menu
	sf::Texture t³o; //tworzenie tekstury t³o 
	t³o.loadFromFile("Obrazy/TloTetris.jpg"); //okreœlenie t³a jako obrazek z pliku
	sf::Sprite obrazek1; //obiekt typu sf::Sprite byœmy mogli nim rysowaæ na ekranie
	obrazek1.setTexture(t³o); //informujemy jaka tekstura ma byæ u¿yta podczas malowania sprite

	//Muzyka
	sf::Music muzyka;
	muzyka.openFromFile("Muzyka/tetris.ogg");
	muzyka.setVolume(20);
	muzyka.play();
	muzyka.setLoop(true);

	//Napis Tytu³owy Tetris
	sf::Texture Napis;
	Napis.loadFromFile("Obrazy/NapisTetris.png");
	sf::Sprite NapisTytul;
	NapisTytul.setTexture(Napis);
	NapisTytul.move(250, 30);

	//Przycisk NowaGra
	sf::Texture NowaGra; //tworzymy obiekt do przechowywania tekstury
	NowaGra.loadFromFile("Obrazy/NowaGra.jpg"); //wczytywanie tekstury do pamieci karty graficznej
	sf::Sprite PrzyciskNowaGra; // klasa do rysowania obrazkami na scenie sf::Sprite - tworzenie obiektu typu Sprite
	PrzyciskNowaGra.setTexture(NowaGra); // W kolejnym kroku informujemy nowo utworzony obiekt, jaka tekstura powinna zostaæ u¿yta podczas rysowania sprajta. Do tego celu s³u¿y metoda setTexture, która jako pierwszy argument przyjmuje obiekt reprezentuj¹cy teksturê (czyli obiekt typu sf::Texture):
	PrzyciskNowaGra.move(250, 150);

	//Przycisk NowaGra pod wp³ywem wciœniecia
	sf::Texture NowaGra1;
	NowaGra1.loadFromFile("Obrazy/NowaGra1.jpg");
	sf::Sprite PrzyciskNowaGra1;
	PrzyciskNowaGra1.setTexture(NowaGra1);
	PrzyciskNowaGra1.move(250, 150);

	//Przycisk Wyniki
	sf::Texture Wyniki;
	Wyniki.loadFromFile("Obrazy/Wyniki.jpg");
	sf::Sprite PrzyciskWyniki;
	PrzyciskWyniki.setTexture(Wyniki);
	PrzyciskWyniki.move(250, 240);

	//Przycisk Wyniki pod wplywem wcisniecia
	sf::Texture Wyniki1;
	Wyniki1.loadFromFile("Obrazy/Wyniki1.jpg");
	sf::Sprite PrzyciskWyniki1;
	PrzyciskWyniki1.setTexture(Wyniki1);
	PrzyciskWyniki1.move(250, 240);

	//Przycisk Sterowanie
	sf::Texture Sterowanie;
	Sterowanie.loadFromFile("Obrazy/Sterowanie.jpeg");
	sf::Sprite PrzyciskSterowanie;
	PrzyciskSterowanie.setTexture(Sterowanie);
	PrzyciskSterowanie.move(250, 330);

	//Przycisk Sterowanie pod wplywem nacisniecia
	sf::Texture Sterowanie1;
	Sterowanie1.loadFromFile("Obrazy/Sterowanie1.jpeg");
	sf::Sprite PrzyciSterowanie1;
	PrzyciSterowanie1.setTexture(Sterowanie1);
	PrzyciSterowanie1.move(250, 330);

	//Przycisk Wyjscie 
	sf::Texture Wyjscie;
	Wyjscie.loadFromFile("Obrazy/Wyjscie.jpg");
	sf::Sprite PrzyciskWyjscie;
	PrzyciskWyjscie.setTexture(Wyjscie);
	PrzyciskWyjscie.move(250, 420);


	//Przycisk Wyjscie pod wplywem nacisniecia
	sf::Texture Wyjscie1;
	Wyjscie1.loadFromFile("Obrazy/Wyjscie1.jpg");
	sf::Sprite PrzyciskWyjscie1;
	PrzyciskWyjscie1.setTexture(Wyjscie1);
	PrzyciskWyjscie1.move(250, 420);

	//Przycisk Cofnij
	sf::Texture Cofnij;
	Cofnij.loadFromFile("Obrazy/Cofnij.jpeg");
	sf::Sprite PrzyciskCofnij;
	PrzyciskCofnij.setTexture(Cofnij);
	PrzyciskCofnij.move(250, 520);

	//Przycisk Cofnij pod wplywem nacisniecia
	sf::Texture Cofnij1;
	Cofnij1.loadFromFile("Obrazy/Cofnij1.jpeg");
	sf::Sprite PrzyciskCofnij1;
	PrzyciskCofnij1.setTexture(Cofnij1);
	PrzyciskCofnij1.move(250, 520);

	//T³o od sterowania
	sf::Texture Ster;
	Ster.loadFromFile("Obrazy/Sterowanie.jpg");
	sf::Sprite Obrazek2;
	Obrazek2.setTexture(Ster);
	Obrazek2.move(150, 20);

	//T³o od wyników
	sf::Texture Win;
	Win.loadFromFile("Obrazy/Wyniki2.jpg");
	sf::Sprite Obrazek3;
	Obrazek3.setTexture(Win);
	Obrazek3.move(50, 50);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) //Glowna petla programu
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) { //zamykanie okienka za pomoca esc lub krzy¿ykiem 
				window.close();


			}
		}
		//
		window.clear(); //wyczyœci scene na kolor czarny
		window.draw(obrazek1);
		window.draw(NapisTytul);
		window.draw(PrzyciskNowaGra);
		window.draw(PrzyciskWyniki);
		window.draw(PrzyciskSterowanie);
		window.draw(PrzyciskWyjscie);

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);


		//Warunki przycisków
		if (PrzyciskNowaGra.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
			window.draw(PrzyciskNowaGra1);

			if (PrzyciskNowaGra.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && (event.mouseButton.button == sf::Mouse::Left)) {


				/////////////////////Okno-Gry/////////////////////////////////////////////////////////////////
				RenderWindow window1(VideoMode(800, 600), "Tetris-Gra", sf::Style::Default);
				////////////////////Klocek////////////////////////////////	    
				RectangleShape cell(Vector2f(cell_size, cell_size));
				klocki kloc(cell);
				//////////////////////Swiat//////////////////////////////
				RectangleShape granica_praw(Vector2f(10, h_cnt * cell_size));
				RectangleShape tablica(Vector2f(125, 65));
				swiat swt(granica_praw, tablica);
				/////////////////////////////////////////////////////////

				kloc.dostep();
				Event event;

				Clock clock;
				while (window1.isOpen()) {

					kloc.flaki(window1, event, clock);
					kloc.rys(window1);
					kloc.rys_sw(window1);
					swt.swiat_rys(window1);
					window1.draw(PrzyciskCofnij);
					sf::Vector2i mousePosition = sf::Mouse::getPosition(window1);

					if (PrzyciskCofnij.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
						window1.draw(PrzyciskCofnij1);
						//Najechanie i nacisniecie
						if (PrzyciskCofnij.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && (event.mouseButton.button == sf::Mouse::Left)) {
							kloc.nowa();
							window1.close();
						}
					}
					else window1.draw(PrzyciskCofnij);

					window1.display();
				}

			}


		}
		else window.draw(PrzyciskNowaGra);
		//Wyniki
		if (PrzyciskWyniki.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
			window.draw(PrzyciskWyniki1);
			if (PrzyciskWyniki.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && (event.mouseButton.button == sf::Mouse::Left)) {
				sf::RenderWindow Wyniki(sf::VideoMode(800, 600), "Tetris-Wyniki");
				while (Wyniki.isOpen())
				{
					sf::Event event;
					while (Wyniki.pollEvent(event))
					{
						if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) { //zamykanie okienka za pomoca esc lub krzy¿ykiem 
							Wyniki.close();
						}


					}
					Wyniki.clear();
					Wyniki.draw(obrazek1);
					Wyniki.draw(Obrazek3);
					sf::Vector2i mousePosition = sf::Mouse::getPosition(Wyniki);

					if (PrzyciskCofnij.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
						Wyniki.draw(PrzyciskCofnij1);
						//Najechanie i nacisniecie
						if (PrzyciskCofnij.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && (event.mouseButton.button == sf::Mouse::Left)) {
							Wyniki.close();
						}
					}
					else Wyniki.draw(PrzyciskCofnij);

					Wyniki.display();



				}



			}
		}
		else window.draw(PrzyciskWyniki);


		//Sterowanie
		if (PrzyciskSterowanie.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
			window.draw(PrzyciSterowanie1);
			if (PrzyciskSterowanie.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && (event.mouseButton.button == sf::Mouse::Left)) {

				sf::RenderWindow SterowanieKlawisze(sf::VideoMode(800, 600), "Tetris-Sterowanie");

				while (SterowanieKlawisze.isOpen())
				{
					sf::Event event;
					while (SterowanieKlawisze.pollEvent(event))
					{
						if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) { //zamykanie okienka za pomoca esc lub krzy¿ykiem 
							SterowanieKlawisze.close();
						}
					}
					sf::Vector2i mousePosition = sf::Mouse::getPosition(SterowanieKlawisze);
					SterowanieKlawisze.clear();
					SterowanieKlawisze.draw(obrazek1);
					SterowanieKlawisze.draw(Obrazek2);


					if (PrzyciskCofnij.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
						SterowanieKlawisze.draw(PrzyciskCofnij1);
						//Najechanie i nacisniecie
						if (PrzyciskCofnij.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && (event.mouseButton.button == sf::Mouse::Left)) {
							SterowanieKlawisze.close();
						}
					}
					else SterowanieKlawisze.draw(PrzyciskCofnij);



					SterowanieKlawisze.display();
				}

			}
		}
		else window.draw(PrzyciskSterowanie);


		//wyjscie

		if (PrzyciskWyjscie.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
			window.draw(PrzyciskWyjscie1);

			//Najechanie i nacisniecie
			if (PrzyciskWyjscie.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && (event.mouseButton.button == sf::Mouse::Left)) {
				window.close();
			}
		}
		else window.draw(PrzyciskWyjscie);



		window.display(); //wyswietlanie zawartosci window

	}
	return 0;
}
