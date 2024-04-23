//============================================================================//
//
// Purpose:     UI Definition
//
// $NoKeywords: $kalkulacka $mainwindow.h $UI
// $Author:    Adam Černoš <xcernoa00@stud.fit.vutbr.cz>
// $Date:       $2024-22-04
//============================================================================//
/**
 * @file mainwindow.h
 * @author Adam Černoš
 *
 *
 * @brief Definice UI funkcí, Vytvořeno pomocí QT editoru
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Class pro UI projektu
*/
class MainWindow : public QMainWindow {
  Q_OBJECT
protected:
  /**
   * @brief handluje input z klávesnice
   * @param[in] event input z klávesnice
  */
  void keyPressEvent(QKeyEvent *event);

public:

  /**
   * @brief Konstruktor MainWindow
  */
  MainWindow(QWidget *parent = nullptr);
  /**
   * @brief Destruktor MainWindow
  */
  ~MainWindow();

private slots:

  /**
   * @brief do primary dá výsledek požadovaného výpočtu podle operation
  */
  void result();

  /**
   * @brief vynuluje primary, secondary a operand pole
  */
  void reset();

  /**
   * @brief dá do pole operand parametr QString operand
   * @param[in] operand string ktery chceme nastavit do pole parametr
  */
  void handleOperation(QString operand);

  /**
   * @brief při kliknutí na tlačítko 0 přidá do pole primary 0
  */
  void on_button_0_clicked();

  /**
   * @brief při kliknutí na tlačítko 1 přidá do pole primary 1
  */
  void on_button_1_clicked();

  /**
   * @brief při kliknutí na tlačítko 2 přidá do pole primary 2
  */
  void on_button_2_clicked();

  /**
   * @brief při kliknutí na tlačítko 3 přidá do pole primary 3
  */
  void on_button_3_clicked();

  /**
   * @brief při kliknutí na tlačítko 4 přidá do pole primary 4
  */
  void on_button_4_clicked();

  /**
   * @brief při kliknutí na tlačítko 5 přidá do pole primary 5
  */
  void on_button_5_clicked();

  /**
   * @brief při kliknutí na tlačítko 6 přidá do pole primary 6
  */
  void on_button_6_clicked();

  /**
   * @brief při kliknutí na tlačítko 7 přidá do pole primary 7
  */
  void on_button_7_clicked();

  /**
   * @brief při kliknutí na tlačítko 8 přidá do pole primary 8
  */
  void on_button_8_clicked();

  /**
   * @brief při kliknutí na tlačítko 9 přidá do pole primary 9
  */
  void on_button_9_clicked();

  /**
   * @brief při kliknutí na tlačítko AC vynuluje pole primary, secondary a operand
  */
  void on_button_ac_clicked();

  /**
   * @brief při kliknutí na tlačítko del umaže poslední znak z primary
  */
  void on_button_del_clicked();

  /**
   * @brief při kliknutí na tlačítko 10x přidá 2 nuly na konec pole primary (popřípadě přidá desetinnou tečku)
  */
  void on_button_times_ten_clicked();

  /**
   * @brief při kliknutí na tlačítko + nastaví pole operand na +
  */
  void on_button_plus_clicked();

  /**
   * @brief při kliknutí na tlačítko - nastaví pole operand na -
  */
  void on_button_minus_clicked();

  /**
   * @brief při kliknutí na tlačítko * nastaví pole operand na *
  */
  void on_button_times_clicked();

  /**
   * @brief při kliknutí na tlačítko / nastaví pole operand na /
  */
  void on_button_div_clicked();

  /**
   * @brief při kliknutí na tlačítko = nastaví pole primary na výsledek požadované operace
  */
  void on_button_equals_clicked();

  /**
   * @brief při kliknutí na tlačítko +/- vymění znaménko čísla
  */
  void on_button_negate_clicked();

  /**
   * @brief při kliknutí na tlačítko . do pole primary přidá desetinnou tečku
  */
  void on_button_decimal_clicked();

  /**
   * @brief při kliknutí na tlačítko ^ nastaví pole operand na ^
  */
  void on_button_y_exp_x_clicked();

  /**
   * @brief při kliknutí na tlačítko ! nastaví pole operand na !
  */
  void on_button_factorial_clicked();

  /**
   * @brief při kliknutí na tlačítko ? otevře nové okno help
  */
  void on_pushButton_clicked();

  /**
   * @brief při kliknutí na tlačítko exit v help zavře okno help
  */
  void on_exitButton_clicked();

  /**
   * @brief při kliknutí na tlačítko 1/x nastaví pole operand na 1/x
  */
  void on_button_1_over_x_clicked();

  /**
   * @brief při kliknutí na tlačítko "odmocnina" nastaví pole operand na "odmocnina"
  */
  void on_button_exp_x_root_y_clicked();

private:
  Ui::MainWindow *ui;
  QDialog *dialog;
};
#endif // MAINWINDOW_H
