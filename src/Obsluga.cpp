#include "Obsluga.hh"
void WyswietlIloscObiektow() {
  std::cout << "Ilosc lacznie stworzonych obiektow klasy Wektor3D: ";
  std::cout << Wektor3D::ZwrocLacznaIloscWektorow() << std::endl;
  std::cout << "Ilosc istniejacych obiektow klasy Wektor3D: ";
  std::cout << Wektor3D::ZwrocIloscWektorow() << std::endl;
  std::cout << "Ilosc lacznie stworzonych obiektow klasy ObiektSceny: ";
  std::cout << ObiektSceny::ZwrocIloscStworzonych() << std::endl;
  std::cout << "Ilosc istniejacych obiektow klasy ObiektSceny: ";
  std::cout << ObiektSceny::ZwrocIloscIstniejacych() << std::endl;
}
void WyswietlMenu() {
  WyswietlIloscObiektow();
  std::cout << "o - obrot drona" << std::endl;
  std::cout << "j - lot na wprost" << std::endl;
  std::cout << "s - zmien drona" << std::endl;
  std::cout << "w - wyswietl menu" << std::endl << std::endl;
  std::cout << "k - koniec dzialania programu" << std::endl;
}
void UstawLacze(PzG::LaczeDoGNUPlota& Lacze) {
  std::string NazwaPliku;
  for (int i = 0; i < ILOSC_DRONOW; ++i) {
    NazwaPliku = "Korpus";
    NazwaPliku.append(std::to_string(i));
    NazwaPliku.append(".dat");
    Lacze.DodajNazwePliku(NazwaPliku.c_str());
    for (int j = 0; j < ILOSC_ROTOROW; ++j) {
      NazwaPliku = "Rotor";
      NazwaPliku.append(std::to_string(i));
      NazwaPliku.append("_");
      NazwaPliku.append(std::to_string(j));
      NazwaPliku.append(".dat");
      Lacze.DodajNazwePliku(NazwaPliku.c_str());
    }
  }
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresY(-50, 50);
  Lacze.UstawZakresX(-50, 50);
  Lacze.UstawZakresZ(-50, 50);
  Lacze.Inicjalizuj();
}

void WybierzDrona(Scena* const sc) {
  std::cout << "Aktualny wyselekcjonowanym dronem jest:" << std::endl;
  std::cout << "Dron " << sc->Indeks() + 1 << ".  ";
  std::cout << "Wspolrzedne: " << sc->ZwrocDrona()->ZwrocSrodek() << std::endl;

  std::cout << "0. Zaniechaj zmiany selekcji" << std::endl;
  sc->WyswietlDrony();
}
