#include "Scena.hh"
#include "Przeszkoda.hh"

/*!
 * \brief Funkcja inicjalizuje drona
 *
 * Funkcja inicjalizuje drona i zapisuje wspolrzedne jego elementow do plikow
 * \param[in] dron - wskaznik na obiekt ObiektSceny ktory jest dronem do
 * inicjalizacji \param[in] Indeks - indeks drona na liscie
 */
void InicjalizujDrona(std::shared_ptr<ObiektSceny> dron, int Indeks) {
  dron->Inicjalizuj();
  dron->Przesun(Wektor3D(Indeks * 15, Indeks * 15, Indeks * 15));
  dron->Zapisz(Indeks);
}
/*!
 * \brief Funkcja pozwala na inicjalizacje przeszkody
 *
 * Funkcja pozwala na inicjalizacje przeszkody oraz jej zapis do odpowiedniego
 * pliku \param[in] przeszkoda - wskaznik na ObiektSceny ktory jest przeszkoda
 * do inicjalizacji \param[in] Indeks - indeks przeszkody na liscie \param[in]
 * Lacze - PzG::LaczeDoGNUPlota do ktorego ma zosstac dodana nowa nazwa pliku
 * przeszkody
 */
void InicjalizujPrzeszkode(std::shared_ptr<ObiektSceny> przeszkoda, int Indeks,
                           PzG::LaczeDoGNUPlota &Lacze) {
  std::fstream PlikWy;
  std::string NazwaPliku;
  NazwaPliku = "Przeszkoda";
  NazwaPliku.append(std::to_string(Indeks));
  NazwaPliku.append(".dat");
  PlikWy.open(NazwaPliku, std::fstream::out);
  przeszkoda->Inicjalizuj(10, 20, 30);
  przeszkoda->Przesun(Wektor3D(50, 0, 0));
  przeszkoda->Zapisz(PlikWy);
  Lacze.DodajNazwePliku(NazwaPliku.c_str());
}

void Scena::StworzListeDrony() {
  for (int i = 0; i < ILOSC_DRONOW; ++i) {
    std::shared_ptr<Dron> dron;

    dron = std::make_shared<Dron>();
    Drony.push_back(dron);
    Obiekty.push_back(dron);
  }
}
void Scena::StworzListeObiekty() {
  for (int i = 0; i < ILOSC_PRZESZKOD; ++i) {
    std::shared_ptr<Przeszkoda> przeszkoda;

    przeszkoda = std::make_shared<Przeszkoda>();
    Obiekty.push_back(przeszkoda);
  }
}

void Scena::Inicjalizuj(PzG::LaczeDoGNUPlota &Lacze) {
  StworzListeDrony();
  StworzListeObiekty();

  int i = 0;
  for (std::shared_ptr<ObiektSceny> obiekt : Obiekty) {
    switch (obiekt->ID()) {
      case 1: {
        InicjalizujDrona(obiekt, i);
        break;
      }
      case 0: {
        InicjalizujPrzeszkode(obiekt, i, Lacze);
        break;
      }
    }
    ++i;
  }
  ItDrony = Drony.begin();
  ItObiekty = Obiekty.begin();
}

bool Scena::ZmienDrona() {
  std::advance(ItDrony, 1);
  if (ItDrony == Drony.end()) {
    ItDrony = Drony.begin();
    return true;
  }
  return false;
}

void Scena::ZmienObiekt() {
  std::next(ItObiekty);
  if (ItObiekty == Obiekty.end()) {
    ItObiekty = Obiekty.begin();
  }
}

bool Scena::CzyKolizja(std::shared_ptr<ObiektSceny> AktualnyDron) {
  for (std::shared_ptr<ObiektSceny> obiekt : Obiekty) {
    if (AktualnyDron == obiekt) {
    } else if (obiekt->CzyKolizja(AktualnyDron))
      return true;
  }
  return false;
}

void Scena::Ruch(PzG::LaczeDoGNUPlota &Lacze) {
  Wektor3D ruch_uz, ruch_kon;
  double kat;
  int ilosc_klatek;
  std::cout << "Wpisz ilosc jednostek poruszania sie > ";
  std::cin >> ruch_uz[0];
  ilosc_klatek = abs(ruch_uz[0]) * 4;
  std::cout << "Wpisz kat wznoszenia > ";
  std::cin >> kat;
  ruch_kon[0] =
      ruch_uz[0] * cos(this->ZwrocDrona()->ZwrocKatObrotu() * M_PI / 180);
  ruch_kon[1] =
      ruch_uz[0] * sin(this->ZwrocDrona()->ZwrocKatObrotu() * M_PI / 180);
  ruch_kon[2] = tan(kat * M_PI / 180) * abs(ruch_uz[0]);
  ruch_kon = ruch_kon / ilosc_klatek;
  for (int klatka = 0; klatka < ilosc_klatek; ++klatka) {
    this->ZwrocDrona()->Ruch(Lacze, this->Indeks(), ruch_kon);
    usleep(2000);
    if (this->CzyKolizja(this->ZwrocDrona())) {
      std::cout << "Wykryto Kolizje!" << std::endl;
      break;
    }
  }
}

void Scena::WyswietlDrony() {
  int i = 1;
  for (std::shared_ptr<Dron> dron : Drony) {
    std::cout << "Dron " << i << ".  ";
    std::cout << "Wspolrzedne: " << dron->ZwrocSrodek() << std::endl;
    ++i;
  }
  this->WybierzDrona();
}

void Scena::WybierzDrona() {
  int wybor;
  std::cout << "Twoj wybor > ";
  std::cin >> wybor;
  if (wybor > 0) {
    if (wybor > std::distance(Drony.begin(), Drony.end())) {
      std::cout << " Nie ma takiego drona!" << std::endl;
    } else {
      ItDrony = Drony.begin();
      std::advance(ItDrony, wybor - 1);
    }
  }
}