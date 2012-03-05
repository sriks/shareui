#ifndef SHAREUI_H
#define SHAREUI_H

#include <QObject>

class ShareUi : public QObject
{
    Q_OBJECT
public:
    explicit ShareUi(QObject *parent = 0);
public slots:
    bool shareUrl(QString link, QString title=QString(), QString description=QString());
};

#endif // SHAREUI_H
