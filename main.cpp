/*
 * Copyright Mytthew (c) 2020. Copying and modifying not allowed.
 * Autor: Mateusz Domagała
 * Komentarz:
 *          Wykonałem zadanie w dość przewrotny sposób tworząc trzy dodatkowe metody z menu wyboru.
 *          Zastosowałem nieskończoną pętlę dzięki, której to użytkownik decyduje kiedy przerwać dodawanie nominałów.
 *          Proszę wybaczyć sposób deklaracji pól na poczatku klasy, ale to przyzwyczajenie z Javy.
 *          Zastosowałem rownież pusty konstruktor, który zastąpiłem metodą dodawania.
 */

#include <iostream>

using namespace std;

class CashRegister {
    bool open = false;
    int B200ZL = 0;
    int B100ZL = 0;
    int B50ZL = 0;
    int B20ZL = 0;
    int B10ZL = 0;
    int M5ZL = 0;
    int M2ZL = 0;
    int M1ZL = 0;
    int M50GR = 0;
    int M20GR = 0;
    int M10GR = 0;
    int M5GR = 0;
    int M2GR = 0;
    int M1GR = 0;

public:
    CashRegister() {};

	void openCash() {
        if (open) {
            cout << "Kasa jest juz otwarta!" << endl;
            return;
        }
        open = true;
        cout << "Kasa otwarta!" << endl;
    }

    void closeCash() {
        if (!open) {
            cout << "Kasa jest juz zamknieta!" << endl;
            return;
        }
        open = false;
        cout << "Kasa zamknieta!" << endl;
    }

    void display() {
    	if (!open) {
    		cout << "Kasa jest zamknieta!" << endl;
		    return;
    	}
    	cout << "W kasie znajduje sie: " << endl;
    	cout << "BANKNOTY: " << endl;
    	cout << B200ZL << " - ilosc banknotow po 200zl" << endl;
    	cout << B100ZL << " - ilosc banknotow po 100zl" << endl;
    	cout << B50ZL << " - ilosc banknotow po 50zl" << endl;
    	cout << B20ZL << " - ilosc banknotow po 20zl" << endl;
    	cout << B10ZL << " - ilosc banknotow po 10zl" << endl;
	    cout << "MONETY ZL: " << endl;
	    cout << M5ZL << " - ilosc monet po 5zl" << endl;
	    cout << M2ZL << " - ilosc monet po 2zl" << endl;
	    cout << M1ZL << " - ilosc monet po 1zl" << endl;
	    cout << "MONETY GR: " << endl;
	    cout << M50GR << " - ilosc monet po 50gr" << endl;
	    cout << M20GR << " - ilosc monet po 20gr" << endl;
	    cout << M10GR << " - ilosc monet po 10gr" << endl;
	    cout << M5GR << " - ilosc monet po 5gr" << endl;
	    cout << M2GR << " - ilosc monet po 2gr" << endl;
	    cout << M1GR << " - ilosc monet po 1gr" << endl;
    }

	void addBills() {
		int values;
		int amount;
		cout << "Podaj wartosc banknotu: " << endl;
		cin >> values;
		cout << "Podaj ilosc banknotow: " << endl;
		cin >> amount;
		switch (values) {
			case 200:
				B200ZL = amount;
				break;
			case 100:
				B100ZL = amount;
				break;
			case 50:
				B50ZL = amount;
				break;
			case 20:
				B20ZL = amount;
				break;
			case 10:
				B10ZL = amount;
				break;
			default:
				return;
		}
	}

	void addCoins() {
		int choice;
		int value;
		int amount;
		cout << "Zlote czy grosze?" << endl;
		cout << "1. Zlote" << endl;
		cout << "2. Grosze" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Podaj wartosc monety: " << endl;
			cin >> value;
			cout << "Podaj ilosc monet: " << endl;
			cin >> amount;
			switch (value) {
				case 5:
					M5ZL = amount;
					break;
				case 2:
					M2ZL = amount;
					break;
				case 1:
					M1ZL = amount;
					break;
				default:
					return;
			}
		}
		if (choice == 2) {
			cout << "Podaj wartosc monety: " << endl;
			cin >> value;
			cout << "Podaj ilosc monet: " << endl;
			cin >> amount;
			switch (value) {
				case 50:
					M50GR = amount;
					break;
				case 20:
					M20GR = amount;
					break;
				case 10:
					M10GR = amount;
					break;
				case 5:
					M5GR = amount;
					break;
				case 2:
					M2GR = amount;
					break;
				case 1:
					M1GR = amount;
					break;
				default:
					return;
			}
		}
	}

    void addMoney() {
		int choice;
		for (;;) {
			cout << "Wybierz co chcesz dodac: " << endl;
			cout << "1. Banknot" << endl;
			cout << "2. Moneta" << endl;
			cout << "0. Wyjscie" << endl;
			cout << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Wybrales banknoty." << endl;
				addBills();
			}
			if (choice == 2) {
				cout << "Wybrales monety." << endl;
				addCoins();
			}
			if (choice == 0) {
				return;
			}
		}
	}

	void checkout() {
		if (!open) {
			cout << "Kasa jest zamknieta!" << endl;
			return;
		}
		double checkOut;
		checkOut = (B200ZL * 200) + (B100ZL * 100) + (B50ZL * 50) + (B20ZL * 20) + (B10ZL * 10) + (M5ZL * 5) + (M2ZL * 2) + (M1ZL * 1) +
		           (M50GR * 0.5) + (M20GR * 0.2) + (M10GR * 0.1) + (M5GR * 0.05) + (M2GR * 0.02) + (M1GR * 0.01);
		int coins = int(checkOut);
		cout << "Stan kasy wynosi: " << coins << " zlotych i " << (checkOut - double(coins)) * 100 << " groszy." << endl;
	}
};

int main() {
    CashRegister cashRegister = *new CashRegister();
	cashRegister.openCash();
	cashRegister.addMoney();
	cashRegister.display();
	cashRegister.checkout();
	return 0;
}