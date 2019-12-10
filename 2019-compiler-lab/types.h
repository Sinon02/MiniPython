#ifndef TYPES_DEFINED
#define TYPES_DEFINED
struct VAL;
struct list {
  int len;
  int size;
  struct VAL *val;
};
union vald {
  int i;          // flag=0
  float f;        // flag=1
  char *s;        // flag=2
  struct list *l; // flag=3
};
struct VAL {
  int flag;
  union vald DATA;
};
typedef struct VAL VAL;
typedef struct {
  char *name;
  VAL val;
  int Res;
} TABLE;
struct slice {
  struct list *l;
  int begin;
  int end;
  int step;
};
union yyd {
  int i;              // 0
  float f;            // 1
  char *s;            // 2
  struct list *l;     // 3
  VAL *v;             // 4
  struct slice slice; // 5
};
typedef struct {
  int type;
  char *name;
  union yyd data;
} YYSTYPE;

// functions
VAL pack(YYSTYPE val);
YYSTYPE unpack(VAL val);
int FIND(char *name);
void yyerror(const char *s);
void print(VAL val);
void print(YYSTYPE val);
struct list *newlist();
void exlist(struct list *l); // extend
void append(struct list *l, VAL _val);
void add(struct list *l, struct list *o);
void insert(struct list &l, int index, VAL _val);
VAL pop(struct list &l, int index);
struct list *slice(struct slice s);
struct list *slice(struct list *l, int begin, int end, int step);
inline void setslice(struct slice s, struct list *o);
void setslice(struct list *l, int begin, int end, int step, struct list *o);
int MOD(int n, int M);
float FMOD(float n, float M);
void PrintFloat(float a);
int GetPlaceInSlice(int index, int len, int left);
#endif
