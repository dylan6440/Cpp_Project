#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPixmap>
#include <QUrl>
#include <QFileInfo>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QPushButton* m_generer;
    QLineEdit* m_nbrGenerations;
    QLabel *m_vainqueur;
    QLabel *m_force;
    QLabel *m_intelligence;
    QLabel *m_agilite;
    QLabel *m_magiePuissance;
    QLabel *m_res;
    QLabel *m_style;

    QGridLayout* m_grid;
/*
    QLabel* m_label;
    QPixmap* m_pixmap_img;
*/
public slots:
    //void generer();
};
#endif // MAINWINDOW_H
