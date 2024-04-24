//============================================================================//
//
// Purpose:     Custom math lib for kalkulacka project
//
// $NoKeywords: $kalkulacka $mathlib.cpp
// $Author:    Patrik Mokruša <xmokrup00@stud.fit.vutbr.cz>
// $Date:       $2024-07-04
//============================================================================//
/**
 * @file mathlib.cpp
 * @author Patrik Mokruša
 *
 * @brief Definice funkci matematicke knihovny pro kalkulacka
 */

// Includes
#include "mathlib.h"
#include <cmath>
#include <stdexcept>
#include <stdlib.h>


double k_plus(double base_num, double add_num) {
  double temp_num = base_num + add_num;
  return temp_num;
};


double k_minus(double base_num, double sub_num) {
  double temp_num = base_num - sub_num;
  return temp_num;
};


double k_krat(double base_num, double times_num) {
  double temp_num = base_num * times_num;
  return temp_num;
};



double k_deleno(double base_num, double div_num) {
  if (div_num == 0) {
    throw std::overflow_error("Nepovoleno delit nulou");
  }
  double temp_num = base_num / div_num;
  return temp_num;
};


double k_faktorial(double base_num) {
  if (base_num < 0 || std::fmod(base_num, 1) != 0) {
    throw std::out_of_range("Zadanne zaporne nebo desetinne cislo");
  }

  int temp_num = 1;
  while (base_num != 0) {
    temp_num = temp_num * base_num;
    base_num = base_num - 1;
  }

  return temp_num;
}


double k_mocnina(double base_num, double mocnitel) {
  if (mocnitel < 0 || std::fmod(mocnitel, 1) != 0) {
    throw std::out_of_range("Zadanne zaporne nebo desetinne cislo");
  }

  double temp_num = 1;
  for (size_t i = 0; i < mocnitel; i++) {
    temp_num = temp_num * base_num;
  }

  return temp_num;
}


double k_odmocnina(double base_num, double odmocnitel) {

  if (odmocnitel == 2) ///< pro klasickou druhou odmocninu
  {
    if (base_num < 0) {
      throw std::invalid_argument(
          "Pod druhou odmocninu nemuzu dat zaporne cislo");
    }
    base_num = sqrt(base_num);
    return base_num;
  }
  if (odmocnitel == 3)
  {
    base_num = cbrt(base_num);
    return base_num;
  }

  if (std::fmod(odmocnitel, 1) != 0 || odmocnitel < 0) {
    throw std::out_of_range("Zadanne zaporne nebo desetinne cislo");
  }
  if (base_num < 0 && std::fmod(odmocnitel, 2) == 0) {
    throw std::invalid_argument("Pod sudou odmocninu nelze dat zaporne cislo");
  }

  double rooted_num = pow(base_num, k_obracena_hodnota(odmocnitel));


  return rooted_num;
}


double k_obracena_hodnota(double base_num) {
  if (base_num == 0) {
    throw std::overflow_error("Nepovoleno delit nulou");
  }
  base_num = 1 / base_num;
  return base_num;
}
