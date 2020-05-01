#ifndef SCENA_HH
#define SCENA_HH
#define ILOSC_DRONOW 3
#define ILOSC_PRZESZKOD 3
#include "Dron.hh"
/*!
 *\brief Struktura przechowuje obiekty znajdujace sie na scenie.
 */
class Scena {
  /*!
   *\brief Pole przechowuje liste zawierajaca obiekty klasy Dron bedace na
   *scenie
   *
   *Pole przechowuje liste zawierajaca obiekty klasy Dron bedace na
   *scenie
   */
  std::list<std::shared_ptr<Dron>> Drony;
  /*!
   *\brief Pole jest iteratorem list Drony
   */
  std::list<std::shared_ptr<Dron>>::iterator ItDrony;
  /*!
   * \brief Pole przechowuje obiekty klas Przeszkoda oraz Dron bedace na scenie
   *
   * Pole przechowuje obiekty klas Przeszkoda oraz Dron bedace na scenie
   */
  std::list<std::shared_ptr<ObiektSceny>> Obiekty;
  /*!
   * \brief Pole jest iteratorem listy Obiekty
   */
  std::list<std::shared_ptr<ObiektSceny>>::iterator ItObiekty;
  /*!
   * \brief Metoda pozwala na wypelnienie listy Drony obiektami
   * std::shared_ptr<Dron>
   */
  void StworzListeDrony();
  /*!
   * \brief Metoda pozwala na wypelnienie listy Obiekty
   * obiektami typu std::shared_ptr<ObiektSceny>
   */
  void StworzListeObiekty();

 public:
 /*!
 * \brief Konstruktor domyslny klasy Scena
 * 
 * Konstruktor domyslny klasy scena tworzy obiekt Scena oraz inicjalizuje PzG::LaczeDoGNUPlota 
 * \param[in] Lacze - referencja do obiektu klasy PzG::LaczeDoGNUPlota ktory ma zostac zainicjalizowany 
 */
   Scena(PzG::LaczeDoGNUPlota &Lacze) { Inicjalizuj(Lacze); }
  /*!
   * \brief Destruktor klasy Scena
   *
   * Destruktor czysci listy Drony oraz Obiekty, tym samym powodujac usuniecie
   * wszystkich obiektow
   *
   */
  ~Scena() {
    Drony.clear();
    Obiekty.clear();
  }
  /*!
   * \brief Metoda zwraca aktualnie wskazywanego drona z listy Drony
   *
   * Metoda zwraca aktualnie wskazywanego drona z listy Drony
   * \return Wskaznik na obiekt Dron z listy Drony
   */
  std::shared_ptr<Dron> ZwrocDrona() { return *ItDrony; }
  /*!
   * \brief Metoda zwraca indeks drona jako integer
   *
   * Metoda zwraca indeks drona jako integer
   * \return liczba(integer) bedacy indeksem drona na liscie
   */
  int Indeks() { return std::distance(Drony.begin(), ItDrony); }
  /*!
   * \brief Metoda pozwala na inicjalizacje Sceny z 3 dronami oraz 3
   * przeszkodami
   *
   * Metoda tworzy listy Drony oraz Obiekty, wypelnia je, a takze tworzy i
   * inicjalizuje obiekty klas Dron oraz Przeszkoda
   */
  void Inicjalizuj(PzG::LaczeDoGNUPlota &Lacze);
  /*!
   * \brief Metoda pozwala na przesuniecie iteratora ItDrony na kolejny na
   * liscie Drony
   *
   * Metoda pozwala na przesuniecie iteratora ItDrony na kolejny na liscie
   *  Drony.
   * W przypadku konca listy, wraca na jej poczatek.
   */
  bool ZmienDrona();
  /*!
   * \brief Metoda pozwala na przesuniecie iteratora ItObiekty na kolejny na
   * liscie Obiekty
   *
   * Metoda pozwala na przesuniecie iteratora ItObiekty na kolejny na liscie
   * Obiekty.
   * W przypadku konca listy, wraca na jej poczatek.
   * \retval True - zwrocony dron jest 1 na liscie
   * \retval False - zwrocony dron nie jest 1 na liscie
   */
  void ZmienObiekt();
  /*!
   * \brief Metoda sprawdza czy nastapila kolizja z innymi obiektami na scenie.
   *
   * Metoda sprawdza czy nastapila kolizja z innymi obiektami na scenie
   * znajdujacymi sie na liscie Obiekty.
   * \param[in] AktualnyDron - wskaznik na sprawdzanego drona.
   * \retval True - nastapila kolizja.
   * \retval False - nie nastapila kolizja.
   */
  bool CzyKolizja(std::shared_ptr<ObiektSceny> AktualnyDron);
  /*!
   * \brief Metoda pozwala na wykonanie ruchu aktualnie wyselekcjonowanym dronem
   *
   *  Metoda pozwala na wykonanie ruchu aktualnie wyselekcjonowanym dronem wraz
   * z detekcja kolizji z innymi obiektami na scenie
   */
  void Ruch(PzG::LaczeDoGNUPlota &Lacze);
  /*!
   * \brief Metoda pozwala wyswietlic liste dostepnych dronow
   */
  void WyswietlDrony();
  /*!
   *
   * \brief Metoda pozwala na wybranie drona z list o danym numerze
   *
   * Metoda pozwala na wybranie drona z list o danym numerze, i obsluguje
   * exception przekroczenia zakresu.
   * \param[in] NumerDrona - numer drona z listy ktory ma zostac wybrany
   */
  void WybierzDrona();
};
#endif
