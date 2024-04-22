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

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *event);

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void result();

    void reset();

    void handleOperation(QString operand);

    void on_button_0_clicked();

    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

    void on_button_9_clicked();

    void on_button_ac_clicked();

    void on_button_del_clicked();

    void on_button_times_ten_clicked();

    void on_button_plus_clicked();

    void on_button_minus_clicked();

    void on_button_times_clicked();

    void on_button_div_clicked();

    void on_button_equals_clicked();

    void on_button_negate_clicked();

    void on_button_decimal_clicked();

    void on_button_y_exp_x_clicked();

    void on_button_factorial_clicked();

    void on_pushButton_clicked();

    void on_exitButton_clicked();

    void on_button_1_over_x_clicked();

    void on_button_exp_x_root_y_clicked();

private:
    Ui::MainWindow *ui;
    QDialog *dialog;
};
#endif // MAINWINDOW_H
