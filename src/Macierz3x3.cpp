#include "Macierz3x3.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz3x3, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Macierz3x3 MacierzX(double kat) {
  Macierz3x3 MacierzRotacji = Macierz3x3();

  kat = kat * M_PI / 180.0;

  MacierzRotacji(0, 0) = 1;
  MacierzRotacji(0, 1) = 0;
  MacierzRotacji(0, 2) = 0;

  MacierzRotacji(1, 0) = 0;
  MacierzRotacji(1, 1) = cos(kat);
  MacierzRotacji(1, 2) = -sin(kat);

  MacierzRotacji(2, 0) = 0;
  MacierzRotacji(2, 1) = sin(kat);
  MacierzRotacji(2, 2) = cos(kat);

  return MacierzRotacji;
}
Macierz3x3 MacierzY(double kat) {
  Macierz3x3 MacierzRotacji;
  kat = kat * M_PI / 180.0;

  MacierzRotacji(0, 0) = cos(kat);
  MacierzRotacji(0, 1) = 0;
  MacierzRotacji(0, 2) = sin(kat);

  MacierzRotacji(1, 0) = 0;
  MacierzRotacji(1, 1) = 1;
  MacierzRotacji(1, 2) = 0;

  MacierzRotacji(2, 0) = -sin(kat);
  MacierzRotacji(2, 1) = 0;
  MacierzRotacji(2, 2) = cos(kat);

  return MacierzRotacji;
}
Macierz3x3 MacierzZ(double kat) {
  Macierz3x3 MacierzRotacji;
  kat = kat * M_PI / 180.0;

  MacierzRotacji(0, 0) = cos(kat);
  MacierzRotacji(0, 1) = -sin(kat);
  MacierzRotacji(0, 2) = 0;

  MacierzRotacji(1, 0) = sin(kat);
  MacierzRotacji(1, 1) = cos(kat);
  MacierzRotacji(1, 2) = 0;

  MacierzRotacji(2, 0) = 0;
  MacierzRotacji(2, 1) = 0;
  MacierzRotacji(2, 2) = 1;

  return MacierzRotacji;
}