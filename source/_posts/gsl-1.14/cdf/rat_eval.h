static double
rat_eval (const double a[], const size_t na,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          const double b[], const size_t nb, const double x)
=======
	  const double b[], const size_t nb, const double x)
>>>>>>> config
{
  size_t i, j;
  double u, v, r;

  u = a[na - 1];

  for (i = na - 1; i > 0; i--)
    {
      u = x * u + a[i - 1];
    }

  v = b[nb - 1];

  for (j = nb - 1; j > 0; j--)
    {
      v = x * v + b[j - 1];
    }

  r = u / v;

  return r;
}
