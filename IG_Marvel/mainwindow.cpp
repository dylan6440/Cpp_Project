#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_grid = new QGridLayout();

    const QSize btnSize = QSize(200,200);
    m_generer = new QPushButton("Generer");
    m_generer->resize(btnSize);
    //connect(m_generer,&QPushButton::released,this); //&MainWindow::generer
    m_grid->addWidget(m_generer,2,0);


    m_nbrGenerations = new QLineEdit("Nbr generations");
    m_grid->addWidget(m_nbrGenerations,1,0);


    m_vainqueur= new QLabel();
    m_vainqueur->setText("Vainqueur \n");
    m_grid->addWidget(m_vainqueur,1,1);

    m_force= new QLabel();
    m_force->setText("Force :\n");
    m_grid->addWidget(m_force,2,1);

    m_intelligence= new QLabel();
    m_intelligence->setText("Intelligence :\n");
    m_grid->addWidget(m_intelligence,3,1);

    m_agilite= new QLabel();
    m_agilite->setText("Agilite :\n");
    m_grid->addWidget(m_agilite,4,1);

    m_magiePuissance= new QLabel();
    m_magiePuissance->setText("Magie / Puissance de feu :\n");
    m_grid->addWidget(m_magiePuissance,5,1);

    m_res= new QLabel();
    m_res->setText("Resistance :\n");
    m_grid->addWidget(m_res,6,1);

    m_style= new QLabel();
    m_style->setText("Resistance :\n");
    m_grid->addWidget(m_style,7,1);

    /*
    m_label = new QLabel(this);
    m_pixmap_img = new QPixmap("url(ironman.png)");
    QPixmap scaled = m_pixmap_img->scaled(QSize(320,380));
    m_label->setPixmap(scaled);
    m_grid->addWidget(m_label,0,1);
    */

    QWidget* window = new QWidget;


    window->setLayout(m_grid);
    setCentralWidget(window);

}

MainWindow::~MainWindow()
{

}
