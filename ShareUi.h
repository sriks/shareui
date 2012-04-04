#ifndef SHAREUI_H
#define SHAREUI_H

#include <QObject>

class ShareUi : public QObject
{
    Q_OBJECT
public:
    explicit ShareUi(QObject *parent = 0);
public slots:
    bool share(QString title, QString description, QString url);
};

#endif // SHAREUI_H
