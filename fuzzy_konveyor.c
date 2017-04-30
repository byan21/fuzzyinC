#include <stdio.h>


// Inisialisasi atau identifikasi sub program yang dipakai
void fuzzifikasi();
unsigned char fuzzifikasi_beban_ringan();
unsigned char fuzzifikasi_beban_sedang();
unsigned char fuzzifikasi_beban_berat();
unsigned char fuzzifikasi_ketinggian_rendah();
unsigned char fuzzifikasi_ketinggian_sedang();
unsigned char fuzzifikasi_ketinggian_tinggi();
void rule_pertama();
void rule_kedua();
void defuzzifikasi();

float berat,ketinggian; // data masukan berat dan tinggi
float beban_ringan,beban_sedang,beban_berat; // derajat keanggotaan berat
float ketinggian_rendah,ketinggian_sedang,ketinggian_tinggi; // derajat keanggotaan tinggi

float tinggi_array[3];
float berat_array[3];
float temp_berat1,temp_berat2;
float temp_tinggi1,temp_tinggi2;
float temp,rule1,rule2,defuz,hasil_rule_1,hasil_rule_2;
int tinggi_index_1, tinggi_index_2, berat_index_1, berat_index_2;

unsigned char fuzzifikasi_beban_ringan()
{
 beban_ringan=0;
 if (berat<=5 && berat>0)
  { beban_ringan=1; }
 else if (berat>5&& berat<10)
  { beban_ringan=(10-berat)/5; }
 else if (berat>=10)
  { beban_ringan=0; };
 return beban_ringan;
};

unsigned char fuzzifikasi_beban_sedang()
{
 beban_sedang=0;
 if (berat<=5 || berat>=15)
  { beban_sedang=0; }
 else if (berat>5 && berat<10)
  { beban_sedang=(berat-5)/5; }
 else if (berat>10 && berat<15)
  { beban_sedang=(15-berat)/5; }
 else if (berat==10)
  { beban_sedang=1; };
 return beban_sedang;
};

unsigned char fuzzifikasi_beban_berat()
{
 beban_berat=0;
 if (berat>10 && berat<15)
  { beban_berat=(berat-10)/5; }
 else if (berat>=15)
  { beban_berat=1; }
 else if (berat<=10)
  { beban_berat=0; };
 return beban_berat;
};

unsigned char fuzzifikasi_ketinggian_rendah()
{
 ketinggian_rendah=0;
 if (ketinggian<=2 && ketinggian>0)
  { ketinggian_rendah=1; }
 else if (ketinggian>2)
  { ketinggian_rendah=(6-ketinggian)/(4); }
 else if (ketinggian>=6)
  { ketinggian_rendah=0; };
 return ketinggian_rendah;
};

unsigned char fuzzifikasi_ketinggian_sedang()
{
 ketinggian_sedang=0;
 if (ketinggian<=2 || ketinggian>=10)
  { ketinggian_sedang=0; }
 else if (ketinggian>2 && ketinggian<6)
  { ketinggian_sedang=(ketinggian-2)/4; }
 else if (ketinggian>6 && ketinggian<10)
  { ketinggian_sedang=(10-ketinggian)/4; }
 else if (ketinggian==6)
  { ketinggian_sedang=1; };
 return ketinggian_sedang;
};

unsigned char fuzzifikasi_ketinggian_tinggi()
{
 ketinggian_tinggi=0;
 if (ketinggian>6 && ketinggian<10)
  { ketinggian_tinggi=(ketinggian-6)/4; }
 else if (ketinggian>=10)
  { ketinggian_tinggi=1; }
 else if (ketinggian<=6)
  { ketinggian_tinggi=0; };
 return ketinggian_tinggi;
};

// Kumpulkan semua sub program fuzzifikasi menjadi satu buah sub program
void fuzzifikasi()
{
 fuzzifikasi_beban_ringan();
 fuzzifikasi_beban_sedang();
 fuzzifikasi_beban_berat();

 fuzzifikasi_ketinggian_rendah();
 fuzzifikasi_ketinggian_sedang();
 fuzzifikasi_ketinggian_tinggi();
};

