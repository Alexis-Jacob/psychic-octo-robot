#include "list.h"

/* void	display(T content) */
/* { */
/*   printf("%i\n", content); */
/* } */

/* int	main(int argc, char **argv) */
/* { */
/*   list_head	head = {0, NULL, NULL}; */

/*   while (*argv) */
/*     add_element(&head, atoi(*argv++)); */
/*   display_list(&head, display); */
/*   printf("Adding element 4\n"); */
/*   add_element(&head, 4); */
/*   display_list(&head, display); */
/*   printf("Remove element 2\n"); */
/*   list *tmp = find_in_list(&head, 2, NULL); */
/*   remove_element(&head, tmp); */
/*   display_list(&head, display); */
/*   free_list(&head); */
/* } */


/* T == char* */


void	display(T content)
{
  printf("%s\n", content);
}

static bool	compare(const char *str1, const char *str2)
{
  return (strcmp(str1, str2) == 0);
}

int	main(int argc, char **argv)
{
  list_head	head = {0, NULL, NULL};

  while (*argv)
    add_element(&head, *argv++);
  display_list(&head, display);
  printf("Adding new_element\n");
  add_element(&head, "new_element");
  display_list(&head, display);
  printf("Remove element ./a.out\n");
  list *tmp = find_in_list(&head, "./a.out", compare);
  remove_element(&head, tmp);
  display_list(&head, display);
  free_list(&head);
}
