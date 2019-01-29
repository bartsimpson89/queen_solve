#include <iostream>
using namespace std;
struct dataNode{
	int data;
	dataNode *next;
	dataNode *pre;
};

int printList(struct dataNode *head)
{
	if (head == NULL) return 0;
	struct dataNode *p = head;
	while(p->next!=NULL)p=p->next;

	while(p->pre!=NULL)
	{
		cout<<p->data;
		p=p->pre;
	}
	cout<<p->data;
	cout<<endl;
	return 0;
}

int freeList(struct dataNode *head)
{
	struct dataNode *tmp=head;
	while(tmp->next!=NULL)
	{
		tmp = tmp->next;
	    free(tmp->pre);
	}
	free(tmp);
	return 0;
}

struct dataNode *newNode(struct dataNode *preNode, int data)
{
	struct dataNode *tmpNode = (struct dataNode *)malloc(sizeof(struct dataNode));
	tmpNode->next = NULL;
	tmpNode->pre = preNode;
	tmpNode->data = data;
	if (preNode != NULL)
		preNode->next = tmpNode;
	return tmpNode;
}


struct dataNode *copyList(struct dataNode *src)
{
	struct dataNode *src_head = src;
	struct dataNode *head = NULL;
	struct dataNode *list = NULL;
	while(src->next!=NULL)
	{
		if (src == src_head)
			head = list = newNode(list, src->data);
		else
			list = newNode(list, src->data);
		src = src->next;
	} 
	list = newNode(list, src->data);
	return head;
}

int compareListLen(struct dataNode *head1, struct dataNode *head2)
{
	while(head1->next!=NULL&&head2->next!=NULL)
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	return (head1->next == NULL) ? 0 : 1;
}


struct dataNode *addList(struct dataNode *head1,struct dataNode *head2)
{
	struct dataNode *p1 = head1;
	struct dataNode *p2 = head2;
	struct dataNode *p_long  = NULL;
	struct dataNode *p_short = NULL;
	if (head1 == NULL || head2 == NULL)
	{
		p1 = (head1 == NULL) ? head2:head1;
		return copyList(p1);
	}
	if (compareListLen(head1, head2) > 0)
	{
		p_long = head1;
		p_short = head2;
	}
	else
	{
		p_long = head2;
		p_short = head1;
	}

	
	int remainder = 0;
	int data = 0;
	struct dataNode *head = NULL;
	struct dataNode *list = NULL;
	while (p_long->next != NULL)
	{
		if(p_short!=NULL)		
		{
			data = (p_long->data + p_short->data+remainder) % 10;
			remainder = (p_long->data + p_short->data+remainder) / 10;
		}
		else
		{
			data = (p_long->data + remainder) % 10;
			remainder = (p_long->data + remainder) / 10;
		}

		if (p_long == head1 || p_long == head2)
			list = head = newNode(list,data);
		else
			list = newNode(list, data);

		p_long = p_long->next; p_short = p_short->next;
	}

	data = (p_long->data + remainder) % 10;
	remainder = (p_long->data + remainder) / 10;
	list = newNode(list, data);
	
	if (remainder > 0)
		list = newNode(list, data);

	return head;
}
	        
struct dataNode *getResult(int a[],int size,int b,int left)
{
	int remainder = 0;
	int data = 0;
	struct dataNode *head = NULL;
	struct dataNode *list = NULL;

	for(int i=0;i<left;i++)	
		if (i == 0)
			list = head = newNode(list, 0);
		else 
			list = newNode(list, 0);

	for(int i=size-1;i>=0;i--)
	{
		data = (b*a[i] + remainder) % 10;
		remainder = (b*a[i] + remainder) / 10;
		if (head == NULL)
			list = head = newNode(list, data);
		else 
			list = newNode(list, data);
	}
	if (remainder > 0)
		list = newNode(list, remainder);
	
	return head;
}

int main(void)
{
	int data[6]={6,6,6,7,8,9};
	int data2[4]={9,9,9,9};
	int data2_len = sizeof(data2)/sizeof(data2[0]);
	int data_len =  sizeof(data)/sizeof(data[0]);
	struct dataNode *result2 = NULL;
	for(int i=data2_len - 1; i>=0;i--)
	{
		struct dataNode *result = getResult(data, data_len, data2[i], data2_len-i-1);
		result2 = addList(result, result2);

		printList(result2);
		freeList(result);
	}
	printList(result2);
	freeList(result2);
	return 0;
}
