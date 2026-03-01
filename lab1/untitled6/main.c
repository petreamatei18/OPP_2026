#include <stdio.h>

int main() {
    char propozitie[200];
    char cuvinte[20][50];
    int nr = 0;
    printf("Scrie propozitia: ");
    scanf("%[^\n]s", propozitie);
    int i = 0, k = 0;
    while (propozitie[i]!= '\0') {
        if (propozitie[i]!= ' ') {
            cuvinte[nr][k++]=propozitie[i];
        } else if (k > 0) {
            cuvinte[nr][k]='\0';
            nr++;
            k=0;
        }
        i++;
    }
    if (k>0) {
        cuvinte[nr][k]='\0';
        nr++;
    }

    for (i =0;i<nr-1;i++) {
        for (int j=0;j <nr-i-1;j++) {
            int len1=0;
            while (cuvinte[j][len1]) len1++;
            int len2 = 0;
            while (cuvinte[j+1][len2]) len2++;
            int schimba=0;
            if (len1<len2) {
                schimba=1;
            } else if (len1 == len2) {
                int p=0;
                while (cuvinte[j][p] && cuvinte[j][p] == cuvinte[j+1][p]) p++;
                if (cuvinte[j][p] >cuvinte[j+1][p]) schimba=1;
            }

            if (schimba) {
                char aux[50];
                for (int p=0; p<50;p++)
                    aux[p]=cuvinte[j][p];
                for (int p=0;p<50;p++)
                    cuvinte[j][p]=cuvinte[j+1][p];
                for (int p=0;p<50;p++)
                    cuvinte[j+1][p]=aux[p];
            }
        }
    }

    for (i =0;i<nr;i++) {
        printf("%s\n", cuvinte[i]);
    }

    return 0;
}