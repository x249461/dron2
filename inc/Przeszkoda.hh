#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include "Prostopadloscian.hh"
/*!
 * \brief Klasa modeluje pojecie przeszkody jako prostopadloscianu.
 *
 * Klasa modeluje pojecie przeszkody jako prostopadloscianu bedacego obiektem na
 * scenie.
 */
class Przeszkoda : public ObiektSceny {
  /*!
   *\brief Pole przechowuje oryginalne punkty poszczegolnych wierzcholkow
   *
   * Pole przechowuje oryginalne punkty poszczegolnych wierzcholkow
   */
  std::vector<Wektor3D> Punkt;
  /*!
   *\brief Pole przechowuje punkty poszczegolnych wierzcholkow w
   * globalnym ukladzie odniesienia
   *
   * Pole przechowuje punkty poszczegolnych wierzcholkow w
   * globalnym ukladzie odniesienia
   */
  std::vector<Wektor3D> Punkt_globalny;
  /*!
   *\brief Pole przechowuje wektor o jaki sa przesuniete wierzcholki w
   * stosunku do lokalnego ukladu odniesienia.
   *
   * Pole przechowuje wektor o jaki sa przesuniete wierzcholki w
   * stosunku do lokalnego ukladu odniesienia.
   */
  Wektor3D Wektor_Trans = Wektor3D();
  /*!
   *\brief Pole przechowuje kat o jaki figura jest obrocona
   *
   * Pole przechowuje kat o jaki figura jest obrocona.
   */
  double KatObrotu = 0;

 public:
  /*!
   * \brief Konstruktor domyslny klasy Przeszkoda
   *
   * Konstruktor domyslny klasy Przeszkoda, ustawia pole TypID na wartosc 0
   * oznaczajace przeszkode
   */
  Przeszkoda() { TypID = 0; }
  /*!
   * \brief Metoda inicjalizuje przeszkode o zadanych wymiarach
   *
   * Metoda inicjalizuje przeszkode o zadanych wymiarach o srodku w punkcie
   * (0,0,0)
   */
  void Inicjalizuj(int dlugosc, int szerokosc, int wysokosc);
  /*!
   * \brief Metoda pozwala na przesuniecie przeszkody o zadany Wektor3D
   *
   * Metoda pozwala na przesuniecie przeszkody o zadany Wektor3D wraz z
   * przesunieciem wspolrzednych zmiennej Srodek
   */
  void Przesun(Wektor3D Wek);
  /*!
   * \brief Metoda pozwala na zapis wspolrzednych przeszkody na strumien
   * wyjsciowy
   *
   * Metoda pozwala na zapis wspolrzednych przeszkody na strumien wyjsciowy Strm
   * \param[in] Strm - strumien wyjsciowy na ktory maja zostac wypisane
   * wspolrzedne przeszkody
   */
  void Zapisz(std::ostream &Strm);
};
#endif