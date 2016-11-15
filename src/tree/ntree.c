#include "../include/tree.h"
#include "../include/parser.h"

/*struct ntree *new_lift(char *word)
{
  struct ntree *res = malloc(sizeof (struct ntree));
  res->name = word;
  res->size = 0;
  //res->and_or = NULL;
  res->sons = NULL;
  return res;
}*/

struct ntree *new_ntree(char *word, enum token_parser token)
{
  struct ntree *res = malloc(sizeof (struct ntree));
  if (!res)
    return NULL;
  res->name = malloc(sizeof (strlen(word)) * sizeof (char));
  res->token = token;
  strcpy(res->name, word);
  res->size = 0;
  res->sons = NULL;
  return res;
}

struct ntree *add_ntree(struct ntree *tree, struct ntree *son)
{
  if (!son)
    return tree;
  if (!tree)
    return son;
  //tree->and_or = realloc(tree->and_or, sizeof (tree->and_or) * sizeof (op));
  tree->sons = realloc(tree->sons, sizeof (struct ntree) * tree->size + 1);
  //strcpy(tree->and_or, op);
  tree->sons[tree->size] = son;
  tree->size++;
  return tree;
}

struct file
{
  struct ntree *tree;
  struct file *next;
};

struct ntree *pop(struct file *f)
{
  if (!f)
    return NULL;

  struct file *rem = f;
  while (f->next)
  {
    rem = f;
    f = f->next;
  }
  struct ntree *tree = f->tree;
  rem->next = NULL;
  free(f);
  if (f == rem && strcmp(tree->name, "\n") == 0)
    return NULL;
  return tree;
}

struct file *push(struct file *f, struct ntree *t)
{
  struct file *new = malloc (sizeof (struct file));
  new->tree = t;
  new->next = f;
  return new;
}

void my_print_ntree(struct ntree *tree)
{
  struct file *my_file = NULL;
  my_file = push(my_file, tree);
  struct ntree *treee = new_ntree("\n", WORD);
  struct ntree *treei = new_ntree("yo", WORD);

  my_file = push(my_file, treee);

  while (my_file)
  {
    struct ntree *curr = pop(my_file);
    if (!curr)
      return;
    if (strcmp(curr->name, "yo") == 0)
    {
      printf("//");
      continue;
    }
    if (strcmp(curr->name, "\n") == 0)
    {
      printf("\n");
      my_file = push(my_file, treee);
      continue;
    }
    printf(" %s |", curr->name);
    for (unsigned i = 0; i < curr->size; i++)
    {
        my_file = push(my_file, curr->sons[i]);
    }
    my_file = push(my_file, treei);
  }
}


/*void print_ntree(struct ntree *tree)
{
  if (tree->size == 0)
  {
    printf("%s", tree->name);
  }
  else
  { 
    for (unsigned i = 0; i < tree->size - 1; i++)
    {
      print_ntree(tree->sons[i]);
      printf(" %c ", tree->and_or[i]);
    }
    print_ntree(tree->sons[tree->size -1]);
    printf(" %c", tree->and_or[tree->size - 1]);
  }
}*/

/*int fakefunction(char *name)
{
  printf("%s\n", name);
  if (strcmp(name, "ls") == 0 || strcmp(name, "cat") == 0 )
    return 0;
  return 1;
}

int exec_all(struct ntree *tree)
{
  if (tree->size == 0)
  {
    return fakefunction(tree->name);
  }
  else
  {
    int tmp = exec_all(tree->sons[0]);
    int res = 0;
    for (unsigned i = 1; i < tree->size; i++)
    {
      res += exec_all(tree->sons[i]);
      if ((tree->and_or[i - 1] == '&' && res + tmp > 0)
          || (tree->and_or[i - 1] == '|' && res + tmp > 1))
        return 1;
      tmp = res;
      res = 0;
    }
    return 0;
  }
}
    

int main(void)
{
  struct ntree *ptr = new_ntree("lss", '&');
  add_ntree(ptr, new_lift("cat"), '|'); 
  add_ntree(ptr, new_lift("cadt"), '&'); 
  struct ntree *ptr2 = new_ntree("ls", '|');
  add_ntree(ptr, ptr2, '|');
  add_ntree(ptr2, new_lift("cat"), '&'); 
  add_ntree(ptr2, new_lift("ls"), ';'); 
  add_ntree(ptr, new_lift("ls"), ';'); 
  printf("\n");
  printf("%d\n", exec_all(ptr));
  printf("\n");
  return 0;
}*/
