<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
for (I = problems ; I->f != 0; I++) 
{
  size_t i;
  double res, err; 
  
=======
for (I = problems ; I->f != 0; I++)
{
  size_t i;
  double res, err;

>>>>>>> config
  gsl_rng * r;

  if (I->dim > 3)
    {
      continue ;
    }

  r = gsl_rng_alloc (gsl_rng_default);

  for (i = 0; i < TRIALS ; i++)
    {
      MONTE_STATE *s = MONTE_ALLOC (I->dim);
#ifdef MONTE_PARAMS
      MONTE_PARAMS params;
#endif

      I->f->dim = I->dim;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
      MONTE_INTEGRATE (I->f, I->xl, I->xu, 
                       I->dim, I->calls / MONTE_SPEEDUP, r, s,
                       &res, &err);
      
      gsl_test_abs (res, I->expected_result, 
                    5 * GSL_MAX(err, 1024*GSL_DBL_EPSILON), 
                    NAME ", %s, result[%d]", I->description, i);
=======

      MONTE_INTEGRATE (I->f, I->xl, I->xu,
		       I->dim, I->calls / MONTE_SPEEDUP, r, s,
		       &res, &err);

      gsl_test_abs (res, I->expected_result,
		    5 * GSL_MAX(err, 1024*GSL_DBL_EPSILON),
		    NAME ", %s, result[%d]", I->description, i);
>>>>>>> config

      MONTE_ERROR_TEST (err, I->expected_error);

      result[i] = res;
      error[i] = err;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
      MONTE_FREE (s);
    }

  
  /* Check the results for consistency as an ensemble */

  { 
=======

      MONTE_FREE (s);
    }


  /* Check the results for consistency as an ensemble */

  {
>>>>>>> config
    double mean = 0, sumd2 = 0, sd;

    /* We need to compute the mean exactly when all terms are equal,
       to get an exact zero for the standard deviation (this is a
       common case when integrating a constant). */

    for (i = 0; i < TRIALS; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        mean += (result[i] - mean) / (i + 1.0);
      }

    for (i = 0; i < TRIALS; i++) 
      {
        sumd2 += pow(result[i] - mean, 2.0);
      }
    
    sd = sqrt(sumd2 / (TRIALS-1.0)) ;
    
    for (i = 0; i < TRIALS; i++)
      {
        gsl_test_factor (error[i], sd, 5.0,
                         NAME ", %s, abserr[%d] vs sd", I->description, i);
=======
	mean += (result[i] - mean) / (i + 1.0);
      }

    for (i = 0; i < TRIALS; i++)
      {
	sumd2 += pow(result[i] - mean, 2.0);
      }

    sd = sqrt(sumd2 / (TRIALS-1.0)) ;

    for (i = 0; i < TRIALS; i++)
      {
	gsl_test_factor (error[i], sd, 5.0,
			 NAME ", %s, abserr[%d] vs sd", I->description, i);
>>>>>>> config
      }
  }

  gsl_rng_free (r);
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
