#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_ntuple.h>
#include <gsl/gsl_test.h>
#include <gsl/gsl_ieee_utils.h>

struct data
{
  int num;
  double x;
  double y;
  double z;
};
int sel_func (void *ntuple_data, void * params);
double val_func (void *ntuple_data, void * params);

int
main (void)
{
  struct data ntuple_row;
  int i;

  double x[1000], y[1000], z[1000], f[100];

  gsl_ntuple_select_fn S;
  gsl_ntuple_value_fn V;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  double scale = 1.5;
  
=======

  double scale = 1.5;

>>>>>>> config
  gsl_ieee_env_setup ();

  S.function = &sel_func;
  S.params = &scale;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  V.function = &val_func;
  V.params = &scale;

  {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    gsl_ntuple *ntuple = gsl_ntuple_create ("test.dat", &ntuple_row, 
                                            sizeof (ntuple_row));
=======
    gsl_ntuple *ntuple = gsl_ntuple_create ("test.dat", &ntuple_row,
					    sizeof (ntuple_row));
>>>>>>> config

    int status = 0;

    for (i = 0; i < 100; i++) f[i] = 0;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    
    for (i = 0; i < 1000; i++)
      {
        double xi = 1.0 / (i + 1.5);
        double yi = xi * xi ;
        double zi = xi * xi * xi;
        
        ntuple_row.x = xi;
        ntuple_row.y = yi;
        ntuple_row.z = zi;
        ntuple_row.num = i;
        
        x[i] = xi; y[i] = yi; z[i] = zi;
        
        if (xi * scale < 0.1)
          {
            double v = xi + yi + zi;
            int k = (int)(100.0*v*scale);
            f[k]++;
          }

        /* printf ("x,y,z = %f,%f,%f; n=%x \n", ntuple_row.x,
           ntuple_row.y, ntuple_row.z, ntuple_row.num); */
        
        {
          int s = gsl_ntuple_bookdata (ntuple);

          if (s != GSL_SUCCESS)
            {
              status = 1;
            }
        }
      }
    
=======

    for (i = 0; i < 1000; i++)
      {
	double xi = 1.0 / (i + 1.5);
	double yi = xi * xi ;
	double zi = xi * xi * xi;

	ntuple_row.x = xi;
	ntuple_row.y = yi;
	ntuple_row.z = zi;
	ntuple_row.num = i;

	x[i] = xi; y[i] = yi; z[i] = zi;

	if (xi * scale < 0.1)
	  {
	    double v = xi + yi + zi;
	    int k = (int)(100.0*v*scale);
	    f[k]++;
	  }

	/* printf ("x,y,z = %f,%f,%f; n=%x \n", ntuple_row.x,
	   ntuple_row.y, ntuple_row.z, ntuple_row.num); */

	{
	  int s = gsl_ntuple_bookdata (ntuple);

	  if (s != GSL_SUCCESS)
	    {
	      status = 1;
	    }
	}
      }

>>>>>>> config
    gsl_ntuple_close (ntuple);

    gsl_test (status, "writing ntuples");
  }

  {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    gsl_ntuple *ntuple = gsl_ntuple_open ("test.dat", &ntuple_row, 
                                          sizeof (ntuple_row));
=======
    gsl_ntuple *ntuple = gsl_ntuple_open ("test.dat", &ntuple_row,
					  sizeof (ntuple_row));
>>>>>>> config
    int status = 0;

    for (i = 0; i < 1000; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        gsl_ntuple_read (ntuple);

        status = (ntuple_row.num != i);
        status |= (ntuple_row.x != x[i]);
        status |= (ntuple_row.y != y[i]);
        status |= (ntuple_row.z != z[i]);

        /* printf ("x,y,z = %f,%f,%f; n=%d\n", ntuple_row.x,
                ntuple_row.y, ntuple_row.z, ntuple_row.num); */
=======
	gsl_ntuple_read (ntuple);

	status = (ntuple_row.num != i);
	status |= (ntuple_row.x != x[i]);
	status |= (ntuple_row.y != y[i]);
	status |= (ntuple_row.z != z[i]);

	/* printf ("x,y,z = %f,%f,%f; n=%d\n", ntuple_row.x,
		ntuple_row.y, ntuple_row.z, ntuple_row.num); */
>>>>>>> config
      }
    gsl_ntuple_close (ntuple);

    gsl_test (status, "reading ntuples");
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  }    
=======
  }
>>>>>>> config

  {
    int status = 0;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    gsl_ntuple *ntuple = gsl_ntuple_open ("test.dat", &ntuple_row, 
                                          sizeof (ntuple_row));
=======
    gsl_ntuple *ntuple = gsl_ntuple_open ("test.dat", &ntuple_row,
					  sizeof (ntuple_row));
>>>>>>> config

    gsl_histogram *h = gsl_histogram_calloc_uniform (100, 0., 1.);

    gsl_ntuple_project (h, ntuple, &V, &S);

    gsl_ntuple_close (ntuple);

    /* gsl_histogram_fprintf (stdout, h, "%f", "%f"); */

    for (i = 0; i < 100; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        /* printf ("h  %g f  %g\n", h->bin[i], f[i]); */

        if (h->bin[i] != f[i])
          {
            status = 1;
          }
=======
	/* printf ("h  %g f  %g\n", h->bin[i], f[i]); */

	if (h->bin[i] != f[i])
	  {
	    status = 1;
	  }
>>>>>>> config
      }

    gsl_test (status, "histogramming ntuples");

    gsl_histogram_free (h);
  }

  exit (gsl_test_summary());
}

int
sel_func (void *ntuple_data, void * params)
{
  double x, y, z, scale;
  scale = *(double *)params;

  x = ((struct data *) ntuple_data)->x;
  y = ((struct data *) ntuple_data)->y;
  z = ((struct data *) ntuple_data)->z;

  return (x*scale < 0.1);
}

double
val_func (void *ntuple_data, void * params)
{
  double x, y, z, scale;
  scale = *(double *)params;

  x = ((struct data *) ntuple_data)->x;
  y = ((struct data *) ntuple_data)->y;
  z = ((struct data *) ntuple_data)->z;

  return (x + y + z) * scale;
}
