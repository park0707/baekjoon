
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct trinode
{
	bool isend;
	struct trinode* child[62];

}trinode;
trinode* newtri()
{
	trinode* new = (trinode*)malloc(sizeof(trinode));
	if (new)
	{
		new->isend = false;
		for (int i = 0; i < 62; i++)
		{
			new->child[i] = NULL;
		}
	}
	return new;
}
void insert(trinode* root, char* key)
{
	trinode* now = root;
	while (*key)
	{
		int index;
		if (isdigit(*key))
			index = *key - '0';
		else if (isupper(*key) != 0)
		{
			index = *key - 'A' + 10;
		}
		else
			index = *key - 'a'+36;
		if (now->child[index] == NULL)
			now->child[index] = newtri();
		now = now->child[index];
		key++;
	}
	now->isend = true;
}
bool search(trinode* root, char* key)
{
	trinode* now = root;
	while (*key)
	{
		int index;
		if (isdigit(*key))
			index = *key - '0';
		else if (isupper(*key) != 0)
		{
			index = *key - 'A' + 10;
		}
		else
			index = *key - 'a' + 36;
		if (now->child[index] == NULL)
			return false;
		now = now->child[index];
		key++;
	}
	return now->isend;
}
void freetri(trinode* root)
{
	if (root == NULL)
		return;
	for (int i = 0; i < 62; i++)
	{
		freetri(root->child[i]);
	}
	free(root);
}
int main(void)
{
	int how, n = 1, r = 0;;
	trinode* tri = newtri();
	char s1[21],s2[21];
	scanf("%d", &how);
	insert(tri, "ChongChong");
	for (int i = 0; i < how; i++)
	{
		scanf("%s %s", s1, s2);
		if (search(tri, s1))
		{
			if(!search(tri,s2))
			{
				insert(tri, s2);
				n++;
			}
			
		}
		else if (search(tri, s2))
		{
			if (!search(tri, s1))
			{
				insert(tri, s1);
				n++;
			}
		}
	}
	printf("%d", n);
	
	freetri(tri);
	return 0;
}