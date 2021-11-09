#include <QCoreApplication>
#include <QString>

#include <iostream>

//#include <QTextStream>
//QTextStream cout(stdout);
//QTextStream cin(stdin);


#include "apiresponse.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    APIResponse api;

    std::string key;

    std::cin >> key;

    //api.getRooms(key);




    return a.exec();
}
