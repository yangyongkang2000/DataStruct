typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType x,SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType x,SearchTree T);
SearchTree Delete(ElementType x,SearchTree T);
void PrintTree(SearchTree T);
SearchTree CreateSearchTree(ElementType *array,int start,int end);
struct TreeNode 
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};
