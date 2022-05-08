#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int number;
	struct node *before;
	struct node *next;
}node_t;

node_t* list_of_list[100500];
//int arr[100500];

node_t *append(node_t* nodest,int num){
	node_t *new_node = (node_t*)malloc(sizeof(node_t));
  
    new_node->number  = num;
    new_node->before = NULL;
    new_node->next = NULL;
 
	if (nodest == NULL)
    {
       nodest = new_node;
       return nodest;
    } 
    
	new_node->before = nodest;
    nodest->next = new_node;
    nodest = nodest->next;
    return nodest;   
}

int main(){
	int L,N,st=1;
	scanf("%d %d",&L,&N);
	for(int i=0;i<L;i++){
		node_t* it = NULL;
		int nub,savest=st;
		scanf("%d",&nub);
		for(int j=0;j<nub;j++){
			it = append(it,st);
			st++;
			if(j==0)		list_of_list[savest] 		= it;
			if(j==nub-1)	list_of_list[savest+nub-1] 	= it;
			else			list_of_list[st] = NULL;
		}
	}
	
	/*for(int i=1;i<st;i++){
		if(list_of_list[i]!=NULL){
			node_t* it = list_of_list[i];
			int go;
			if(it->before!=NULL)	go = 0;
			if(it->next!=NULL)		go = 1;
			while(it!=NULL){
				printf("%d ",it->number);
				if(go==0)	it = it->before;
				if(go==1)	it = it->next;
			}printf("\n");
		}
	}*/
	
	int go = 0; 
	//0 forward = forward
	//1 forward = backward
	node_t* it = list_of_list[1];
	for(int xxx=0;xxx<N;xxx++){
		char menu[3];
		scanf(" %s",menu);
		if(menu[0]=='B'){
			if(go==0 && it->before!=NULL){
				if(it->before->before!=NULL && it->before->before->number==it->number)	go = 1;
				it = it->before;
			}
			if(go==1 && it->next!=NULL){
				if(it->next->next!=NULL && it->next->next->number==it->number)	go = 0;
				it = it->next;
			}
		}
		if(menu[0]=='F'){
			//printf("%d %d\n",go,it->number);
			if(go==0 && it->next!=NULL){
				if(it->next->next!=NULL && it->next->next->number==it->number)	go = 1;
				it = it->next;
			}
			if(go==1 && it->before!=NULL){
				if(it->before->before!=NULL && it->before->before->number==it->number)	go = 0;
				it = it->before;
			}
		}
		if(menu[0]=='C'){
			int pos;
			scanf("%d",&pos);
			//printf("....\n");
			if(go==0){
				if(it->next!=NULL){
					//printf("11111\n");
					
					list_of_list[it->next->number] = it->next;
					if(it->next->before!=NULL && it->next->before->number==it->number){
						it->next->before = NULL;
					}
					else if(it->next->next!=NULL && it->next->next->number==it->number){
						it->next->next = NULL;
					}
					
					if(list_of_list[pos]->before==NULL)	{
						//printf("not re\n");
						list_of_list[pos]->before = it;
					}
					else								{
						//printf("re\n");
						list_of_list[pos]->next = it;
					}
					
				}	
					
				it->next = list_of_list[pos];
				list_of_list[pos] = NULL;
					
					
				if(it->next->next!=NULL && it->next->next->number==it->number)	go = 1;
				it = it->next;

			}
			else if(go==1){
				if(it->before!=NULL){
					
					list_of_list[it->before->number] = it->before;
					if(it->next->before!=NULL && it->next->before->number==it->number){
						it->next->before = NULL;
					}
					else if(it->next->next!=NULL && it->next->next->number==it->number){
						it->next->next = NULL;
					}
					
					
					if(list_of_list[pos]->before==NULL)	{
						//printf("not re\n");
						list_of_list[pos]->before = it;
					}
					else								{
						//printf("re\n");
						list_of_list[pos]->next = it;
					}
					
				}
				it->before = list_of_list[pos];
				list_of_list[pos] = NULL;
					
				if(it->before->before!=NULL && it->before->before->number==it->number)	go = 0;
				it = it->before;

			}
			
			
		}
		//arr[xxx] = it->number;
		printf("%d\n",it->number);
	}
	/*for(int i=0;i<N;i++){
		cout << arr[i] << '\n';
	}*/
}

/*
4 10 
3
4
2
5
B 
F 
C 9
C 4 
F 
B 
F 
C 3 
F 
C 14 
*/
