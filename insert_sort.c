#include <stdio.h>
#include <malloc.h>

#define LEN 7

/**
 * defind the result node
 */
typedef struct sNode{
	
	int  * num;
	struct sNode * next;
	struct sNode * previous;
	
} Node;

int stack[LEN] = {1,5,3,6,10,9,2};

Node * push( int * num, Node * node );

int main(){
	
	Node * first = ( Node * ) malloc( sizeof( Node ) );
	
	
	int i;
	for( i = 0; i < LEN ; ++i ){
		first = push( &stack[i], first );			
	}
	
	Node * current = first;
	while( current != NULL ){
		printf( "%d \n" , * current->num );
		current = current->next;
	}
	
}

Node * push( int * num, Node * nodeStart ){
	
	
	//first create node;
	Node * cNode = ( Node * ) malloc( sizeof( Node ) );
	cNode->num = num;
	
	
	
	if( nodeStart->num == NULL ){
		nodeStart = cNode;
		return nodeStart;
	}
	
	
	Node * pNode = nodeStart;
	
	while( pNode != NULL ){
		
		
		if( * cNode->num <= * pNode->num ){
			
			
			
			cNode->next     = pNode;
			
			if( pNode->previous != NULL ){
				
				cNode->previous = pNode->previous;
				pNode->previous->next = cNode;
				pNode->previous = cNode;	
	
			}else{
				pNode->previous = cNode;
				nodeStart = cNode;
			}
			return nodeStart;
		}
		
		
		if( pNode->next == NULL ){
			pNode->next = cNode;
			cNode->previous = pNode;
			return nodeStart;
		}
		
		pNode = pNode->next;
		
	}
	
	
}
