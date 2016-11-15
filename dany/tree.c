#include <stdio.h>
#include <stdlib.h>


struct btree
{
  struct btree *left;
  struct btree *right;
  char *name;
}

struct btree *new_btree(struct btree *left, struct btree *right)
{
  struct btree *res = malloc(sizeof (struct btree));
  res->left = left;
  res->right = right;
}

struct btree * add_btree(struct btree *tree, struct btree *node)
{
  struct btree *ptr = tree;
  if (!tree)
    return node;
  else
  {
    if (strcmp(node->name, tree->name) < 0)
    {
      ptr = add_btree(node->left, node); 
      tree->left = ptr;
    }
    else
    {
      ptr = add_btree(node->right, node);
      tree->right = ptr;
    }
    return tree;
  }
}

int search_btree(struct btree * tree, char *value)
{
  if (!tree)
    return 0;
  else
  {
    int cmp = strcmp(value, tree->name);
    if (cmp == 0)
      return 1;
    else
    {
      if (cmp < 0)
        return search_btree(tree->left, value);
      else
        return search_btree(tree->right, value);
    }
  }
}

char *delete_max(struct btree *tree, char *max)
{
  if (!tree->right)
  {
    max = tree->name;
    tree = tree->left;
  }
  else
    delete_max(max, tree->right);
}

void delete_btree(struct btree *tree, char *value)
{
  char *max;
  if (tree)
  {
    int cmp = strcmp(value, tree->name);
    if (cmp < 0)
      delete_btree(tree->left, value);
    else
    {
      if (cmp > 0)
        delete_btree(tree->right, value);
      else
      {
        if (!tree->left)
	  tree = tree->right;
	else
	{
	  if (!tree->right)
	    tree = tree->left;
          else
	  {
	    max = delete_max(max, tree->left);
	    tree->name = max;
	  }
	}
      }
    }
  }
}

int islift(struct node *node)
{
  if (!node->left && !node->right)
    return 1;
  else
    return 0;
}

void delete_node(struct node *node)
{
  if (!islift(node))
  {
    if (node->right)
      
