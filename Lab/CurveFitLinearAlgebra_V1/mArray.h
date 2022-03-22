#ifndef MARRAY_H
#define MARRAY_H

class mArray
{
	private:
		int      Rows;  //Rows of the Array
		int      Cols;  //Cols of the Array
		double **Data;  //Dynamic 2D Array
	public:
		mArray(char *);
		mArray(int,int);
		mArray(const mArray &);
		mArray(bool,const mArray &,int,int,int,int);
                mArray(bool,const mArray &);
		~mArray();
		mArray operator+(const mArray &);
		mArray operator-(const mArray &);
		mArray operator*(const mArray &);
		mArray operator=(const mArray &);
		static mArray logsig(const mArray &);
                static mArray invMat(const mArray &);
		int *sort(int);
		void mPrint(char *);
		int getRows()const {return Rows;};
		int getCols()const {return Cols;};
		double getData(int r,int c)const {return Data[r][c];};
		void setData(double a,int r,int c){Data[r][c]=a;};
};

#endif