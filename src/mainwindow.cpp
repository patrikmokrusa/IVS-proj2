//============================================================================//
//
// Purpose:     UI Implementation
//
// $NoKeywords: $kalkulacka $mainwindow.cpp $UI
// $Author:    Adam Černoš <xcernoa00@stud.fit.vutbr.cz>
// $Date:       $2024-22-04
//============================================================================//
/**
 * @file mainwindow.cpp
 * @author Adam Černoš
 * @author Patrik Mokruša
 *
 * @brief Implementace UI funkcí, Vytvořeno pomocí QT editoru
 */

#include "mainwindow.h"
#include "../mathlib.cpp"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <stdexcept>
#include <string>

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

QString allowedInputs[] = {"0", "1", "2", "3", "4", "5",
                           "6", "7", "8", "9", "."};
QString allowedOperations[] = {"^", "+", "-", "*", "/"};

void MainWindow::result() {
  QString primary = ui->lineEdit_primary->text();
  QString secondary = ui->lineEdit_secondary->text();
  QString operation = ui->lineEdit_operation->text();

  double primary_d = primary.toDouble();
  double secondary_d = secondary.toDouble();
  double result;

  if (operation == "+") {
    result = k_plus(primary_d, secondary_d);
  } else if (operation == "-") {
    result = k_minus(secondary_d, primary_d);
  } else if (operation == "*") {
    result = k_krat(primary_d, secondary_d);
  } else if (operation == "/") {
    try {
      result = k_deleno(secondary_d, primary_d);
    } catch (std::overflow_error const &ex) {
      ui->lineEdit_primary->setText(ex.what());
      return;
    }
  } else if (operation == "^") {
    try {
      result = k_mocnina(secondary_d, primary_d);
    } catch (std::out_of_range const &ex) {
      ui->lineEdit_primary->setText(ex.what());
      return;
    }

  } else if (operation == "√") {
    try {
      result = k_odmocnina(secondary_d, primary_d);
    } catch (const std::out_of_range &e) {
      ui->lineEdit_primary->setText(e.what());
      return;
    } catch (const std::invalid_argument &e) {
      ui->lineEdit_primary->setText(e.what());
      return;
    }
  } else if (operation == "!") {
    try {
      result = k_faktorial(secondary_d);
    } catch (const std::out_of_range &e) {
      ui->lineEdit_primary->setText(e.what());
      return;
    }
  } else if (operation == "1/x") {
    try {
      result = k_obracena_hodnota(secondary_d);
    } catch (const std::overflow_error &e) {
      ui->lineEdit_primary->setText(e.what());
      return;
    }
  }
  reset();
  ui->lineEdit_primary->setText(QString::number(result));
}

void MainWindow::reset() {
  ui->lineEdit_primary->setText("");
  ui->lineEdit_secondary->setText("");
  ui->lineEdit_operation->setText("");
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Escape) {
    QCoreApplication::quit();
  } else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
    result();
    return;
  } else if (event->key() == Qt::Key_Backspace) {
    ui->lineEdit_primary->backspace();
    return;
  } else if (event->key() == Qt::Key_Delete) {
    reset();
  }

  QString input = event->text();

  for (int i = 0; i < 5; i++) {
    if (input == allowedOperations[i])
      handleOperation(input);
  }

  for (int i = 0; i < 11; i++) {
    if (input == allowedInputs[i])
      ui->lineEdit_primary->insert(input);
  }
}

void MainWindow::handleOperation(QString operand) {
  QString primary = ui->lineEdit_primary->text();
  QString secondary = ui->lineEdit_secondary->text();
  QString operation = ui->lineEdit_operation->text();
  if (primary.length() == 0 && secondary.length() == 0) {
    return;
  }
  if (operation != "") {
    ui->lineEdit_operation->setText(operand);
    return;
  }

  ui->lineEdit_secondary->setText(primary);
  ui->lineEdit_operation->setText(operand);
  ui->lineEdit_primary->setText("");
}

void MainWindow::on_button_0_clicked() { ui->lineEdit_primary->insert("0"); }

void MainWindow::on_button_1_clicked() { ui->lineEdit_primary->insert("1"); }

void MainWindow::on_button_2_clicked() { ui->lineEdit_primary->insert("2"); }

void MainWindow::on_button_3_clicked() { ui->lineEdit_primary->insert("3"); }

void MainWindow::on_button_4_clicked() { ui->lineEdit_primary->insert("4"); }

void MainWindow::on_button_5_clicked() { ui->lineEdit_primary->insert("5"); }

void MainWindow::on_button_6_clicked() { ui->lineEdit_primary->insert("6"); }

void MainWindow::on_button_7_clicked() { ui->lineEdit_primary->insert("7"); }

void MainWindow::on_button_8_clicked() { ui->lineEdit_primary->insert("8"); }

void MainWindow::on_button_9_clicked() { ui->lineEdit_primary->insert("9"); }

void MainWindow::on_button_ac_clicked() { reset(); }

