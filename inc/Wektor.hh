#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <assert.h>
#include <cmath>
#include <iomanip>
#include <iostream>

/*!
 * \file
 * \brief Plik zawiera definicje szablonu klasy Wektor<>
 */

/*!
 * \brief Szablon klasy Wektor<>
 *
 * Szablon klasy Wektor<> pozwala na stworzenie wektora w dowolnym wymiarze.
 * Przechowuje on ilosc wspolrzednych rowna danemu wymiarowi. Pozwala na
 * dokonywanie dzialan + i - na Wektor<> oraz obliczania dlugosci wektorow.
 */
template <int Wymiar>
class Wektor {
  /*!
   * \brief Pole opisuje wspolrzedne poszczegolnych skladowych wektora
   *
   * Pole opsiuej wspolrzedne poszczegolnych skladowych wektora.
   * Wielosc tablicy uzalezniona jest od wymiaru w jakim ma byc uzywany wektor.
   */
  double Wsp[Wymiar];
  /*!
   *\brief Pole przechowuje ilosc uzywanych obiektow klasy Wektor3D
   *
   * Pole przechowuje ilosc uzywanych obiektow klasy Wektor3D
   */
  static int IloscWektorow;
  /*!
   *\brief Pole przechowuje ilosc stworzonych obiektow klasy Wektor3D
   *
   * Pole przechowuje ilosc stworzonych obiektow klasy Wektor3D
   */
  static int LacznaIlosc;

 public:
  /*!
   *\brief Konstruktor domyslny
   *
   * Konstruktor domyslny, ustawia wartosci wszystkich skladowych na 0.
   */
  Wektor() {
    for (int i = 0; i < Wymiar; i++) {
      this->Wsp[i] = 0;
    }
    ++IloscWektorow;
    ++LacznaIlosc;
  }
  /*!
   *\brief Konstruktor kopiujacy
   *
   * Konstruktor kopiujacy dla klasy Wektor3D
   */
  Wektor(const Wektor &obj) {
    ++IloscWektorow;
    ++LacznaIlosc;
    for (int i = 0; i < Wymiar; ++i) {
      Wsp[i] = obj[i];
    }
  }
  /*!
   *\brief Konstruktor parametryczny dla obiektu Wektor3D
   *
   *Konstruktor parametryczny dla obiektu Wektor3D
   */
  Wektor(int x, int y, int z) {
    this->Wsp[0] = x;
    this->Wsp[1] = y;
    this->Wsp[2] = z;
    ++IloscWektorow;
    ++LacznaIlosc;
  }
  /*!
   *\brief Destruktor obiektu Wektor
   *
   * Destruktor obiektu Wektor
   */
  ~Wektor() { --IloscWektorow; }
  /*!
   *\brief Metoda zwraca ilosc aktualnie uzywanych obiektow klasy Wektor
   *
   * Metoda zwraca ilosc aktualnie uzywanych obiektow klasy Wektor
   * \return Zwraca wartosc pola IloscWektorow
   */
  static int ZwrocIloscWektorow() { return IloscWektorow; }
  /*!
   *\brief Metoda zwraca ilosc stworzonych obiektow klasy Wektor
   *
   * Metoda zwraca ilosc stworzonych obiektow klasy Wektor
   * \return Zwraca wartosc pola LacznaIlosc
   */
  static int ZwrocLacznaIloscWektorow() { return LacznaIlosc; }
  /*!
   * \brief Przeciazenie operatora [] dla Wektor<>
   *
   * Przeciazenie pozwala na szybki dostep do zmiennej
   * reprezentujacej wspolrzedne wektora
   * \param Ind - index zmiennej
   *
   * \return Zwraca wartosc pola Wsp[Ind]
   */
  double operator[](int Ind) const {
    assert(Ind >= 0 && Ind < Wymiar);
    return this->Wsp[Ind];
  }
  /*!
   * \brief Przeciazenie operatora [] dla Wektor<> wraz z referencja
   *
   * Przeciazenie pozwala na latwa zmiane pojedynczej wspolrzednej wektora
   * poprzez referencje.
   * \param Ind - index zmiennej
   *
   * \return Zwraca referencje do pola Wsp[Ind]
   */
  double &operator[](int Ind) {
    assert(Ind >= 0 && Ind < Wymiar);
    return this->Wsp[Ind];
  }
  /*!
   *\brief Metoda obllicza dlugosc Wektor<>
   *
   * Metoda oblicza dlugosc wektora w dowolnym wymiarze
   * \return Metoda zwraca dlugosc wektora w postaci liczby typu double
   */
  double Dlugosc() {
    double suma = 0;
    for (int i = 0; i < Wymiar; i++) {
      suma += (Wsp[i] * Wsp[i]);
    }
    return sqrt(suma);
  }
  /*!
   *\brief Przeciazenie operatora + dla Wektor<>
   *
   * Przeciazenie operatora + dla klasy Wektor<> pozwala na dodawanie
   * do siebie wektorow tego samego wymiaru.
   * \param Arg2 - drugi skladnik dodawania
   * \return Przeciazenie zwraca Wektor<Wymiar> bedacy wynikiem dodawania
   */
  Wektor<Wymiar> operator+(Wektor<Wymiar> Arg2) const {
    Wektor<Wymiar> temp;
    for (int i = 0; i < Wymiar; i++) {
      temp[i] = this->Wsp[i] + Arg2[i];
    }
    return temp;
  }
  /*!
   *\brief Przeciazenie oepratora += dla Wektor<>
   *
   * Przeciazenie operatora += dla Wektor<> pozwala na wykonywanie
   * operacji typu Wektor<Wymiar> += Wektor<Wymiar>.
   * \param Arg2 - skladnik ktory ma zostac dodany
   * \return Przeciazenie zwraca wynik dodawania.
   */
  Wektor<Wymiar> &operator+=(const Wektor<Wymiar> &Arg2) {
    for (int i = 0; i < Wymiar; i++) this->Wsp[i] += Arg2[i];
    return *this;
  }
  /*!
   *\brief Przeciazenie operatora - dla Wektor<>
   *
   * Przeciazenie operatora - dla klasy Wektor<> pozwala na odejmowanie
   * od siebie wektorow tego samego wymiaru.
   * \param Arg2 - drugi skladnik odejmowania
   * \return Przeciazenie zwraca Wektor<Wymiar> bedacy wynikiem odejmowania
   */
  Wektor<Wymiar> operator-(Wektor<Wymiar> Arg2) const {
    Wektor<Wymiar> temp;
    for (int i = 0; i < Wymiar; i++) {
      temp[i] = this->Wsp[i] - Arg2[i];
    }
    return temp;
  }
  /*!
   *\brief Przeciazenie operatora / dla Wektor<>
   *
   * Przeciazenie operatora / dla klasy Wektor<> pozwala na dzielenie
   * Wektora przez liczbe calkowita.
   * \param Arg2 - dzielnik
   * \return Przeciazenie zwraca Wektor<Wymiar> bedacy wynikiem dzielenia
   */
  Wektor<Wymiar> operator/(int Arg2) const {
    Wektor<Wymiar> temp;
    for (int i = 0; i < Wymiar; i++) {
      temp[i] = this->Wsp[i] / Arg2;
    }
    return temp;
  }
};

