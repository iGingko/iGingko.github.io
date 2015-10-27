#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_histogram.h>

int
main (int argc, char **argv)
{
  double a, b;
  size_t n;

  if (argc != 4)
    {
      printf ("Usage: gsl-histogram xmin xmax n\n"
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
              "Computes a histogram of the data "
              "on stdin using n bins from xmin "
              "to xmax\n");
=======
	      "Computes a histogram of the data "
	      "on stdin using n bins from xmin "
	      "to xmax\n");
>>>>>>> config
      exit (0);
    }

  a = atof (argv[1]);
  b = atof (argv[2]);
  n = atoi (argv[3]);

  {
    double x;
    gsl_histogram * h = gsl_histogram_alloc (n);
    gsl_histogram_set_ranges_uniform (h, a, b);

    while (fscanf (stdin, "%lg", &x) == 1)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        gsl_histogram_increment (h, x);
=======
	gsl_histogram_increment (h, x);
>>>>>>> config
      }
    gsl_histogram_fprintf (stdout, h, "%g", "%g");
    gsl_histogram_free (h);
  }
  exit (0);
}
