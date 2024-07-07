# DataStructure
A project for data structure.
For every data structure, you should care three things: logical structure, physical structure and data operations.

## Linear List
##### Definition: 
&nbsp;&nbsp;&nbsp;&nbsp;A linear list is a finite sequence of n(n>=0) data elements with the same data structure.

##### Basic Operation:
1. **InitList(&L)**: build a new linear list `L` and allocate memory space. 
2. **DestroyList(&L)**: destroy the linear list `L` and free the memory space.
3. **ListInsert(&L, i, e)**: insert the element `e` at the position `i` of linear list `L`.
4. **ListDelete(&L, i, &e)**: delete the element at the position `i` of linear list `L` and copy the element to `e` .
5. **LocateElem(L, e)**: find the specified element `e` in linear list `L`.
6. **GetElem(L, i)**: find the element at the position `i` of linear list `L`.

##### Other Operation:
1. **Length(L)**: return the length of the linear list `L`.
2. **PrintList(L)**: print the linear list `L`.
3. **Empty(L)**: return whether the linear list `L` is empty.

#### 1. Sequence List
##### Definition
&nbsp;&nbsp;&nbsp;&nbsp;Use sequential storage to implement linear list.
##### Characteristic
1. support random access
2. high storage density
3. expand the capacity is not easy
4. insert and delete operations are inconvenient

#### 2. (Circular) Single/Double Linked List
##### Definition
&nbsp;&nbsp;&nbsp;&nbsp;Use linked storage to implement linear list.
##### Characteristic
1. not support random access
2. lower storage density
3. expand the capacity is easy
4. insert and delete operations are convenient
##### Realize Method
1. with head node(better)
2. without head node

#### 3. Static Linked List
##### Definition
&nbsp;&nbsp;&nbsp;&nbsp;Use array to implement linked list.


## Stack
##### Definition:
&nbsp;&nbsp;&nbsp;&nbsp;A linear list based on the principle of last in first out.
##### Basic Operation:
1. **InitStack(&S)**: build a new stack `S` and allocate memory space.
2. **DestroyStack(&S)**: destroy the stack `S` and free the memory space.
3. **Push(&S, x)**: add data to the top of the stack.
4. **Pop(&S, &x)**: remove first element.
5. **GetTop(S, &x)**: get the data at the first element of the stack.

##### Other Operation:
1. **empty(S)**: return true if the stack is empty.

## Queue
##### Definition:
&nbsp;&nbsp;&nbsp;&nbsp;A linear list based on the principle of first in first out.
##### Basic Operation:
1. **InitQueue(&Q)**: build a new Queue `Q` and allocate memory space.
2. **DestroyQueue(&Q)**: destroy the Queue `Q` and free the memory space.
3. **Enqueue(&Q, x)**: add data to the end of the Queue.
4. **DeQueue(&Q, &x)**: remove the first element.
5. **GetHead(Q, &x)**: get the data at the first element of the Queue.

##### Other Operation:
1. **empty(Q)**: return true if the Queue is empty.