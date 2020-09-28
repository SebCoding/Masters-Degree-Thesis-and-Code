/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_file_head
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_head:])";

#ifndef SVM_GLOBAL_ALLOC_H
#define SVM_GLOBAL_ALLOC_H
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_file_tail
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_tail:])";

#endif /* NOT SVM_GLOBAL_ALLOC_H */
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zalloc_no_exception
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zalloc_no_exception)
 */

m4svm_define_begin v = ":], [:m4svm_global_zalloc_no_exception:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzalloc_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_$1_no_exception(ptr) \
_svmh_gzalloc_$1_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzalloc_$1_no_exception(ptr) \
_svmh_gzalloc_$1_no_exception (&ptr)

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzfree_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_$1_no_exception(ptr) \
_svmh_gzfree_$1_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_$1_no_exception(ptr) \
_svmh_gzfree_$1_no_exception (&ptr)

#endif

m4svm_define_end v = ":])";


/*
----------------------------------------------------------------------
m4svm_global_zmalloc_no_exception
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zmalloc_no_exception)
 */

m4svm_define_begin v = ":], [:m4svm_global_zmalloc_no_exception:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzmalloc_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_$1_no_exception(n, ptr) \
_svmh_gzmalloc_$1_no_exception (__FILE__, __FUNCTION__, __LINE__, n,&ptr)

#else

#define _svmm_gzmalloc_$1_no_exception(n, ptr) \
_svmh_gzmalloc_$1_no_exception (n, &ptr)

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzmfree_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_$1_no_exception(ptr) \
_svmh_gzmfree_$1_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_$1_no_exception(ptr) \
_svmh_gzmfree_$1_no_exception (&ptr)

#endif

m4svm_define_end v = ":])";


/*
----------------------------------------------------------------------
m4svm_global_zalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zalloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_zalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_$1(env, ptr) \
_svmh_gzalloc_$1 (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_$1(env, ptr) \
_svmh_gzalloc_$1 (env, &ptr)

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_$1(ptr) \
_svmh_gzfree_$1 (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_$1(ptr) \
_svmh_gzfree_$1 (&ptr)

#endif

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_malloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_malloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_malloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmalloc_$1(env, n, ptr) \
_svmh_gmalloc_$1 (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gmalloc_$1(env, n, ptr) \
_svmh_gmalloc_$1 (env, n, &ptr)

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmfree_$1(ptr) \
_svmh_gmfree_$1 (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gmfree_$1(ptr) \
_svmh_gmfree_$1 (&ptr)

#endif

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zmalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zmalloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_zmalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_$1(env,n,ptr) \
_svmh_gzmalloc_$1 (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_$1(env,n,ptr) \
_svmh_gzmalloc_$1 (env, n, &ptr)

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_gzmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_$1(ptr) \
_svmh_gzmfree_$1 (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_$1(ptr) \
_svmh_gzmfree_$1 (&ptr)

#endif

m4svm_define_end v = ":])";
