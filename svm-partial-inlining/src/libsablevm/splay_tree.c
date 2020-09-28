/* This file has been automatically generated from "splay_tree.list" */

/*
----------------------------------------------------------------------
_svmf_tree_splay_type
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_type (_svmt_type_node ** proot, _svmt_type_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_type_node *parent = node->parent;
      _svmt_type_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_type_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_type_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_type_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_type_node *A = *node_second;
	  _svmt_type_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_type_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_type_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_type_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_type_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_type_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_type_node *A = *node_second;
	_svmt_type_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_type
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_type (_svmt_type_node * value1, _svmt_type_node * value2);

#define _svmm_tree_find_type(root, value) \
_svmh_tree_find_type (&root, value)

svm_static _svmt_type_node * _svmh_tree_find_type (_svmt_type_node ** proot, _svmt_type_node * value)
{
  _svmt_type_node *current = *proot;
  _svmt_type_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_type (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_type (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_type (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_type
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_type(root, value) \
_svmh_tree_insert_type (&root, value)

svm_static void
_svmh_tree_insert_type (_svmt_type_node ** proot, _svmt_type_node * value)
{
  _svmt_type_node **pcurrent = proot;
  _svmt_type_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_type (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_type (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_type
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_type(root, node) \
_svmh_tree_remove_type (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_type (_svmt_type_node ** proot, _svmt_type_node * node)
{
  _svmt_type_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_type_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_type (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_type_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_type (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_type_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_type_destroy (_svmt_type_node * root,
			     void (*free_node_internal) (_svmt_type_node * node))
{
  _svmt_type_node *prev = NULL;
  _svmt_type_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_type_node (prev);
	    }
	}
    }
}


/*
----------------------------------------------------------------------
_svmf_tree_splay_gc_map
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_gc_map_node *parent = node->parent;
      _svmt_gc_map_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_gc_map_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_gc_map_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_gc_map_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_gc_map_node *A = *node_second;
	  _svmt_gc_map_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_gc_map_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_gc_map_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_gc_map_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_gc_map_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_gc_map_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_gc_map_node *A = *node_second;
	_svmt_gc_map_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_gc_map
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_gc_map (_svmt_gc_map_node * value1, _svmt_gc_map_node * value2);

#define _svmm_tree_find_gc_map(root, value) \
_svmh_tree_find_gc_map (&root, value)

svm_static _svmt_gc_map_node * _svmh_tree_find_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * value)
{
  _svmt_gc_map_node *current = *proot;
  _svmt_gc_map_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_gc_map (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_gc_map (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_gc_map (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_gc_map
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_gc_map(root, value) \
_svmh_tree_insert_gc_map (&root, value)

svm_static void
_svmh_tree_insert_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * value)
{
  _svmt_gc_map_node **pcurrent = proot;
  _svmt_gc_map_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_gc_map (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_gc_map (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_gc_map
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_gc_map(root, node) \
_svmh_tree_remove_gc_map (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * node)
{
  _svmt_gc_map_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_gc_map_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_gc_map (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_gc_map_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_gc_map (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_gc_map_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_gc_map_destroy (_svmt_gc_map_node * root,
			     void (*free_node_internal) (_svmt_gc_map_node * node))
{
  _svmt_gc_map_node *prev = NULL;
  _svmt_gc_map_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_gc_map_node (prev);
	    }
	}
    }
}


/*
----------------------------------------------------------------------
_svmf_tree_splay_imethod_signature
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_imethod_signature_node *parent = node->parent;
      _svmt_imethod_signature_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_imethod_signature_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_imethod_signature_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_imethod_signature_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_imethod_signature_node *A = *node_second;
	  _svmt_imethod_signature_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_imethod_signature_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_imethod_signature_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_imethod_signature_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_imethod_signature_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_imethod_signature_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_imethod_signature_node *A = *node_second;
	_svmt_imethod_signature_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_imethod_signature
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_imethod_signature (_svmt_imethod_signature_node * value1, _svmt_imethod_signature_node * value2);

#define _svmm_tree_find_imethod_signature(root, value) \
_svmh_tree_find_imethod_signature (&root, value)

svm_static _svmt_imethod_signature_node * _svmh_tree_find_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * value)
{
  _svmt_imethod_signature_node *current = *proot;
  _svmt_imethod_signature_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_imethod_signature (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_imethod_signature (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_imethod_signature (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_imethod_signature
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_imethod_signature(root, value) \
_svmh_tree_insert_imethod_signature (&root, value)

svm_static void
_svmh_tree_insert_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * value)
{
  _svmt_imethod_signature_node **pcurrent = proot;
  _svmt_imethod_signature_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_imethod_signature (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_imethod_signature (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_imethod_signature
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_imethod_signature(root, node) \
_svmh_tree_remove_imethod_signature (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * node)
{
  _svmt_imethod_signature_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_imethod_signature_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_imethod_signature (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_imethod_signature_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_imethod_signature (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_imethod_signature_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_imethod_signature_destroy (_svmt_imethod_signature_node * root,
			     void (*free_node_internal) (_svmt_imethod_signature_node * node))
{
  _svmt_imethod_signature_node *prev = NULL;
  _svmt_imethod_signature_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_imethod_signature_node  (prev);
	    }
	}
    }
}


/*
----------------------------------------------------------------------
_svmf_tree_splay_internal_method
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_internal_method_node *parent = node->parent;
      _svmt_internal_method_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_internal_method_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_internal_method_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_internal_method_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_internal_method_node *A = *node_second;
	  _svmt_internal_method_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_internal_method_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_internal_method_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_internal_method_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_internal_method_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_internal_method_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_internal_method_node *A = *node_second;
	_svmt_internal_method_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_internal_method
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_internal_method (_svmt_internal_method_node * value1, _svmt_internal_method_node * value2);

#define _svmm_tree_find_internal_method(root, value) \
_svmh_tree_find_internal_method (&root, value)

svm_static _svmt_internal_method_node * _svmh_tree_find_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * value)
{
  _svmt_internal_method_node *current = *proot;
  _svmt_internal_method_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_internal_method (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_internal_method (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_internal_method (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_internal_method
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_internal_method(root, value) \
_svmh_tree_insert_internal_method (&root, value)

svm_static void
_svmh_tree_insert_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * value)
{
  _svmt_internal_method_node **pcurrent = proot;
  _svmt_internal_method_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_internal_method (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_internal_method (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_internal_method
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_internal_method(root, node) \
_svmh_tree_remove_internal_method (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * node)
{
  _svmt_internal_method_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_internal_method_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_internal_method (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_internal_method_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_internal_method (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_internal_method_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_internal_method_destroy (_svmt_internal_method_node * root,
			     void (*free_node_internal) (_svmt_internal_method_node * node))
{
  _svmt_internal_method_node *prev = NULL;
  _svmt_internal_method_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_internal_method_node (prev);
	    }
	}
    }
}


#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER) && !defined (_SABLEVM_METHOD_INLINING)

/*
----------------------------------------------------------------------
_svmf_tree_splay_sequence
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_sequence_node *parent = node->parent;
      _svmt_sequence_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_sequence_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_sequence_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_sequence_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_sequence_node *A = *node_second;
	  _svmt_sequence_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_sequence_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_sequence_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_sequence_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_sequence_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_sequence_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_sequence_node *A = *node_second;
	_svmt_sequence_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_sequence
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_sequence (_svmt_sequence_node * value1, _svmt_sequence_node * value2);

#define _svmm_tree_find_sequence(root, value) \
_svmh_tree_find_sequence (&root, value)

svm_static _svmt_sequence_node * _svmh_tree_find_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * value)
{
  _svmt_sequence_node *current = *proot;
  _svmt_sequence_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_sequence (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_sequence (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_sequence
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_sequence(root, value) \
_svmh_tree_insert_sequence (&root, value)

svm_static void
_svmh_tree_insert_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * value)
{
  _svmt_sequence_node **pcurrent = proot;
  _svmt_sequence_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_sequence (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_sequence
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_sequence(root, node) \
_svmh_tree_remove_sequence (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * node)
{
  _svmt_sequence_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_sequence_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_sequence (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_sequence_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_sequence (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_sequence_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_sequence_destroy (_svmt_sequence_node * root,
			     void (*free_node_internal) (_svmt_sequence_node * node))
{
  _svmt_sequence_node *prev = NULL;
  _svmt_sequence_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_sequence_node (prev);
	    }
	}
    }
}


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER && !_SABLEVM_METHOD_INLINING */

