/* Program usage: mpiexec -n 1 toy[-help] [all TAO options] */

/* ----------------------------------------------------------------------
min f=(x1-x2)^2 + (x2-2)^2 -2*x1-2*x2
s.t.     x1^2 + x2 = 2
      0 <= x1^2 - x2 <= 1
      -1 <= x1,x2 <= 2
---------------------------------------------------------------------- */

#include <petsctao.h>
#include <math.h>

PetscScalar Anfang = 1;
PetscScalar Ende = 1;
PetscScalar dt = 0.01;
PetscInt NN = 200;

static  char help[]="";

/*
   User-defined application context - contains data needed by the
   application-provided call-back routines, FormFunction(),
   FormGradient(), and FormHessian().
*/

/*
   x,d in R^n
   f in R
   bin in R^mi
   beq in R^me
   Aeq in R^(me x n)
   Ain in R^(mi x n)
   H in R^(n x n)
   min f=(1/2)*x'*H*x + d'*x
   s.t.  Aeq*x == beq
         Ain*x >= bin
*/
typedef struct {
  PetscInt n; /* Length x */
  PetscInt ne; /* number of equality constraints */
  PetscInt ni; /* number of inequality constraints */
  Vec      x;
} AppCtx;

/* -------- User-defined Routines --------- */

PetscErrorCode InitializeProblem(AppCtx *);
PetscErrorCode DestroyProblem(AppCtx *);
PetscErrorCode FormFunctionGradient(Tao,Vec,PetscReal *,Vec,void *);



PetscErrorCode main(int argc,char **argv)
{
  PetscErrorCode     ierr;                /* used to check for functions returning nonzeros */
  Tao                tao;
  AppCtx             user;                /* application context */

  ierr = PetscInitialize(&argc,&argv,(char *)0,help);if (ierr) return ierr;

  ierr = InitializeProblem(&user);CHKERRQ(ierr);
  ierr = TaoCreate(PETSC_COMM_WORLD,&tao);CHKERRQ(ierr);
  ierr = TaoSetType(tao,TAOBQNLS);CHKERRQ(ierr);
  ierr = TaoSetInitialVector(tao,user.x);CHKERRQ(ierr);
  ierr = TaoSetObjectiveAndGradientRoutine(tao,FormFunctionGradient,(void*)&user);CHKERRQ(ierr);

  ierr = TaoSetFromOptions(tao);CHKERRQ(ierr);

  ierr = TaoSolve(tao);CHKERRQ(ierr);
   
  ierr = DestroyProblem(&user);CHKERRQ(ierr);
  ierr = TaoDestroy(&tao);CHKERRQ(ierr);
  ierr = PetscFinalize();
  return ierr;
}

PetscErrorCode InitializeProblem(AppCtx *user)
{
  PetscErrorCode ierr;

  PetscFunctionBegin;
  user->n = NN;
  ierr = VecCreateSeq(PETSC_COMM_SELF,user->n,&user->x);CHKERRQ(ierr);
  ierr = VecSet(user->x,2);
  //ierr = VecSetRandom(user->x,NULL);CHKERRQ(ierr);

  PetscFunctionReturn(0);
}

PetscErrorCode DestroyProblem(AppCtx *user)
{
  PetscErrorCode ierr;
  PetscFunctionBegin;
  ierr = VecDestroy(&user->x);CHKERRQ(ierr);
  PetscFunctionReturn(0);
}

PetscErrorCode FormFunctionGradient(Tao tao, Vec X, PetscReal *f, Vec G, void *ctx)
{
  PetscScalar       *g;
  const PetscScalar *x;
  PetscErrorCode    ierr;
  PetscScalar       summe; 

  PetscFunctionBegin;
  ierr = VecGetArrayRead(X,&x);CHKERRQ(ierr);
  ierr = VecGetArray(G,&g);CHKERRQ(ierr);
/*  
  summe = 0.0;
	
  summe += ((x[0]-Anfang)*(x[0]-Anfang)+(Ende-x[NN-1])*(Ende-x[NN-1]))/(2*dt);
  for(int i = 1;i<NN;i++){
  	summe += ((x[i]-x[i-1])*(x[i]-x[i-1]))/(2*dt);
  }
  *f = summe;
  
  g[0] = ((x[0]-Anfang)-(x[1]-x[0]))/dt;
  g[NN-1] = ((x[NN-1]-x[NN-2])-(Ende-x[NN-1]))/dt;

  for(int i = 1;i<NN-1;i++){
	 g[i] = ((x[i]-x[i-1])-(x[i+1]-x[i]))/dt;
  }

*/

  summe = 0.0;
	
  summe += ((x[0]-Anfang)*(x[0]-Anfang)+(Ende-x[NN-1])*(Ende-x[NN-1]))/(2*dt)-9.81*x[0]*dt-9.81*x[NN-1]*dt;
  for(int i = 1;i<NN;i++){
  	summe += ((x[i]-x[i-1])*(x[i]-x[i-1]))/(2*dt)-9.81*x[i]*dt;
  }
  *f = summe;
  
  g[0] = ((x[0]-Anfang)-(x[1]-x[0]))/dt-9.81*dt;
  g[NN-1] = ((x[NN-1]-x[NN-2])-(Ende-x[NN-1]))/dt-9.81*dt;

  for(int i = 1;i<NN-1;i++){
	 g[i] = ((x[i]-x[i-1])-(x[i+1]-x[i]))/dt-9.81*dt;
  }
  
  ierr = VecRestoreArrayRead(X,&x);CHKERRQ(ierr);
  ierr = VecRestoreArray(G,&g);CHKERRQ(ierr);
  PetscFunctionReturn(0);
}


/*TEST
   
    mpicc -I/usr/include/petsc/ -I/usr/include/mpi -lpetsc -lm -lmpi toy.cpp
    mpiexec a.out -tao_smonitor -tao_view_solution

TEST*/
