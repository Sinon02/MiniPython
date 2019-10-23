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
  typedef union
   {
   int Int;
   float Float;
   }VAL;   
   typedef struct{
   char name[20];
   VAL val;
   int type; //type
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
