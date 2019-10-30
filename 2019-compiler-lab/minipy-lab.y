%{
   /* definition */
   #include <stdio.h>
   #include <ctype.h>
   using namespace std;
   #include <iostream>
   #include <string>
   #include <map>
   #include "lex.yy.c"
   #include <string.h>
   #include <iomanip>
   
  typedef struct VAL
   {
        int flag;
	union{
		int i;//flag=0
		float f;//flag=1
		string s;//flag=2
		struct list{
			int len;
			int size;
			struct VAL *val;
		}l;//flag=3
	}DATA;
   }VAL;   
   typedef struct{
   char name[20];
   VAL *val;
   }TABLE;
   TABLE table[10];
   int count=0;
   int FIND(char * name);
   void yyerror(char *s);
   #define eps 1e-6
%}
%token ID INT REAL STRING_LITERAL


%%
Start : prompt Lines
      ;
Lines : Lines  stat '\n' prompt
      | Lines  '\n' prompt
      | 
      | error '\n' {yyerrok;}
      ;
prompt : {cout << "miniPy> ";}
       ;
stat  : assignExpr {cout<<"stat"<<endl;}
      ;
assignExpr:
        atom_expr '=' assignExpr	{int i=0;i=FIND($1.name);
					cout<<"i= "<<i<<endl;
					cout<<"$1.name "<<$1.name<<endl;
					if(i==-1)
					{i=count;
					strcpy(table[count].name,$1.name);
					count++;
					}
					table[i].type=$3.Tval.type;
					cout<<"$3.Type "<<$3.Tval.type<<endl;
					switch(table[i].type)
					{
					case 0: table[i].val.Int=$3.Tval.val;
					cout<<"table value "<<table[i].val.Int<<endl;
					break;
					case 1: table[i].val.Float=$3.Tval.val;
					if(table[i].val.Float-(int)table[i].val.Float<eps)
					cout<<"table value(changed) "<<fixed << setprecision(1)<<table[i].val.Float<<endl;
					else
					cout<<"table value "<<table[i].val.Float<<endl;
					break;
					}
					cout<<"table index "<<i<<endl;
					cout<<"table name "<<table[i].name<<endl;
					cout<<"table type "<<table[i].type<<endl;
									}
      | add_expr	{cout<<"add_expr"<<endl;
			cout<<$1.Tval.val<<endl;} 
      ;
number : INT {cout<<"INT "<<endl;$$.Tval.type=0;}
       | REAL{cout<<"REAL "<<endl;$$.Tval.type=1;}
       ;
factor : '+' factor
       | '-' factor
       | atom_expr	{cout<<"atom_expr"<<endl;
			int i;i=FIND($1.name);
      			if(i!=-1)
			{switch(table[i].type)
			{case 0: 
			$$.Tval.val=table[i].val.Int;
			break;
			case 1: 
			$$.Tval.val=table[i].val.Float;
			break;
			$$.Tval.type=table[i].type;
			cout<<"ID "<<$$.Tval.val<<endl;
			}
			}
			}

       ; 
atom  : ID
      | STRING_LITERAL 
      | List 
      | number{cout<<"number "<<endl;} 
      ;
slice_op :  /*  empty production */
        | ':' add_expr 
        ;
sub_expr:  /*  empty production */
        | add_expr
        ;        
atom_expr : atom {cout<<"atom"<<endl;}
        | atom_expr  '[' sub_expr  ':' sub_expr  slice_op ']'
        | atom_expr  '[' add_expr ']'
        | atom_expr  '.' ID
        | atom_expr  '(' arglist opt_comma ')'
        | atom_expr  '('  ')'
        ;
arglist : add_expr
        | arglist ',' add_expr 
        ;
        ;      
List  : '[' ']'
      | '[' List_items opt_comma ']' 
      ;
opt_comma : /*  empty production */
          | ','
          ;
List_items  
      : add_expr
      | List_items ',' add_expr 
      ;
add_expr : add_expr '+' mul_expr  {$$.Tval.val=$1.Tval.val+$3.Tval.val; $$.Tval.type=($1.Tval.type||$3.Tval.type);}
	      |  add_expr '-' mul_expr {$$.Tval.val=$1.Tval.val-$3.Tval.val;$$.Tval.type=($1.Tval.type||$3.Tval.type);}
	      |  mul_expr  {cout<<"add_expr"<<endl;}
        ;
