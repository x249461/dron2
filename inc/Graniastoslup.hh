#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
#include "Prostopadloscian.hh"
/*!
 *\brief Klasa modeluje pojecie Graniastoslupa
 */

class Graniastoslup : public Obiekt_graf {
 
  /*!
   * \brief Pole przechowuje przesuniecie obiektu wzgledem srodka ukladu
   * wspolrzednych
   *
   * Pole przechowuje przesuniecie obiektu wzgledem srodka ukladu wspolrzednych
   */
  Wektor3D offset;

 public:
  /*!
   * \brief Metoda pozwala na inicjalizacje obiektu Graniastoslup o ustalonych
   * wierzcholkach
   *
   * Metoda pozwala na inicjalizacje obiektu Graniastoslup o ustalonych
   * wierzcholkach
   */
  void Inicjalizuj();
  /*!
   * \brief Metoda pozwala na poczatkowego ustawienie obiektu
   *
   * Metoda pozwala na poczatkowego ustawienei obiektu z uwzglednieniem jego
   * przesuniecia wzgledem srodka ukladu wspolrzednych
   * \param offset - oddalenie od srodka ukladu wspolrzednych
   */
  void UstawPolozenie(Wektor3D offset);
  /*!
   * \brief Metoda pozwala na obrot obiektu wzgledem swojego srodka
   *
   * Metoda pozwala na obrot obiektu wzgledem swojego srodka o zadany kat
   * \param kat - kat obrotu
   */
  void ObrotSmigiel(double kat);
  /*!
   * \brief Metoda pozwala na ustawienie pola offset
   *
   * Metoda pozwala na ustawienie pola offset, oraz wykonuje operacje
   * offset[2]+=2 \param Arg - offset ktory ma zostac ustawiony
   */
  void UstawOffset(Wektor3D Arg);
  /*!
   * \brief Przeciazenie pozwala na dodanie Wektor3D do kazdego wierzcholka
   *
   * Przeciazenie pozwala na dodanie Wektor3D do kazdego wierzcholka. Pozwala to
   * na przesuniecie bryly o zadany wektor.
   * \param Arg2 - wektor przesuniecia
   * \return Graniastoslup przesuniety o wektor Arg2
   */
  Graniastoslup operator+(Wektor3D Arg2);
};
#endif