#if defined (_SABLEVM_METHOD_INLINING) && defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

/*
----------------------------------------------------------------------
_svmf_tree_splay_sequence_by_bytecodes
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_sequence_by_bytecodes (_svmt_sequence_node ** proot, _svmt_sequence_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_sequence_node *parent = node->parent;
      _svmt_sequence_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_sequence_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_sequence_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_sequence_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_sequence_node *A = *node_second;
	  _svmt_sequence_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_sequence_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_sequence_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_sequence_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_sequence_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_sequence_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_sequence_node *A = *node_second;
	_svmt_sequence_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_sequence_by_bytecodes
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_sequence_by_bytecodes (_svmt_sequence_node * value1, _svmt_sequence_node * value2);

#define _svmm_tree_find_sequence_by_bytecodes(root, value) \
_svmh_tree_find_sequence_by_bytecodes (&root, value)

svm_static _svmt_sequence_node * _svmh_tree_find_sequence_by_bytecodes (_svmt_sequence_node ** proot, _svmt_sequence_node * value)
{
  _svmt_sequence_node *current = *proot;
  _svmt_sequence_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence_by_bytecodes (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_sequence_by_bytecodes (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_sequence_by_bytecodes (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_sequence_by_bytecodes
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_sequence_by_bytecodes(root, value) \
_svmh_tree_insert_sequence_by_bytecodes (&root, value)

svm_static void
_svmh_tree_insert_sequence_by_bytecodes (_svmt_sequence_node ** proot, _svmt_sequence_node * value)
{
  _svmt_sequence_node **pcurrent = proot;
  _svmt_sequence_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence_by_bytecodes (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_sequence_by_bytecodes (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_sequence_by_bytecodes
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_sequence_by_bytecodes(root, node) \
_svmh_tree_remove_sequence_by_bytecodes (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_sequence_by_bytecodes (_svmt_sequence_node ** proot, _svmt_sequence_node * node)
{
  _svmt_sequence_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_sequence_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_sequence_by_bytecodes (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_sequence_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_sequence_by_bytecodes (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_sequence_by_bytecodes_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_sequence_by_bytecodes_destroy (_svmt_sequence_node * root,
			     void (*free_node_internal) (_svmt_sequence_node * node))
{
  _svmt_sequence_node *prev = NULL;
  _svmt_sequence_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_sequence_node (prev);
	    }
	}
    }
}


/*
----------------------------------------------------------------------
_svmf_tree_splay_sequence_by_implementation
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_sequence_by_implementation (_svmt_mi_sequence_node_info ** proot, _svmt_mi_sequence_node_info * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_mi_sequence_node_info *parent = node->parent;
      _svmt_mi_sequence_node_info *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_mi_sequence_node_info **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_mi_sequence_node_info **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_mi_sequence_node_info **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_mi_sequence_node_info *A = *node_second;
	  _svmt_mi_sequence_node_info *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_mi_sequence_node_info **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_mi_sequence_node_info **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_mi_sequence_node_info **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_mi_sequence_node_info **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_mi_sequence_node_info **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_mi_sequence_node_info *A = *node_second;
	_svmt_mi_sequence_node_info *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_sequence_by_implementation
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_sequence_by_implementation (_svmt_mi_sequence_node_info * value1, _svmt_mi_sequence_node_info * value2);

#define _svmm_tree_find_sequence_by_implementation(root, value) \
_svmh_tree_find_sequence_by_implementation (&root, value)

svm_static _svmt_mi_sequence_node_info * _svmh_tree_find_sequence_by_implementation (_svmt_mi_sequence_node_info ** proot, _svmt_mi_sequence_node_info * value)
{
  _svmt_mi_sequence_node_info *current = *proot;
  _svmt_mi_sequence_node_info *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence_by_implementation (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_sequence_by_implementation (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_sequence_by_implementation (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_sequence_by_implementation
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_sequence_by_implementation(root, value) \
_svmh_tree_insert_sequence_by_implementation (&root, value)

svm_static void
_svmh_tree_insert_sequence_by_implementation (_svmt_mi_sequence_node_info ** proot, _svmt_mi_sequence_node_info * value)
{
  _svmt_mi_sequence_node_info **pcurrent = proot;
  _svmt_mi_sequence_node_info *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence_by_implementation (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_sequence_by_implementation (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_sequence_by_implementation
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_sequence_by_implementation(root, node) \
_svmh_tree_remove_sequence_by_implementation (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_sequence_by_implementation (_svmt_mi_sequence_node_info ** proot, _svmt_mi_sequence_node_info * node)
{
  _svmt_mi_sequence_node_info **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_mi_sequence_node_info *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_sequence_by_implementation (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_mi_sequence_node_info *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_sequence_by_implementation (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_sequence_by_implementation_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_sequence_by_implementation_destroy (_svmt_mi_sequence_node_info * root,
			     void (*free_node_internal) (_svmt_mi_sequence_node_info * node))
{
  _svmt_mi_sequence_node_info *prev = NULL;
  _svmt_mi_sequence_node_info *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_mi_sequence_node_info (prev);
	    }
	}
    }
}


#endif /* _SABLEVM_METHOD_INLINING && _SABLEVM_INLINED_THREADED_INTERPRETER */