mul_expr : mul_expr '*' factor {$$.Tval.val=$1.Tval.val*$3.Tval.val;$$.Tval.type=($1.Tval.type||$3.Tval.type);}
        |  mul_expr '/' factor {$$.Tval.val=$1.Tval.val/$3.Tval.val;$$.Tval.type=($1.Tval.type||$3.Tval.type);}
	      |  mul_expr '%' factor {$$.Tval.val=(int)$1.Tval.val%(int)$3.Tval.val;$$.Tval.type=($1.Tval.type||$3.Tval.type);}
        |  factor {cout<<"factor"<<endl;}
        ;

%%

int main()
{
   return yyparse();
}

void yyerror(char *s)
{
   cout << s << endl<<"miniPy> "; 
}

int yywrap()
{ return 1; }        		    

int FIND(char *s)
{
  int i =0;
  for(i=0;i<count;i++)
  { if(!strcmp(s,table[i].name))
	return i;   
} 
return -1; 
}


void print(VAL val)
{
	int i;
	switch(VAL.flag)
	{
		case 0:
			cout<<VAL.DATA.i;
			break;
		case 1:
			cout<<VAL.DATA.f;
			break;
		case 2:
			cout<<VAL.DATA.s;
			break;
		case 3:
			cout<<'[';
			if(VAL.DATA.l.len>0) print(VAL.DATA.l.val[0]);
			for(i=1;i<VAL.DATA.l.len;i++)
			{
				cout<<', ';
				print(VAL.DATA.l.val[i]);
			}
			cout<<']';
			break;
	}
}

VAL* newlist()
{
	VAL *l;
	l=(VAL*)malloc(sizeof(VAL));
	l.flag=3;
	l.DATA.l.len=0;
	l.DATA.l.size=INIT_LIST_SIZE;
	l.DATA.l.val=(VAL*)malloc(INIT_LIST_SIZE*sizeof(VAL));
	if(l.DATA.l.val==0) 
	{
		yyerror("malloc fail");
		//other operation
	}
	return l;
}

void exlist(struct list &l) //extend
{
	l.size*=2;
	l.val=realloc(l.val,l.size);
	if(l.val==0) 
	{
		yyerror("malloc fail");
		//other operation
	}
	return;
}

void append(struct list &l,VAL _val)
{
	if(l.len>=l.size) exlist(l);
	l.val[l.len++]=_val;
}

void add(struct list &l,struct list o)
{
	int i;
	while(l.len+o.len-1>=l.size) exlist(l);
	for(i=0;i<o.len;i++)l.val[l.len++]=o.val[i];
}

void insert(struct list &l,int index,VAL _val)
{
	int i;
	if(index>l.len) yyerror("index out of bound");
	if(l.len>=l.size) exlist(l);
	for(i=l.len;i>index;i--) l.val[i]=l.val[i-1];
	l.len++;
	l.val[index]=_val;
}

VAL pop(struct list &l,int index)
{
	VAL _val=l.val[index];
	for(i=index+1;i<l.len;i++) l.val[i-1]=l.val[i];
	l.len--;
	return _val;
}

VAL* slice(struct list l,int begin,int end,int step)
{
	VAL* _val;
	int i;
	_val=newlist();
	for(i=begin;i<end;i+=step) append(_val->DATA.l,l.val[i]);
	return _val;
}

/*void setslice(struct list &l,int begin,int end,int step,struct list o)
{
	int i,j;
	if(begin<0||step<1||end>l.len) yyerror("index out of bound");
	if(step!=1)
	{
		if((end-begin)/step!=o.len) yyerror("incompatible length");
		for(i=begin,j=0;i<end;i+=step) l.d[i]=o.d[j++];
	}
	else//step=1
	{
		if(end-begin>o.len)
		{
			while(l.len+o.len-end+begin-1>=l.size) exlist(l);
			for(i=l.len+o.len-1-end+begin,j=l.len-1;j>=end;i--,j--) l.d[i]=l.d[j];
		}
		else if(end-begin<o.len)
		{
			for(i=begin+o.len,j=end;j<l.len;i++,j++) l.d[i]=l.d[j];

		}
		for(i=len.begin,j=0;j<o.len;i++,j++) l.d[i]=o.d[j]; 
		l.len=l.len+o.len-end+begin;
	}
	return
}*/
