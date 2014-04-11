#include "heap_min.h" 
int parent(int i){
    return i / 2;
};

int left(int i){
    return 2 * i;
};

int right(int i){
    return 2 * i + 1;
};

void allocate_memory(HeapMin *heap_min, int lenght){
    heap_min->values = (Cell *)malloc(sizeof(Cell) * (lenght + 1));
    heap_min->keys2position = (int *)malloc(sizeof(int) * lenght);
    heap_min->values[0].value = lenght;
};

int lenght(HeapMin *heap_min){
    return heap_min->values[0].value;
};

void min_heapify(HeapMin *heap_min, int i){
    int l, r, min;
    l = left(i);
    r = right(i);
    if(l <= lenght(heap_min) and heap_min->values[l].value < heap_min->values[i].value)
        min = l;
    else
        min = i;
    if(r <= lenght(heap_min) and heap_min->values[r].value < heap_min->values[min].value)
        min = r;
    if(min != i){
        swap(heap_min, i, min);
        min_heapify(heap_min, min);
    };
};

void swap(HeapMin *heap_min, int i, int j){
    int aux_key, aux_value;
    aux_key = heap_min->values[i].key;
    aux_value = heap_min->values[i].value;
    heap_min->values[i].key = heap_min->values[j].key;
    heap_min->values[i].value = heap_min->values[j].value;
    heap_min->keys2position[heap_min->values[i].key] = i;
    heap_min->values[j].key = aux_key;
    heap_min->values[j].value = aux_value;
    heap_min->keys2position[aux_key] = j;
};

void build_min_heap(HeapMin *heap_min){
    for(int i = lenght(heap_min) / 2; i > 0; i--)
        min_heapify(heap_min, i);
};

void decrement_lenght(HeapMin *heap_min){
    heap_min->values[0].value -= 1;
};

void set_value_and_key_i(HeapMin *heap_min, int i, int value, int key){
    set_value_i(heap_min, i, value);
    set_key_i(heap_min, i, key);
};

void set_value_i(HeapMin *heap_min, int i, int value){
    heap_min->values[i].value = value;
};

void set_key_i(HeapMin *heap_min, int i, int key){
    heap_min->values[i].key = key;
    heap_min->keys2position[key] = i;
};

int get_key_i(HeapMin *heap_min, int i){
    return heap_min->values[i].key;
};

int get_value_i(HeapMin *heap_min, int i){
    return heap_min->values[i].value;
};

int get_position_from_key(HeapMin *heap_min, int key){
    return heap_min->keys2position[key];
};