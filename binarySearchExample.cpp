//Azra �yk� Ulukan 22120205059

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int binarySearch(FILE *file, const char *key){
	
	// Kelimeleri saklayacak bir dizi
    char line[500][100]; // Dosyadaki okunacak max sat�r s�tun say�s�

    int lineNumber = 0; //Dosyadaki kelime say�s�
		
    // Dosyadan s�rayla kelimeleri oku ve diziye kaydet
    while (fscanf(file, "%s", line[lineNumber]) != EOF) {
        lineNumber++;
    }
    
    // Dosyay� kapat
    fclose(file);
    
    long left=0, right=lineNumber-1, mid;
    
    while(left<=right){
    	mid= (left+right)/2;
    	int cmp= strcmp(key, line[mid]);
    	if (cmp == 0) //Ayn�ysa 0 d�ner, ilki b�y�kse + , k���kse -
    	{
    	printf("%d. Satirda ", mid+1);
    	return 1;
		}
    
    	else if(cmp>0)
    		left=mid+1;
    		
    	else
    		right=mid-1;
	} 
	return -1;
    
}

int main(){
	char fileName[100];
	char key[100]; //Aranan kelime

    printf("Dosya adini girin (orn: 'dosyaAdi.txt'): ");
    scanf("%s", fileName);

    printf("Aranacak ismi girin: ");
    scanf("%s", key);

    clock_t start_time, end_time;
    double totalTime;

    start_time = clock(); // Ba�lang�� zaman�
    
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Dosya acma hatasi");
        return 1;
    }
    
    int result = binarySearch(file, key);

    end_time = clock(); // Biti� zaman�
    totalTime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // �al��ma s�resi
    
     
	if (result == 1) {
        printf("%s dosya icinde bulundu.\n", key);
    } else {
        printf("%s dosya icinde bulunamadi.\n", key);
    }

    printf("Calisma suresi: %f\n", totalTime);

    fclose(file);

	    return 0;
}

