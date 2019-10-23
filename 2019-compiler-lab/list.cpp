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
		int i;
		float f;
		string s;
		struct list *l;
	};
};

