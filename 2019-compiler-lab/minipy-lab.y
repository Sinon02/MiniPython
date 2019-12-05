%{
   /* definition */
   #include <stdio.h>
   #include <ctype.h>
   #include <time.h>
   using namespace std;
   #include <iostream>
   #include <string>
   #include <vector>
   #include <map>
   #include <cmath>
   #include "lex.yy.c"
   #include <string.h>
   #include <iomanip>
   #include "types.h"
#define eps 1e-6
#define INIT_LIST_SIZE 10
#define INIT_TABLE_SIZE 20

TABLE *table;
int tablelen=0;
int tablesize=INIT_TABLE_SIZE;
vector<unsigned long> print_stack;

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
prompt : {cout << "\nminiPy> ";}
       ;
stat  : assignExpr 
      ;
assignExpr:
        atom_expr '=' assignExpr	{
					switch($1.type)
					{
					case 0:
					case 1:
					case 2:
					case 3:yyerror("assign to right value");break;
					case 4:{*($1.data.v)=pack($3);
				 			int i=FIND($1.name);
							if(table[i].Res==1)
							{
								table[i].Res=0;
							}
							break;
					}
					case 5:if($3.type==3)setslice($1.data.slice,$3.data.l);else {yyerror("type error");YYERROR;}
					}
					}
      | add_expr	{
			print($1);
			}
      ;
number : INT 
       | REAL
       ;
factor : '+' factor
       | '-' factor	{
				switch($2.type)
				{
					case 0: $$.data.i=-$2.data.i;$$.type=$2.type;break;
					case 1: $$.data.f=-$2.data.f;$$.type=$2.type;break;
					case 2:	yyerror("TypeError: bad operand type for unary -: 'str'");
						YYERROR;
					case 3: yyerror("TypeError: bad operand type for unary -: 'list'");
						YYERROR;
					default: yyerror("TypeError: bad operand type");
						YYERROR;
				}	
			}
       | atom_expr	{
			{
				switch($1.type)
				{	
					case 4: 
						$$=unpack(*($1.data.v));
						break;
					case 5:
						$$.type=3;
						$$.data.l=slice($1.data.slice); 
						break;
					default:
						break;
				}
			}
		}

       ; 
atom  : ID {
			$$.name=(char *)malloc(sizeof(char)*strlen($1.data.s));
			strcpy($$.name,$1.data.s);
			$$.data.v=&(table[FIND($1.data.s)].val);
			$$.type=4;
		}
      | STRING_LITERAL 
      | List 
      | number
      ;
slice_op :  /*  empty production */{$$.type=1;$$.data.i=1;}
        | ':' add_expr {if($1.type!=0){yyerror("type error");YYERROR;}else $$=$2;}
        ;
sub_expr:  /*  empty production */  {$$.type=-1;}
        | add_expr {if($1.type!=0) {yyerror("type error");YYERROR;}}
        ;        
atom_expr : atom 
        | atom_expr  '[' sub_expr  ':' sub_expr  slice_op ']'{
				if($1.type==5)
				{
					$$.type=5;
					$$.data.slice.l=$1.data.slice.l;
					$$.data.slice.end=$5.type==0?($1.data.slice.begin+$1.data.slice.step*$5.data.i):$1.data.slice.end;
					$$.data.slice.begin+=$1.data.slice.step*($3.type==0?$3.data.i:0);
					$$.data.slice.step=$1.data.slice.step*$6.data.i;
				} 
				else if($1.type==3)
				{
					$$.data.l=slice($1.data.l,$3.type==0?$3.data.i:0,$5.type==0?$5.data.i:$1.data.l.len,$6.data.i);
					$$.type=3;
				}
				else if($1.type==4)
				{
					if((*($1.data.v)).flag==3)
					{
						$$.data.slice.l=&((*($1.data.v)).DATA.l);
						$$.data.slice.end=$5.type==0?$5.data.i:((*($1.data.v)).DATA.l.len);
						$$.data.slice.begin=$3.type==0?$3.data.i:0;
						$$.data.slice.step=$6.data.i;
						$$.type=5;
					}	
					else {yyerror("type error");YYERROR;}
				}
				else {yyerror("type error");YYERROR;}
				}
        | atom_expr  '[' add_expr ']'{
				if($1.type==5){if($3.type==0){$3.data.i=$1.data.slice.begin+$1.data.slice.step*$3.data.i;$1.type=3;$1.data.l=*($1.data.slice.l);}else{yyerror("type error");YYERROR;}}
				else if($1.type==4) {$1=unpack(*($1.data.v));}
				if($3.type==0&&$1.type==3){if($3.data.i<$1.data.l.len){$$.type=4;$$.data.v=$1.data.l.val+$3.data.i;}else yyerror("index out of bound");}
				else{yyerror("type error");YYERROR;}
				}
        | atom_expr  '.' ID {$$=$1;$$.name=$3.data.s;}
        | atom_expr  '(' arglist opt_comma ')'{
			if(!strcmp($1.name,"len"))
			{
				int i=FIND($1.name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=$3.data.l.len;
				if(len>1)
				{
					yyerror("TypeError: len() takes exactly one argument");
					YYERROR;
				}
				int type=$3.data.l.val[0].flag;
				if(type==2)
				{
					$$.data.i=strlen($3.data.l.val[0].DATA.s);
				}
				else if(type==3)
				{
					$$.data.i=$3.data.l.val[0].DATA.l.len;
				}
				else{
					yyerror("TypeError: object has no len()");
					YYERROR;
				}
				$$.type=0;
			}
			else if(!strcmp($1.name,"range"))
			{	
				int i=FIND($1.name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=$3.data.l.len;
				for(i=0;i<len;i++)
				{
					if($3.data.l.val[i].flag==3)
					{
						yyerror("TypeError: range() integer end argument expected, got list.");
						YYERROR;
					}
				}
				
				if(len==1)
				{
					struct list l;
					l=newlist();
					for(int i=0;i<$3.data.l.val[0].DATA.i;i++)
					{
						VAL val;
						val.flag=0;
						val.DATA.i=i;
						append(l,val);
					}
				    	$$.data.l=l;
					$$.type=3;
				}
				else if(len==2)
				{
					struct list l;
					l=newlist();
					int start=$3.data.l.val[0].DATA.i;
					int end=$3.data.l.val[1].DATA.i;
					for(int i=start;i<end;i++)
					{
						VAL val;
						val.flag=0;
						val.DATA.i=i;
						append(l,val);
					}
					$$.data.l=l;
					$$.type=3;
				}
				else if(len==3)
				{
					struct list l;
					l=newlist();
					int start=$3.data.l.val[0].DATA.i;
					int end=$3.data.l.val[1].DATA.i;
					int step=$3.data.l.val[2].DATA.i;
					for(int i=start;i!=end;i+=step)
					{
						VAL val;
						val.flag=0;
						val.DATA.i=i;
						append(l,val);
					}
					$$.data.l=l;
					$$.type=3;
				}
				else
				{
					yyerror("TypeError: range expected at most 3 arguments");
					YYERROR;
				}

			}
			else if(!strcmp($1.name,"print"))
			{
				int i=FIND($1.name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=$3.data.l.len;
				for(int i=0;i<len;i++)
				{
					print($3.data.l.val[i]);
					cout<<" ";
				}
				yyerror("");
				YYERROR;
				
			}
			else if(!strcmp($1.name,"append"))
			{
				int i=FIND($1.name);
				int len=$3.data.l.len;
				if(len==1)
				{
					append((*($$.data.v)).DATA.l,$3.data.l.val[0]);
					$$.type=-1;
				}
				else
				{
					char *tmp=(char*)malloc(sizeof(char)*60);
					sprintf(tmp, "TypeError: append() takes exactly one argument (%d given)",len);
					$$.data.s=tmp;
					$$.type=2;
				}
			}
			else if(!strcmp($1.name,"list"))
			{
				int i=FIND($1.name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				int len=$3.data.l.len;
				if(len>1)
				{
					yyerror("TypeError: list() takes at most 1 argument");
					YYERROR;
				}
				int type=$3.data.l.val[0].flag;
				if(type==2)
				{
					struct list l;l=newlist();
					int str_len=strlen($3.data.l.val[0].DATA.s);
					for(int i=0;i<str_len;i++)
					{
						VAL val;val.flag=2;val.DATA.s=(char *)malloc(sizeof(char));
						*val.DATA.s=$3.data.l.val[0].DATA.s[i];
						append(l,val);
					}
					$$.type=3;
					$$.data.l=l;
				}
				else if(type==3)
				{
					$$.type=3;
					$$.data.l=$3.data.l.val[0].DATA.l;
				}
				else
				{
					yyerror("TypeError: object is not iterable");
					YYERROR;
				}
				
				
			}
		}
        | atom_expr  '('  ')'
		{
			if(!strcmp($1.name,"quit"))
			{
				int i=FIND($1.name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				exit(-1);
			}
			else if(!strcmp($1.name,"time"))
			{
				int i=FIND($1.name);
				if(table[i].Res==0)
				{
					yyerror("TypeError: object is not callable");
					YYERROR;
				}
				time_t t = time(NULL);
    				struct tm* stime=localtime(&t);
				char *tmp=(char*)malloc(sizeof(char)*32);
     				sprintf(tmp, "%04d-%02d-%02d %02d:%02d:%02d",1900+stime->tm_year,1+stime->tm_mon,
                		stime->tm_mday, stime->tm_hour,
                		stime->tm_min,stime->tm_sec);
				$$.data.s=tmp;
				$$.type=2;
			}
			else if(!strcmp($1.name,"list"))/*TODO:list.append(5)*/
			{
				struct list l;
				l=newlist();
				$$.data.l=l;
				$$.type=3;
			}
		}
        ;
arglist : add_expr {struct list l;l=newlist();append(l,pack($1));$$.type=3;$$.data.l=l;}
        | arglist ',' add_expr {append($1.data.l,pack($3));$$=$1;}
        ;  
List  : '[' ']'{$$.type=3;$$.data.l=newlist();}
      | '[' List_items opt_comma ']'{$$=$2;}
      ;
opt_comma : /*  empty production */
          | ','
          ;
List_items  
      : add_expr {struct list l;l=newlist();append(l,pack($1));$$.type=3;$$.data.l=l;}
      | List_items ',' add_expr {append($1.data.l,pack($3));$$=$1;}
      ;
add_expr : add_expr '+' mul_expr  {
	 			switch($1.type)
				{
				case 0:
					switch($3.type)
					{
						case 0: $$.type=0;$$.data.i=$1.data.i+$3.data.i;break;
						case 1: $$.type=1;$$.data.f=$1.data.i+$3.data.f;break;
						case 2: 
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 1:
					switch($3.type)
					{
						case 0: $$.type=1;$$.data.f=$1.data.f+$3.data.i;break;
						case 1: $$.type=1;$$.data.f=$1.data.f+$3.data.f;break;
						case 2:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 2:
					switch($3.type)
					{
					case 2:	{
						int sum_len = strlen($1.data.s)+strlen($3.data.s)+1;
						char *temp = (char *)malloc(sizeof(char)*sum_len);
						sprintf(temp,"%s%s",$1.data.s,$3.data.s);
						$$.type=2;
						$$.data.s=temp;  
						break;
					} 
					case 1:
					case 0:
					case 3: yyerror("type error");YYERROR; break;
					case 4:
					case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 3:
					switch($3.type)
					{
						case 0: 
						case 1:
						case 2: yyerror("type error");YYERROR; break;
						case 3: $$.type=3;$$.data.l=newlist();add($$.data.l,$1.data.l);add($$.data.l,$3.data.l);break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 4:
				case 5: yyerror("internal error");YYERROR;
				}
				}
	      |  add_expr '-' mul_expr {
	 			switch($1.type)
				{
				case 0:
					switch($3.type)
					{
						case 0: $$.type=0;$$.data.i=$1.data.i-$3.data.i;break;
						case 1: $$.type=1;$$.data.f=$1.data.i-$3.data.f;break;
						case 2: 
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 1:
					switch($3.type)
					{
						case 0: $$.type=1;$$.data.f=$1.data.f-$3.data.i;break;
						case 1: $$.type=1;$$.data.f=$1.data.f-$3.data.f;break;
						case 2:
						case 3: yyerror("type error"); YYERROR;break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 2:
					switch($3.type)
					{
						case 2: yyerror("TypeError: unsupported operand type(s) for -: 'str' and 'str'");YYERROR;  break; 
						case 1:
						case 0:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 3:
					switch($3.type)
					{
						case 0: 
						case 1:
						case 2: 
						case 3: yyerror("type error"); YYERROR;break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 4:
				case 5: yyerror("internal error");YYERROR;
				}
				}
	      |  mul_expr  
        ;
mul_expr : mul_expr '*' factor  {
	 			switch($1.type)
				{
				case 0:
					switch($3.type)
					{
						case 0: $$.type=0;$$.data.i=$1.data.i*$3.data.i;break;
						case 1: $$.type=1;$$.data.f=$1.data.i*$3.data.f;break;
						case 2:
							{
							int sum_len = strlen($3.data.s)*$1.data.i+1;
							char *temp = (char *)malloc(sizeof(char)*sum_len);
							strcpy(temp,$3.data.s);
							for(int i=0;i<$1.data.i-1;i++)
							{	
							sprintf(temp,"%s%s",temp,$3.data.s);
							}
							$$.type=2;
							$$.data.s=temp;  
							break;
							} 

						case 3: $$.type=3;$$.data.l=newlist();for(int i=0;i<$1.data.i;i++) add($$.data.l,$3.data.l); break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 1:
					switch($3.type)
					{
						case 0: $$.type=1;$$.data.f=$1.data.f*$3.data.i;break;
						case 1: $$.type=1;$$.data.f=$1.data.f*$3.data.f;break;
						case 2:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 2:
					switch($3.type)
					{
						case 0: 
							{
							int sum_len = strlen($1.data.s)*$3.data.i+1;
							char *temp = (char *)malloc(sizeof(char)*sum_len);
							strcpy(temp,$1.data.s);
							for(int i=0;i<$3.data.i-1;i++)
							{	
							sprintf(temp,"%s%s",temp,$1.data.s);
							}
							$$.type=2;
							$$.data.s=temp;  
							break;
							}
						case 1:
						case 2:
						case 3: yyerror("type error");YYERROR; break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 3:
					switch($3.type)
					{
						case 0: $$.type=3;$$.data.l=newlist();for(int i=0;i<$3.data.i;i++) add($$.data.l,$1.data.l); break;
						case 1:
						case 2:
						case 3: yyerror("type error"); YYERROR;break;
						case 4:
						case 5: yyerror("internal error");YYERROR;break;
					}
					break;
				case 4:
				case 5: yyerror("internal error");YYERROR;
				}
				} 
        |  mul_expr '/' factor  {
				if($1.type<2&&$3.type<2) {$$.type=1;$$.data.i=($1.type?$1.data.f:$1.data.i)/($3.type?$3.data.f:$3.data.i);}
				else {yyerror("type error");YYERROR;};
				}
        |  mul_expr '%' factor {if($1.type<2&&$3.type<2) /*{$$.type=1;$$.data.i=($1.type?$1.data.f:$1.data.i)%($3.type?$3.data.f:$3.data.i);}*/;/*TODO:change to py mod*/}
        |  factor 
        ;

%%

int main()
{	int i;
    int FuncNum=10;
	table=(TABLE*)malloc(INIT_TABLE_SIZE*sizeof(TABLE));
	for(i=0;i<FuncNum;i++)
	{
		table[i].Res=1;
		table[i].name=(char *)malloc(sizeof(char)*10);
	}
	strcpy(table[0].name,"len");
	strcpy(table[1].name,"time");
	strcpy(table[2].name,"list");
	strcpy(table[3].name,"print");
	strcpy(table[4].name,"range");
	strcpy(table[5].name,"quit");

	tablelen=10;
	return yyparse();
}

void yyerror(const char *s)
{
   cout << s << endl<<"miniPy> "; 
}

int yywrap()
{ return 1; }        		    

VAL pack(YYSTYPE val)
{
	VAL r;
	switch(val.type)
	{
	default:
		r.flag=val.type;
		r.DATA=*((union vald*)(&(val.data)));
		break;
	case 4:
		r=*(val.data.v);
		break;
	case 5:
		r.flag=3;
		r.DATA.l=slice(val.data.slice);
		break;
	}
	return r;
}

YYSTYPE unpack(VAL val)
{
	YYSTYPE r;
	r.type=val.flag;
	r.data=*((union yyd*)(&(val.DATA)));
	return r;
}
int FIND(char *s)
{
	int i =0;
	for(i=0;i<tablelen;i++) if(!strcmp(s,table[i].name))
	{
		free(s);
		return i;
	} 
	if(tablelen>=tablesize)
	{
		tablesize*=2;
		table=(TABLE*)realloc(table,tablesize);
	}
	table[tablelen].name=s;
	table[tablelen].val.flag=-1;
	tablelen++;
	return i;
}

void print(VAL val)
{
	int i;
	switch(val.flag)
	{
		case -1:
			cout<<"None";
			break;
		case 0:
			cout<<val.DATA.i;
			break;
		case 1:
			cout<<val.DATA.f;
			break;
		case 2:
			cout<<"'"<<val.DATA.s<<"'";
			break;
		case 3:
			for(auto& p : print_stack)
			{
				if(p==(unsigned long)val.DATA.l.val)
				{
					cout<<"[...]";
					return;
				}
			}
			print_stack.push_back((unsigned long)val.DATA.l.val);
			cout<<'[';
			if(val.DATA.l.len>0) print(val.DATA.l.val[0]);
			for(i=1;i<val.DATA.l.len;i++)
			{
				cout<<", ";
				print(val.DATA.l.val[i]);
			}
			cout<<']';
			print_stack.pop_back();
			break;
	}
}

inline void print(YYSTYPE val)
{
	print(pack(val));
}

struct list newlist()  //TODO:gc
{
	struct list l;
	l.len=0;
	l.size=INIT_LIST_SIZE;
	l.val=(VAL*)malloc(INIT_LIST_SIZE*sizeof(VAL));
	if(l.val==0) 
	{
		yyerror("malloc fail");
		//other operation
	}
	return l;
}

void exlist(struct list &l) //extend
{
	l.size*=2;
	l.val=(VAL*)realloc(l.val,l.size*sizeof(VAL));
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
	int i;
	VAL _val=l.val[index];
	for(i=index+1;i<l.len;i++) l.val[i-1]=l.val[i];
	l.len--;
	return _val;
}

struct list slice(struct list l,int begin,int end,int step)
{
	struct list _val;
	int i;
	_val=newlist();
	while(begin<0) begin+=l.len;
	while(end<0) begin+=l.len;
	for(i=begin;i<end;i+=step) append(_val,l.val[i]);
	return _val;
}

inline struct list slice(struct slice s)
{
	return slice(*(s.l),s.begin,s.end,s.step);
}

void setslice(struct list &l,int begin,int end,int step,struct list o)
{
	int i,j;
	if(begin<0||step<1||end>l.len) yyerror("index out of bound");
	if(step!=1)
	{
		if((int)ceil((double)(end-begin)/step)!=o.len) yyerror("incompatible length");
		for(i=begin,j=0;i<end;i+=step) l.val[i]=o.val[j++];
	}
	else//step=1
	{
		if(end-begin>o.len)
		{
			while(l.len+o.len-end+begin-1>=l.size) exlist(l);
			for(i=l.len+o.len-1-end+begin,j=l.len-1;j>=end;i--,j--) l.val[i]=l.val[j];
		}
		else if(end-begin<o.len)
		{
			for(i=begin+o.len,j=end;j<l.len;i++,j++) l.val[i]=l.val[j];

		}
		for(i=begin,j=0;j<o.len;i++,j++) l.val[i]=o.val[j]; 
		l.len=l.len+o.len-end+begin;
	}
	return;
}

inline void setslice(struct slice s,struct list o)
{
	setslice(*(s.l),s.begin,s.end,s.step,o);
	return;
}
