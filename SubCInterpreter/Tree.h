enum ScopeType{
  TREE,
  FUNC
};
enum Type{
  INT_,
  CHAR_,
  INT_V_,
  CHAR_V_,
  INT_P_,
  CHAR_P_
};
union VarVal{
  int intVal;
  char charVal;
};
union VarPtr{
  int * intPtr;
  char * charPtr;
};

struct TreeNode;  // avoiding compiler warning
enum nodeType;
enum exprType;

typedef struct FunNode {

  char* funName;
  enum Type funType;
  struct FunNode * next;
  struct TreeNodeList * child_list;
  struct ScopeStack * scope_stack;
  struct TreeNode * function_scope;

} FunNode;

typedef struct FunNodeList { // List of function nodes

  int elements;
  FunNode * first;
  FunNode * last;

} FunNodeList;

typedef struct ProgramNode {

  FunNodeList * function_list;
  struct TreeNode * global_scope;
  struct ScopeStack * actual_stack;
  struct ScopeStack * global_scope_stack;
  // warnings counter
  int warnings;
  // value returned by 'main' function
  int return_value;
  // flag is 1 if there is a main function in the file
  char main_flag;

} ProgramNode;

////////////////////////////////////////////////////////////////////////////////
////////////////// SYMBOL TABLE STRUCTURES /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct SymbolTable{

  int elements;
  struct SymbolTable_Node * first;
  struct SymbolTable_Node * last;
};

struct SymbolTable_Node{

  char identifier[32];
  enum Type type; // INT_ CHAR_ INT_V_ CHAR_V_
  union VarVal varVal;
  union VarPtr varPtr;
  int arrayDim;
  char ignore;

  struct SymbolTable_Node * next;
};

////////////////////////////////////////////////////////////////////////////////
///////////////// TREE NODE USEFUL FUNCTIONS ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char * TreeNode_Identifier  (struct TreeNode *);
int Retrieve_ArrayIndex     (struct TreeNode *);
int IsCostant               (struct TreeNode *);
int isOperation             (struct TreeNode *);
int isAssignable            (struct TreeNode *);
int Multiple_Modifications  (struct TreeNode *, char*);
enum Type expressionType    (struct TreeNode *);
int isStringFormat          (char);
void * TreeNode_Var_Pointer (struct TreeNode *);
int isArrayPointer          (struct TreeNode *);
int Expr_toInt              (struct TreeNode *);

////////////////////////////////////////////////////////////////////////////////
//////////////////  SYMBOL TABLE FUNCTIONS  ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct SymbolTable * SymbolTable_Set                        ();
int SymbolTable_Add                                         (struct SymbolTable *, char *, enum Type, int, char);
int SymbolTable_AddInt                                      (struct SymbolTable *, char *, int);
void SymbolTable_Print                                      (struct SymbolTable *);
struct SymbolTable_Node * SymbolTable_Get                   (struct SymbolTable *, int);
int SymbolTable_Search                                      (struct SymbolTable *, char *);
int SymbolTable_Put                                         (struct SymbolTable *, struct SymbolTable_Node *, int);
struct SymbolTable_Node * SymbolTable_RetrieveVar           (char *);
struct SymbolTable_Node * SymbolTable_IterativeRetrieveVar  (char *);
int Retrieve_VarValue                                       (char *, int);
void * Retrieve_VarPointer                                  (char *, int);
enum Type Retrieve_VarType                                  (char *);
int Retrieve_ArrayDim                                       (char *);
int Check_VarWasDeclared                                    (char *, int);
void SymbolTable_AssignValue                                (struct TreeNode *, int);
int IgnoreFlag                                              (char *);
void SymbolTableCopy                                        (struct SymbolTable *, struct SymbolTable *);
void Change_ArrayDim                                        (char *, int);

////////////////////////////////////////////////////////////////////////////////
////////////////// PROGRAM NODE FUNCTIONS //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

ProgramNode* ProgramNode_Set  ();
int CheckFunAlreadyExist      (char*);


////////////////////////////////////////////////////////////////////////////////
//////////////////  FUNCTION NODE AND LIST METHODS  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void FunNodeList_Set              (ProgramNode *);
void FunNodeList_Add              (struct TreeNode *);
int FunNodeList_Search            (char *);
struct FunNode * FunNodeList_Get  (int);
enum Type Retrive_FunType         (char *);

////////////////////////////////////////////////////////////////////////////////
//////////////////  SCOPE STACK FUNCTIONS  /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct ScopeStack * ScopeStack_Set  ();
void ScopeStack_Push                (struct ScopeStack *, struct TreeNode *, char);
void ScopeStack_Pop                 (struct ScopeStack *);
struct TreeNode * ScopeStack_Peek   (struct ScopeStack *);
void SetAs_ActualScope              (struct TreeNode *, char);
struct TreeNode * Get_ActualScope   ();
int ScopeStack_Elements             ();
struct Scope * Get_ActualScopeNode  ();

////////////////////////////////////////////////////////////////////////////////
//////////////////  TREE BUILDING FUNCTIONS  ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void Add_Node_Tree  (struct TreeNode *);

////////////////////////////////////////////////////////////////////////////////
//////////////////  TREE NODE LIST FUNCTIONS  //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct TreeNodeList* TreeNodeList_Set       ();
void TreeNodeList_Add                       (struct TreeNodeList*, struct TreeNode *);
void TreeNodeList_Rem                       (struct TreeNodeList *);
struct TreeNode * TreeNodeList_IndexSearch  (struct TreeNodeList *, int);

////////////////////////////////////////////////////////////////////////////////
//////////////////  PRINT TREE FUNCTIONS  //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void PrintTree                (ProgramNode*);
void PrintTreeNode            (struct TreeNodeList*);
void PrintTreeNodeType        (unsigned int, struct TreeNode *);
void PrintExprType            (unsigned int, struct TreeNode *);
char * PrintVarType           (enum Type);
void PrintCmpType             (unsigned int, struct TreeNode *);
void PrintDepth               ();
void PrintTreeNodeList        (struct TreeNodeList*);
char * VarTypeString          (enum Type);
void PrintActualST            ();
void PrintActualStack         ();
char * NodeTypeString         (struct TreeNode *);
char * ExprTypeString         (struct TreeNode *);
char * PrintNodeType          (enum nodeType);
char * PrintExpressionType    (enum exprType);
char * IdentifierTypeString   (enum Type);
void PrintScopeStackDimension ();

////////////////////////////////////////////////////////////////////////////////
////////////////// ERROR MESSAGES //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char * ErrorMsg ();
char * WarnMsg  ();
