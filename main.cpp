
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x)
{
  return(1/x);
}
 int N = 1000; //liczba punktów/prostokątów podziałowych
  double xp,xk,s,dx,x,st;
  int i;
void metodaProstokatow(double xp, double xk)
{
    s  = 0;
  dx = (xk - xp) / N;
  for(i = 1; i <= N; i++) s += f(xp + i * dx);
  s *= dx;
  cout << "Dla metody *PROSTOKATOW* wartosc calki wynosi : " << setw(8) << s
  << endl << endl;
}
void metodaTrapezow(double xp, double xk)
{
   s  = 0;
  dx = (xk - xp) / N;
  for(i = 1; i < N; i++) s += f(xp + i * dx);
  s = (s + (f(xp) + f(xk)) / 2) * dx;
  cout << "Dla metody *TRAPEZOWEJ* wartosc calki wynosi : " << setw(8) << s
       << endl << endl;
}
void metodaSimpsona(double xp, double xk)
{
   s  = 0; st = 0;
  dx = (xk - xp) / N;
  for(i = 1; i <= N; i++)
  {
    x = xp + i * dx;
    st += f(x - dx / 2);
    if(i < N) s += f(x);
  }
  s = dx / 6 * (f(xp) + f(xk) + 2 * s + 4 * st);
  cout << "Dla metody *SIMPSONA* Wartosc calki wynosi : " << setw(8) << s
       << endl << endl;
}

int main()
{


  cout << setprecision(5)      // 5 cyfry po przecinku
       << fixed;               // format stałoprzecinkowy

  cout << "Obliczanie  calki oznaczonej\n"
          "za pomoca roznych metod     \n"
          "----------------------------\n"
          "f(x) = 1/x\n\n"
          "Podaj poczatek przedzialu calkowania\n\n"
          "xp = ";
  cin >> xp;
  cout << "\nPodaj koniec przedzialu calkowania\n\n"
          "xk = ";
  cin >> xk;
  cout << endl;
  cout<<"Podaj ilosc punktow przedzialowych\n\n"
        "N = ";
    cin>>N;
    cout << endl;
    metodaProstokatow(xp,xk);
    metodaTrapezow(xp,xk);
    metodaSimpsona(xp,xk);
  system("pause");
  return 0;
}
