#ifndef KLASY_H
#define KLASY_H

#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QVector>
#include <time.h>
#include <fstream>
#include <QList>

class komorka
{
    private:
        int x;
        int y;
        int stan;

    public:
        komorka();
        void poczatek(int a,int b);
        void nowa();
        void smierc();
        int sprawdz();
        void event(int suma,int stanb);
        komorka& operator =(const komorka &k);

        friend class Tabela;
};

class swiat
{
    private:
        QVector< QVector<komorka> > tab;

    public:
        swiat();
        swiat(int row,int col,QVector<int> rzad,QVector<int> kolumna);
        swiat(int row,int col);
        QVector< QVector<int> > zyj(int row,int col);
        void generacja(int row,int col);
        void event(int suma);
        ~swiat();
        swiat& operator =(const swiat &w);

        friend class Tabela;
};

void sleep(unsigned int mseconds);


#endif // KLASY_H
