#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>


int main(int argc, char *argv[])
{
    QApplication application(argc,argv);
    QWidget windows;
    QTextEdit* input = new QTextEdit();
    input->setText("Hola mundo!");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(input);
    windows.setLayout(layout);
    windows.show();
    //Necesitamos un ciclo para que el programa
    //siga ejecutándose
    return application.exec();
}
