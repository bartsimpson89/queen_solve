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

struct dataNode *addList(struct dataNode *head1,struct dataNode *head2)
{
	struct dataNode *p1 = head1;
	struct dataNode *p2 = head2;
	struct dataNode *p_long  = NULL;
	struct dataNode *p_short = NULL;
	if (head1 == NULL || head2 == NULL)
	{
		p1 = (head1==NULL)?head2:head1;
		struct dataNode *head = NULL;
		struct dataNode *result = NULL;
		while(p1->next!=NULL)
		{
			struct dataNode *tmpNode = (struct dataNode *)malloc(sizeof(struct dataNode));
			tmpNode->next=NULL;
			tmpNode->pre=NULL;
			tmpNode->data=p1->data;
			if(p1 == head1 || p1 == head2)
			{
				head=tmpNode;
			}
			else
			{
				tmpNode->pre = result;
				result->next=tmpNode;

			}
			result = tmpNode;
			p1=p1->next;
		}
               
		struct dataNode *tmpNode = (struct dataNode *)malloc(sizeof(struct dataNode));
		tmpNode->data = p1->data;
		tmpNode->next=NULL;
		tmpNode->pre = result;
		result->next=tmpNode;
		result=tmpNode;

		return head;

	}

	while(p1->next!=NULL&&p2->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	if (p1->next == NULL)
	{
		p_long = head2;
		p_short = head1;
	}
	else 
	{
		p_long = head1;
		p_short = head2;
	}
	int tmp = 0;

	struct dataNode *head = NULL;
	struct dataNode *result = NULL;
	while (p_long->next!=NULL)
	{
		struct dataNode *tmpNode = (struct dataNode *)malloc(sizeof(struct dataNode));
		tmpNode->next=NULL;
		tmpNode->pre=NULL;

		if(p_short!=NULL)		
		{
			tmpNode->data = (p_long->data+p_short->data+tmp)%10;
			tmp = (p_long->data+p_short->data+tmp)/10;
		}
		else
		{
			tmpNode->data = (p_long->data+tmp)%10;
			tmp = (p_long->data+tmp)/10;
		}

		if (p_long == head1 || p_long == head2)
		{
			head = tmpNode;
		}
		else
		{
			tmpNode->pre=result;
			result->next=tmpNode;
			tmpNode->next=NULL;
		}
		result = tmpNode;
		p_long = p_long->next;
		p_short = p_short->next;
	}
	struct dataNode *tmpNode = (struct dataNode *)malloc(sizeof(struct dataNode));
	tmpNode->data = (p_long->data + tmp)%10;
	tmp = (p_long->data + tmp)/10;
	tmpNode->next=NULL;
	tmpNode->pre = result;
	result->next=tmpNode;
	result=tmpNode;
	
	
	if (tmp > 0)
	{
		struct dataNode *tmpNode = (struct dataNode *)malloc(sizeof(struct dataNode));
		tmpNode->data = tmp;
		tmpNode->next = NULL;
		tmpNode->pre = result;
		result->next=tmpNode;
	}

	return head;
}
	        
struct dataNode *getResult(int a[],int size,int b,int left)
{
	int tmp = 0;
	int result = 0;
	struct dataNode *head = NULL;
	struct dataNode *tmpNode = NULL;

	for(int i=size-1;i>=0;i--)
	{

		result = (b*a[i]+tmp)%10;
		tmp = (b*a[i]+tmp)/10;
		struct dataNode *p = (struct dataNode *)malloc(sizeof(struct dataNode));
		p->data = result;
		p->next=NULL;
		p->pre=NULL;
		
		if (i == size -1)
		{
			head = p;
		}
		else
		{
			p->pre = tmpNode;
			tmpNode->next = p;
		}
		tmpNode = p;
	}
	if (tmp > 0)
	{
		struct dataNode *p = (struct dataNode *)malloc(sizeof(struct dataNode));
		p->data = tmp;
		p->pre = tmpNode;
		tmpNode->next = p;
		p->next = NULL;
	}

	
	for(int i=0;i<left;i++)
	{
		
		struct dataNode *p = (struct dataNode *)malloc(sizeof(struct dataNode));
		p->data = 0;
		p->pre=NULL;

		head->pre=p;
		p->next=head;
		head=p;
	}

	return head;
}



int main(void)
{
	int data[6]={1,2,3,4,5,6};
	int data2[3]={1,1,1};
	struct dataNode *result2 = NULL;
	for(int i=sizeof(data2)/sizeof(data2[0])-1;i>=0;i--)
	{
		struct dataNode *result = getResult(data,sizeof(data)/sizeof(data[0]),data2[i],sizeof(data2)/sizeof(data2[0])-i-1);
		printList(result);
		
		result2 = addList(result, result2);

		printList(result2);
		freeList(result);
	}
	printList(result2);
	freeList(result2);
	return 0;
}



