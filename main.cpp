#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
//====================FUNCTIONS====================
void mattimes(double t, double a[][3], double m[][3])
{
int i, j;
for(i = 0; i < 3; i++)
  for(j = 0; j < 3; j++)
    m[i][j] = t*a[i][j];
}

void matsub(double a[][3], double b[][3], double c[][3])
{
  int i, j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      c[i][j] = a[i][j]-b[i][j];
}
void matvecmult(double m[][3], double *v, double *prod)
{
  double sum;
  int i, j;
  for(i = 0; i < 3; i++)
  {
    sum = 0;
    for(j = 0; j < 3; j++)
    {
      sum += m[i][j] * v[j];
    }
    prod[i] = sum;
  }
}

void mattimes2(double t, double a[][2], double m[][2])
{
int i, j;
for(i = 0; i < 2; i++)
  for(j = 0; j < 2; j++)
    m[i][j] = t*a[i][j];
}

void matsub2(double a[][2], double b[][2], double c[][2])
{
  int i, j;
  for(i = 0; i < 2; i++)
    for(j = 0; j < 2; j++)
      c[i][j] = a[i][j]-b[i][j];
}
void matvecmult2(double m[][2], double *v, double *prod)
{
  double sum;
  int i, j;
  for(i = 0; i < 2; i++)
  {
    sum = 0;
    for(j = 0; j < 2; j++)
    {
      sum += m[i][j] * v[j];
    }
    prod[i] = sum;
  }
}

//====================PROBLEM 1====================
void probOne()
{
  /**********INPUTS**********/
  ofstream outfile ("P1");
  double y0, y, deltat, t, a, n, lbound, ubound, SAMPLE_RATE;

  /**********INPUT MENU**********/
  cout << "Enter number of iterations: ";
  cin >> n;
  cout << "Enter lower bound: ";
  cin >> lbound;
  cout << "Enter upper bound: ";
  cin >> ubound;
  cout << "Enter intitial conditions y0: ";
  cin >> y0;
  cout << "Enter number input value for 'a': ";
  cin >> a;
  
  /**********INPUT VERIFY**********/
  cout << "Conditions entered for problem 1:" << endl;
  cout << "n = " << n << '\n' << "Lower Bound = " << lbound << '\n' << "Upper Bound" << ubound << '\n' << "Initial Conditions = " << y0 << '\n' << "a = " << a << endl;

  /**********ITERATIONS**********/
  //initial 
  deltat = 0.001;
  SAMPLE_RATE=n/deltat;
  y = y0;     
  outfile << 0 << " " << y << endl;
  //((ubound - lbound)/n);

  for(int i = 1; i < SAMPLE_RATE; i++) 
  {
    y = (1+a*deltat)*y;
    t=i*deltat;
    outfile << t << " " << y << endl;
  }
  outfile.close();
}

//====================PROBLEM 2====================
void probTwo()
{
  /**********INPUTS**********/
  ofstream outfile ("P2");
  double deltat, lbound, ubound, a0, a1, a2, x[3], n, SAMPLE_RATE;
  double mat1[3][3];
  double mat2[3][3];
  double I[3][3] = { { 1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
   
  /**********INPUT MENU**********/
  cout << "Enter number of iterations: ";
  cin >> n;
  cout << "Enter lower bound: ";
  cin >> lbound;
  cout << "Enter upper bound: ";
  cin >> ubound;

  x[0] = -2;
  x[1] = 3;
  x[2] = -1.7;
/*
  a0 = 1.802;
  a1 = 36.06;
  a2 = 0.45;
*/
  a0 = 72.5;
  a1 = 38.25;
  a2 = 3;
  
  double a[3][3] = { { 0, -1, 0}, {0, 0, -1}, {a0, a1, a2} };

  /**********INPUT VERIFY**********/
  cout << "Conditions entered for problem 2:" << endl;
  cout << "n = " << n << '\n' << "Lower Bound = " << lbound << '\n' << "Upper Bound" << ubound << '\n' << "Initial Conditions y0: " << x[0] << '\n' << "Initial Conditions 'y0: " << x[1] << '\n' << "Initial Conditions ''y0: " << x[2] << '\n' << endl;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << '\n';
  }

  /**********ITERATIONS**********/
  outfile << 0 << " " << x[0] << endl;
  float t = 0;
  deltat =0.001;
  SAMPLE_RATE=n/deltat;
  //x = (1+a*deltat)*x;
  for(int i = 1; i < SAMPLE_RATE; i++) 
  {
    t=i*deltat;
    mattimes(deltat, a, mat1);
    matsub(I, mat1, mat2);
    matvecmult(mat2, x, x);
    outfile << t << " " << x[0] << endl;
  }
  outfile.close();
}

//====================PROBLEM 3====================
void probThree()
{
  /**********INPUTS**********/
  ofstream outfile ("P3");
  double deltat, lbound, ubound, a0, a1, x[2], n, SAMPLE_RATE;
  double mat1[2][2];
  double mat2[2][2];
  double I[2][2] = {{1, 0}, {0, 1}};
   
  /**********INPUT MENU**********/
  cout << "Enter number of iterations: ";
  cin >> n;
  cout << "Enter lower bound: ";
  cin >> lbound;
  cout << "Enter upper bound: ";
  cin >> ubound;
  /*cout << "Enter intitial conditions for y0: ";
  cin >> x[0];
  cout << "Enter intitial conditions for 'y0: ";
  cin >> x[1];
  cout << "Enter number input value for a0: ";
  cin >> a0;
  cout << "Enter number input value for a1: ";
  cin >> a1;*/

  x[0] = 5;
  x[1] = 40.625;
  
  a0 =41.667;
  a1 =196.042;
  
  double a[2][2] = { { 0, -1}, {a0, a1} };
  /**********INPUT VERIFY**********/
  cout << "Conditions entered for problem 3:" << endl;
  cout << "n = " << n << '\n' << "Lower Bound = " << lbound << '\n' << "Upper Bound = " << ubound << '\n' << "Initial Conditions y0: " << x[0] << '\n' << "Initial Conditions 'y0: " << x[1] << '\n' << '\n' << endl;

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << '\n';
  }
  /**********ITERATIONS**********/
  //initial   
  outfile << 0 << " " << x[0] << endl;
  deltat = 0.001; 
  float t = 0;
  SAMPLE_RATE= (n/deltat);
  for(int i = 1; i < SAMPLE_RATE; i++)
  {
    t=i*deltat;
    mattimes2(deltat, a, mat1);
    matsub2(I, mat1, mat2);
    matvecmult2(mat2, x, x);
    outfile << t << " " << x[0] << endl;
  }
  outfile.close();
}

//====================MAIN====================
int main() 
{
  int choice = 0;
  /**********CASE**********/
  cout << "For Problem 1: Enter 1" << '\n' << "For Problem 2: Enter 2" << '\n' << "For Problem 3: Enter 3" << '\n' << "To Exit: Enter 4" << endl;
  cin >> choice;
  switch (choice)
  {
    case 1: 
      cout << "Entered 1" << endl;
      probOne();
      break;
      
    case 2: 
      cout << "Entered 2" << endl;
      probTwo();
      break;

    case 3: 
      cout << "Entered 3" << endl;
      probThree();
      break;

    case 4: 
      cout << "Entered 4" << endl;
      getchar();
      break;

    default:
      cout << "ERROR no input, exiting" << endl;
      break;
  }
}