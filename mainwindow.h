#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionWczytaj_triggered();

private:
    Ui::MainWindow *ui;
};

class Tabela : public QTableWidget
{
    Q_OBJECT

public:
    Tabela(QWidget *parent);

private:
    QTimer* zegar;

public slots:
    void Ozyw(int row,int column);
    void Rozmiar(int row,int col);
    void Start();
    void Symulacja(int row,int col);
    void Stale();
    void Iteracja();
    void Koniec();

signals:
    void Juz(int row,int col);
    void Koniecs();
};

class MOJpushbutton : public QPushButton
{
    Q_OBJECT

public:
    MOJpushbutton(QWidget *parent);

public slots:
    void Rozmiarrow(int rows);
    void Rozmiarcol(int cols);
    void Emituj();

private:
    int row;
    int col;

signals:
    void Nowyrozmiar(int rows,int cols);
};


#endif // MAINWINDOW_H
