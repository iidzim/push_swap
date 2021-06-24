/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:26:09 by iidzim            #+#    #+#             */
/*   Updated: 2021/06/24 17:55:45 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

// C++ code for linked list merged sort 
#include <bits/stdc++.h> 
using namespace std; 

// Link list node 
class node { 
public: 
	int data; 
	node* next; 
}; 

// Merging two sorted lists.
node* MergeSortedList(node* lst1, node* lst2) 
{ 
	node* result = NULL; 

	// Base Cases
	if (lst1 == NULL) 
		return (lst2); 
	else if (lst2 == NULL) 
		return (lst1); 

	// recursively merging two lists
	if (lst1->data <= lst2->data) { 
		result = lst1;
		result->next = MergeSortedList(lst1->next, lst2);
	} 
	else { 
		result = lst2; 
		result->next = MergeSortedList(lst1, lst2->next); 
	} 
	return result; 
} 

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.
void SplitList(node* source, node** front, node** back) 
{ 
	node* ptr1; 
	node* ptr2; 
	ptr2 = source; 
	ptr1 = source->next; 

	// ptr1 is incrmented twice and ptr2 is icremented once.
	while (ptr1 != NULL) { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL) { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		}
	}

	// ptr2 is at the midpoint.
	*front = source; 
	*back = ptr2->next; 
	ptr2->next = NULL; 
} 


// Merge Sort
void MergeSort(node** thead) 
{ 
	node* head = *thead; 
	node* ptr1; 
	node* ptr2; 

  // Base Case
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	// Splitting list
	SplitList(head, &ptr1, &ptr2); 

	// Recursively sorting two lists.
	MergeSort(&ptr1); 
	MergeSort(&ptr2); 

	// Sorted List.
	*thead = MergeSortedList(ptr1, ptr2); 
} 



// Printing List.
void printList(node* tnode) 
{ 
	while (tnode != NULL) { 
		cout << tnode->data << " "; 
		tnode = tnode->next; 
	} 
} 

// Push function for inserting nodes in the list.
void push(node** thead, int new_data) 
{ 
	node* new_node = new node(); 
	new_node->data = new_data; 
	new_node->next = (*thead); 
	(*thead) = new_node; 
} 

// Driver Program.
int main() 
{ 
  // Empty list
	node* res = NULL; 
	node* MyList = NULL; 

  // List: 10->4->15->1->2->12->54
	push(&MyList, 54); 
	push(&MyList, 12); 
	push(&MyList, 2); 
	push(&MyList, 1); 
	push(&MyList, 15); 
	push(&MyList, 4);
    push(&MyList, 10); 

	cout << "Unsorted Linked List: "; 
	printList(MyList); 
	cout << "\n"; 

	MergeSort(&MyList); 

	cout << "Sorted Linked List: "; 
	printList(MyList); 

	return 0; 
} 