void rule_pertama(/* arguments */) {
  if (tinggi_array[tinggi_index_1]>berat_array[berat_index_1]) {
    rule1=berat_array[berat_index_1];
  }else{
    rule1=tinggi_array[tinggi_index_1];
  }
    if ((tinggi_index_1==0&&berat_index_1==0)||(tinggi_index_1==0&&berat_index_1==1)||(tinggi_index_1==1&&berat_index_1==0)) {
      if (rule1==0) {
        hasil_rule_1=8;
        printf("Lambat1 %0.2f \n",hasil_rule_1);
      }else if (rule1==1) {
        hasil_rule_1=4;
        printf("Lambat1 %0.2f \n",hasil_rule_1);
      }else{
        hasil_rule_1=8-(4*rule1);
        printf("Lambat1 %0.2f \n",hasil_rule_1);
      }
    }else if ((tinggi_index_1==0&&berat_index_1==2)||(tinggi_index_1==1&&berat_index_1==1)||(tinggi_index_1==2&&berat_index_1==0)) {
      if (rule1==0) {
        hasil_rule_1=4;
        printf("Sedang1 %0.2f \n",hasil_rule_1);
      } else if (rule1==1) {
        hasil_rule_1=8;
        printf("Sedang1 %0.2f \n",hasil_rule_1);
      }else{
        hasil_rule_1=4+(4*rule1);
        printf("Sedang1 %0.2f \n",hasil_rule_1);
      }
    }else if ((tinggi_index_1==1&&berat_index_1==2)||(tinggi_index_1==2&&berat_index_1==1)||(tinggi_index_1==2&&berat_index_1==2)) {
      if (rule1==0) {
        hasil_rule_1=8;
        printf("Cepat1 %0.2f \n",hasil_rule_1);
      }else if (rule1==1) {
        hasil_rule_1=12;
        printf("Cepat1 %0.2f \n",hasil_rule_1);
      }else{
        hasil_rule_1=8+(4*rule1);
        printf("Cepat1 %0.2f \n",hasil_rule_1);
      }
    }
}


void rule_kedua(/* arguments */) {
  if (tinggi_array[tinggi_index_2]>berat_array[berat_index_2]) {
    rule2=berat_array[berat_index_2];
    //printf("rule 2 %0.2f\n",rule2 );
  }else{
    rule2=tinggi_array[tinggi_index_2];
    //printf("rule 2 %0.2f\n",rule2 );
  }
  //printf("Tinggi index 2 %d Berat index 2 %d \n",tinggi_index_2,berat_index_2 );
    if ((tinggi_index_2==0&&berat_index_2==0)||(tinggi_index_2==0&&berat_index_2==1)||(tinggi_index_2==1&&berat_index_2==0)) {
      if (rule2==0) {
        hasil_rule_2=8;
        printf("Lambat2 %0.2f \n",hasil_rule_2);
      }else if (rule2==1) {
        hasil_rule_2=4;
        printf("Lambat2 %0.2f \n",hasil_rule_2);
      }else{
        hasil_rule_2=8-(4*rule2);
        printf("Lambat2 %0.2f \n",hasil_rule_2);
      }
    }else if ((tinggi_index_2==0&&berat_index_2==2)||(tinggi_index_2==1&&berat_index_2==1)||(tinggi_index_2==2&&berat_index_2==0)) {
      if (rule2==0) {
        hasil_rule_2=4;
        printf("Sedang2 %0.2f \n",hasil_rule_2);
      } else if (rule2==1) {
        hasil_rule_2=8;
        printf("Sedang2 %0.2f \n",hasil_rule_2);
      }else{
        hasil_rule_2=4+(4*rule2);
        printf("Sedang2 %0.2f \n",hasil_rule_2);
      }
    }else if ((tinggi_index_2==1&&berat_index_2==2)||(tinggi_index_2==2&&berat_index_2==1)||(tinggi_index_2==2&&berat_index_2==2)) {
      if (rule2==0) {
        hasil_rule_2=8;
        printf("Cepat2 %0.2f \n",hasil_rule_2);
      }else if (rule2==1) {
        hasil_rule_2=12;
        printf("Cepat2 %0.2f \n",hasil_rule_2);
      }else{
        hasil_rule_2=8+(4*rule2);
        printf("Cepat2 %0.2f \n",hasil_rule_2);
      }
    }
}

