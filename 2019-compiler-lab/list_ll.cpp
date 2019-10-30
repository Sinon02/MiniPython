struct list{
	struct data *d;
	struct list *next;
};

struct symbol{
	char name[20];
	struct data *d;
};

struct data{
	int flag;
	union d{
		int i;//flag=0
		float f;//flag=1
		string s;//flag=2
		struct list *l;//flag=3
	};
};

struct list_slice{
	struct list **ph;
	int len;
	int step;
};

void print(struct data d)
{
	struct data *p;
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
			p=d.d.l;
			if(p!=0)
			{
				print(p->d);
				for(p=p->next;p!=0;p=p->next)
				{
					cout<<',';
					print(p->d);
				}
			}
			cout<<']';
	}
}

struct list_slice slice(
