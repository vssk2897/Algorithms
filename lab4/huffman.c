#include <stdio.h>
#include <stdlib.h>
 
// This constant can be avoided by explicitly calculating height of Huffman Tree
#define MAX_TREE_HT 100
 
// A Huffman tree node
struct MinHeapNode
{
    char data;  // One of the input characters
    unsigned freq;  // Frequency of the character
    struct MinHeapNode *left, *right; // Left and right child of this node
};
 
struct MinHeap
{
    unsigned size;    // Current size of min heap
    unsigned capacity;   // capacity of min heap
    struct MinHeapNode **array;  // Array of minheap node pointers
};


int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    huffmanCodes(arr, freq, size);
    return 0;
}

void huffmanCodes(char data[],int freq[],int size)
{
	struct MinHeapNode *root = buildHuffmanTree(data,freq,size);
	int arr[MAX_TREE_HT],top=0;
	printCodes(root,arr,top);
}

struct MinHeapNode *buildHuffmanTree(char data[],int freq[],int size)
{
	struct MinHeapNode *left,*right,*top;
	struct MinHeap *minHeap=createAndBuildMinHeap(data,freq,size);
	if(isSize1(minHeap)!=1)
	{
		
	}
}

struct MinHeap *createAndBuildMinHeap(char data[],int freq[],int size)
{
	struct MinHeap *minHeap=createMinHeap(size);
	for(i=0;i<n;++i)
	{
		minHeap->array[i]=newNode(data[i],freq[i]);
	}
	minHeap->size=size;
	minHeap=buildMinHeap(minHeap);
	return minHeap;
}
struct MinHeap *createMinHeap(int capacity)
{
	struct MinHeap *temp=(struct MinHeap*)malloc(sizeof(struct MinHeap));
	temp->size=0;
	temp->capacity=capacity;
	temp->array=(struct MinHeap**)malloc(capacity * sizeof(struct MinHeap*));
	return temp;
}
struct MinHeapNode *newNode(char data,int freq)
{
	struct MinHeapNode *temp=(struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
	temp->left=temp->right=NULL;
	temp->data=data;
	temp->freq=freq;
}
struct MinHeap *buildMinHeap(struct MinHeap *minHeap)
{
	n=minHeap->size-1;
	for(i=(n-1)/2;i>=0;--i)
	{
		minHeapify(minHeap,i);
	}
	return minHeap;
}
void minHeapify(struct MinHeap *minHeap,int id)
{
	smallest=id;
	left=2*id+1;
	right=2*id+2;
	if(minHeap->array[left]->freq < minHeap->array[smallest]->freq )
	{	
		smallest=left;
	}
	if(minHeap->array[right]->freq < minHeap->array[smallest]->freq )
	{	
		smallest=right;
	}
	if(id!=smallest)
	{
		swapNode(&minHeap->array[smallest],&minHeap->array[id]);
		minHeapify(minHeap,smallest);
	}	
}
void swapNode(struct MinHeapNode** a,struct MinHeapNode** b)
{
	struct MinHeapNode* t;
	*t=*a;
	*a=*b;
	*b=*t;
}
int isSize1
