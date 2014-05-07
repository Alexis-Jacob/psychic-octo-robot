#ifndef	__LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>

#ifndef	T
#define T void*
#endif

#define	bool	char
#define true	1
#define false	0

typedef struct list
{
  struct list *next;
  struct list *prev;
  T	content;
} list;

typedef	struct head
{
  int	size;
  list	*begin;
  list	*end;
}list_head;

list	*add_element(list_head *head, T content);
list	*remove_element(list_head *head, list *to_remove);
void	dislay_content(T content);
void	display_list(const list_head *head, void (*ptr)(T));
void	free_list(list_head *head);
list	*find_in_list(const list_head *head, T param, bool (*ptr)(const T, const T));
#endif
