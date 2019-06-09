#include <stdio.h>
#include <stdlib.h>
 
typedef struct ns{
  int data;
  struct ns* next;
}node;
 
node* create_node(int);
void insert_node(node*, node*);
void remove_node(node*);
void print_node(node*);
void free_node(node*);
node* reverse_node(node*);
node* sort_node(node*);
int count_node(node*);
 
int main(void){
  node* lists = create_node(0);
  node* a = create_node(1);
  node* b = create_node(2);
  node* c = create_node(3);
  node* d = create_node(4);
  node* e = create_node(5);
 
  insert_node(lists, e);
  insert_node(lists, a);
  insert_node(a,b);
  insert_node(b,c);
  insert_node(c,d);
 
  remove_node(d);
 
  print_node(lists);
  count_node(lists);
 
  node* head = reverse_node(lists);
  print_node(head);
 
 
  node* f = create_node(7);
  node* g = create_node(9);
  insert_node(a,f);
  insert_node(c,g);
  print_node(head);
  head = sort_node(head);
  print_node(head);
}
 
node* create_node(int data){
  node* n = (node*)malloc(sizeof(node));
  n->data = data;
  n->next = NULL;
 
  return n;
}
 
void insert_node(node* n1, node* input){
  input->next = n1->next;
  n1->next = input;
}
 
void remove_node(node* n1){
  n1->next = n1->next->next;
}
 
void print_node(node* head){
  node* n = lists;
  printf("linked list:");
  while(n != NULL){
    printf("%d",n->data);
	n = n->next;
  }
  printf("\n");
}
 
void free_node(node* head){ 
  if(lists->next != NULL){
	free_node(lists->next);
  }
  free(lists);
}
 
node* reverse_node(node* head){
  node *p1, *p2, *p3;
 
  if(head == NULL || head->next == NULL){
	return head;
  }
 
  p1 = head;
  p2 = head->next;
 
  while(p2){
	p3 = p2->next;
	p2->next = p1;
	p1 = p2;
	p2 = p3;
  }
 
  head->next = NULL;
  head = p1;
 
  return head;
}
 
node* sort_node(node* head){
  node *p;
  int n, temp, i, j;
  n = count_node(head);
 
  if(head == NULL || head->next == NULL){
	return head;
  }
 
  p = head;                                                                                                
 
  int test;
  test = p->next->data;
  for(j=1; j<n; ++j){
      p = head;
      for(i=0; i< n-j; ++i){
          if(p->data > p->next->data){
              temp = p->data;
              p->data = p->next->data;
              p->next->data = temp;
          }
      p = p->next;
      }
  }
 
  return head;
}
 
int count_node(node* head){
  int n=0;
  while(head){
	n = n+1;
	head = head->next;
  }
  printf("node count = %d \n",n);
 
  return n;
}
 
Resule
linked list:01234
node count = 5
linked list:43210
linked list:4392170
node count = 7
linked list:0123479
