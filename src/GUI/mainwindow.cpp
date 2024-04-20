#include "mainwindow.h"
#include "./ui_mainwindow.h"



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
    ui->lineEdit_primary->setText("");
    ui->lineEdit_secondary->setText("");
    ui->lineEdit_operation->setText("");

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

void MainWindow::on_button_div_by_ten_clicked()
{
    QString text = ui->lineEdit_primary->text();
    if(text.length() == 0){
        return;
    }
    else if(text.length() == 1 && text[0] == '0'){
        return;
    }
}


void MainWindow::on_button_plus_clicked()
{
    QString primary = ui->lineEdit_primary->text();
    QString secondary = ui->lineEdit_secondary->text();
    QString operation = ui->lineEdit_operation->text();
    if(ui->lineEdit_primary->text().length() == 0 && ui->lineEdit_secondary->text().length() == 0) {
        return;
    }
    if(operation != "") {
        ui->lineEdit_operation->setText("+");
        return;
    }

    ui->lineEdit_secondary->setText(primary);
    ui->lineEdit_operation->setText("+");
    ui->lineEdit_primary->setText("");
}


void MainWindow::on_button_minus_clicked()
{
    QString primary = ui->lineEdit_primary->text();
    QString secondary = ui->lineEdit_secondary->text();
    QString operation = ui->lineEdit_operation->text();

    if(ui->lineEdit_primary->text().length() == 0 && ui->lineEdit_secondary->text().length() == 0) {
        return;
    }
    if(operation != "") {
        ui->lineEdit_operation->setText("-");
        return;
    }

    ui->lineEdit_secondary->setText(primary);
    ui->lineEdit_operation->setText("-");
    ui->lineEdit_primary->setText("");
}


void MainWindow::on_button_times_clicked()
{
    QString primary = ui->lineEdit_primary->text();
    QString secondary = ui->lineEdit_secondary->text();
    QString operation = ui->lineEdit_operation->text();

    if(ui->lineEdit_primary->text().length() == 0 && ui->lineEdit_secondary->text().length() == 0) {
        return;
    }
    if(operation != "") {
        ui->lineEdit_operation->setText("*");
        return;
    }

    ui->lineEdit_secondary->setText(primary);
    ui->lineEdit_operation->setText("*");
    ui->lineEdit_primary->setText("");
}


void MainWindow::on_button_div_clicked()
{
    QString primary = ui->lineEdit_primary->text();
    QString secondary = ui->lineEdit_secondary->text();
    QString operation = ui->lineEdit_operation->text();

    if(ui->lineEdit_primary->text().length() == 0 && ui->lineEdit_secondary->text().length() == 0) {
        return;
    }
    if(operation != "") {
        ui->lineEdit_operation->setText("/");
        return;
    }

    ui->lineEdit_secondary->setText(primary);
    ui->lineEdit_operation->setText("*");
    ui->lineEdit_primary->setText("");
}

void MainWindow::on_button_equals_clicked()
{
    ui->lineEdit_secondary->setText("");
    ui->lineEdit_operation->setText("");
    ui->lineEdit_primary->setText("result");
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



