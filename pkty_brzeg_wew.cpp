#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 30; // Maksymalna liczba punktów - określa górny zakres wartości

class Punkty {
private:
	int n; // Liczba punktów - określa zakres liczb
	vector<int> P; // Permutacja liczb z zakresu 1..n - określa zbiór punktów

	// Badanie sektorów
	// korzysta z posortowanych rosnąco wartości x w tablicy P
	bool sw(int x) {
		for (int i = 0; i < x; ++i)
			if (P[i] < P[x])
				return true;
		return false;
	}

	bool nw(int x) {
		for (int i = 0; i < x; ++i)
			if (P[i] > P[x])
				return true;
		return false;
	}

	bool ne(int x) {
		for (int i = x + 1; i < n; ++i)
			if (P[i] > P[x])
				return true;
		return false;
	}

	bool se(int x) {
		for (int i = x + 1; i < n; ++i)
			if (P[i] < P[x])
				return true;
		return false;
	}


	char klasyfikujPunkt(int x) {
		if (sw(x) && nw(x) && ne(x) && se(x))
			return 'W';
		else
			return 'B';
	}

	// Przygotowanie układu kartezjańskiego do prezentacji
	void przygotujUklad(vector<vector<char>> &U) {

		for (int y = n - 1; y >= 0; --y)
			for (int x = 0; x < n; ++x)
				if (P[x] != (y + 1))
					U[y][x] = '.'; // Wypełnienie "tła" układu
				else
					U[y][x] = klasyfikujPunkt(x); // Wstawienie punktu
	}

public:
	Punkty(int nn): n(nn) {
		P = vector<int>(n);
	}

	int& operator[](int i) {
		return P[i];
	}

	// Generowanie permutacji liczb z zakresu 1..n
	void generujPerm() {
		vector<int> wartosci;
		int q = n;

		// Wypełnij wartościami z zakresu 1..n
		for (int i = 0; i < n; ++i) {
			wartosci.push_back(i + 1);
		}

		// Losuj wartości
		for (int i = 0, w; q > 1; ++i, --q) {
			w = rand() % q;
			P[i] = wartosci[w];
			wartosci.erase(wartosci.begin() + w);
		}
		P[n - 1] = wartosci[0];
	}

	// Prezentacja pseudograficzna
	void prezentujUkladXY() {
		vector<vector<char>> ukladXY(n, vector<char>(n));
		przygotujUklad(ukladXY);

		cout << "\ny^\n";
		for (int y = n - 1; y >= 0; --y) {
			cout << (y+1) % 10 << '|'; // Wartości y oraz oś OY
			for (int x = 0; x < n; ++x)
				cout << ' ' << ukladXY[y][x];
			cout << endl;
		}

		// Oś OX
		cout << "0+";
		for (int i = 0; i < n; ++i)
			cout << "--";
		cout << "->" << endl;

		// Wartości x
		for (int i = 0; i <= n; ++i)
			cout << ' ' << i%10;
		cout << " x\n\n";
	}
};

int main() {
	setlocale(LC_ALL, "");

	cout << "Program tworzy zbiór n punktów\nna podstawie permutacji liczb z zakresu 1..n.\n";
	cout << "n<=0 lub n>" << MAX_N << " kończą program.\n";
	cout << "Permutacja jest generowana losowo albo wprowadzana z klawiatury.\n";
	cout << "Punkty mają współrzędne (x, y), gdzie:\n";
	cout << "x = pozycja elementu w permutacji (1..n),\ny = wartość tego elementu (1..n).\n";
	cout << "Każdy punkt wyznacza 4 sektory: SW, NW, NE, SE.\n";
	cout << "Punkty są klasyfikowane na wewnętrzne ('W') i brzegowe ('B').\n";
	cout << "Punkt nazywamy wewnętrznym, jeżeli w każdym sektorze\nznajduje się przynajmniej jeden punkt;\n";
	cout << "w przeciwnym przypadku nazywamy go brzegowym.\n";
	cout << "Zbiór punktów jest prezentowany pseudograficznie.\n\n";

	int n;
	char a;

	while (true) {
		cout << "Podaj liczbę punktów. n = ";
		cin >> n;
		if (n <= 0 || n > MAX_N)
			break;
		Punkty P(n);
		if (n > 1) {
			cout << "Permutacja liczb. Generowanie losowe? (t/n): ";
			cin >> a;
			if (a == 't')
				P.generujPerm();
			else {

				int v;
				vector<bool> spr(n, false); // Dla eliminacji ewentualnych błędów (powtórzeń)
				cout << "Podaj permutację wartości z zakresu 1.." << n << ":\n";
				for (int i = 0; i < n; ++i) {
					cin >> v;
					if (v >= 1 && v <= n && !spr[v - 1]) {
						P[i] = v;
						spr[v - 1] = true;
					}
					else {
						--i;
						continue;
					}
				}
				cin.ignore(256, '\n');

			}
		}
		else
			P[0] = 1;
		P.prezentujUkladXY();
		cout << endl;
	}
	cout << "Koniec programu.\n";
	return 0;
}
