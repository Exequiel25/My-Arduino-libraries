/*
  Node.h - Library for using a Node
  Created by Exequiel Magni, March 10, 2022.
*/

#include "Arduino.h"
#include "Node.h"

Node::Node() {}

void Node::add_item(Node *&list, int hh, int mm)
{
  Node *new_node = new Node();
  new_node->_hh = hh;
  new_node->_mm = mm;

  Node *aux1 = list;
  Node *aux2;

  while ( (aux1 != NULL) && (aux1->_hh < hh) )
  {
    aux2 = aux1;
    aux1 = aux1->next;
  }

  if (list == aux1)
  {
    list = new_node;
  }
  else
  {
    aux2->next = new_node;
  }

  new_node->next = aux1;
}

void Node::remove_item(Node *&list, int index)
{
  if (list != NULL)
  {
    Node *aux_delete = new Node();
    Node *aux_prev = NULL;
    aux_delete = list;

    while ( (aux_delete != NULL) &&  (index-- >=0) )
    {
      aux_prev = aux_delete;
      aux_delete = aux_delete->next;
    }

    if (aux_delete != NULL)
    {
      if (aux_prev == NULL)
      {
        list = list->next;
        delete aux_delete;
      }
      else
      {
        aux_prev->next = aux_delete->next;
        delete aux_delete;
      }
    }
  }

}

void Node::remove_all(Node *&list)
{
  if (list != NULL)
  {
    Node *aux_delete = new Node();
    Node *aux_next;
    aux_delete = list;

    while (aux_delete != NULL)
    {
      aux_next = aux_delete->next;
      delete aux_delete;
      aux_delete = aux_next;
    }
  }
}

void Node::edit_item(Node *&list, int index, int new_hh, int new_mm)
{
  if (list != NULL)
  {
    remove_item(list, index);
    add_item(list, new_hh, new_mm);
  }
}

int Node::get_item_hh(Node *list, int index)
{
  if (list != NULL)
  {
    Node *actual = new Node();
    actual = list;

    while ( (actual != NULL) && (index-- > 0) )
    {
      actual = actual->next;
    }
    
    return actual->_hh;
  }
}

int Node::get_item_mm(Node *list, int index)
{
  if (list != NULL)
  {
    Node *actual = new Node();
    actual = list;

    while ( (actual != NULL) && (index-- > 0) )
    {
      actual = actual->next;
    }
    
    return actual->_mm;
  }
}

int Node::get_size(Node *list)
{
  int size = 0;
  if (list != NULL)
  {
    Node *aux = new Node();
    aux = list;
    while (aux != NULL)
    {
      aux = aux->next;
      size++;
    }
  }

  return size;
}

String Node::time_left(Node *list, int hh, int mm)
{
  String back_count;
  if (list != NULL)
  {
    int this_h,this_m,rest_m;
    int rest_h = 0;
    int index = -1;

    do
    {
      this_h = list->get_item_hh(list,index);
      index++;
    } while (this_h < hh && index < list->get_size(list));
    
    if (this_h > hh)
    {
      this_m = list->get_item_mm(list, index-1);
      rest_m = (this_h*60 + this_m) - (hh*60 + mm);
    }
    else if (this_h < hh)
    {
      this_h = list->get_item_hh(list,0);
      this_m = list->get_item_mm(list,0);
      if (this_h == hh) 
      {
        rest_m = this_m - mm;
      }
      else
      {
        rest_m = (this_h*60 + this_m) + 1440 - (hh*60 + mm);
      }
    }

    while (rest_m >= 60)
    {
      rest_m -= 60;
      rest_h++;
    }
    
    back_count = (rest_h < 10)?"0":"";
    back_count += rest_h;
    back_count += ":";
    if (rest_m < 10)
    {
      back_count += "0";
    }
    back_count += rest_m;

  }
  else
  {
    back_count = "--:--";
  }

  return back_count;
}