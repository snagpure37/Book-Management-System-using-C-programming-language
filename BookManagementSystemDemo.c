/*
														'Book Management System'
							Allows user to add, display, remove, update book details in the array(database)
Display functionality allows user to display all books, display top 3 books by rating and price, display available books to issue all the books from database
						Allows user to issue the book among available book and shows the warning when wrong menu entered
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Structures
typedef struct Date
{
	int mm;
	int dd;
	int yy;
}Date;

typedef struct Book{
	int bookId;
	char bookName[40];
	char authorName[30];
	char category[20];
	Date issueDate;
	double price;
	float rating;
}Book;

//Function Decalaration
void hardCodeValue();

//crud functions
void addBook(Book*);
void addNewBook(Book*);
void displayAll(Book*);
void display(Book*);
void updateBook(Book*);
void removeBook(Book*);

void displayOneBook(Book*);
void updateBookName(Book*);
void updateAuthorName(Book*);
void updateCategory(Book*);
void updatePrice(Book*);
void updateRating(Book*);

//issue Book Functions
void displayAvailableBooks(Book*);
void issueBook(Book*);

//search functions
void searchBook(Book*);
void searchById(Book*);
void searchByBookName(Book*);
void searchByCategory(Book*);
void searchByAuthorName(Book*);
void top3BookByPrice(Book*);
void top3BookByRating(Book*);

//sort functions
void sort(Book*);
void sortBookByPrice(Book*);
void sortBookByRating(Book*);

//Global variables
int bookCount = 0;
int size;


//Main Function
void main(){
	printf("\n**_Welcome to the Book Managemnet System_**\n");

	int maxSize = 5;
	size = size + maxSize;
	Book* bookDb;
	bookDb = (Book*)malloc(sizeof(Book)*size);

	hardCodeValue(bookDb);		//function call

//can comment later
	if(bookCount == 0)
	{
		printf("\n**Warning : No Book Found...\n");
	}
	
	int choice;
	
	do
	{
		printf("\n\t1.Add");
		printf("\n\t2.Display ");
		printf("\n\t3.Search Book");
		printf("\n\t4.Update Book");
		printf("\n\t5.Remove book by Id");
		printf("\n\t6.Sort");
		printf("\n\t7.Issue Book");
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			{
				addBook(bookDb);		//function call
				break;
			}
			case 2:
			{
				display(bookDb);		//function call
				break;
			}
			case 3:
			{
				searchBook(bookDb);		//function call
				break;
			}
			case 4:
			{
				updateBook(bookDb);		//function call
				break;
			}
			case 5:
			{
				removeBook(bookDb);		//function call
				break;
			}
			case 6:
			{
				sort(bookDb);		//function call
				break;
			}
			case 7:
			{
				issueBook(bookDb);		//function call
				break;
			}
			default :
			{
				printf("\n**Warning : Invalid choice...\n");
				break;
			}
		}
		printf("\n--- continue in Main Menu ? ---");
		printf("\n\tYes? Enter any non zero number ");
		printf("\n\tNo.Exit Application? Enter zero(0)\n");
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		
	}while(choice!=0);
	
	printf("\n**Success : You Exit Application Successfully...\n");
	
	free(bookDb);		//freeing the memory block alloted in the heap
}

void addBook(Book* bookDb)		//function definition
{
	int ch;
	int tempSize;
	if(bookCount >= size)
	{
		printf("\n**Warning : Memory Full...\n\n");
		do
		{
			printf("----Do you want to increase size?----");
			printf("\n\t1.Yes");
			printf("\n\t2.No?");
			printf("\nEnter your choice : ");
			scanf("%d",&ch);
			
			switch(ch)
			{
				case 1:
				{
					printf("\nHow many books you want to store ? ");
					scanf("%d",&tempSize);
					size = size + tempSize;
					bookDb = (Book*)realloc(bookDb,sizeof(Book)*size);	//reallocating the size to the array in heap
					printf("\n-----Do you want to add book now?-----");
					printf("\n\tYes? Enter any non zero value");
					printf("\n\tNo? Enter zero");
					printf("\nEnter your choice : ");
					scanf("%d",&ch);
					if(ch!=0)
						addNewBook(bookDb);			//function call
					break;
				}
				case 2:
				{
					printf("\n**Warning : Did not increased size\n");
					break;
				}
				default:
				{
					printf("\n**Warning : Invalid choice...\n");
					break;
				}
			}
			ch=0;
		}while(ch != 0);
	}
	else
	{
		addNewBook(bookDb);			//function call
	}
}

void addNewBook(Book* bookDb)		//function definition
{
	printf("\nEnter Id : ");
	scanf("%d",&bookDb[bookCount].bookId);
	
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(bookDb[bookCount].bookId == bookDb[i].bookId)
		{
			printf("\n**Warning : Book by id %d already exist...\n");
			return;
		}
	}
	
	printf("Enter Book Name : ");
	fflush(stdin);
	gets(bookDb[bookCount].bookName);
	
	printf("Enter Author Name : ");
	fflush(stdin);
	gets(bookDb[bookCount].authorName);
	
	printf("Enter a category : ");
	fflush(stdin);
	gets(bookDb[bookCount].category);
	
	printf("Enter a date in dd/mm/yyyy format : ");
	scanf("%d%d%d",&bookDb[bookCount].issueDate.dd,&bookDb[bookCount].issueDate.mm,&bookDb[bookCount].issueDate.yy);
	
	printf("Enter Price :");
	scanf("%lf",&bookDb[bookCount].price);
	
	printf("Enter Rating : ");
	scanf("%f",&bookDb[bookCount].rating);
	
	printf("\n**Success : Book %d Added...\n",bookCount+1);
	bookCount++;
}

void display(Book* bookDb)			//function definition
{	
	if(bookCount == 0)
	{
		printf("\n**Warning : No Book Found...\n");
		return;
	}
	
	int ch;
	do
	{
		printf("\n\t1.Display all Books");
		printf("\n\t2.Display top 3 books by price");
		printf("\n\t3.Display top 3 books by rating");
		printf("\n\t4.Display Available Books");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				displayAll(bookDb);		//function call
				break;
			}
			case 2:
			{
				top3BookByPrice(bookDb);		//function call
				break;
			}
			case 3:
			{
				top3BookByRating(bookDb);		//function call
				break;
			}
			case 4:
			{
				displayAvailableBooks(bookDb);		//function call
				break;
			}
			default :
			{
				printf("\n**Warning : Invalid choice...\n");
				break;
			}
		}
		printf("\n--- continue in Display Menu ? ---");
		printf("\n\tYes? Enter any non zero number ");
		printf("\n\tNo? Enter zero(0)\n");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		
	}while(ch!=0);
	
	printf("\n**Success : You Exit Display Successfully...\n");
	
}

void displayAll(Book* bookDb)		//function definition
{
	int i;
	for(i=0;i<bookCount;i++){
		printf("\n---- Book %d Info ----",i+1);
		displayOneBook(&bookDb[i]);		//function call
	}
}

void searchBook(Book* bookDb)		//function definition
{
	if(bookCount == 0)
	{
		printf("\n**Warning : No Book Found...\n");
		return;
	}
	int ch;
	do
	{
		printf("\n\t1.Search by Id");
		printf("\n\t2.Search by Title");
		printf("\n\t3.Search by Author Name");
		printf("\n\t4.Search by Category");
		printf("\n\nEnter the choice to search : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				searchById(bookDb);		//function call
				break;
			}
			case 2:
			{
				searchByBookName(bookDb);		//function call
				break;
			}
			case 3:
			{
				searchByAuthorName(bookDb);		//function call
				break;
			}
			case 4:
			{
				searchByCategory(bookDb);		//function call
				break;
			}
			default:
			{
				printf("\n**Warning : Invalid choice for search...\n");
				break;
			}
		}
		printf("\n--- Continue Searching ? ---");
		printf("\n\tYes? Enter any non zero number ");
		printf("\n\tNo? Enter zero(0)\n");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		
	}while(ch !=0);
	
	printf("\n**Success : You are done Searching\n");
	return;
}

void searchById(Book* bookDb)		//function definition
{
	int id;
	printf("\nEnter an Id you want to search : ");
	scanf("%d",&id);
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(bookDb[i].bookId == id)
		{
			printf("\n**Success : Searched book Info...\n");
			displayOneBook(&bookDb[i]);		//function call
			return;
		}
	}
	printf("\n**Warning : Book by Id of %d does not exist...\n",id);
}

void searchByBookName(Book* bookDb)		//function definition
{
	char bName[30];
	printf("\nEnter Book Name you want to search : ");
	fflush(stdin);
	gets(bName);
	
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(strcasecmp(bName,bookDb[i].bookName) == 0)
		{
			printf("\n**Success : Searched book Info...\n");
			displayOneBook(&bookDb[i]);		//function call
			return;			
		}
	}
	printf("\n**Warning : Book by name '%s' does not exist...\n",bName);
}

void searchByCategory(Book* bookDb)		//function definition
{
	char bCategory[20];
	printf("\nEnter the Book category you want to search : ");
	fflush(stdin);
	gets(bCategory);
	
	int flag = 0;
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(strcasecmp(bCategory,bookDb[i].category) == 0)
		{
			flag = 1;
			printf("\n**Success : Searched book Info...\n");
			displayOneBook(&bookDb[i]);		//function call
		}
	}
	if(flag == 0)
	{
		printf("\n**Warning : Book by category '%s' does not exist...\n",bCategory);
		return;
	}
}

void searchByAuthorName(Book* bookDb)		//function definition
{
	char aName[30];
	printf("\nEnter the author name you want to search : ");
	fflush(stdin);
	gets(aName);
	
	int flag = 0;
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(strcasecmp(aName,bookDb[i].authorName) == 0)
		{
			flag = 1;
			printf("\n**Success : Searched book Info...\n");
			displayOneBook(&bookDb[i]);		//function call
		}
	}
	
	if(flag == 0)
	{
		printf("\n**Warning : Book by author '%s' does not exist...\n",aName);
	}
}

void updateBook(Book* bookDb)		//function definition
{
	if(bookCount == 0)
	{
		printf("\n**Warning : No Book Found...\n");
		return;
	}
	int id;
	printf("\nEnter the book Id that you want to update : ");
	scanf("%d",&id);
	
	int flag = 0;
	double p;
	float r;
	
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(id == bookDb[i].bookId)
		{
			printf("\n**Success : Book Found...");
			displayOneBook(&bookDb[i]);
			flag = 1;
			
			int ch;
			
			do
			{
				printf("\nWhat do you want to update : ");
				printf("\n\t1.Book Name");
				printf("\n\t2.Author Name");
				printf("\n\t3.Category");
				printf("\n\t4.Price");
				printf("\n\t5.Rating");
				printf("\nEnter your choice : ");
				scanf("%d",&ch);
				
				switch(ch)
				{
					case 1:
					{
						updateBookName(&bookDb[i]);		//function call
						break;
					}
					case 2:
					{
						updateAuthorName(&bookDb[i]);		//function call
						break;
					}
					case 3:
					{
						updateCategory(&bookDb[i]);		//function call
						break;
					}
					case 4:
					{
						updatePrice(&bookDb[i]);			//function call
						break;
					}
					case 5:
					{
						updateRating(&bookDb[i]);			//function call
						break;
					}
				}
				printf("\nDo you want to continue updating : ");
				printf("\n\tYes? Enter non zero value");
				printf("\n\tNo? Enter zero(0)");
				printf("\nEnter your choice : ");
				scanf("%d",&ch);
			}while(ch!=0);
			printf("\n**Success : You are done Updating\n");

		}
	}
	if(flag ==0)
		printf("\n**Warning : Book by Id %d does not exist...\n",id);
}

void updateBookName(Book* bookDb)		//function definition
{
	char bName[30];
	printf("\nEnter new name for Book : ");
	fflush(stdin);
	gets(bName);
	
	if(strcasecmp(bookDb->bookName,bName) == 0)
	{
		printf("\n**Warning : Book Name can not be same as old book Name...\n");
		return;
	}
	
	strcpy(bookDb->bookName,bName);
	printf("\n**Success : Book name updated successfully...\n");
	
}

void updateAuthorName(Book* bookDb)		//function definition
{
	char author[30];
	printf("\nEnter new author name for Book : ");
	fflush(stdin);
	gets(author);
	
	if(strcasecmp(bookDb->authorName,author) == 0)
	{
		printf("\n**Warning : Author Name can not be same as old Author Name...\n");
		return;
	}
	
	strcpy(bookDb->authorName,author);
	printf("\n**Success : Author name updated successfully...\n");
}

void updateCategory(Book* bookDb)		//function definition
{
	char bCat[20];
	printf("\nEnter category for Book : ");
	fflush(stdin);
	gets(bCat);
	
	if(strcasecmp(bookDb->category,bCat) == 0)
	{
		printf("\n**Warning : Book Category can not be same as old Category...\n");
		return;
	}
	
	strcpy(bookDb->category,bCat);
	printf("\n**Success : Book Category Updated successfully...\n");
}

void updatePrice(Book* bookDb)		//function definition
{
	double bPrice;
	printf("\nEnter price for Book : ");
	scanf("%lf",&bPrice);
	
	if(bookDb->price == bPrice)
	{
		printf("\n**Warning : Price cannot be same as old price...\n");
		return;
	}
	
	bookDb->price = bPrice;
	printf("\n**Success : Price updated successfully...\n");	
}

void updateRating(Book* bookDb)		//function definition
{
	float bRate;
	printf("\nEnter the rating of Book : ");
	scanf("%f",&bRate);
	
	if(bookDb->rating == bRate)
	{
		printf("\n**Warning : Rating cannot be same as old rating...\n");
		return;
	}
	
	bookDb->rating = bRate;
	printf("\n**Success : Rating updated successfully...\n");
}

void removeBook(Book* bookDb)		//function definition
{
	if(bookCount == 0)
	{
		printf("\n**Warning : No Book Present in Array...\n");
		return;
	}
	
	int id;
	printf("\nEnter the id of book you want to delete : ");
	scanf("%d",&id);
	
	int flag = 0;
	int index;
	
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(bookDb[i].bookId == id)
		{
			flag = 1;
			index = i;
			break;
		}
	}
	if(flag == 0)
	{
		printf("\n**Warning : Book does not exist...\n\n");
		return;
	}

	for(i=index; i<bookCount && flag == 1; i++)
	{
		bookDb[i] = bookDb[i+1];
	}
	bookCount--;
	printf("\n**Success : Book Removed Successfully...\n");
}

void top3BookByPrice(Book* bookDb)		//function definition
{
	Book tempDb[bookCount];
	int i,j;
	for(i=0; i<bookCount; i++)
	{
		tempDb[i] = bookDb[i];		//copies data
	}
	
	for(i=0; i<bookCount-1; i++)
	{
		for(j=0; j<bookCount-1-i; j++)
		{
			if(tempDb[j].price < tempDb[j+1].price)		//sorting in tempDb
			{
				Book temp = tempDb[j];
				tempDb[j] = tempDb[j+1];
				tempDb[j+1] = temp;
			}
		}
	}
	
	printf("\n**Success : Top 3 Books based on Price...\n");
	for(i=0; i<bookCount && i<3; i++)
	{
		displayOneBook(&bookDb[i]);		//function call
	}
}

void top3BookByRating(Book* bookDb)		//function definition
{
	Book tempDb[bookCount];
	int i,j;
	for(i=0; i<bookCount; i++)
	{
		tempDb[i] = bookDb[i];
	}
	for(i=0; i<bookCount-1; i++)
	{
		for(j=0; j<bookCount-1-i; j++)
		{
			if(tempDb[j].rating < tempDb[j+1].rating)
			{
				Book temp = tempDb[j];
				tempDb[j] = tempDb[j+1];
				tempDb[j+1] = temp;
			}
		}
	}
	
	printf("\n**Success : Top 3 Books based on Rating...\n");
	for(i=0; i<bookCount && i<3; i++)
	{
		displayOneBook(&bookDb[i]);		//function call
	}
}

void sort(Book* bookDb)		//function definition
{
	if(bookCount == 0)
	{
		printf("\n**Warning : No Book Found...\n");
		return;
	}
	int ch;
	do
	{
		printf("\n\t1.Sort by Price");
		printf("\n\t2.Sort by Rating");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				sortBookByPrice(bookDb);		//function call
				break;
			}
			case 2:
			{
				sortBookByRating(bookDb);		//function call
				break;
			}
			default : 
			{
				printf("\n**Warning : Invalid choice for sorting\n");
				break;
			}
		}
		printf("\n--- Continue Sorting ? ---");
		printf("\n\tYes? Enter any non zero number ");
		printf("\n\tNo? Enter zero(0)\n");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
	}while(ch!=0);
	
	printf("\n**Success : You are done Sorting\n");
	return;
}

void sortBookByPrice(Book* bookDb)		//function definition
{
	Book tempDb[bookCount];
	int i,j;
	for(i=0; i<bookCount; i++)
	{
		tempDb[i] = bookDb[i];
	}
	
	for(i=0; i<bookCount-1; i++)
	{
		for(j=0; j<bookCount-1-i; j++)
		{
			if(tempDb[j].price > tempDb[j+1].price)
			{
				Book temp = tempDb[j];
				tempDb[j] = tempDb[j+1];
				tempDb[j+1] = temp;
			}
		}
	}
	printf("\n**Success : Sorted book by Price (low to high) Info...\n");
	for(i=0; i<bookCount; i++)
	{
		displayOneBook(&bookDb[i]);		//function call
	}
}

void sortBookByRating(Book* bookDb)		//function definition
{
	Book tempDb[bookCount];
	int i,j;
	for(i=0; i<bookCount; i++)
	{
		tempDb[i] = bookDb[i];
	}
	for(i=0; i<bookCount-1; i++)
	{
		for(j=0; j<bookCount-1-i; j++)
		{
			if(tempDb[j].rating < tempDb[j+1].rating)
			{
				Book temp = tempDb[j];
				tempDb[j] = tempDb[j+1];
				tempDb[j+1] = temp;
			}
		}
	}
	printf("\n**Success : Sorted book by Rating Info...\n");
	for(i=0; i<bookCount; i++)
	{
		displayOneBook(&bookDb[i]);		//function call
	}
	
}

void displayAvailableBooks(Book* bookDb)		//function definition
{
	printf("\n**Success : Available books...\n");
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(bookDb[i].issueDate.dd == 0 && bookDb[i].issueDate.mm == 0 && bookDb[i].issueDate.yy == 0)
		{
			displayOneBook(&bookDb[i]);	//function call
		}
	}
}

void issueBook(Book* bookDb)		//function definition
{
	if(bookCount == 0)
	{
		printf("\n**Warning : No Book Found...\n");
		return;
	}
	char bName[40];
	printf("\nEnter the book name you want to issue : ");
	fflush(stdin);
	gets(bName);
	
	int i;
	for(i=0; i<bookCount; i++)
	{
		if(strcasecmp(bookDb[i].bookName,bName)==0)
		{
			if(bookDb[i].issueDate.dd == 0 && bookDb[i].issueDate.mm == 0 && bookDb[i].issueDate.yy == 0)
			{
				printf("\nBook is available\n");
				printf("Enter date of issue : ");
				scanf("%d%d%d",&bookDb[i].issueDate.dd,&bookDb[i].issueDate.mm,&bookDb[i].issueDate.yy);
				printf("\n**Success : Book Issued Successfully...\n");
			}
			else
			{
				printf("\nBook is unavailable\n");
			}
			return;
		}
	}
	printf("\n**Warning : Book does not exist...\n");
}

void displayOneBook(Book* bookDb)		//function definition
{
	printf("\nBook Id. = %d",bookDb->bookId);
	printf("\nBook Name = %s",bookDb->bookName);
	printf("\nAuthor Name = %s",bookDb->authorName);
	printf("\nCategory = %s",bookDb->category);
	printf("\nDate of Issue = %d/%d/%d",bookDb->issueDate.dd, bookDb->issueDate.mm, bookDb->issueDate.yy);
	printf("\nPrice = %.2lf",bookDb->price);
	printf("\nRating = %.2f\n",bookDb->rating);
}

void hardCodeValue(Book* bookDb)		//function definition
{
	bookDb[bookCount].bookId = 101;
	strcpy(bookDb[bookCount].bookName,"How to Win Friends and Influence People");
	strcpy(bookDb[bookCount].authorName,"Dale Carnegie");
	strcpy(bookDb[bookCount].category,"self-help");
	bookDb[bookCount].issueDate.dd = 0;
	bookDb[bookCount].issueDate.mm = 0;
	bookDb[bookCount].issueDate.yy = 0;	bookDb[bookCount].price = 90;
	bookDb[bookCount].rating = 4.7;
//	printf("**Success : Book %d Added...\n",++bookCount);
	bookCount++;
	
	bookDb[bookCount].bookId = 102;
	strcpy(bookDb[bookCount].bookName,"Life's Amazing Secret");
	strcpy(bookDb[bookCount].authorName,"Gaur Gopal das");
	strcpy(bookDb[bookCount].category,"self-help");
	bookDb[bookCount].issueDate.dd = 9;
	bookDb[bookCount].issueDate.mm = 12;
	bookDb[bookCount].issueDate.yy = 2020;
	bookDb[bookCount].price = 169;
	bookDb[bookCount].rating = 4.7;
//	printf("\n**Success : Book %d Added...\n",++bookCount);
	bookCount++;
	
	bookDb[bookCount].bookId = 103;
	strcpy(bookDb[bookCount].bookName,"Think Like a Monk");
	strcpy(bookDb[bookCount].authorName,"Jay Shetty");
	strcpy(bookDb[bookCount].category,"spirituality");
	bookDb[bookCount].issueDate.dd = 0;
	bookDb[bookCount].issueDate.mm = 0;
	bookDb[bookCount].issueDate.yy = 0;
	bookDb[bookCount].price = 299;
	bookDb[bookCount].rating = 4.8;
//	printf("\n**Success : Book %d Added...\n",++bookCount);
	bookCount++;
	
	bookDb[bookCount].bookId = 104;
	strcpy(bookDb[bookCount].bookName,"God of Small Things");
	strcpy(bookDb[bookCount].authorName,"Arundhati Roy");
	strcpy(bookDb[bookCount].category,"historical-fiction");
	bookDb[bookCount].issueDate.dd = 7;
	bookDb[bookCount].issueDate.mm = 7;
	bookDb[bookCount].issueDate.yy = 2010;
	bookDb[bookCount].price = 199;
	bookDb[bookCount].rating = 4.0;
//	printf("\n**Success : Book %d Added...\n",++bookCount);
	bookCount++;
	
	bookDb[bookCount].bookId = 105;
	strcpy(bookDb[bookCount].bookName,"Ram - Scion of Ikshvaku");
	strcpy(bookDb[bookCount].authorName,"Amish");
	strcpy(bookDb[bookCount].category,"mythological-fiction");
	bookDb[bookCount].issueDate.dd = 0;
	bookDb[bookCount].issueDate.mm = 0;
	bookDb[bookCount].issueDate.yy = 0;
	bookDb[bookCount].price = 219;
	bookDb[bookCount].rating = 4.1;
//	printf("\n**Success : Book %d Added...\n",++bookCount);
	bookCount++;
	
	printf("\n**Info : Number of books present in array = %d...\n",bookCount);
}


