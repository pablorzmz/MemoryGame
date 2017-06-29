#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    //EL YA ES UN WIDEGET
    //CONECTAR UNA SEÑAL CON UN SLOTS
    m_input = new QTextEdit();
    connect(m_input,&QTextEdit::textChanged,this,&MainWindow::evaluateExpression);
    //se le puede enviar al padre por defecto QVBoxlayout(this);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_input);
    m_result = new QLabel();
    //usar tr, metodo que usan todos los objetos QObject
    m_result->setText(tr("Please insert an aritmetic expression"));
    layout->addWidget(m_result);
    setLayout(layout);
    show();

}

#include <iostream>
#include <ExpressionEvaluator.h>
# include <sstream>
void MainWindow::evaluateExpression()
{
    try {
        //Que retorne una referencia constante a donde este el texto de esto
        const QString& text =  m_input->document()->toPlainText();
        std::string stdString = qUtf8Printable(text);
        std::istringstream stream(stdString);
        double result =  ExpressionEvaluator<double>().evaluate(stream);
        std::cerr<<"Result: "<<result<<std::endl;
    } catch (std::underflow_error& exec) {
        std::cerr<<exec.what()<<std::endl;
    }


}
