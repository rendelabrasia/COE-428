#define HASH_TABLE_SIZE 1057
typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];

void add(char * tag, int var) 
{
  int charSum = 0, 
  int x;
  int y;
	
  for(x=0 ; x< var; x++)
	{
	
     charSum = charSum + tag[i];
	
    }

	y= charSum%HASH_TABLE_SIZE; //This represents the division method.

}

