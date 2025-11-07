#include <QCoreApplication>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Hello World" <<endl;

    return a.exec();
}
