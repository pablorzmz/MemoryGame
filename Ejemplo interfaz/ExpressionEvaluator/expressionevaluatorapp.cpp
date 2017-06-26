#include "expressionevaluatorapp.h"

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

ExpressionEvaluatorApp::ExpressionEvaluatorApp(int &argc, char *argv[])
:QApplication(argc,argv)
{
    //Si lo hacemos en memoria dinámica, si debemos eliminarlo
    QTextEdit* input = new QTextEdit();
    input->setText("Hola mundo!");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(input);
    windows->setLayout(layout);
    //esta en memoria de pila, se destruye automáticamente.
    windows->show();
    //Necesitamos un ciclo para que el programa
    //siga ejecutándose

}



