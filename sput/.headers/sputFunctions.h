/*----------Enumerated Types-----------*/


/*----------Symbolic Constants-----------*/



/*----------Structures----------*/

//struct stackNode {
//
//    int num;
//    struct stackNode *nextNode;
//
//};

//struct stackStructure  {
//
 //   struct stackNode *start;
  //  struct stackNode *current;
//    int nItems;

//};

/*----------Function Prototypes-----------*/
typedef struct queueNode *QueueNode;
typedef struct actionQueueStructure *ActionQueueStructure;

ActionQueueStructure createActionQueue(int size );
QueueNode createNode();
int pushToQueue(ActionQueueStructure queue, int newData);
int popFromQueue(ActionQueueStructure queue);