void defuzzifikasi(/* arguments */) {
  defuz=(((rule1*hasil_rule_1)+(rule2*hasil_rule_2))/(rule1+rule2));
  printf("\n");
  printf("Hasil akhir %0.2f \n",defuz);
}

void main(void)
{
      int i;

       // masukkan input berat dan tinggi benda
       berat=13.2;
       ketinggian=5.8;

       fuzzifikasi(); // memanggil fungsi fuzzifikasi

       //menyusun karakter ke dalam satu baris dengan menggunakan fungsi sprintf
       printf("%0.2f %0.2f %0.2f",ketinggian_rendah,ketinggian_sedang,ketinggian_tinggi);
       tinggi_array[0]=ketinggian_rendah; //1
       tinggi_array[1]=ketinggian_sedang; //2
       tinggi_array[2]=ketinggian_tinggi; //3
       printf("\n");
       /*  assume first element of array is the first larges t*/
       temp_tinggi1 = tinggi_array[0];
       /*  assume first element of array is the second largest */
       temp_tinggi2 = tinggi_array[1];
       if (temp_tinggi1 < temp_tinggi2)
       {
           temp = temp_tinggi1;
           temp_tinggi1 = temp_tinggi2;
           temp_tinggi2 = temp;
       }
       for (i = 2; i < 3;	i++)
       {
           if (tinggi_array[i] >= temp_tinggi1)
           {
               temp_tinggi2 = temp_tinggi1;
               temp_tinggi1 = tinggi_array[i];
           }
           else if (tinggi_array[i] > temp_tinggi2)
           {
               temp_tinggi2 = tinggi_array[i];
           }
       }
       for (i = 0; i < 3; i++) {
         if (temp_tinggi1==tinggi_array[i]) {
           tinggi_index_1=i;
         }else if (temp_tinggi2==tinggi_array[i]) {
           tinggi_index_2=i;
           //printf(" tinggi_index_2 %d\n",tinggi_index_2 );
         }
       }

/* ---------------------------------------------------------------------------------*/
       //printf("%0.2f " " %0.2f",temp_tinggi1, temp_tinggi2 );

       printf("%0.2f %0.2f %0.2f",beban_ringan,beban_sedang,beban_berat);
       berat_array[0]=beban_ringan; //1
       berat_array[1]=beban_sedang; //2
       berat_array[2]=beban_berat; //3

       printf("\n");
       /*  assume first element of array is the first larges t*/
       temp_berat1 = berat_array[0];
       /*  assume first element of array is the second largest */
       temp_berat2 = berat_array[1];
       if (temp_berat1 < temp_berat2)
       {
           temp = temp_berat1;
           temp_berat1 = temp_berat2;
           temp_berat2 = temp;
       }
       for (i = 2; i < 3;	i++)
       {
           if (berat_array[i] >= temp_berat1)
           {
               temp_berat2 = temp_berat1;
               temp_berat1 = berat_array[i];
           }
           else if (berat_array[i] > temp_berat2)
           {
               temp_berat2 = berat_array[i];
           }
       }
       for (i = 0; i < 3; i++) {
         if (temp_berat1==berat_array[i]) {
           berat_index_1=i;
         }else if (temp_berat2==berat_array[i]) {
           berat_index_2=i;
           //printf(" berat_index_2 %d\n",berat_index_2 );
         }
       }
       //printf("urut tinggi %0.2f " " %0.2f",temp_tinggi1, temp_tinggi2 );
       //printf("urut berat %0.2f " " %0.2f",temp_berat1, temp_berat2 );
       rule_pertama();
       rule_kedua();
       defuzzifikasi();
}
