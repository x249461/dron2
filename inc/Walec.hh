#ifndef WALEC_HH
#define WALEC_HH
#include "Wektor3D.hh"
/*!
 * \brief Struktura modeluje pojecie Walca
 *
 * Struktura modeluje pojecie walca.
 */
struct Walec {
  /*!
   *\brief Promien walca
   */
  int promien;
  /*!
   * \brief Wysokosc walca
   */
  int wysokosc;
  /*!
   * \brief Punkt bedacy srodkiem walca
   */
  Wektor3D punkt_srodka;
};
#endif
