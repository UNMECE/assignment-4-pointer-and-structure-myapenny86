#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char*name, int index)
{
	item_list[index].price = price;
	item_list[index].sku = (char *)malloc(strlen(sku) + 1);
	strcpy(item_list[index].sku, sku);

	item_list[index].category = (char *)malloc(strlen(category) + 1);
	strcpy(item_list[index].category, category);

	item_list[index].name = (char *)malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size)
{
	for(int i = 0; i < size; i++)
	{
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);
}

double average_price(Item *item_list, int size)
{
	double total = 0.0;
	for (int i = 0; i < size; i++)
	{
		total += item_list[i].price;
	}
	return total/size;
}

void print_items(Item *item_list, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("###############\n");
		printf("Item name = %s\n", item_list[i].name);
		printf("Item sku = %s\n", item_list[i].sku);
		printf("Item category = %s\n", item_list[i].category);
		printf("Item price = %lf\n", item_list[i].price);
		printf("###############\n");
	}
}

int main(int argc, char *argv[])
{
	int num_items = 5;
	Item *item_list = (Item *)malloc(num_items * sizeof(Item));

	add_item(item_list, 5.00, "19282", "breakfast", "reeses cereal", 0);
	add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
	add_item(item_list, 7.50, "12345", "beverage", "orange juice", 2);
	add_item(item_list, 12.99, "54321", "snacks", "chips", 3);
	add_item(item_list, 2.75, "67890", "vegetables", "carrot", 4);

	print_items(item_list, num_items);
	
	double avg_price = average_price(item_list, num_items);
	printf("################\n");
	printf("Average price of items = %lf\n", avg_price);
	printf("################\n");

	if(argc == 2)
	{
		char *search_sku = argv[1];
		int found = 0;
		for(int i = 0; i < num_items; i++)
		{
			if(strcmp(item_list[i].sku, search_sku) == 0)
			{
				printf("Item found!\n");
				printf("Item name = %s\n", item_list[i].name);
				printf("Item sku = %s\n", item_list[i].sku);
				printf("Item category = %s\n", item_list[i].category);
				printf("Item price = %lf\n", item_list[i].price);
				found = 1;
				break;
			}
		}
		if(!found)
		{
			printf("Item not found.\n");
		}
	}

	free_items(item_list, num_items);
	
	return 0;
}






































