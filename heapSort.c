#include <stdio.h>
#include <stdlib.h>

#define 	SIZEMAX	10

struct SqList
{
    /* data */
    int 	array[SIZEMAX];
    int 	length;
};

void heapAjust(struct SqList *, int, int);
void swap(struct SqList *, int, int);
void heapSort(struct SqList *);



int main()
{
    struct SqList  list;
    int     i;

    for (i = 0; i < SIZEMAX/2; i++)
        list.array[i] = rand();

    list.length = SIZEMAX / 2;

	heapSort(&list);	
    // for (i = 0; i < SIZEMAX / 2; i++)
    // 	printf("%d  ," , list.array[i]);

    return 0;
}


void heapSort(struct SqList *list)
{
    int 	i;
    int     index_max = list->length - 1 ;


    for (i = (index_max) / 2  - 1; i >= 0; i--){
    	if (i == 0) {
    		printf("******************************\n");
    		break;
    	}
        heapAjust(list, i, index_max);
    }

    for (i = index_max; i > 0; i--) {
        swap(list, 0, i);
        heapAjust(list, 0, i - 1);
    }

           // for (i = index_max / 2 ; i > 0; i--) {
           //     heapAjust(list, i, index_max);
           // }
    
           // for (i = index_max; i > 1; i--) {
           //     swap(list, 1, i);
           //     heapAjust(list, 1, i-1);
           // }
} 


void heapAjust(struct SqList *list, int index_min, int index_max)
{
    int     temp, j;
    temp = list->array[index_min];

    for ( j = 2 * index_min + 1; j <= index_max; j *= 2) {

        if (j < index_max && list->array[j] <= list->array[j + 1]) {
            j++;       
        }
        if (temp >= list->array[j]) {
            break;
        }

        list->array[index_min] = list->array[j];
        index_min = j;
    }

    list->array[index_min] = temp;   // insert it ;
}

void swap(struct SqList *list, int index_min, int max_index)
{
    int     temp;
    temp = list->array[index_min];
    list->array[index_min] = list->array[max_index];
    list->array[max_index] = temp;
    printf("%d\n", list->array[max_index]);
}















