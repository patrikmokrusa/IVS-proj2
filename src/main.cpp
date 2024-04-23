//============================================================================//
//
// Purpose:     Driver program for UI
//
// $NoKeywords: $kalkulacka $main.cpp $UI
// $Author:    Adam Černoš <xcernoa00@stud.fit.vutbr.cz>
// $Date:       $2024-22-04
//============================================================================//
/**
 * @file main.cpp
 * @author Adam Černoš
 * 
 *
 * @brief Driver program pro UI
 */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
