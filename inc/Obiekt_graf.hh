#ifndef OBIEKT_GRAF_HH
#define OBIEKT_GRAF_HH
#include <fstream>
#include <vector>
#include "Macierz3x3.hh"
#include "ObiektSceny.hh"
/*!
 *\brief Klasa modeluje pojecie obiektu graficznego w 3 wymiarach
 */
class Obiekt_graf {
 protected:
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
  /*!
   * \brief Pole przechowuje wspolrzedne srodka figury
   *
   * Pole przechowuje wspolrzedne srodka figury w ukladzie globalnym
   */
  Wektor3D Srodek;

 public:
  /*!
   *\brief Metoda przesuwa obiekt o zadany wektor
   *
   * Metoda przesuwa obiekt o zadany Wektor3D
   * \param Wek - Wektor przesuniecia
   */
  void Przesun(Wektor3D Wek);
  /*!
   *\brief Metoda obraca obiekt o zadany kat
   *
   * Metoda obraca obiekt o zadany kat w lokalnym ukladzie odniesienia
   * po czym dokonuje zmian w globalnym ukladzie odniesienia. Wektor
   * przesuniecia jest dodawany do pola Wektor_Trans.
   * \param Kat - Kat obrotu w stopniach
   */
  void Obrot(double Kat);
  /*!
   *\brief Metoda pozwala na zapis wierzcholkow do strumienia wyjsciowego
   *
   * Metoda pozwala na zapis wierzcholkow do strumienia wyjsciowego.
   * Formatowanie jest przystosowane dla programu GnuPlot
   * \param Strm - strumien wyjsciowy
   */
  void Zapisz(std::ostream &Strm);
  /*!
   *\brief Przeciazenie operatora + dla Obiekt_graf i Wektor3D
   *
   * Przeciazenie pozwala na dodanie wektora do Obiektu, powodujac
   * tym jego przesuniecie o ten wektor
   * \param Arg2 - Wektor przesunienia
   * \return Obiekt_graf po przesuniecie
   */
  Obiekt_graf operator+(Wektor3D Arg2);
};
#endif