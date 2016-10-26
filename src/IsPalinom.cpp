#include "IsPalindrom.h"
#include <cstdlib>
#include <iostream>

bool IsPalindrom(CNode* list)
{
		CNode* tmp = list;
		int count = 0;
		int* a = NULL;
		int f = 1;
		while (tmp != 0)
		{
			a = (int*)realloc(a, (count+1)*sizeof(int));
			//if (a != NULL)
			//{
				a[count] = tmp->data;
				count++;
				tmp = tmp->next;
		/*	}
			else
			{
				f = 0;
				std::cout << "Error";
			}*/
		}
		
		for (int i = 0; i < count; ++i)
			if (a[i] != a[count - i - 1])
			{
				f = 0;
				break;
			}
		free(a);
		return (f == 1);
}