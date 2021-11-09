#include "apiresponse.h"

APIResponse::APIResponse()
{

    networkManager = new QNetworkAccessManager;

    connect(networkManager, &QNetworkAccessManager::finished, this, &APIResponse::setReplyFromAPI);

    networkManager->get(QNetworkRequest(QUrl("http://localhost:5000/api/Room")));

}

/*
void APIResponse::onResult(QNetworkReply* reply)
{

    replyFromAPI = reply;


    if(!reply->error()){

        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

        QJsonArray root = document.array();

        //QJsonObject firstObject = (root.at(15)).toObject();

        for(int i = 0; i < root.count(); ++i)
        {
            //QJsonObject roomObject = (root.at(i)).toObject();
            //QString rootString = roomObject.value("wrpName").toString();
            //((root.at(i)).toObject()).value("wrpName").toString()
            //listofRooms->append(((root.at(i)).toObject()).value("wrpName").toString());

            qDebug() << ((root.at(i)).toObject()).value("wrpName").toString();
        }

        //listofRooms->append()
        //qDebug() << firstObject.value("wrpName").toString();
        //qDebug() << firstObject.keys().at(0) << " : " << firstObject.value((firstObject.keys().at(0))).toDouble();
        //qDebug() << firstObject.keys().at(1) << " : " << firstObject.value((firstObject.keys().at(1))).toString();
        //qDebug() << firstObject.keys().at(2) << " : " << firstObject.value((firstObject.keys().at(2))).toDouble();
        //qDebug() << firstObject.keys().at(3) << " : " << firstObject.value((firstObject.keys().at(3))).toString();
        //qDebug() << firstObject.keys().at(4) << " : " << firstObject.value((firstObject.keys().at(4))).toDouble();

    }

}
*/

QNetworkReply *APIResponse::getReplyFromAPI() const
{
    return replyFromAPI;
}

void APIResponse::setReplyFromAPI(QNetworkReply *newReplyFromAPI)
{
    if(!newReplyFromAPI->error())
    {
        replyFromAPI = newReplyFromAPI;
    }
}

void APIResponse::getRooms(const QString &keyRoomValue)
{
    QJsonDocument document = QJsonDocument::fromJson(replyFromAPI->readAll());

    QJsonArray root = document.array();

    for(int i = 0; i < root.count(); ++i)
    {
        qDebug() << ((root.at(i)).toObject()).value(keyRoomValue).toString();
    }
}




