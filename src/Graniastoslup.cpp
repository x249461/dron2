#include "Graniastoslup.hh"

void Graniastoslup::Inicjalizuj() {
  Punkt.push_back(Wektor3D(4, 0, 2));
  Punkt.push_back(Wektor3D(1, -3, 2));
  Punkt.push_back(Wektor3D(2, 3, 2));
  Punkt.push_back(Wektor3D(-2, -3, 2));
  Punkt.push_back(Wektor3D(-1, 3, 2));
  Punkt.push_back(Wektor3D(-4, 0, 2));

  Punkt.push_back(Wektor3D(4, 0, -2));
  Punkt.push_back(Wektor3D(1, -3, -2));
  Punkt.push_back(Wektor3D(2, 3, -2));
  Punkt.push_back(Wektor3D(-2, -3, -2));
  Punkt.push_back(Wektor3D(-1, 3, -2));
  Punkt.push_back(Wektor3D(-4, 0, -2));
  Punkt_globalny = Punkt;
}

void Graniastoslup::ObrotSmigiel(double kat) {
  Macierz<3> Mac_Obrotu = MacierzZ(kat);
  for (long unsigned int i = 0; i < Punkt.size(); ++i) {
    this->Punkt[i] = this->Punkt[i] - this->offset;
    this->Punkt[i] = Mac_Obrotu * this->Punkt[i];
    this->Punkt[i] = this->Punkt[i] + this->offset;
    Punkt_globalny[i] = Punkt[i] + Wektor_Trans;
  }
}
void Graniastoslup::UstawOffset(Wektor3D Arg) {
  offset = Arg;
  offset[2] += 2;
}
void Graniastoslup::UstawPolozenie(Wektor3D offset) {
  for (long unsigned int i = 0; i < Punkt.size(); ++i) {
    this->Punkt[i] += offset;
  }
  this->Punkt_globalny = this->Punkt;
  this->offset = offset;
}
Graniastoslup Graniastoslup::operator+(Wektor3D Arg2) {
  for (long unsigned int i = 0; i < Punkt.size(); ++i) {
    Punkt_globalny[i] += Arg2;
  }
  Wektor_Trans = Wektor_Trans + Arg2;
  return (*this);
}