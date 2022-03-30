/* 
 * Author: Willy Quezada
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
class AbsRow{
    protected:
        int size;
        int *rowData;
    public:
        virtual int getSize()const = 0;
        virtual int getData(int)const = 0;
};

class RowAray:public AbsRow{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int mrkRand(int);
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,int);
};

int RowAray::mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}

RowAray::RowAray(unsigned int n){
    size=n;
    rowData=new int[size];
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
    }
}

RowAray::~RowAray(){
    delete []rowData;
}

void RowAray::setData(int row,int val){
    if(row>=0&&row<size)rowData[row]=val;
    else rowData[row]=0;
}

class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual int getData(int,int)const = 0;
};

class Table:public AbsTabl{
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        int getData(int,int)const;
        void setData(int,int,int);
};

Table::Table(unsigned int rows,unsigned int cols){
    szRow=rows;
    szCol=cols;
    columns=new RowAray*[cols];
    for(int col=0;col<cols;col++){
        columns[col]=new RowAray(rows);
    }
}

Table::Table(const Table &a){
    //Student to supply
    szRow = a.szRow;
    szCol = a.szCol;
    columns = new RowAray * [szCol];
    for(int col = 0; col < szCol; col++){
        columns[col] = new RowAray(szRow);
        for(int row = 0; row < szRow; row++){
            int val = a.columns[col]->getData(row);
            columns[col]->setData(row, val);
        }
    }
        
}

Table::~Table(){
    //Student to supply
    for(int i = 0; i < szCol; i++)
    {
        delete columns[i];
    }
    columns = 0;
    delete [] columns;
}

int Table::getData(int row,int col)const{
    //Student to supply
    return columns[col]->getData(row);
}

void Table::setData(int row,int col,int val){
    //Student to supply
    columns[col]->setData(row,val);
}

class PlusTab:public Table
{
    public:
        PlusTab(unsigned int r,unsigned int c):Table(r,c){};
        PlusTab operator+(const PlusTab &);
};

PlusTab PlusTab::operator+(const PlusTab &a){
    //Student to supply
    PlusTab temp(this->getSzRow(),this->getSzCol());
    for(int i = 0; i < temp.getSzRow(); i++)
    {
        for(int j = 0; j < temp.getSzCol(); j++)
        {
           (temp.columns[j])->setData(i,this->getData(i,j) + a.getData(i,j));
        }
        
    }
    return temp;
}
//Global Constants

//Function Prototype
void prntTab(const Table &);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows,cols;
   
   //Initialize Variables
   cout<<"Input the Rows and Cols"<<endl;
   cout<<"For a 2-D Array composed of 1-D Rows"<<endl;
   cout<<"Created from Abstract Classes"<<endl;
   cout<<"Inherited to include Overloaded Operators"<<endl;
   cin>>rows>>cols;
   
   //Test out the Tables
   PlusTab tab1(rows,cols);
   PlusTab tab2(tab1);
   PlusTab tab3=tab1+tab2;
   
   //Print the tables
   cout<<"Abstracted and Polymorphic Print Table 1 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab1);
   cout<<"Copy Constructed Table 2 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab2);
   cout<<"Operator Overloaded Table 3 size is [row,col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab3);

   return 0;
}

void prntTab(const Table &a){
    cout<<endl;
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(4)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}
