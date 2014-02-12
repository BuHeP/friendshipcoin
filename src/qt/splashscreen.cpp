#include "splashscreen.h"
#include "clientversion.h"
#include "util.h"

#include <QPainter>
#undef loop /* ugh, remove this when the #define loop is gone from util.h */
#include <QApplication>

SplashScreen::SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f) :
    QSplashScreen(pixmap, f)
{
    // set reference point, paddings
    int paddingLeftCol2         = 230;
    int paddingTopCol2          = 376;
    int line1 = 0;
    int line2 = 13;
    int line3 = 26;

    float fontFactor            = 1.0;

    // define text to place
    //QString titleText       = QString(QApplication::applicationName()).replace(QString("-testnet"), QString(""), Qt::CaseSensitive); // cut of testnet, place it as single object further down
   // QString versionText     = QString("Version %1 ").arg(QString::fromStdString(FormatFullVersion()));
    //QString copyrightText1   = QChar(0xA9)+QString(" 2009-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The Bitcoin developers"));
    //QString copyrightText2   = QChar(0xA9)+QString(" 2011-%1 ").arg(COPYRIGHT_YEAR) + QString(tr("The Friendshipcoin developers"));

    QString font            = "Arial";

    // load the bitmap for writing some text over it
    QPixmap newPixmap;
    if(GetBoolArg("-testnet")) {
        newPixmap     = QPixmap(":/images/splash_testnet");
    }
    else {
        newPixmap     = QPixmap(":/images/splash");
    }

    QPainter pixPaint(&newPixmap);
    pixPaint.setPen(QColor(70,70,70));
    // draw copyright stuff
    pixPaint.end();

    this->setPixmap(newPixmap);
}
