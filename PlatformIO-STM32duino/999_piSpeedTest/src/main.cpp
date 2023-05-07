#include <Arduino.h>

double piGaussLegendre(long int n)
{
  long double an = 1.0, bn = 1.0 / sqrt(2), tn = 0.25, pn = 1.0, a_pom;
  while (n--)
  {
    a_pom = an;
    an = (an + bn) / 2;
    bn = sqrt(a_pom * bn);
    tn = tn - pn * pow(a_pom - an, 2);
    pn *= 2;
  }
  return pow(an + bn, 2) / (4.0 * tn);
}

double piBrouncker(long int n)
{
  double wartosc = 2;
  for (; n >= 0; n--)
  {
    wartosc = double((2 * n + 1) * (2 * n + 1)) / (2.0 + wartosc);
  }
  return 4.0 / (1.0 + wartosc);
}

double piMonteCarlo(long int n)
{
  double x, y;
  long int T = 0;
  for (long int i = 0; i < n; i++)
  {
    x = double(rand()) / RAND_MAX - 0.5;
    y = double(rand()) / RAND_MAX - 0.5;
    if (x * x + y * y <= 0.25)
    {
      T++;
    }
  }
  return 4 * double(T) / n;
}

void setup()
{
  Serial.begin(115200);

  long int n;

  Serial.println("Metoda Gauss–Legendre");
  auto start = millis();
  for (n = 0; n < 100; n++)
  {
    volatile double out = piGaussLegendre(n);
  }
  auto stop = millis();
  auto duration = stop - start;
  Serial.print("Czas wykonania : ");
  Serial.print(duration);
  Serial.println(" [ms]");

  Serial.println("Metoda Brouncker'a");
  start = millis();
  for (n = 0; n <= 10000; n += 1000)
  {
    volatile double out = piBrouncker(n);
  }
  stop = millis();
  duration = stop - start;
  Serial.print("Czas wykonania : ");
  Serial.print(duration);
  Serial.println(" [ms]");

  Serial.println("Metoda Monte Carlo");
  start = millis();
  for (n = 0; n < 100; n++)
  {
    volatile double out = piGaussLegendre(n);
  }
  stop = millis();
  duration = stop - start;
  Serial.print("Czas wykonania : ");
  Serial.print(duration);
  Serial.println(" [ms]");
}

/*
esp32 - D0WDxx
Metoda Gauss–Legendre
Czas wykonania : 32 [ms]
Metoda Brouncker'a
Czas wykonania : 158 [ms]
Metoda Monte Carlo
Czas wykonania : 31 [ms]
*/

/*
esp32 S2
Metoda Gauss–Legendre
Czas wykonania : 37 [ms]
Metoda Brouncker'a
Czas wykonania : 219 [ms]
Metoda Monte Carlo
Czas wykonania : 37 [ms]
*/

/*
esp32 C3
Metoda Gauss–Legendre
Czas wykonania : 179 [ms]
Metoda Brouncker'a
Czas wykonania : 199 [ms]
Metoda Monte Carlo
Czas wykonania : 179 [ms]
*/

/*
stm32 nucleo-F207ZGT
Metoda Gauss–Legendre
Czas wykonania : 68 [ms]
Metoda Brouncker'a
Czas wykonania : 350 [ms]
Metoda Monte Carlo
Czas wykonania : 69 [ms]
*/

/*
stm32 nucleo-F439ZIT
Metoda Gauss–Legendre
Czas wykonania : 52 [ms]
Metoda Brouncker'a
Czas wykonania : 252 [ms]
Metoda Monte Carlo
Czas wykonania : 53 [ms]
*/

/*
stm32 nucleo-F746ZGT
Metoda Gauss–Legendre
Czas wykonania : 26 [ms]
Metoda Brouncker'a
Czas wykonania : 123 [ms]
Metoda Monte Carlo
Czas wykonania : 26 [ms]
*/

void loop()
{
  delay(10);
}
