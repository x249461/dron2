#ifndef OBIEKT_SCENY_HH
#define OBIEKT_SCENY_HH
#include <memory>
#include "Walec.hh"
/*!
 * \brief Klasa modeluje pojecie Obiektu bedacego czescia sceny
 *
 * Klasa modeluje pojecie Obiektu bedacego czescia sceny. Jest to dron oraz
 * przeszkoda
 */
class ObiektSceny {
  /*!
   * \brief Pole statyczne przechwouje informacje o ilosci istniejacych obiektow
   * klasy ObiektSceny
   */
  static int IloscIstniejacych;
  /*!
   * \brief Pole statyczne przechwouje informacje o ilosci lacznie stworzonych
   * obiektow klasy ObiektSceny
   */
  static int IloscStworzonych;

 protected:
  /*!
   * \brief Pole sluzy do identyfikacji klasy pochodnej
   *
   * Pole sluzy do identyfikacji klasy pochodnej\n
   * 0-Przeszkoda\n
   * 1-Dron\n
   */
  int TypID;
  /*!
   * \brief Pole przechowuje wspolrzedne srodka obiektu
   *
   * Pole przechowuje wspolrzedne srodka obiektu w globalnym ukladzie
   * wspolrzednych
   */
  Wektor3D Srodek;
  /*!
   * \brief Pole przechowuje dane walca aproksymujacego obwod drona
   *
   * Pole przechwouje strukture Walec, ktora zawiera promien, wysokosc oraz
   * punkt srodka aproksymacji obwodu drona
   */
  Walec Aproksymacja;
  /*!
   * \brief Pole przechowuje informacje o tym jak szeroka jest figura w
   * plaszczyznie X
   */
  double SzerokoscX;
  /*!
   * \brief Pole przechowuje informacje o tym jak dluga jest fiura w
   * plaszczyznie Y
   */
  double DlugoscY;
  /*!
   * \brief Pole przechowuje informacje o tym jak wysoka jest figura w
   * plaszczyznie Z
   */
  double WysokoscZ;

 public:
  /*!
   * \brief Konstruktor domyslny klasy ObiektSceny
   *
   * Konstruktor domyslny klasy ObiektSceny, zwieksza ilosc pola
   * IloscIstniejacych oraz IloscStworzonych
   */
  ObiektSceny() {
    ++IloscIstniejacych;
    ++IloscStworzonych;
  }
  /*!
   * \brief Destruktor klasy ObiektSceny
   *
   * Destruktor klasy ObiektSceny. Zmniejsza wartosc pola IloscIstniejacych.
   */
  ~ObiektSceny() { --IloscIstniejacych; }
  /*!
   * \brief Konstruktor kopiujacy klasy ObiektSceny
   */
  ObiektSceny(ObiektSceny const &obj) { ++IloscIstniejacych; }
  /*!
   * \brief Metoda sprawdza czy przekazany do niej ObiektSceny koliduje z danym
   * obiektem
   *
   * Metoda sprawdza czy przekazany do niej ObiektSceny koliduje z danym
   * obiektem.
   * \param[in] AktualnyDron - Wskaznik do klasy ObiektSceny do
   * sprawdzenia czy nastapila z nim kolizja
   * \retval true - obiekty koliduja ze soba
   * \retval false - obiekty nie koliduja ze soba
   */
  bool CzyKolizja(std::shared_ptr<ObiektSceny> AktualnyDron);
  /*!
   * \brief Metoda pozwala na zwrocenie pola TypID
   *
   * Metoda pozwala na zwrocenie pola TypID
   * \return wartosc TypID
   */
  int ID() const { return TypID; }
  /*!
   * \brief Metoda pozwala na wybor odpowiedniej metody zapisu w klasach
   * pochodnych
   *
   *  Metoda pozwala na wybor odpowiedniej metody zapisu w klasach pochodnych
   */
  virtual void Zapisz(int Numer) {}
  /*!
   * \brief Metoda pozwala na wybor odpowiedniej metody zapisu w klasach
   * pochodnych
   *
   *  Metoda pozwala na wybor odpowiedniej metody zapisu w klasach pochodnych
   */
  virtual void Zapisz(std::ostream &Strm) {}
  /*!
   * \brief Metoda pozwala na uzyskanie dostepu do metody Inicjalizuj w klasach
   * pochodnych
   *
   * Metoda pozwala na uzyskanie dostepu do metody Inicjalizuj w klasie
   * pochodnej Dron
   */
  virtual void Inicjalizuj() {}
  /*!
   * \brief Metoda pozwala na uzyskanie dostepu do metody Inicjalizuj w klasach
   * pochodnych
   *
   * Metoda pozwala na uzyskanie dostepu do metody Inicjalizuj w klasie
   * pochodnej Przeszkoda
   */
  virtual void Inicjalizuj(int szerokosc, int dlugosc, int wysokosc) {}
  /*!
   * \brief Metoda pozwala na uzyskanie dostepu do metody Przesun w klasach
   * pochodnych
   *
   * Metoda pozwala na uzyskanie dostepu do metody Przesun w klasach
   * pochodnych
   */
  virtual void Przesun(Wektor3D wektor) {}
  /*!
   * \brief Metoda zwraca wartosc pola Srodek
   *
   * Metoda zwraca wartosc pola Srodek
   * \return Wartosc pola Srodek
   */
  virtual Wektor3D ZwrocSrodek() { return Srodek; }
  /*!
   * \brief Metoda zwraca wartosc pola SzerokoscX
   *
   * Metoda zwraca wartosc pola SzerokoscX
   * \return Wartosc pola SzerokoscX
   */
  double ZwrocSzerokoscX() { return SzerokoscX; }
  /*!
   * \brief Metoda zwraca wartosc pola DlugoscY
   *
   * Metoda zwraca wartosc pola DlugoscY
   * \return Wartosc pola DlugoscY
   */
  double ZwrocDlugoscY() { return DlugoscY; }
  /*!
   * \brief Metoda zwraca wartosc pola WysokoscZ
   *
   * Metoda zwraca wartosc pola WysokoscZ
   * \return Wartosc pola WysokoscZ
   */
  double ZwrocWysokoscZ() { return WysokoscZ; }
  /*!
   * \brief Metoda statyczna zwraca wartosc pola IloscIstniejacych
   */
  static int ZwrocIloscIstniejacych() { return IloscIstniejacych; }
  /*!
   * \brief Metoda zstatyczna zwraca wartosc pola IloscStworzonych
   */
  static int ZwrocIloscStworzonych() { return IloscStworzonych; }
};

#endif
