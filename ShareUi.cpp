/*!
  Class to invoke share ui in harmattan.
  Referenced from sharebear example.
  **/

#include <QString>
#include <QDebug>
#include <MDataUri>
#include <maemo-meegotouch-interfaces/shareuiinterface.h>
#include "ShareUi.h"

const QString TITLE("title");
const QString DESCRIPTION("description"); // old impl
const QString TYPE_TEXT_URL("text/x-url"); // old impl

ShareUi::ShareUi(QObject *parent) :
    QObject(parent) {}

/*!
  Shares the content using Harmattan share framework.
  **/
bool ShareUi::share(QString title, QString description, QString url) {

    bool res = false;
    MDataUri duri;
    duri.setMimeType(TYPE_TEXT_URL);

// Old implementation for reference
//    duri.setTextData(url);
//    duri.setAttribute(TITLE, title);
//    duri.setAttribute(DESCRIPTION,description);

    QString content = title+"\n"+description+"\n"+url;
    duri.setTextData(content);
    if (duri.isValid()) {
        QStringList items;
        items << duri.toString();
        ShareUiInterface shareIf("com.nokia.ShareUi");
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
