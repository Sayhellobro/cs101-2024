#include <stdio.h>

typedef struct Books{
    int id;
    int price;
    char title[100];
}book_t;

void total_price(book_t books[6]){
    int total=0;
    for(int i=0;i<6;i++){
        total+=books[i].price;
    }
    printf("%d", total);
}

void list_books(book_t books){
    printf("%d %s\n", books.price, books.title);
}

int main(){
    int n;
    book_t Book[6];
    
    Book[0].id=1;
    Book[0].price=1000;
    strcpy(Book[0].title, "All the Light We Cannot See");
    
    Book[1].id=2;
    Book[1].price=300;
    strcpy(Book[1].title, "The 38 Letters from J.D. Rockefeller to his son");
   
    Book[2].id=3;
    Book[2].price=1000;
    strcpy(Book[2].title, "The Ballad of Songbirds and Snakes");
    
    Book[3].id=4;
    Book[3].price=550;
    strcpy(Book[3].title, "Killers of the Flower Moon");
    
    Book[4].id=5;
    Book[4].price=870;
    strcpy(Book[4].title, "Elon Musk");
    
    Book[5].id=6;
    Book[5].price=1344;
    strcpy(Book[5].title, "Milk and Honey 12-Month 2024");
    
    scanf("%d", &n);

    if(n==0){
        total_price(Book);
    }
    else{
        list_books(Book[n-1]);
    }

    return 0;
}
