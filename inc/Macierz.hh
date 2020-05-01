#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor3D.hh"

/*!
 * \file
 * \brief Plik zawiera definicje szablonu klasy Macierz<>
 */

/*!
 * \brief Szablon klasy Macierz<>
 *
 * Szablon klasy Macierz<> pozwala na stworzenie macierzy kwadratowej
 * o dowolnych wymiarach.
 */
template <int Wymiar>
class Macierz {
  /*!
   *\brief Pole Wartosc przedstawia wartosci macierzy w danym jej miejscu
   */
  double Wartosc[Wymiar][Wymiar];

 public:
  /*!
   *\brief Konstruktor domyslny
   *
   * Konstruktor domyslny dla klasy Macierz<> tworzy macierz jednostkowa
   */
  Macierz() {
    for (int i = 0; i < Wymiar; i++) {
      for (int j = 0; j < Wymiar; j++) {
        Wartosc[i][j] = 0;
        if (i == j) Wartosc[i][j] = 1;
      }
    }
  }
  /*!
   * \brief Przeciazenie operatora funkcyjnego () dla klasy Macierz<>
   *
   * Przeciazenie operatora () pozwala na latwe otrzymanie wartosci macierzy
   * znajdujacej sie pod danym indeksem
   * \param Wierz - wiersz wartosci ktora chcemy otrzymac
   * \param Kolumna - kolumna wartosci ktora chcemy otrzymac
   *
   * \return Przeciazenie zwraca wartosc macierzy w zadanym wierszu i kolumnie.
   */
  double operator()(int Wiersz, int Kolumna) const {
    assert(Wiersz >= 0 && Wiersz < Wymiar && Kolumna >= 0 && Kolumna < Wymiar);
    return this->Wartosc[Wiersz][Kolumna];
  }
  /*!
   * \brief Przeciazenie operatora funkcyjnego () dla Macierz<>
   *
   * Przeciazenie operatora () pozwala na latwe modyfikowanie wartosci
   * macierzy znajdujacej sie pod danym indeksem
   * \param Wierz - wiersz wartosci ktora chcemy zmienic
   * \param Kolumna - kolumna wartosci ktora chcemy zmienic
   *
   * \return Przeciazenie zwraca referencje wartosci macierzy w zadanym
   * wierszu i kolumnie.
   */
  double &operator()(int Wiersz, int Kolumna) {
    assert(Wiersz >= 0 && Wiersz < Wymiar && Kolumna >= 0 && Kolumna < Wymiar);
    return this->Wartosc[Wiersz][Kolumna];
  }
  /*!
   * \brief Przeciazenie operatora mnozenia dla klasy Macierz<>
   *
   * Przeciazenie ma na celu umozliwic mnozenie macierzy przez wektor
   * o takich samych wymiarach.
   * \param Arg2 - Wektor<> przez ktory mnozymy macierz
   *
   * \return Wektor<> bedacy wynikiem mnozenia.
   */
  Wektor<Wymiar> operator*(Wektor<Wymiar> const &Arg2) const {
    Wektor<Wymiar> temp;
    double suma;
    for (int i = 0; i < Wymiar; i++) {
      for (int j = 0; j < Wymiar; j++) {
        suma = 0;
        for (int k = 0; k < Wymiar; k++) {
          suma += (*this)(i, k) * Arg2[k];
        }
        temp[i] = suma;
      }
    }
    return temp;
  }
  /*!
   *\brief Przeciazenie operatora * dla mnozenia macierzy
   *
   * Przeciazenie operatora * dla mnozenia macierzy pozwala na
   * mnozenie przez siebie instancji klasy Macierz<> o tych samych
   * wymiarach.
   * \param Arg2 - drugi skladnik mnozenia
   * \return Przeciazenie zwraca Macierz<> bedaca wynikiem mnozenia.
   */
  Macierz<Wymiar> operator*(Macierz<Wymiar> const &Arg2) {
    Macierz<Wymiar> temp;
    double suma;
    for (int i = 0; i < Wymiar; i++) {
      for (int j = 0; j < Wymiar; j++) {
        suma = 0;
        for (int k = 0; k < Wymiar; k++) {
          suma += (*this)(i, k) * Arg2(k, j);
        }
        temp(i, j) = suma;
      }
    }
    return temp;
  }
};

/*!
 *\brief Przeciazenie operatora << dla klasy Macierz<>
 *
 * Przeciazenie pozwala na wypisanie wartosci obiektu Macierz<>.
 * \param Strm - strumien wyjsciowy
 * \param Mac - Macierz<> ktorej wartosci maja zostac wypisane
 */
template <int Wymiar>
inline std::ostream &operator<<(std::ostream &Strm,
                                const Macierz<Wymiar> &Mac) {
  Strm << std::endl;
  for (int i = 0; i < Wymiar; i++) {
    for (int j = 0; j < Wymiar; j++) {
      Strm << std::setw(20) << Mac(i, j) << " ";
    }
    Strm << std::endl;
  }
  Strm << std::endl;
  return Strm;
}

#endif
