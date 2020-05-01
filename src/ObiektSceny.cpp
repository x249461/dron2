#include "ObiektSceny.hh"
int ObiektSceny::IloscIstniejacych = 0;
int ObiektSceny::IloscStworzonych = 0;

bool ObiektSceny::CzyKolizja(std::shared_ptr<ObiektSceny> AktualnyDron) {
  if (TypID == 1) {  // Sprawdzenie dla klasy Dron
    // Obliczenie z wzoru na koło (x-xsr)^2+(y-ysr)^2 = r ^2 czy jakos tak
    double OdlegloscSrodkow =
        sqrt((this->ZwrocSrodek()[0] - AktualnyDron->ZwrocSrodek()[0]) *
                 (this->ZwrocSrodek()[0] - AktualnyDron->ZwrocSrodek()[0]) +
             (this->ZwrocSrodek()[1] - AktualnyDron->ZwrocSrodek()[1]) *
                 (this->ZwrocSrodek()[1] - AktualnyDron->ZwrocSrodek()[1]));
    if (OdlegloscSrodkow <=  // Sprawdzenie czy OdlegloscSrodkow jest mniejsza
                             // niz suma promieni
        this->Aproksymacja.promien + AktualnyDron->Aproksymacja.promien) {
      // Sprawdzenie czy wysokosc drona zawiera sie w wysokosci drugiego
      if (abs(this->Aproksymacja.punkt_srodka[2] -
              AktualnyDron->Aproksymacja.punkt_srodka[2]) <
          this->Aproksymacja.wysokosc) {
        return true;
      }
    }
  } else if (TypID == 0) {
    // Srodek + polowa dlugosci boku po danej osi + promien aproksymacji dron
    // Tak po kazdej osi X, Y, Z i potem sprawdzic czy srodek drona
    // jest Xmin < X < Xmax
    // a w Xmin wzor z 1 linijki tylko z minusami
    double Xmax = this->ZwrocSrodek()[0] + AktualnyDron->Aproksymacja.promien +
                  this->ZwrocSzerokoscX() / 2;
    double Xmin = this->ZwrocSrodek()[0] - AktualnyDron->Aproksymacja.promien -
                  this->ZwrocSzerokoscX() / 2;

    double Ymax = this->ZwrocSrodek()[1] + AktualnyDron->Aproksymacja.promien +
                  this->ZwrocDlugoscY() / 2;
    double Ymin = this->ZwrocSrodek()[1] - AktualnyDron->Aproksymacja.promien -
                  this->ZwrocDlugoscY() / 2;

    if (Xmin <= AktualnyDron->ZwrocSrodek()[0] &&
        AktualnyDron->ZwrocSrodek()[0] <= Xmax &&
        Ymin <= AktualnyDron->ZwrocSrodek()[1] &&
        AktualnyDron->ZwrocSrodek()[1] <= Ymax) {
      double Zmax = this->ZwrocSrodek()[2] +
                    (AktualnyDron->Aproksymacja.wysokosc / 2) +
                    this->ZwrocWysokoscZ() / 2;
      double Zmin = this->ZwrocSrodek()[2] -
                    (AktualnyDron->Aproksymacja.wysokosc / 2) -
                    this->ZwrocWysokoscZ() / 2;
      if (Zmin <= AktualnyDron->ZwrocSrodek()[2] &&
          AktualnyDron->ZwrocSrodek()[2] <= Zmax)
        return true;
    }
  }
  return false;
}
