#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Celil �eref *1210505053*
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
        // Liste bo� ise, yeni d���m� ba�a yerle�tiriyoruz
        head = temp;
        head->next = NULL;
    } else {
        // Liste dolu ise, yeni d���m� ba�a ekleyip ba�lant�lar� g�ncelliyoruz
        temp->next = head;
        head = temp;
    }
}

// Eleman silme fonksiyonu
void delete() {
    struct node* temp;
    if (head == NULL) {
        printf("\nListe Bos\n");  // Liste bo� ise mesaj veriyoruz
        return;
    } else {
        temp = head;
        head = head->next;
        free(temp);  // �lk d���m� silip belle�i serbest b�rak�yoruz
    }
}

// Liste elemanlar�n� g�r�nt�leme fonksiyonu
void display() {
    struct node* temp;
    if (head == NULL) {
        printf("\nListe Bos\n");  // Liste bo� ise mesaj veriyoruz
        return;
    }
    temp = head;
    printf("\nListe Elemanlar�: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);  // D���mlerin verilerini yazd�r�yoruz
        temp = temp->next;
    }
}

int main() {
	setlocale(LC_ALL, "Turkish");
    int choice, num;

    while (1) {
        printf("\nL�tfen Se�iminizi Girin:\n");
        printf("1. Ekle\n2. Sil\n3. G�r�nt�le\n4. ��k��\n");
        printf("Se�iminiz: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEklemek �sted�inizi Liste Eleman�: ");
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
                printf("\nGe�ersiz Se�im!\n");  // Ge�ersiz bir se�enek girildi�inde mesaj veriyoruz
                break;
        }
    }
}

