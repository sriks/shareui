#include <QString>
#include <QDebug>
#include <MDataUri>
#include <maemo-meegotouch-interfaces/shareuiinterface.h>
#include "ShareUi.h"

const QString TITLE("title");
const QString DESCRIPTION("description");
const QString TYPE_TEXT_URL("text/x-url");

ShareUi::ShareUi(QObject *parent) :
    QObject(parent) {}

bool ShareUi::shareUrl(QString link, QString title, QString description) {
    qDebug()<<Q_FUNC_INFO<< "Make data URI from"
             << link << title << description;
//    QString link = "http://forum.nokia.com";
//    QString title = "Forum Nokia";
//    QString desc = "Support for Nokia Developers";

    bool res = false;
    MDataUri duri;
    duri.setMimeType(TYPE_TEXT_URL);
    duri.setTextData(link);
    duri.setAttribute(TITLE, title);
    duri.setAttribute(DESCRIPTION,description);

    if (duri.isValid()) {
        QStringList items;
        items << duri.toString();
        qDebug() << Q_FUNC_INFO<<"URI:" << items.join (" ");

        ShareUiInterface shareIf("com.nokia.ShareUi");
           // Check if interface is valid
        res = shareIf.isValid();
        if (res)
            shareIf.share(items);
        else
            qWarning()<<Q_FUNC_INFO<<"Invalid interface";
    } else {
        qWarning()<<Q_FUNC_INFO<<"Invalid URI";
    }
return res;
}

// eof
