#define	 INIT_LIST_SIZE 10
struct data{
	int flag;
	union{
		int i;//flag=0
		float f;//flag=1
		string s;//flag=2
		struct list{
			int len;
			int size;
			struct data *d;
		} l;//flag=3
	}d;
};

struct symbol{
	char name[20];
	struct data *d;
};

void print(struct data d)
{
	int i;
	switch(d.flag)
	{
		case 0:
			cout<<d.d.i;
			break;
		case 1:
			cout<<d.d.f;
			break;
		case 2:
			cout<<d.d.s;
			break;
		case 3:
			cout<<'[';
			if(d.d.l.len>0)print(d.d.l.d[0]);
			for(i=1;i<d.d.l.len;i++)
			{
				cout<<',';
				print(d.d.l.d[i]);
			}
			cout<<']';
			break;
	}
}

data* newlist()
{
	data *l;
	l=(data*)malloc(sizeof(data));
	l.flag=3;
	l.d.l.len=0;
	l.d.l.size=INIT_LIST_SIZE;
	l.d.l.d=(data*)malloc(INIT_LIST_SIZE*sizeof(data));
	if(l.d.l.d==0) 
	{
		yyerror("malloc fail");
		//other operation
	}
	return l;
}

void exlist(struct list &l)
{
	l.size*=2;
	l.d=realloc(l.d,l.size);
	if(l==0) 
	{
		yyerror("malloc fail");
		//other operation
	}
	return;
}

void append(struct list &l,data d)
{
	if(l.len>=l.size) exlist(l);
	l.d[l.len++]=d;
}

void add(struct list &l,struct list o)
{
	int i;
	while(l.len+o.len-1>=l.size) exlist(l);
	for(i=0;i<o.len;i++)l.d[l.len++]=o.d[i];
}

void insert(struct list &l,int index,data d)
{
	int i;
	if(index>l.len) yyerror("index out of bound");
	if(l.len>=l.size) exlist(l);
	for(i=l.len;i>index;i--) l.d[i]=l.d[i-1];
	l.len++;
	l.d[index]=d;
}

data pop(struct list &l,int index)
{
	data d=l.d[index];
	for(i=index+1;i<l.len;i++) l.d[i-1]=l.d[i];
	l.len--;
	return d;
}

data* slice(struct list l,int begin,int end,int step)
{
	data* d;
	int i;
	d=newlist();
	for(i=begin;i<end;i+=step) append(d->d.l,l.d[i]);
	return d;
}

void setslice(struct list &l,int begin,int end,int step,struct list o)
{
	int i,j;
	if(begin<0||step<1||end>l.len) yyerror("index out of bound");
	if(step!=1)
	{
		if((end-op)/step!=o.len) yyerror("incompatible length");
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
}