template <int Wymiar>
int Wektor<Wymiar>::IloscWektorow = 0;

template <int Wymiar>
int Wektor<Wymiar>::LacznaIlosc = 0;

/*!
 *\brief Przeciazenie dla operatora >> dla klasy Wektor<>
 *
 * Przeciazenie pozwala na wpisanie przez uzytkownika wspolrzednych
 * wektora. Przyjmowant format to liczby oddzielone znakiem bialym.
 * \param Strm - strumien wejsciowy.
 * \param Wek - Wektor<> do ktorego maja zostac zapisane wspolrzedne.
 * \return Przeciazenie zwraca zawartosc strumienia Strm.
 */
template <int Wymiar>
inline std::istream &operator>>(std::istream &Strm, Wektor<Wymiar> &Wek) {
  for (int i = 0; i < Wymiar; i++) {
    Strm >> Wek[i];
    if (Strm.fail()) return Strm;
  }
  return Strm;
}

/*!
 * \brief Przeciazenie operatora << dla klasy Wektor<>
 *
 * Przeciazenie pozwala na wypisanie wspolrzednych Wektor<> w formacie
 * [Wsp1,Wsp2,...]
 * \param Strm - strumien wyjsciowy
 * \param Wek - Wektor<> ktorego wspolrzedne maja zostac wypisane
 * \return Przeciazenie zwraca zawartosc strumienia Strm
 */
template <int Wymiar>
inline std::ostream &operator<<(std::ostream &Strm, const Wektor<Wymiar> &Wek) {
  Strm << std::fixed << std::setprecision(1) << "[ ";
  for (int i = 0; i < Wymiar; i++) {
    Strm << Wek[i] << ", ";
  }
  Strm << "]";
  return Strm;
}

#endif
