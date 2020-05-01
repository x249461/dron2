#include "Przeszkoda.hh"
void Przeszkoda::Inicjalizuj(int dlugosc, int szerokosc, int wysokosc) {
    Punkt.push_back(Wektor3D(dlugosc/2, szerokosc/2, wysokosc/2));
    Punkt.push_back(Wektor3D(dlugosc/2, -szerokosc/2, wysokosc/2));
    Punkt.push_back(Wektor3D(-dlugosc/2, szerokosc/2, wysokosc/2));
    Punkt.push_back(Wektor3D(-dlugosc/2, -szerokosc/2, wysokosc/2));

    Punkt.push_back(Wektor3D(-dlugosc/2, szerokosc/2, -wysokosc/2));
    Punkt.push_back(Wektor3D(-dlugosc/2, -szerokosc/2, -wysokosc/2));
    Punkt.push_back(Wektor3D(dlugosc/2, szerokosc/2, -wysokosc/2));
    Punkt.push_back(Wektor3D(dlugosc/2, -szerokosc/2, -wysokosc/2));


  Srodek = (Wektor3D(0, 0, 0));
  SzerokoscX = Punkt[1][0] - Punkt[2][0];
  DlugoscY = Punkt[0][1] - Punkt[1][1];
  WysokoscZ = Punkt[3][2] - Punkt[4][2];
  Punkt_globalny = Punkt;
}
void Przeszkoda::Zapisz(std::ostream &Strm) {
  for (long unsigned int i = 0; i < Punkt_globalny.size(); i++) {
    if (i % 2 == 0) Strm << std::endl;
    for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[i][j];
    }
    Strm << std::endl;
  }
  Strm << std::endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      Strm << std::setw(25) << std::fixed << std::setprecision(10)
           << Punkt_globalny[i][j];
    }
    Strm << std::endl;
  }
}
void Przeszkoda::Przesun(Wektor3D Wek) {
  for (long unsigned int i = 0; i < Punkt_globalny.size(); ++i) {
    Punkt_globalny[i] += Wek;
  }
  Srodek += Wek;
  Wektor_Trans += Wek;
}