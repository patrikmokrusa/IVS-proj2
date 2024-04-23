//============================================================================//
//
// Purpose:     Interface for mathlib
//
// $NoKeywords: $kalkulacka $mathlib.h
// $Author:    Patrik Mokruša <xmokrup00@stud.fit.vutbr.cz>
// $Date:       $2024-07-04
//============================================================================//
/**
 * @file mathlib.h
 * @author Patrik Mokruša
 *
 * @brief Deklarace funkci matematicke knihovny pro kalkulacka
 */

#ifndef MATHLIB_H
#define MATHLIB_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief k_plus
 * přičte add_num k base_num
 * @param[in] base_num prvni ciclo (pred +)
 * @param[in] add_num druhe cislo (za +)
 * @return vraci soucet cisel
 */
double k_plus(double base_num, double add_num);

/**
 * @brief k_minus
 * odecte sub_num od base_num
 * @param[in] base_num prvni ciclo (pred -)
 * @param[in] sub_num druhe cislo (za -)
 * @return vraci rozdil cisel
 */
double k_minus(double base_num, double sub_num);

/**
 * @brief k_krat
 * prinasobi tiems_num k base_num
 * @param[in] base_num prvni ciclo (pred *)
 * @param[in] times_num druhe cislo (za *)
 * @return vraci soucin cisel
 */
double k_krat(double base_num, double times_num);

/**
 * @brief k_deleno
 * vydeli base_num s div_num
 * @param[in] base_num prvni ciclo (pred /)
 * @param[in] div_num druhe cislo (za /)
 * @return vraci vydelene cislo
 * @exception overflow_error pri deleni nulou
 */
double k_deleno(double base_num, double div_num);

/**
 * @brief k_faktorial
 * vypocita faktorial
 * @param[in] base_num cislo ze ktereho chceme faktorial
 * @return vraci faktorial
 * @exception out_of_range pri zadani zaporneho nebo desetinneho cisla
 */
double k_faktorial(double base_num);

/**
 * @brief k_mocnina
 * umocni basenum_num na ^ base_num
 * @param[in] base_num puvodni ciclo (pod mocninou)
 * @param[in] mocnitel cislo na (mocnitel)
 * @return vraci umocnene cislo
 * @exception out_of_range pri mocnenim zapornym cislem
 */
double k_mocnina(double base_num, double mocnitel);

/**
 * @brief k_odmocnina
 * base_num odmocni odmocnitel -em
 * @param[in] base_num puvodni cislo (pod odmocninou)
 * @param[in] times_num kolikata odmocnina (odmocnitel)
 * @return odmocnene cislo
 * @exception invalid_argument pri odmocnenim desetinnym nebo zapornym cislem
 */
double k_odmocnina(double base_num, double odmocnitel);

/**
 * @brief k_obracena_hodnota
 * obracena hodnota k base_num (1/base_num)
 * @param[in] base_num cislo ke kteremu chceme obracenou hodnotu
 * @return vraci obracenou hodnotu k cislu
 * @exception overflow_error pri zadani nuly (nelze delit nulou)
 */
double k_obracena_hodnota(double base_num);

#ifdef __cplusplus
}
#endif

#endif
