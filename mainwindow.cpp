#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Klasy.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),ui->tableWidget,SLOT(Ozyw(int,int)));
    connect(ui->actionZamknij,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->pushButton,SLOT(Rozmiarrow(int)));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),ui->pushButton,SLOT(Rozmiarcol(int)));
    connect(ui->pushButton,SIGNAL(clicked()),ui->pushButton,SLOT(Emituj()));
    connect(ui->pushButton,SIGNAL(Nowyrozmiar(int,int)),ui->tableWidget,SLOT(Rozmiar(int,int)));
    connect(ui->pushButton_3,SIGNAL(clicked()),ui->tableWidget,SLOT(Start()));
    connect(ui->tableWidget,SIGNAL(Juz(int,int)),ui->tableWidget,SLOT(Symulacja(int,int)));
    connect(ui->pushButton_4,SIGNAL(clicked()),ui->tableWidget,SLOT(Stale()));
    connect(ui->pushButton_2,SIGNAL(clicked()),ui->tableWidget,SLOT(Koniec()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

Tabela::Tabela(QWidget *parent) :
    QTableWidget(parent)
{
    zegar= new QTimer(this);
    zegar->setInterval(200);

    connect(zegar,SIGNAL(timeout()),this,SLOT(Iteracja()));
    connect(this,SIGNAL(Koniecs()),zegar,SLOT(stop()));

    setColumnCount(10);
    setRowCount(10);

    for(int i=0;i<10;i++)
        setColumnWidth(i,800/10);

    for(int i=0;i<10;i++)
        setRowHeight(i,800/10);
}

void Tabela::Ozyw(int row, int column)
{
    QTableWidgetItem * newItem= new QTableWidgetItem("",1);
    newItem->setBackgroundColor(QColor(Qt::red));

    setItem(row,column,newItem);
}

void Tabela::Rozmiar(int row, int col)
{
    QList<QTableWidgetItem*> tablica;
    tablica=this->findItems("",Qt::MatchExactly);

    if(tablica.empty()==false)
        this->clearContents();

    setColumnCount(col);
    setRowCount(row);

    for(int i=0;i<col;i++)
        setColumnWidth(i,800/col);

    for(int i=0;i<row;i++)
        setRowHeight(i,800/row);
}

void Tabela::Start()
{
    emit Juz(rowCount(),columnCount());
}

void Tabela::Symulacja(int row, int col)
{
    QList<QTableWidgetItem *> lista;
    QVector<int> rzad;
    QVector<int> kolumna;
    QVector< QVector<int> > wsk;

    lista=(*this).findItems("",Qt::MatchExactly);

    for(int i=0;i<lista.length();i++)
    {
        rzad.append((lista[i])->row());
        kolumna.append((lista[i])->column());
    }

    swiat world(row,col,rzad,kolumna);

    wsk=world.zyj(row,col);

    this->clearContents();

    for(int i=0;i<wsk[0].size();i++)
    {
        QTableWidgetItem *newItem= new QTableWidgetItem("",3);
        newItem->setBackgroundColor(QColor(Qt::blue));

        setItem(wsk[0][i],wsk[1][i],newItem);
    }
}

void Tabela::Stale()
{
    zegar->start();
}

void Tabela::Iteracja()
{
    QList<QTableWidgetItem *> lista;
    QVector<int> rzad;
    QVector<int> kolumna;
    QVector< QVector<int> > wsk;

    lista=(*this).findItems("",Qt::MatchExactly);

    for(int j=0;j<lista.length();j++)
    {
        rzad.append((lista[j])->row());
        kolumna.append((lista[j])->column());
    }

    swiat world(this->rowCount(),this->columnCount(),rzad,kolumna);

    wsk=world.zyj(this->rowCount(),this->columnCount());

    this->clearContents();

    for(int k=0;k<wsk[0].size();k++)
    {
        QTableWidgetItem *newItem= new QTableWidgetItem("",4);
        newItem->setBackgroundColor(QColor(Qt::blue));

        setItem(wsk[0][k],wsk[1][k],newItem);
    }

    this->repaint();
}

void Tabela::Koniec()
{
    emit Koniecs();
}

MOJpushbutton::MOJpushbutton(QWidget *parent) :
    QPushButton(parent),row(0),col(0)
{}

void MOJpushbutton::Rozmiarrow(int rows)
{
    row=rows;
}

void MOJpushbutton::Rozmiarcol(int cols)
{
    col=cols;
}

void MOJpushbutton::Emituj()
{
    emit Nowyrozmiar(this->row,this->col);
}


void MainWindow::on_actionWczytaj_triggered()
{
   ui->tableWidget->Koniec();
   ui->tableWidget->Rozmiar(100,100);

   QVector<QTableWidgetItem*> wektor(36);

   QTableWidgetItem* wzor=new QTableWidgetItem("",7);
   wzor->setBackgroundColor(QColor(Qt::red));

   for(int i=0;i<36;i++)
       wektor[i]=new QTableWidgetItem(*wzor);

   ui->tableWidget->setItem(50,47,wektor[0]);
   ui->tableWidget->setItem(50,41,wektor[1]);
   ui->tableWidget->setItem(50,51,wektor[2]);
   ui->tableWidget->setItem(50,52,wektor[3]);
   ui->tableWidget->setItem(50,32,wektor[4]);
   ui->tableWidget->setItem(50,31,wektor[5]);
   ui->tableWidget->setItem(49,46,wektor[6]);
   ui->tableWidget->setItem(49,42,wektor[7]);
   ui->tableWidget->setItem(49,51,wektor[8]);
   ui->tableWidget->setItem(49,52,wektor[9]);
   ui->tableWidget->setItem(49,65,wektor[10]);
   ui->tableWidget->setItem(49,66,wektor[11]);
   ui->tableWidget->setItem(48,44,wektor[12]);
   ui->tableWidget->setItem(48,43,wektor[13]);
   ui->tableWidget->setItem(48,51,wektor[14]);
   ui->tableWidget->setItem(48,52,wektor[15]);
   ui->tableWidget->setItem(48,66,wektor[16]);
   ui->tableWidget->setItem(48,65,wektor[17]);
   ui->tableWidget->setItem(51,47,wektor[18]);
   ui->tableWidget->setItem(51,48,wektor[19]);
   ui->tableWidget->setItem(51,45,wektor[20]);
   ui->tableWidget->setItem(51,41,wektor[21]);
   ui->tableWidget->setItem(51,53,wektor[22]);
   ui->tableWidget->setItem(51,55,wektor[23]);
   ui->tableWidget->setItem(51,31,wektor[24]);
   ui->tableWidget->setItem(51,32,wektor[25]);
   ui->tableWidget->setItem(52,47,wektor[26]);
   ui->tableWidget->setItem(52,41,wektor[27]);
   ui->tableWidget->setItem(52,55,wektor[28]);
   ui->tableWidget->setItem(53,46,wektor[29]);
   ui->tableWidget->setItem(53,42,wektor[30]);
   ui->tableWidget->setItem(54,43,wektor[31]);
   ui->tableWidget->setItem(54,44,wektor[32]);
   ui->tableWidget->setItem(47,53,wektor[33]);
   ui->tableWidget->setItem(47,55,wektor[34]);
   ui->tableWidget->setItem(46,55,wektor[35]);

}