void MainWindow::on_button_del_clicked() { ui->lineEdit_primary->backspace(); }

void MainWindow::on_button_times_ten_clicked() {
  QString text = ui->lineEdit_primary->text();
  if (text.length() == 0) {
    return;
  } else if (text.length() == 1 && text[0] == '0') {
    return;
  }

  else if (text.contains(".")) {
    int index = text.indexOf('.');

    if (index == (text.length() - 1)) {
      ui->lineEdit_primary->backspace();
      ui->lineEdit_primary->insert("0");
    } else {
      text[index] = text[index + 1];
      text[index + 1] = '.';
      if (text[index + 1] == '\0') {
        ui->lineEdit_primary->setText(text);
      } else {
        ui->lineEdit_primary->setText(text);
      }
    }
  } else {
    ui->lineEdit_primary->insert("0");
  }
  return;
};

void MainWindow::on_button_plus_clicked() { handleOperation("+"); }

void MainWindow::on_button_minus_clicked() { handleOperation("-"); }

void MainWindow::on_button_times_clicked() { handleOperation("*"); }

void MainWindow::on_button_div_clicked() { handleOperation("/"); }

void MainWindow::on_button_y_exp_x_clicked() { handleOperation("^"); }

void MainWindow::on_button_negate_clicked() {
  QString text = ui->lineEdit_primary->text();
  if (text.length() == 0)
    return;
  else if (text[0] == '-') {
    text.remove(0, 1);
    ui->lineEdit_primary->setText(text);

  } else {
    ui->lineEdit_primary->setText("-" + text);
  }
}

void MainWindow::on_button_decimal_clicked() {
  QString text = ui->lineEdit_primary->text();
  if (text.contains(".")) {
    return;
  } else if (text.length() == 0) {
    ui->lineEdit_primary->setText("0.");
    return;
  }

  else {
    ui->lineEdit_primary->insert(".");
    return;
  }
}

void MainWindow::on_button_equals_clicked() { result(); }

void MainWindow::on_pushButton_clicked() {
  dialog = new QDialog();
  dialog->setWindowModality(Qt::WindowModality::ApplicationModal);
  dialog->setMinimumSize(220, 300);
  dialog->setMaximumSize(220, 300);
  QPushButton *ExitButton = new QPushButton();
  connect(ExitButton, SIGNAL(clicked()), this, SLOT(exitButton_clicked()));

  QLabel *LabelMain = new QLabel();
  LabelMain->setText("Tohle je HELP");
  LabelMain->setGeometry(10, 20, 200, 30);
  LabelMain->setParent(dialog);
  LabelMain->show();

  QLabel *LabelOperation = new QLabel();
  LabelOperation->setText("aplikaci můžeme ovládat");
  LabelOperation->setGeometry(10, 40, 200, 30);
  LabelOperation->setParent(dialog);
  LabelOperation->show();

  QLabel *LabelOperation2 = new QLabel();
  LabelOperation2->setText("pomocí klávesnice či myši");
  LabelOperation2->setGeometry(10, 60, 200, 30);
  LabelOperation2->setParent(dialog);
  LabelOperation2->show();

  QLabel *LabelOperation3 = new QLabel();
  LabelOperation3->setText("Povolené operace jsou /*-+^");
  LabelOperation3->setGeometry(10, 80, 200, 30);
  LabelOperation3->setParent(dialog);
  LabelOperation3->show();

  QLabel *LabelOperation4 = new QLabel();
  LabelOperation4->setText("Číslice 0123456789");
  LabelOperation4->setGeometry(10, 100, 200, 30);
  LabelOperation4->setParent(dialog);
  LabelOperation4->show();

  QLabel *LabelOperation5 = new QLabel();
  LabelOperation5->setText("Zmáčknutelné 'del' 'enter' 'backward'");
  LabelOperation5->setGeometry(10, 120, 200, 30);
  LabelOperation5->setParent(dialog);
  LabelOperation5->show();

  QLabel *LabelExit = new QLabel();
  LabelExit->setText("ESC ukončí program");
  LabelExit->setGeometry(10, 140, 200, 30);
  LabelExit->setParent(dialog);
  LabelExit->show();

  QLabel *LabelResult = new QLabel();
  LabelResult->setText("Hodně štěstí a příjemnou práci :)");
  LabelResult->setGeometry(10, 160, 200, 30);
  LabelResult->setParent(dialog);
  LabelResult->show();

  ExitButton->setText("Odejít z nápovědy");
  ExitButton->setGeometry(30, 250, 160, 30);
  ExitButton->setParent(dialog);
  ExitButton->show();
  dialog->show();
}
void MainWindow::exitButton_clicked() { dialog->close(); }

void MainWindow::on_button_factorial_clicked() {
  handleOperation("!");
  result();
}

void MainWindow::on_button_1_over_x_clicked() {
  handleOperation("1/x");
  result();
}

void MainWindow::on_button_exp_x_root_y_clicked() { handleOperation("√"); }
