#include "Obiekt_graf.hh"

void Obiekt_graf::Przesun(Wektor3D Wek) {
  for (long unsigned int i = 0; i < Punkt_globalny.size(); ++i) {
    Punkt_globalny[i] += Wek;
  }
  Srodek+= Wek;
  Wektor_Trans += Wek;
}
void Obiekt_graf::Obrot(double Kat) {
  Macierz<3> Mac_Obrotu = MacierzZ(Kat);
  KatObrotu += Kat;
  if (KatObrotu >= 360)
    KatObrotu -= 360;
  else if (KatObrotu <= -360)
    KatObrotu += 360;
  for (long unsigned int i = 0; i < Punkt_globalny.size(); ++i) {
    Punkt[i] = Mac_Obrotu * Punkt[i];
    Punkt_globalny[i] = Punkt[i] + Wektor_Trans;
  }
}
void Obiekt_graf::Zapisz(std::ostream &Strm) {
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
Obiekt_graf Obiekt_graf::operator+(Wektor3D Arg2) {
  for (long unsigned int i = 0; i < Punkt.size(); ++i) {
    Punkt_globalny[i] += Arg2;
  }
  return (*this);
}