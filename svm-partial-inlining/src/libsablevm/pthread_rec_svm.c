/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* implementation of recursive locks on top of pthread */

#include "includes.h"

/* for future compatibility, attr should be set to NULL */
int
pthread_rec_mutex_svm_init (pthread_rec_mutex_svm_t *rec,
			    pthread_rec_mutexattr_svm_t *recattr)
{
  assert (recattr == NULL);

  pthread_mutex_init (&rec->mutex, NULL);
  pthread_cond_init (&rec->cond, NULL);
  rec->count = 0;
  return 0;
}

int
pthread_rec_mutex_svm_destroy (pthread_rec_mutex_svm_t *rec)
{
  return (pthread_cond_destroy (&rec->cond)
	  || pthread_mutex_destroy (&rec->mutex)) ? EBUSY : 0;
}

int
pthread_rec_mutex_svm_lock (pthread_rec_mutex_svm_t *rec)
{
  pthread_mutex_lock (&rec->mutex);

  if (rec->count == 0)
    {
      rec->count = 1;
      rec->owner = pthread_self ();
    }
  else if (pthread_equal (rec->owner, pthread_self ()))
    {
      rec->count++;
    }
  else
    {
      do
	{
	  pthread_cond_wait (&rec->cond, &rec->mutex);
	}
      while (rec->count != 0);

      rec->count = 1;
      rec->owner = pthread_self ();
    }

  pthread_mutex_unlock (&rec->mutex);
  return 0;
}

int
pthread_rec_mutex_svm_trylock (pthread_rec_mutex_svm_t *rec)
{
  pthread_mutex_lock (&rec->mutex);

  if (rec->count == 0)
    {
      rec->count = 1;
      rec->owner = pthread_self ();
    }
  else if (pthread_equal (rec->owner, pthread_self ()))
    {
      rec->count++;
    }
  else
    {
      pthread_mutex_unlock (&rec->mutex);
      return EBUSY;
    }

  pthread_mutex_unlock (&rec->mutex);
  return 0;
}

int
pthread_rec_mutex_svm_unlock (pthread_rec_mutex_svm_t *rec)
{
  pthread_mutex_lock (&rec->mutex);

  rec->count--;
  if (rec->count == 0)
    {
      pthread_cond_signal (&rec->cond);
    }

  pthread_mutex_unlock (&rec->mutex);
  return 0;
}
