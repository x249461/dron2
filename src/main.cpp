#include "Obsluga.hh"
#include "Scena.hh"
#include "lacze_do_gnuplota.hh"

int main() {
  PzG::LaczeDoGNUPlota Lacze;  //  Deklaracje zmiennych
  Scena *sc = new Scena(Lacze);
  char wybor;

  UstawLacze(Lacze);  // Ustawienie parametrow lacza
  Lacze.Inicjalizuj();
  Lacze.Rysuj();

  WyswietlMenu();

  while (1) {
    std::cout << "Twoj wybor > ";
    std::cin >> wybor;
    switch (wybor) {
      case 'o': {
        sc->ZwrocDrona()->Obrot(Lacze, sc->Indeks());
        Lacze.Rysuj();
        break;
      }
      case 'j': {
        sc->Ruch(Lacze);
        Lacze.Rysuj();
        break;
      }
      case 's': {
        WybierzDrona(sc);
        break;
      }
      case 'w': {
        WyswietlMenu();
        break;
      }
      case 'k': {
        delete sc;
        WyswietlIloscObiektow();
        return 0;
      }
      default: {
        std::cout << "Niepoprawny wybor" << std::endl;
      }
    }
  }
}
