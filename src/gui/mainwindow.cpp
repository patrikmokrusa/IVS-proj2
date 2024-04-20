#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../mathlib.cpp"
#include <string>
#include <stdexcept>


#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString allowedInputs[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "."};
QString allowedOperations[] = { "^", "+", "-", "*", "/"};

void MainWindow::result()
{
    QString primary = ui->lineEdit_primary->text();
    QString secondary = ui->lineEdit_secondary->text();
    QString operation = ui->lineEdit_operation->text();

    double primary_d = primary.toDouble();
    double secondary_d = secondary.toDouble();
    double result;

    if (operation == "+")
    {
        result = k_plus(primary_d, secondary_d);
    }
    else if (operation == "-")
    {
        result = k_minus(primary_d, secondary_d);
    }
    else if (operation == "*")
    {
        result = k_krat(primary_d, secondary_d);
    }
    else if (operation == "/")
    {
        try {
            result = k_deleno(secondary_d, primary_d);
        }
        catch (std::overflow_error const& ex){
            ui->lineEdit_primary->setText(ex.what());
            return;
        }
    }
    else if (operation == "^")
    {
        try
        {
            result = k_mocnina(secondary_d, primary_d);
        }
        catch(std::out_of_range const& ex)
        {
            ui->lineEdit_primary->setText(ex.what());
            return;
        }
        
    }
    else if (operation == "√")
    {
        try
        {
            result = k_odmocnina(secondary_d, primary_d);
        }
        catch(const std::exception& e)
        {
            ui->lineEdit_primary->setText(e.what());
            return;
        }
        
    }
    reset();
    ui->lineEdit_primary->setText(QString::number(result));
}

void MainWindow::reset()
{
    ui->lineEdit_primary->setText("");
    ui->lineEdit_secondary->setText("");
    ui->lineEdit_operation->setText("");
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        result();
        return;
    }
    else if(event->key() == Qt::Key_Backspace) {
        ui->lineEdit_primary->backspace();
        return;
    }
    else if(event->key() == Qt::Key_Delete) {
        reset();
    }

    QString input = event->text();

    for (int i = 0; i < 5; i++){
        if(input == allowedOperations[i]) handleOperation(input);
    }

    for (int i = 0; i < 11; i++) {
        if(input == allowedInputs[i]) ui->lineEdit_primary->insert(input);
    }
}

void MainWindow::handleOperation(QString operand)
{
    QString primary = ui->lineEdit_primary->text();
    QString secondary = ui->lineEdit_secondary->text();
    QString operation = ui->lineEdit_operation->text();
    if(primary.length() == 0 && secondary.length() == 0) {
        return;
    }
    if(operation != "") {
        ui->lineEdit_operation->setText(operand);
        return;
    }

    ui->lineEdit_secondary->setText(primary);
    ui->lineEdit_operation->setText(operand);
    ui->lineEdit_primary->setText("");
}

void MainWindow::on_button_0_clicked()
{
    ui->lineEdit_primary->insert("0");
}

void MainWindow::on_button_1_clicked()
{

    ui->lineEdit_primary->insert("1");
}

void MainWindow::on_button_2_clicked()
{
    ui->lineEdit_primary->insert("2");
}

void MainWindow::on_button_3_clicked()
{
    ui->lineEdit_primary->insert("3");
}

void MainWindow::on_button_4_clicked()
{
    ui->lineEdit_primary->insert("4");
}

void MainWindow::on_button_5_clicked()
{
    ui->lineEdit_primary->insert("5");
}

void MainWindow::on_button_6_clicked()
{
    ui->lineEdit_primary->insert("6");
}

void MainWindow::on_button_7_clicked()
{
    ui->lineEdit_primary->insert("7");
}

void MainWindow::on_button_8_clicked()
{
    ui->lineEdit_primary->insert("8");
}

void MainWindow::on_button_9_clicked()
{
    ui->lineEdit_primary->insert("9");
}

void MainWindow::on_button_ac_clicked()
{
    reset();
}


void MainWindow::on_button_del_clicked()
{
    ui->lineEdit_primary->backspace();
}


void MainWindow::on_button_times_ten_clicked()
{
    QString text = ui->lineEdit_primary->text();
    if(text.length() == 0){
        return;
    }
    else if(text.length() == 1 && text[0] == '0'){
        return;
    }

    else if(text.contains(".")) {
        int index = text.indexOf('.');


        if(index == (text.length() - 1)) {
            ui->lineEdit_primary->backspace();
            ui->lineEdit_primary->insert("0");
        }
        else{
            text[index] = text[index + 1];
            text[index + 1] = '.';
            if(text[index + 1] == '\0'){
                ui->lineEdit_primary->setText(text);
            }
            else{
                ui->lineEdit_primary->setText(text);
            }
        }
    }
    else {
        ui->lineEdit_primary->insert("0");
    }
    return;
};


void MainWindow::on_button_plus_clicked()
{
    handleOperation("+");
}


void MainWindow::on_button_minus_clicked()
{
    handleOperation("-");
}


void MainWindow::on_button_times_clicked()
{
    handleOperation("*");
}


void MainWindow::on_button_div_clicked()
{
    handleOperation("/");
}

void MainWindow::on_button_y_exp_x_clicked()
{
    handleOperation("^");
}

void MainWindow::on_button_negate_clicked()
{
    QString text = ui->lineEdit_primary->text();
    if(text[0] == '-'){
        text.remove(0, 1);
        ui->lineEdit_primary->setText(text);

    }
    else{
        ui->lineEdit_primary->setText("-" + text);
    }
}


void MainWindow::on_button_decimal_clicked()
{
    QString text = ui->lineEdit_primary->text();
    if(text.contains(".")) {
        return;
    }
    else if(text.length() == 0) {
        ui->lineEdit_primary->setText("0.");
        return;
    }

    else {
        ui->lineEdit_primary->insert(".");
        return;
    }
}

void MainWindow::on_button_equals_clicked()
{

    result();
}

void MainWindow::on_button_factorial_clicked()
{
    ui->lineEdit_primary->setText("factorial");
}

