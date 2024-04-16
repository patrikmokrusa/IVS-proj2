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
 * Pro spusteni testu si stahnete google test z githubu a dejte do slozy test
 * takto: test/googletest-main/(googlemock, googletest, ...)
 */

// Includes
#include "mathlib.h"
#include <cmath>
#include <stdexcept>
#include <stdlib.h>

/**
 * @brief k_plus
 * přičte add_num k base_num
 * @param[in] base_num prvni ciclo (pred +)
 * @param[in] add_num druhe cislo (za +)
 * @return vraci soucet cisel
 */
double k_plus(double base_num, double add_num) {
  double temp_num = base_num + add_num;
  return temp_num;
};

/**
 * @brief k_minus
 * odecte sub_num od base_num
 * @param[in] base_num prvni ciclo (pred -)
 * @param[in] sub_num druhe cislo (za -)
 * @return vraci rozdil cisel
 */
double k_minus(double base_num, double sub_num) {
  double temp_num = base_num - sub_num;
  return temp_num;
};

/**
 * @brief k_krat
 * prinasobi tiems_num k base_num
 * @param[in] base_num prvni ciclo (pred *)
 * @param[in] times_num druhe cislo (za *)
 * @return vraci soucin cisel
 */
double k_krat(double base_num, double times_num) {
  double temp_num = base_num * times_num;
  return temp_num;
};

/**
 * @brief k_deleno
 * vydeli base_num s div_num
 * @param[in] base_num prvni ciclo (pred /)
 * @param[in] div_num druhe cislo (za /)
 * @return vraci vydelene cislo
 * @exception pri deleni nulou
 */
double k_deleno(double base_num, double div_num) {
  if (div_num == 0) {
    throw std::overflow_error("Nepovoleno delit nulou");
  }
  double temp_num = base_num / div_num;
  return temp_num;
};

/**
 * @brief k_faktorial
 * vypocita faktorial
 * @param[in] base_num cislo ze ktereho chceme faktorial
 * @return vraci faktorial
 * @exception pri zadani zaporneho nebo desetinneho cisla
 */
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

/**
 * @brief k_mocnina
 * umocni basenum_num na^ base_num
 * @param[in] base_num puvodni ciclo (pod mocninou)
 * @param[in] mocnitel cislo na (mocnitel)
 * @return vraci umocnene cislo
 * @exception pri mocnenim zapornym cislem
 */
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

/**
 * @brief k_odmocnina
 * base_num odmocni odmocnitel -em
 * @param[in] base_num puvodni cislo (pod odmocninou)
 * @param[in] times_num kolikata odmocnina (odmocnitel)
 * @return odmocnene cislo
 * @exception pri odmocnenim desetinnym nebo zapornym cislem
 * @todo jednoduche priklady fungujou ale na tezsi to tweakuje
 */
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

  double j = 1; ///< urcuje iterator, podle ktereho se hada obecna odmocnina

  if (std::fmod(odmocnitel, 1) != 0 || odmocnitel < 0) {
    throw std::out_of_range("Zadanne zaporne nebo desetinne cislo");
  }
  if (base_num < 0 && std::fmod(odmocnitel, 2) == 0) {
    throw std::invalid_argument("Pod sudou odmocninu nelze dat zaporne cislo");
  }

  double rooted_num = 1;

  while (pow(rooted_num, odmocnitel) < base_num) {
    rooted_num = rooted_num + j;
  }

  return rooted_num;
}
/**
 * @brief k_obracena_hodnota
 * obracena hodnota k base_num (1/base_num)
 * @param[in] base_num cislo ke kteremu chceme obracenou hodnotu
 * @return vraci obracenou hodnotu k cislu
 * @exception pri zadani nuly (nelze delit nulou)
 */
double k_obracena_hodnota(double base_num) {
  if (base_num == 0) {
    throw std::overflow_error("Nepovoleno delit nulou");
  }
  base_num = 1 / base_num;
  return base_num;
}
