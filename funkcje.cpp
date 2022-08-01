#include "Naglowek.hpp"

static int tetromino[7][4][4] =
{
		1,0,0,0,
		1,0,0,0,
		 1,0,0,0,
		 1,0,0,0,

		  1,1,0,0,
		   1,1,0,0,
		   0,0,0,0,
		  0,0,0,0,

		  1,0,0,0,
		  1,1,0,0,
		  0,1,0,0,
		  0,0,0,0,

		  1,0,0,0,
		 1,0,0,0,
		  1,1,0,0,
		  0,0,0,0,

		 0,1,0,0,
		 1,1,0,0,
		 1,0,0,0,
		  0,0,0,0,

		 1,0,0,0,
		 1,1,0,0,
		  1,0,0,0,
		  0,0,0,0,

		   0,1,0,0,
		  0,1,0,0,
		  1,1,0,0,
		   0,0,0,0,
};


static int macierz_gl[h_cnt][w_cnt] = { 0 };
/*Funkcja 'zerujaca macierz glowna dzieki temu mozna rozpoczac nowa gre*/
void klocki::nowa() {

	for (int i = 0; i < h_cnt; i++) {
		for (int j = 0; j < w_cnt; j++) {
			macierz_gl[i][j] = 0;
		}
	}

}
/*Funkca sprawdzajaca kolizje bloku tetromino z scianami bocznymi z sciana dolna lub z innym klockiem*/
bool klocki::kolizja() {
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++) {
		if (tetromino[randd][y][x] == 0)  continue; //Brak kolizji
		if (x + cx < 0 || x + cx >= w_cnt || y + cy >= h_cnt)return false; //Kolizja z scianami lub z podloga
		if (macierz_gl[cy + y][cx + x])return false;   //Kolizja z innym klockiem
	}
	return true;
}
/*Funkcja czyszczaca dana linie jesli w jedna linia jest zapelniona klockami tetromino*/
void klocki::czysciciel() {
	int wys = h_cnt - 1;
	for (int i = h_cnt - 1; i >= 0; i--)
	{
		int szer = 0;
		for (int j = 0; j < w_cnt; j++) {

			if (macierz_gl[i][j]) {//jesli na ktorym kolwiek miejscu danego wiersza macierzy glownej napotka 0 przerywa sprawdzanie danego wiersza
				szer++;
			}
		}
		if (szer < w_cnt) {
			for (int k = 0; k < w_cnt; k++) {
				macierz_gl[wys][k] = macierz_gl[i][k];   //Usuniecie wiersza o poprawnym warunku
			}
			wys--;   
		}
	}
}
/*Funkcja odpowiadajaca za poruszanie sie klockow tetromino*/
bool klocki::ruch_dl(int opcja) {
	if (opcja == 1) {

		cy++;
		if (kolizja() == false)  //Jescli fun kolizja zwróci  kolizje
		{
			cy--;
			for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
			{
				if (tetromino[randd][y][x]) {
					macierz_gl[cy + y][cx + x] = randd + 1;
				}
			}
			czysciciel();
			los();
			return false;
		}
		return true;
	}
	//Opcja druga okazala sie zbedna i nie jest wykorzystywana
	if (opcja == 2) {

		cy++;
		if (kolizja() == false)
		{
			cy -= 1100;
			for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
			{
				if (tetromino[randd][y][x]) {
					macierz_gl[cy + y][cx + x] = randd + 1;
				}
			}
			czysciciel();
			los();
			return false;
		}
		return true;
	}

}
/*Funkcja odpowiadajaca za rotacje tetromina znajduje teoretyczny srodek symetrii oraz wykonuje 'obrót' macierzy w kierunku przeciwnym do obrotu wskazówek zegara*/
void klocki::rotacja() {
	int dl = 0;
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
	{
		if (tetromino[randd][y][x]) {
			dl = max(max(x, y) + 1, dl);  //Znalezienie teoretycznego srodka symetrii
		}
	}
	int temp[4][4] = { 0 };  //Macierz robocza do rotacji
	//rotacja preciwna do wskazowek zegara
	for (int y = 0; y < dl; y++)for (int x = 0; x < dl; x++) {
		if (tetromino[randd][y][x]) {   //Jesli napotkamy jedynke w danym wierszu i kolumnie zostanie przeniesiona
			temp[dl - 1 - x][y] = 1;
		}
	}
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++) {
		tetromino[randd][y][x] = temp[y][x];   //Aktualizacja zrotowanego tetromino
	}
}
/*Funkcja wyswietlajaca klocki ktore juz zostaly usadowione, Jesli w danym wierzu i kolumnie macierzy glownej znajduje sie cos ró¿nego od zera zostanie wyswietlone*/
void klocki::rys(RenderWindow& wind) {
	for (int y = 0; y < h_cnt; y++)for (int x = 0; x < w_cnt; x++)
		if (macierz_gl[y][x])
		{
			cell.setFillColor(kolor[macierz_gl[y][x] - 1]);
			cell.setPosition(Vector2f(x * cell_size, y * cell_size));
			//Aktualizacja klockow ktore juz byly
			wind.draw(cell);

		}
}
/*Funkcja rysujaca obecny bloczek tetromina jesli w konkretnej konfiguracji bloczka znajduje sie 1 to funkcja renderuje komorke o wielkosci 25x25 px */
void klocki::rys_sw(RenderWindow& window) {
	cell.setFillColor(kolor[randd]); //Rysowanie klocka konkretnych jego sk³adowych kwadratowych
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		if (tetromino[randd][y][x])
		{
			cell.setPosition(Vector2f((cx + x) * cell_size, (cy + y) * cell_size));

			window.draw(cell);

		}
}

/*Funkcja 'G³ówna klasy klocki odpowiadajaca za wywolywanie konkretnych funkcji w okreslonej hierarchii*/
void klocki::flaki(RenderWindow& window, Event& event, Clock& clock) {

	/*Odczyt czasu*/
	static float prev = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() - prev >= 0.5)
	{
		prev = clock.getElapsedTime().asSeconds();
		ruch_dl(1);  
	}


	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
		}
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Left) {
				cx--;
				if (kolizja() == false)cx++;
			}
			if (event.key.code == Keyboard::Right) {
				cx++;
				if (kolizja() == false)cx--;
			}
			if (event.key.code == Keyboard::Down) {
				ruch_dl(1);

			}
			if (event.key.code == Keyboard::Up) {
				rotacja();
				if (kolizja() == false) {
					rotacja(), rotacja(), rotacja();
				}
			}
			if (event.key.code == Keyboard::Space) {
				while (ruch_dl(1) == true);
			}
		}

	}

	window.clear();

}


/*Konstruktor klasy swiat, wstepna konfiguracja prawej granicy oraz tablicy do wyswietlania punktów*/
swiat::swiat(RectangleShape& granica, RectangleShape& tab) :granica_praw(granica), tablica(tab) {
	granica_praw.setFillColor(Color::Red);
	tablica.setOutlineThickness(10);
	tablica.setOutlineColor(Color::Blue);
	tablica.setFillColor(Color::White);
}

/*Funkcja wyswietlajaca na ekranie tablice oraz prawa granice*/
void swiat::swiat_rys(RenderWindow& window) {
	granica_praw.setPosition(Vector2f(w_cnt * cell_size + 1, 0));
	window.draw(granica_praw);
	tablica.setPosition(Vector2f(w_cnt * cell_size + 50, 60));
	window.draw(tablica);
}