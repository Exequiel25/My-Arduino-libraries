/*
  Node.h - Library for using a Node
  Created by Exequiel Magni, March 10, 2022.
*/
 
#include "Arduino.h"

// Guardián de inclusión múltiple
#ifndef Node_h
#define Node_h

class Node
{
private:
  int _hh;
  int _mm;
  class Node *next = NULL;
public:
  Node();
  void add_item(Node *&list, int hh, int mm);
  void remove_item(Node *&list, int index);
  void remove_all(Node *&list);
  void edit_item(Node *&list, int index, int new_hh, int new_mm);
  int get_item_hh(Node *list, int index);
  int get_item_mm(Node *list, int index);
  int get_size(Node *list);
  String time_left(Node *list, int hh, int mm);
};

#endif