#ifndef DISPLAYER_H
#define DISPLAYER_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include <QVector>
#include <QLabel>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QScrollArea>
#include <QListWidget>
#include <QLineF>
#include <QVBoxLayout>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QSpinBox>
#include <QLineEdit>
#include <QFormLayout>

#include "myqgraphicslineitem.h"
#include "myqgraphicsscene.h"

class MyQGraphicsLineItem;
class MyQGraphicsScene;
class Couple;

class Couple

{

public:

    Couple(qreal r, int im_number);
    qreal getRow() const;
    int getImageNumber() const;
    void setRow(qreal r);
    void setImageNumber(int im_number);

private:

    qreal row;
    int imageNumber;

};

class Displayer : public QWidget

{

public :

    Displayer(QWidget *parent, QString config);
    bool isEmpty();
    QVector<MyQGraphicsLineItem*> &getLines();
    QGraphicsView* getView();
    int getSceneHeight() const;
    void findSaveDir();
    QDir getSaveDir() const;
    QString getTestName() const;
    int getID() const;
    void showLineNumber(bool show);
    void showLabelPos(bool show, qreal pos = 0);
    void addImages(const QVector<QImage *> &im_vect);
    void setSceneWidth(int width);
    void drawLine(int posY);
    void removeLine(MyQGraphicsLineItem *line);
    void drawDivLines(const QVector<int> &splitPoints);
    void getSplitPoints(QVector<Couple *> *splitPoints);
    void clean(bool saveSuccess = false);

private :

    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QFormLayout *formLayout;
    QLabel *informations;
    MyQGraphicsScene *scene;
    QGraphicsView *view;
    bool empty;
    QGraphicsTextItem *emptyItem;
    QVector <MyQGraphicsLineItem*> lines;
    QVector <QGraphicsPixmapItem*> items;
    int sceneHeight;
    int sceneWidth;
    QLabel *lineNumber;
    QLabel *selectedLine;
    QLabel *position;
    QDir saveDir;
    QSpinBox *save_id;
    QLabel *Lsave_id;
    QLineEdit *testName;
    QLabel *LtestName;

};


#endif // DISPLAYER_H
