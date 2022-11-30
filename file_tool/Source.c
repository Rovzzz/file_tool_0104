#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main() {
    setlocale(LC_CTYPE, "Russian_Russia.1251");
    int a, b, c;
    double x1, x2;
    FILE *data;
    FILE *otvet;
    data = fopen("data.txt", "rt");
    fscanf(data, "%d%d%d", &a,&b,&c);
    printf("a = %d\nb = %d\nc = %d\n", a, b, c);
    fclose(data);

    double D = b * b - 4.0f * a * c;
    printf("������������ = %f\n",D);


    if (D > 0.0f)
    {
        otvet = fopen("otvet.txt", "wt");
        printf("��� �����:\n");
        char sd[] = "������������ = ";
        char s0[] = "��� �����:\n";
        fputs(sd, otvet);
        fprintf(otvet, "%f\n", D);
        fputs(s0, otvet);

        x1 = (sqrt(D) - b) / (2.0f * a);
        printf("x1 = %f\n", x1);
        fprintf(otvet, "%f\n", x1);

        x2 = (-sqrt(D) - b) / (2.0f * a);
        printf("x2 = %f\n", x2);
        fprintf(otvet, "%f\n\n", x2);
        fclose(otvet);
        return 1;                           // ��� �����
    }
    else if (D == 0.0f)
    {
        otvet = fopen("otvet.txt", "wt");
        char sd[] = "������������ = ";
        fputs(sd, otvet);
        printf("���� ������:\n");
        char s0[] = "���� ������:\n";
        fputs(s0, otvet);

        x1 = x2 = -b / (2.0f * a);
        printf("x1=x2 = %f", x1);
        fprintf(otvet, "%f\n", x1);
        fclose(otvet);
        return 0;                           // ���� ������
    }
    else if (D < 0.0f) {
        otvet = fopen("otvet.txt", "wt");
        printf("�� ����� ������");
        char s0[] = "�� ����� ������\n";
        fclose(otvet);
        return -1;                         // �� ����� ������
    }

}
