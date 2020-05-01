#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "Obiekt_graf.hh"
/*!
 *\brief Klasa modeluje pojecie prostopadloscianu, bedacego Obiektem
 *graficznym
 */
class Prostopadloscian : public Obiekt_graf {
 public:
  /*!
   * \brief Metoda zwraca wartosc pola Srodek z klasy Obiekt_graf
   *
   * Metoda zwraca wartosc pola Srodek z klasy Obiekt_graf
   * \return Wartosc pola Srodek
   */
  Wektor3D ZwrocSrodek() { return Srodek; }
  /*!
   *\brief Metoda inicjaliuzuje wierzcholki prostopadloscianu do zadanych
   * wartosci
   *
   * Metoda inicjaliuzuje wierzcholki prostopadloscianu do zadanych
   * wartosci
   */
  void Inicjalizuj();
  /*!
   *\brief Przeciazenie operatora dodawania dla klasy Prostopadloscian i
   * Wektor3D
   *
   * Przeciazenie pozwala na przesuniecie prostopadloscianu o zadany wektor
   * \param Arg2 - Wektor3D przesuniecia
   * \return Prostopadloscian po przesuniecie o wektor Arg2
   */
  Prostopadloscian operator+(Wektor3D Arg2);
  /*!
   *\brief Przeciazenie pozwala na dostep do wspolrzednych poszczegolnych
   * wierzcholkow prostopadloscianu.
   *
   * Przeciazenie pozwala na dostep do wspolrzednych poszczegolnych
   * wierzcholkow prostopadloscianu.
   * \param Ind - Indeks wierzcholka
   * \return Wektor3D danego wierzcholka
   */
  Wektor3D operator[](int Ind) { return Punkt[Ind]; }
};
#endif