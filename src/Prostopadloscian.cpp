#include "Prostopadloscian.hh"

void Prostopadloscian::Inicjalizuj() {
  Punkt.push_back(Wektor3D(5, 5, 5));
  Punkt.push_back(Wektor3D(5, -5, 5));
  Punkt.push_back(Wektor3D(-5, 5, 5));
  Punkt.push_back(Wektor3D(-5, -5, 5));

  Punkt.push_back(Wektor3D(-5, 5, -5));
  Punkt.push_back(Wektor3D(-5, -5, -5));
  Punkt.push_back(Wektor3D(5, 5, -5));
  Punkt.push_back(Wektor3D(5, -5, -5));

  Srodek=(Wektor3D(0,0,0));
  
  Punkt_globalny = Punkt;
}
Prostopadloscian Prostopadloscian::operator+(Wektor3D Arg2) {
  for (long unsigned int i = 0; i < Punkt.size(); ++i) {
    Punkt_globalny[i] += Arg2;
  }
  Wektor_Trans = Wektor_Trans + Arg2;
  Srodek+=Arg2;
  return (*this);
}