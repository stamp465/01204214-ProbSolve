#include<bits/stdc++.h>

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
			if(j==0)			list_of_list[st] = it;
			else if(j==nub-1)	list_of_list[st] = it;
			else				list_of_list[st] = NULL;
			st++;
		}
	}
	
	for(int i=1;i<st;i++){
		if(list_of_list[i]!=NULL){
			printf("list of %d -> ",i);
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
	}
	
	int go = 0; 
	//0 forward = forward
	//1 forward = backward
	node_t* it = list_of_list[1];
	for(int xxx=0;xxx<N;xxx++){
		char menu[3];
		scanf(" %s",menu);
		if(menu[0]=='B'){
			if(go==0 && it->before!=NULL){
				if(it->before->before!=NULL && it->before->before==it)	go = 1;
				it = it->before;
			}
			else if(go==1 && it->next!=NULL){
				if(it->next->next!=NULL && it->next->next==it)	go = 0;
				it = it->next;
			}
		}
		else if(menu[0]=='F'){
			//printf("%d %d\n",go,it->number);
			if(go==0 && it->next!=NULL){
				if(it->next->next!=NULL && it->next->next==it)	go = 1;
				//printf("next %d %d\n",it->number,it->next->number);
				it = it->next;
			}
			else if(go==1 && it->before!=NULL){
				if(it->before->before!=NULL && it->before->before==it)	go = 0;
				//printf("next be %d %d\n",it->number,it->before->number);
				it = it->before;
			}
		}
		else if(menu[0]=='C'){
			int pos;
			scanf("%d",&pos);
			//printf("....\n");
			if(go==0){
				if(it->next!=NULL){
					//printf("11111\n");
					
					list_of_list[it->next->number] = it->next;
					if(it->next->before!=NULL && it->next->before==it){
						it->next->before = NULL;
					}
					else if(it->next->next!=NULL && it->next->next==it){
						it->next->next = NULL;
					}
					
				}	
				
				if(it->next==NULL){
					list_of_list[it->number] = NULL;
				}
				it->next = list_of_list[pos];
				int chxx = 0;
				if(list_of_list[pos]->before==NULL && list_of_list[pos]->next==NULL){
					chxx = 1;
				}
				if(list_of_list[pos]->before==NULL)	{
						//printf("not re\n");
					list_of_list[pos]->before = it;
				}
				else if(list_of_list[pos]->next==NULL)						{
					//printf("re\n");
					list_of_list[pos]->next = it;
				}
				//printf("%d %d %d\n",it->next->number,it->next->before->number,it->next->next->number);
				if(chxx==0)	list_of_list[pos] = NULL;
					
					
				if(it->next->next!=NULL && it->next->next==it)	go = 1;
				if(it->next!=NULL)	it = it->next;

			}
			else if(go==1){
				if(it->before!=NULL){
					
					list_of_list[it->before->number] = it->before;
					if(it->before->next!=NULL && it->before->next==it){
						it->before->next = NULL;
					}
					else if(it->before->before!=NULL && it->before->before==it){
						it->before->before = NULL;
					}

					
				}
				
				
				
				if(it->before==NULL){
					list_of_list[it->number] = NULL;
				}
				it->before = list_of_list[pos];
				int chxx = 0;
				if(list_of_list[pos]->before==NULL && list_of_list[pos]->next==NULL){
					chxx = 1;
				}
				if(list_of_list[pos]->next==NULL)	{
					list_of_list[pos]->next = it;
				}
				else if(list_of_list[pos]->before==NULL)	{
					list_of_list[pos]->before = it;
				}
				if(chxx==0)	list_of_list[pos] = NULL;
					
				if(it->before->before!=NULL && it->before->before==it)	go = 0;
				if(it->before!=NULL)	it = it->before;

			}
			
			
			for(int ix=1;ix<st;ix++){
				if(list_of_list[ix]!=NULL){
					printf("list of %d -> ",ix);
					node_t* it22 = list_of_list[ix];
					node_t* it22x = list_of_list[ix];
					int gox;
					if(it22->before!=NULL)		gox = 0;
					if(it22->next!=NULL)		gox = 1;
					while(it22!=NULL){
						printf("%d ",it22->number);
						if(gox==0){
							if(it22->before!=NULL && it22->before->before != NULL && it22->before->before == it22) 	gox = 1;
							it22 = it22->before;
						}
						else if(gox==1){
							if(it22->next!=NULL && it22->next->next  != NULL && it22->next->next == it22) 		gox = 0;
							it22 = it22->next;
						}
					}
					
					if(ix==104){
						if(it22x->before!=NULL)		printf("before "),printf("%d ...",it22x->before->number);
						//printf("01");
						if(it22x->before==NULL)		printf("before is NULL ... ");
						//printf("02");
						if(it22x->next!=NULL)		printf("next "),printf("%d ...",it22x->next->number);
						//printf("03");
						if(it22x->next==NULL)		printf("next is NULL ... ");
						//printf("04");
					}
					printf("\n");
				}
			}
			
		}
		//arr[xxx] = it->number;
		//printf("%d go %d\n",it->number,go);
		printf(".... now -> %d\n",it->number);
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




4 40
3
3
3
3
F
C 7
F
F
C 10
C 4
C 12
F
F
C 6
F
F
F
B
B
C 3
C 5
F
F


4 40
1
1
1
1
C 3
C 4
C 2
F
F
B
B
B
B
B
F
F
F
F



30 1000
6
9
6
9
9
6
7
9
10
5
9
7
5
6
7
5
5
6
7
8
9
7
9
9
10
5
9
8
10
5



*/