#if defined (_SABLEVM_METHOD_INLINING) && defined (_SABLEVM_DIRECT_THREADED_INTERPRETER)

/*
----------------------------------------------------------------------
_svmf_tree_splay_instructions
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_instructions (_svmt_mi_instruction_node ** proot, _svmt_mi_instruction_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_mi_instruction_node *parent = node->parent;
      _svmt_mi_instruction_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_mi_instruction_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_mi_instruction_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_mi_instruction_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_mi_instruction_node *A = *node_second;
	  _svmt_mi_instruction_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_mi_instruction_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_mi_instruction_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_mi_instruction_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_mi_instruction_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_mi_instruction_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_mi_instruction_node *A = *node_second;
	_svmt_mi_instruction_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_instructions
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_instructions (_svmt_mi_instruction_node * value1, _svmt_mi_instruction_node * value2);

#define _svmm_tree_find_instructions(root, value) \
_svmh_tree_find_instructions (&root, value)

svm_static _svmt_mi_instruction_node * _svmh_tree_find_instructions (_svmt_mi_instruction_node ** proot, _svmt_mi_instruction_node * value)
{
  _svmt_mi_instruction_node *current = *proot;
  _svmt_mi_instruction_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_instructions (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_instructions (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_instructions (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_instructions
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_instructions(root, value) \
_svmh_tree_insert_instructions (&root, value)

svm_static void
_svmh_tree_insert_instructions (_svmt_mi_instruction_node ** proot, _svmt_mi_instruction_node * value)
{
  _svmt_mi_instruction_node **pcurrent = proot;
  _svmt_mi_instruction_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_instructions (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_instructions (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_instructions
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_instructions(root, node) \
_svmh_tree_remove_instructions (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_instructions (_svmt_mi_instruction_node ** proot, _svmt_mi_instruction_node * node)
{
  _svmt_mi_instruction_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_mi_instruction_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_instructions (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_mi_instruction_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_instructions (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_instructions_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_instructions_destroy (_svmt_mi_instruction_node * root,
			     void (*free_node_internal) (_svmt_mi_instruction_node * node))
{
  _svmt_mi_instruction_node *prev = NULL;
  _svmt_mi_instruction_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmm_gzfree_mi_instruction_node (prev);
	    }
	}
    }
}


#endif /* _SABLEVM_METHOD_INLINING && _SABLEVM_DIRECT_THREADED_INTERPRETER */

