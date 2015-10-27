static inline
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
void set_initial_result (gsl_integration_workspace * workspace, 
                         double result, double error);

static inline
void set_initial_result (gsl_integration_workspace * workspace, 
                         double result, double error)
=======
void set_initial_result (gsl_integration_workspace * workspace,
			 double result, double error);

static inline
void set_initial_result (gsl_integration_workspace * workspace,
			 double result, double error)
>>>>>>> config
{
  workspace->size = 1;
  workspace->rlist[0] = result;
  workspace->elist[0] = error;
}
