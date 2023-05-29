#include <stdio.h>
#include <stdlib.h>


/*

AUTHOR : CEM YILMAZ | VERSE YAZILIM



*/




// FONKSIYON TANIMLAMALARI
void print_money(float);
void print_duration(int);
void print_entry(float, float, int);
void print_full_report(float, float, int, int, int);

int main()
{
    void print_money(float money)
    {
        printf("%.1f $", money);
    }

    void print_duration(int month)
    {
        int monthh = month % 12; 
        int year = month / 12;
        printf("-> year : %d, month : %d", year, monthh);
    }

    void print_entry(float kredi_tutari, float rate, int ay)
    {
        float toplamFaiz = (kredi_tutari / 100) * (rate / (float)12) * ay; // doğru sonuç vermesi için floata cast ettim 

        print_duration(ay);
        printf("\nTotal payment : ");
        print_money(toplamFaiz + kredi_tutari); // BURADA İÇERİDE TOPLAMA NEDENMİZ TOTAL PARAYI GÖRMEK İÇİN
        printf("\nMonthly payment : ");
        print_money((toplamFaiz + kredi_tutari) / (float)ay); // doğru sonuç vermesi için floata cast ettim 
        printf("\n");
    }

    void print_full_report(float kredi_tutari, float int_rate, int maks_yil, int maks_ay, int yineleme)
    {

        int ayYineleme = 0;
        for (int i = 0; i < (maks_yil * 12 + maks_ay) / yineleme; i++)
        {
            ayYineleme += yineleme;      // burada yeni bir değişken tanımlama sebebim yineleme ile yapınca yineleme sürekli arttığı için kod doğru çalışmıyordu

            printf("----------------------\n");
            print_entry(kredi_tutari, int_rate, ayYineleme);

            printf("----------------------\n");
        }
    }

    printf("......................................................\n\n");
    printf(".*.*.*.*.*Welcome to the Interest Calculator*.*.*.*.*.\n\n");
    printf("......................................................\n\n");
    char name[20] = "";
    float annual_interest_rate = 0.0;
    float loan_amount = 0.0;
    int max_year, max_month, iteration_interval = 0;

    printf("Please enter your name : ");
    scanf("%s", name);
    printf("\nLoan amount : ");
    scanf("%f", &loan_amount);
    printf("\nInterest rate (per year) : ");
    scanf("%f", &annual_interest_rate);
    printf("\n-> TIME LENGTH\n");
    printf(" Loan term in years : ");
    scanf("%d", &max_year);
    printf("\n Loan term in months : ");
    scanf("%d", &max_month);
    printf("\n Iteration in months : ");
    scanf("%d", &iteration_interval);
    printf("\n......................................................\n\n");

    print_full_report(loan_amount, annual_interest_rate, max_year, max_month, iteration_interval);
}