#if defined (_SABLEVM_MEMORY_DEBUGGING)

/*
----------------------------------------------------------------------
_svmf_tree_splay_mdebug_alloc_info
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot, _svmt_mdebug_alloc_info_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_mdebug_alloc_info_node *parent = node->parent;
      _svmt_mdebug_alloc_info_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  _svmt_mdebug_alloc_info_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_mdebug_alloc_info_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_mdebug_alloc_info_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_mdebug_alloc_info_node *A = *node_second;
	  _svmt_mdebug_alloc_info_node *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	_svmt_mdebug_alloc_info_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_mdebug_alloc_info_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_mdebug_alloc_info_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_mdebug_alloc_info_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_mdebug_alloc_info_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_mdebug_alloc_info_node *A = *node_second;
	_svmt_mdebug_alloc_info_node *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
----------------------------------------------------------------------
_svmh_tree_find_mdebug_alloc_info
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_mdebug_alloc_info (_svmt_mdebug_alloc_info_node * value1, _svmt_mdebug_alloc_info_node * value2);

#define _svmm_tree_find_mdebug_alloc_info(root, value) \
_svmh_tree_find_mdebug_alloc_info (&root, value)

svm_static _svmt_mdebug_alloc_info_node * _svmh_tree_find_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot, _svmt_mdebug_alloc_info_node * value)
{
  _svmt_mdebug_alloc_info_node *current = *proot;
  _svmt_mdebug_alloc_info_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_mdebug_alloc_info (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_mdebug_alloc_info (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_mdebug_alloc_info (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_mdebug_alloc_info
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_mdebug_alloc_info(root, value) \
_svmh_tree_insert_mdebug_alloc_info (&root, value)

svm_static void
_svmh_tree_insert_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot, _svmt_mdebug_alloc_info_node * value)
{
  _svmt_mdebug_alloc_info_node **pcurrent = proot;
  _svmt_mdebug_alloc_info_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_mdebug_alloc_info (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_mdebug_alloc_info (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_mdebug_alloc_info
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_mdebug_alloc_info(root, node) \
_svmh_tree_remove_mdebug_alloc_info (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot, _svmt_mdebug_alloc_info_node * node)
{
  _svmt_mdebug_alloc_info_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_mdebug_alloc_info_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_mdebug_alloc_info (proot, next);

      /* the next value is now the root of the tree, so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      _svmt_mdebug_alloc_info_node *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_mdebug_alloc_info (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_splay_mdebug_alloc_info_destroy: Free all nodes of the tree
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_tree_splay_mdebug_alloc_info_destroy (_svmt_mdebug_alloc_info_node * root,
			     void (*free_node_internal) (_svmt_mdebug_alloc_info_node * node))
{
  _svmt_mdebug_alloc_info_node *prev = NULL;
  _svmt_mdebug_alloc_info_node *current = root;

  while (current != NULL)
    {
      if (current->left != NULL)
	current = current->left;
      else
	{
	  if (current->right != NULL)
	    current = current->right;
	  else
	    {
	      prev = current;
	      current = current->parent;

	      if (current != NULL)
		{
		  if (prev == current->left)
		    current->left = NULL;
		  else if (prev == current->right)
		    current->right = NULL;
		}

	      if (free_node_internal != NULL)
		free_node_internal (prev);
	      _svmf_free_alloc_info_node (prev);
	    }
	}
    }
}


#endif /* _SABLEVM_MEMORY_DEBUGGING */
