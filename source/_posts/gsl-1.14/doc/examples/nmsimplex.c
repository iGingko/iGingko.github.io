<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
=======
int
>>>>>>> config
main(void)
{
  double par[5] = {1.0, 2.0, 10.0, 20.0, 30.0};

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  const gsl_multimin_fminimizer_type *T = 
=======
  const gsl_multimin_fminimizer_type *T =
>>>>>>> config
    gsl_multimin_fminimizer_nmsimplex2;
  gsl_multimin_fminimizer *s = NULL;
  gsl_vector *ss, *x;
  gsl_multimin_function minex_func;

  size_t iter = 0;
  int status;
  double size;

  /* Starting point */
  x = gsl_vector_alloc (2);
  gsl_vector_set (x, 0, 5.0);
  gsl_vector_set (x, 1, 7.0);

  /* Set initial step sizes to 1 */
  ss = gsl_vector_alloc (2);
  gsl_vector_set_all (ss, 1.0);

  /* Initialize method and iterate */
  minex_func.n = 2;
  minex_func.f = my_f;
  minex_func.params = par;

  s = gsl_multimin_fminimizer_alloc (T, 2);
  gsl_multimin_fminimizer_set (s, &minex_func, x, ss);

  do
    {
      iter++;
      status = gsl_multimin_fminimizer_iterate(s);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
      if (status) 
        break;
=======

      if (status)
	break;
>>>>>>> config

      size = gsl_multimin_fminimizer_size (s);
      status = gsl_multimin_test_size (size, 1e-2);

      if (status == GSL_SUCCESS)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          printf ("converged to minimum at\n");
        }

      printf ("%5d %10.3e %10.3e f() = %7.3f size = %.3f\n", 
              iter,
              gsl_vector_get (s->x, 0), 
              gsl_vector_get (s->x, 1), 
              s->fval, size);
    }
  while (status == GSL_CONTINUE && iter < 100);
  
=======
	{
	  printf ("converged to minimum at\n");
	}

      printf ("%5d %10.3e %10.3e f() = %7.3f size = %.3f\n",
	      iter,
	      gsl_vector_get (s->x, 0),
	      gsl_vector_get (s->x, 1),
	      s->fval, size);
    }
  while (status == GSL_CONTINUE && iter < 100);

>>>>>>> config
  gsl_vector_free(x);
  gsl_vector_free(ss);
  gsl_multimin_fminimizer_free (s);

  return status;
}
