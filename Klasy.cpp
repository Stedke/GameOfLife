#include "Klasy.h"

using namespace std;

swiat::~swiat()
{

}

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void swiat::generacja(int row,int col)
{
    int i,j,suma=0;
    swiat B(row,col);

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==0 && j==0)
            {
                suma=tab[0][1].sprawdz()+tab[1][0].sprawdz()+tab[1][1].sprawdz();
                (B.tab)[0][0].event(suma,tab[0][0].sprawdz());
                suma=0;
            }
            else
            {
                if(i==row-1 && j==0)
                {
                    suma=tab[row-1][1].sprawdz()+tab[row-2][0].sprawdz()+tab[row-2][1].sprawdz();
                    (B.tab)[row-1][0].event(suma,tab[row-1][0].sprawdz());
                    suma=0;
                }
                else
                {
                    if(i==0 && j==col-1)
                    {
                        suma=tab[0][col-2].sprawdz()+tab[1][col-1].sprawdz()+tab[1][col-2].sprawdz();
                        (B.tab)[0][col-1].event(suma,tab[0][col-1].sprawdz());
                        suma=0;
                    }
                    else
                    {
                        if(i==row-1 && j==col-1)
                        {
                            suma=tab[row-1][col-2].sprawdz()+tab[row-2][col-1].sprawdz()+tab[row-2][col-2].sprawdz();
                            (B.tab)[row-1][col-1].event(suma,tab[row-1][col-1].sprawdz());
                            suma=0;
                        }
                        else
                        {
                            if(i==0)
                            {
                                suma=tab[0][j+1].sprawdz()+tab[0][j-1].sprawdz()+tab[1][j].sprawdz()+tab[1][j+1].sprawdz()+tab[1][j-1].sprawdz();
                                (B.tab)[0][j].event(suma,tab[0][j].sprawdz());
                                suma=0;
                            }
                            else
                            {
                                if(i==row-1)
                                {
                                    suma=tab[row-1][j+1].sprawdz()+tab[row-1][j-1].sprawdz()+tab[row-2][j].sprawdz()+tab[row-2][j+1].sprawdz()+tab[row-2][j-1].sprawdz();
                                    (B.tab)[row-1][j].event(suma,tab[row-1][j].sprawdz());
                                    suma=0;
                                }
                                else
                                {
                                    if(j==0)
                                    {
                                        suma=tab[i-1][0].sprawdz()+tab[i+1][0].sprawdz()+tab[i][1].sprawdz()+tab[i-1][1].sprawdz()+tab[i+1][1].sprawdz();
                                        (B.tab)[i][0].event(suma,tab[i][0].sprawdz());
                                        suma=0;
                                    }
                                    else
                                    {
                                        if(j==col-1)
                                        {
                                            suma=tab[i-1][col-1].sprawdz()+tab[i+1][col-1].sprawdz()+tab[i][col-2].sprawdz()+tab[i-1][col-2].sprawdz()+tab[i+1][col-2].sprawdz();
                                            (B.tab)[i][col-1].event(suma,tab[i][col-1].sprawdz());
                                            suma=0;

                                        }
                                        else
                                        {
                                            suma=tab[i-1][j-1].sprawdz()+tab[i-1][j].sprawdz()+tab[i-1][j+1].sprawdz()+tab[i][j+1].sprawdz()+tab[i][j-1].sprawdz()+tab[i+1][j-1].sprawdz()+tab[i+1][j].sprawdz()+tab[i+1][j+1].sprawdz();
                                            (B.tab)[i][j].event(suma,tab[i][j].sprawdz());
                                            suma=0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            (this->tab)[i][j]=(B.tab)[i][j];
}

void komorka::event(int suma,int stanb)
{
    if(suma==3)
        this->nowa();

    if(suma==2 && stanb==1)
        this->nowa();

    if(suma==2 && stanb==0)
        this->smierc();

    if(suma==0 || suma==1)
        this->smierc();

    if(suma>3)
        this->smierc();
}

int komorka::sprawdz()
{
    return stan;
}

void komorka::nowa()
{
    stan=1;
}

void komorka::smierc()
{
    stan=0;
}

QVector< QVector<int> > swiat::zyj(int row,int col)
{
   this->generacja(row,col);

   QVector<int> r;
   QVector<int> c;
   QVector< QVector<int> > wsk(2);

   for(int i=0;i<row;i++)
       for(int j=0;j<col;j++)
       {
           if((tab[i][j].sprawdz())==1)
           {
               r.append(i);
               c.append(j);
           }
       }

   wsk[0]=r;
   wsk[1]=c;

   return wsk;
}

void komorka::poczatek(int a, int b)
{
    x=a;
    y=b;
}

komorka::komorka()
{
    x=0;
    y=0;
    stan=0;
}

swiat::swiat() :
    tab(1)
{}

swiat::swiat(int row, int col,QVector<int> rzad,QVector<int> kolumna) :
    tab(row)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            komorka a;

            tab[i].append(a);
            tab[i][j].poczatek(j,i);
        }

    for(int i=0;i<rzad.size();i++)
    {
        tab[rzad[i]][kolumna[i]].nowa();
    }
}

swiat::swiat(int row, int col) :
    tab(row)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            komorka a;

            tab[i].append(a);
            tab[i][j].poczatek(j,i);
        }
}

komorka& komorka::operator =(const komorka &k)
{
    this->x=k.x;
    this->y=k.y;
    this->stan=k.stan;

    return *this;
}

swiat& swiat::operator =(const swiat &w)
{

    this->tab=w.tab;

    return *this;
}



