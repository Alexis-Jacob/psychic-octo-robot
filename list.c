#include "list.h"

list	*add_element(list_head *head, T content)
{
  list *new_element;

  if ((new_element = malloc(sizeof(*new_element))) == NULL)
    {
      fprintf(stderr, "Malloc Error\n");
      return NULL;
    }
  head->size += 1;
  new_element->content = content;
  new_element->next = NULL;
  new_element->prev = head->end != NULL ? head->end : NULL;
  if (head->end != NULL)
    head->end->next = new_element;
  head->end = new_element;
  if (head->begin == NULL)
    head->begin = new_element;
  return new_element;
}

list	*remove_element(list_head *head, list *to_remove)
{
  list	*prev = to_remove->prev;
  list	*next = to_remove->next;

  if (prev == NULL)
      head->begin = next;
  else
    prev->next = next;
  if (next == NULL)
    head->end = prev;
  else
    next->prev = prev;
  free(to_remove);
  return prev;
}

void	display_list(const list_head *head, void (*ptr)(T))
{
  list	*tmp;

  tmp = head->begin;
  while (tmp != NULL)
    {
      (ptr)(tmp->content);
      tmp = tmp->next;
    }
}

void	free_list(list_head *head)
{
  list *node;
  list	*tmp;

  node = head->begin;
  while (node != NULL)
    {
      tmp = node;
      node = node->next;
      free(tmp);
    }
  head->size = 0;
  head->begin = NULL;
  head->end = NULL;
}

list	*find_in_list(const list_head *head, T param, bool (*ptr)(const T, const T))
{
  list	*rep;

  rep = head->begin;
  while (rep != NULL)
    {
      if (ptr == NULL)
	{
	  if (rep->content == param)
	    return rep;
	}
      else
	if ((*ptr)(rep->content, param) == true)
	  return rep;
      rep = rep->next;
    }
  return NULL;
}
