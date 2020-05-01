#ifndef OBSLUGA_HH
#define OBSLUGA_HH
#include "Scena.hh"
#include "lacze_do_gnuplota.hh"
#define ILOSC_ROTOROW 4
/*!
 * \brief Funkcja pozwala na wyswietlenie ilosci obiektow klas Wektor3D i
 * ObiektSceny
 */
void WyswietlIloscObiektow();
/*!
 *\brief Funkcja wyswietla menu uzytkownika
 */
void WyswietlMenu();
/*!
 *\brief Funkcja ustawia parametry lacza do GNUPlota
 *
 *Funkcja ustawia parametry lacza takie jak:
 *nazwy plikow,
 *tryb rysowania,
 *zakresy
 * \param[in] Lacze - referencja do obiektu PzG::LaczeDoGNUPlota ktorego dane
 *maja zostac zmodyfikowane
 */
void UstawLacze(PzG::LaczeDoGNUPlota& Lacze);
/*!
 * \brief Funkcja wyswietla aktualnie wyselekcjowanego drona i pozwala na
 * dokonanie wyboru drona z listy
 *
 * \param[in] sc - Wskaznik do obiektu klasy Scena z ktorej ma zostac wybrany
 * dron
 */
void WybierzDrona(Scena* const sc);
#endif
