#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Celil Þeref *1210505053*
struct node {
    int data;
    struct node *next;
}*head;

// Eleman ekleme fonksiyonu
void insert(int num) {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = num;
    if (head == NULL) {
        // Liste boþ ise, yeni düðümü baþa yerleþtiriyoruz
        head = temp;
        head->next = NULL;
    } else {
        // Liste dolu ise, yeni düðümü baþa ekleyip baðlantýlarý güncelliyoruz
        temp->next = head;
        head = temp;
    }
}

// Eleman silme fonksiyonu
void delete() {
    struct node* temp;
    if (head == NULL) {
        printf("\nListe Bos\n");  // Liste boþ ise mesaj veriyoruz
        return;
    } else {
        temp = head;
        head = head->next;
        free(temp);  // Ýlk düðümü silip belleði serbest býrakýyoruz
    }
}

// Liste elemanlarýný görüntüleme fonksiyonu
void display() {
    struct node* temp;
    if (head == NULL) {
        printf("\nListe Bos\n");  // Liste boþ ise mesaj veriyoruz
        return;
    }
    temp = head;
    printf("\nListe Elemanlarý: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);  // Düðümlerin verilerini yazdýrýyoruz
        temp = temp->next;
    }
}

int main() {
	setlocale(LC_ALL, "Turkish");
    int choice, num;

    while (1) {
        printf("\nLütfen Seçiminizi Girin:\n");
        printf("1. Ekle\n2. Sil\n3. Görüntüle\n4. Çýkýþ\n");
        printf("Seçiminiz: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEklemek Ýstedðinizi Liste Elemaný: ");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nGeçersiz Seçim!\n");  // Geçersiz bir seçenek girildiðinde mesaj veriyoruz
                break;
        }
    }
}

