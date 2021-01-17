ElemSN * CreateLink(int a[])
{
	ElemSN * h, *t;
	h = t = (ElemSN *)malloc(sizeof(ElemSN));
	h->next = NULL;
	for (int i = 0; i<N; ++i){
		t = t->next = (ElemSN *)malloc(sizeof(ElemSN));
		t->data = a[i];
		t->next = NULL;
	}
	return h;
}

void PrintLink(ElemSN * h)
{
	for (ElemSN * p = h; p->next; p = p->next){
		printf("%5d", p->next->data);
	}
	printf("\n");
}