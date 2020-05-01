#ifndef DRON_HH
#define DRON_HH
#include <unistd.h>
#include "Graniastoslup.hh"
#include "lacze_do_gnuplota.hh"
#define ILOSC_ROTOROW 4
/*!
 * \brief Klasa modeluje pojecia drona
 *
 * Klasa modeluje pojecie drona skladajacego sie z kadlubu oraz 4 wirnikow.
 */
class Dron : public ObiektSceny {
  /*!
   * \brief Pole przechowuje 4 obiektu typu Graniastoslup bedace wirnikami
   *
   * Pole przechowuje 4 obiektu typu Graniastoslup bedace wirnikami
   */
  Graniastoslup Rotor[4];
  /*!
   * \brief Pole przechowuje obiekt Prostopadloscian bedacy korpusem drona
   *
   * Pole przechowuje obiekt Prostopadloscian bedacy korpusem drona
   */
  Prostopadloscian Korpus;
  /*!
   * \brief Pole przechowuje kat obrotu wzgledem poczatkowego polozenia
   *
   * Pole przechowuje kat obrotu wzgledem poczatkowego polozenia
   */
  double Kat_Obrotu = 0;


 public:
 /*! 
 * \brief Konstruktor domyslny przypisujacy TypID wartosc 1
 *
 * Konstruktor domyslny przypisujacy TypID wartosc 1 w celu odroznienia
 * klasy Dron od innych klas
 */ 
  Dron() { TypID = 1; }
  /*!
  * \brief Metoda zwraca zawartosc pola Srodek
  * 
  * Metoda zwraca zawartosc pola Srodek z obiektu Korpus
  * \return Wektor3D - Zawartosc pola Srodek
  */
  Wektor3D ZwrocSrodek() { return Korpus.ZwrocSrodek(); }
  /*!
  * \brief Metoda zwraca zawartosc pola Kat_Obrotu
  * \return Wartosc pola Kat_Obrotu
  */
  double ZwrocKatObrotu(){return Kat_Obrotu;}
  /*!
   * \brief Metoda pozwala na animacje ruchu drona na wprost
   *
   * Metoda pozwala na animacje ruchu drona na wprost z uwzglednieniem stopnia
   * wznoszenia lub opadania
   * \param Lacze - lacze do programu GNUPlot przez
   * ktore ma byc rysowany dron
   */
  void Ruch(PzG::LaczeDoGNUPlota &Lacze, int NumerDrona, Wektor3D ruch_kon);
  /*!
   * \brief Metoda pozwala na animacje obrotu drona wokol wlasnej osi
   *
   * Metoda pozwala na animacje obrotu drona wokol wlasnej osi
   * \param Lacze - lacze do programu GNUPlot przez
   * ktore ma byc rysowany dron
   */
  void Obrot(PzG::LaczeDoGNUPlota &Lacze, int NumerDrona);
  /*!
   * \brief Metoda pozwala na zapis wspolrzednych drona do plikow
   *
   * Metoda pozwala na zapis wspolrzednych poszczegolnych elementow drona do
   * osobnych plikow w celu ich pozniejszego narysowania poprzez program GNUPlot
   */
  void Zapisz(int NumerDrona);
  /*!
   * \brief Metoda pozwala na inicjalizacje obiektow skladajacych sie na drona
   *
   * Metoda pozwala na inicjalizacje obiektow skladajacych sie na drona
   */
  void Inicjalizuj();
  /*!
   * \brief Metoda pozwala na animacje obrotu rotorow drona
   *
   * Metoda pozwala na animacje obrotu rotorow drona
   * \param Lacze - lacze do programu GNUPlot przez
   * ktore ma byc rysowany dron
   */
  void Animacja(PzG::LaczeDoGNUPlota &Lacze, int NumerDron);
  /*!
   * \brief Metoda aktualizujaca pozycje rotorow w odniesieniu do korpusu
   *
   * Metoda aktualizujaca pozycje rotorow w odniesieniu do korpusu. Zmienia ona
   * pole offset w obiekcie Graniastoslup, tak by rotor znajdowal sie na
   * wierzcholku korpusu
   */
  void AktualizujRotory();
  /*!
   *\brief Metoda pozwala na przesuniecie drona bez jego animacji
   */
  void Przesun(Wektor3D przesuniecie);
};
#endif