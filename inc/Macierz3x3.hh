#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH

#include "Macierz.hh"

/*!
 * \class Macierz3x3
 *
 * \brief Klasa Macierz3x3 jest instacja szablonu Macierz<>.
 * Modeluje pojecie macierzy o wymiarze 3x3.
 */
typedef Macierz<3> Macierz3x3;
/*!
 *\brief Funkcja tworzy macierz obrotu przez os OX
 *\param kat - kat o ktory ma byc obrocona bryla, podany w stopniach
 *\return Funkcja zwraca macierz rotacji Macierz3x3
 */
Macierz3x3 MacierzX(double kat);
/*!
 *\brief Funkcja tworzy macierz obrotu przez os OY
 *\param kat - kat o ktory ma byc obrocona bryla, podany w stopniach
 *\return Funkcja zwraca macierz rotacji Macierz3x3
 */
Macierz3x3 MacierzY(double kat);
/*!
 *\brief Funkcja tworzy macierz obrotu przez os OZ
 *\param kat - kat o ktory ma byc obrocona bryla, podany w stopniach
 *\return Funkcja zwraca macierz rotacji Macierz3x3
 */
Macierz3x3 MacierzZ(double kat);
#endif
