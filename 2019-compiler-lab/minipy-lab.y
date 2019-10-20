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
   typedef union
   {
   int Int;
   }VAL;   
   typedef struct{
   char name[20];
   int flag;
   VAL val;
   }TABLE;
   TABLE table[10];
   int count=0;
   int FIND(char * name);
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
        atom_expr '=' assignExpr{cout<<"$1.name"<<$1.name<<endl;strcpy(table[count].name,$1.name);table[count].val.Int=$3.val;cout<<"table name "<<table[0].name<<endl;cout<<"table value"<<table[0].val.Int<<endl;count++;}
      | add_expr {cout<<"add_expr"<<endl;cout<<$1.val<<endl;} 
      ;
number : INT 
       | REAL
       ;
factor : '+' factor
       | '-' factor
       | atom_expr{cout<<"atom_expr"<<endl;}
       ; 
atom  : ID {int i;i=FIND($1.name);if(i!=-1){$$.val=table[i].val.Int;cout<<"ID "<<$$.val<<endl;}}
      | STRING_LITERAL 
      | List 
      | number 
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
add_expr : add_expr '+' mul_expr  {$$.val=$1.val+$3.val;}
	      |  add_expr '-' mul_expr {$$.val=$1.val-$3.val;}
	      |  mul_expr  {cout<<"add_expr"<<endl;}
        ;
mul_expr : mul_expr '*' factor {$$.val=$1.val*$3.val;}
        |  mul_expr '/' factor {$$.val=$1.val/$3.val;}
	      |  mul_expr '%' factor {$$.val=$1.val%$3.val;}
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
