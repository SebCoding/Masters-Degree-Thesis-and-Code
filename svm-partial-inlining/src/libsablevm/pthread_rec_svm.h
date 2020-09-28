/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* *INDENT-OFF* */

typedef struct pthread_rec_mutex_svm_t_struct pthread_rec_mutex_svm_t;

/* kept as an incomplete type */
typedef struct pthread_rec_mutexattr_svm_t_struct pthread_rec_mutexattr_svm_t;

/* *INDENT-ON* */

struct pthread_rec_mutex_svm_t_struct
{
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  size_t count;
  pthread_t owner;
};

int pthread_rec_mutex_svm_init (pthread_rec_mutex_svm_t *rec,
				pthread_rec_mutexattr_svm_t *recattr);
int pthread_rec_mutex_svm_destroy (pthread_rec_mutex_svm_t *rec);
int pthread_rec_mutex_svm_lock (pthread_rec_mutex_svm_t *rec);
int pthread_rec_mutex_svm_trylock (pthread_rec_mutex_svm_t *rec);
int pthread_rec_mutex_svm_unlock (pthread_rec_mutex_svm_t *rec);
