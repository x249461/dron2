#include "Dron.hh"
void Dron::Ruch(PzG::LaczeDoGNUPlota &Lacze, int NumerDrona,
                Wektor3D ruch_kon) {
  Korpus.Przesun(ruch_kon);
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    Rotor[i].Przesun(ruch_kon);
  }
  this->Animacja(Lacze, NumerDrona);
  this->Zapisz(NumerDrona);
  Lacze.Rysuj();
  Aproksymacja.punkt_srodka = Korpus.ZwrocSrodek();
}
void Dron::Obrot(PzG::LaczeDoGNUPlota &Lacze, int NumerDrona) {
  double kat;
  std::cout << "Wprowadz kat obrotu > ";
  std::cin >> kat;
  Kat_Obrotu += kat;
  if (Kat_Obrotu >= 360)
    Kat_Obrotu -= 360;
  else if (Kat_Obrotu <= -360)
    Kat_Obrotu += 360;

  for (int klatka = 0; klatka < abs(kat); ++klatka) {
    Korpus.Obrot(1);
    for (int i = 0; i < ILOSC_ROTOROW; ++i) {
      Rotor[i].Obrot(1);
    }
    this->Animacja(Lacze, NumerDrona);
    this->Zapisz(NumerDrona);
    Lacze.Rysuj();
    usleep(20000);
  }
}

void Dron::Zapisz(int NumerDrona) {
  std::fstream PlikWy;
  std::string NazwaPliku;
  NazwaPliku = "Korpus";
  NazwaPliku.append(std::to_string(NumerDrona));
  NazwaPliku.append(".dat");
  PlikWy.open(NazwaPliku, std::fstream::out);
  Korpus.Zapisz(PlikWy);
  PlikWy.close();
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    NazwaPliku = "Rotor";
    NazwaPliku.append(std::to_string(NumerDrona));
    NazwaPliku.append("_");
    NazwaPliku.append(std::to_string(i));
    NazwaPliku.append(".dat");
    PlikWy.open(NazwaPliku, std::fstream::out);
    Rotor[i].Zapisz(PlikWy);
    PlikWy.close();
  }
}

void Dron::Inicjalizuj() {
  Korpus.Inicjalizuj();
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    Rotor[i].Inicjalizuj();
  }
  Rotor[0].UstawPolozenie(Wektor3D(5, 5, 7));
  Rotor[1].UstawPolozenie(Wektor3D(5, -5, 7));
  Rotor[2].UstawPolozenie(Wektor3D(-5, 5, 7));
  Rotor[3].UstawPolozenie(Wektor3D(-5, -5, 7));
  Aproksymacja.punkt_srodka = Korpus.ZwrocSrodek();
  Aproksymacja.promien = 10;
  Aproksymacja.wysokosc = 14;
}

void Dron::Animacja(PzG::LaczeDoGNUPlota &Lacze, int NumerDrona) {
  AktualizujRotory();
  Rotor[0].ObrotSmigiel(10);
  Rotor[1].ObrotSmigiel(-10);
  Rotor[2].ObrotSmigiel(-10);
  Rotor[3].ObrotSmigiel(10);

  this->Zapisz(NumerDrona);
  Lacze.Rysuj();
  usleep(1000);
}

void Dron::AktualizujRotory() {
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    Rotor[i].UstawOffset(Korpus[i]);
  }
}

void Dron::Przesun(Wektor3D przesuniecie) {
  Korpus.Przesun(przesuniecie);
  for (int i = 0; i < ILOSC_ROTOROW; ++i) {
    Rotor[i].Przesun(przesuniecie);
  }
  Aproksymacja.punkt_srodka = Korpus.ZwrocSrodek();
}