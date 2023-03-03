#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#define  len sizeof(phone)

typedef struct PHONE {
    char name[10];
    char home[5];
    char phone1[20];
    char phone2[20];
    char email[20];
    int sign;
    //  int classify;
    struct PHONE *next;
}phone;
phone *head;






void mainmenuface() {

    char menu[] = {
        "��ӭ�������ǵ�ͨѶ¼ϵͳ������\n"
    };

    int i;
    for(i = 0; menu[i] != '\0'; i++) {
        Sleep(30);
        printf("%c", menu[i]);
    }
    printf("�������������������������������������\n");
    printf("��********************************************************************��\n");
    printf("��                          ͨѶ¼����ϵͳ                            ��\n");
    printf("��                                                                    ��\n");
    printf("��          1.�½���ϵ����Ϣ               5.������ϵ����Ϣ           ��\n");
    printf("��                                                                    ��\n");
    printf("��          2.���������ϵ��               6.�����ϵ����Ϣ           ��\n");
    printf("��                                                                    ��\n");
    printf("��          3.�޸���ϵ����Ϣ               7.ɾ����ϵ����Ϣ           ��\n");
    printf("��                                                                    ��\n");
    printf("��          4.������ϵ����Ϣ               8.�������˵�               ��\n");
    printf("��********************************************************************��\n");
    printf("��                          ����9�˳�ϵͳ                             ��\n");
    printf("��          -------------------------------------------               ��\n");
}
void show_one(phone *p) {
    printf("����:%s\t\t", p->name);
    printf("���:%d\n", p->sign);
    printf("����:%s\t", p->home);
    printf("�绰����1:%s\t", p->phone1);
    printf("�绰����2:%s\t", p->phone2);
    printf("��������:%s\n", p->email);
}

phone * Lookdata(phone *p1) {
    phone *p2;
    p2 = head;
    printf("\n\t\t\t������ʾ���ݡ���\n");
    printf("----------------------------------------------------------------------\n");
    while(p2 != NULL) {
        printf("����:%s\t\t", p2->name);
        printf("���:%d\n", p2->sign);
        printf("����:%s\t", p2->home);
        printf("�绰����1:%s\t", p2->phone1);
        printf("�绰����2:%s\t", p2->phone2);
        printf("��������:%s\t", p2->email);
        printf("\n\n");
        printf("----------------------------------------------------------------------\n");
        p2 = p2->next;
    }
    return p2;
}

phone * Inputdata() {
    phone*p1, *p2, *p3;
    int flag = 1;
    int k = 1, i = 1, max;

    p1 = p2 = (phone*)malloc(len);
    head = NULL;

    printf("\n\t\t\t�����½���ϵ����Ϣ����\n");
    if(p1 != NULL) {
        head = p1;
        while(flag) {
            printf("----------------------------------------------------------------------\n");
            printf("������Ҫ¼����ϵ�˵�����������һ��������over������\n");
            p3 = head;
            scanf("%s", p1->name);
            if(strcmp(p1->name, "over") != 0) {



                p3 = head;
                while(i < k) {
                    i++;
                    if(strcmp(p1->name, p3->name) == 0) {
                        if(p3->sign > max)max = p3->sign;
                    }
                    p3 = p3->next;
                }
                p1->sign=++max;
                max = 0;

                p1->sign = 1;

                printf("������Ҫ¼����ϵ�˵ļ���\n");
                scanf("%s", p1->home);
                printf("������Ҫ¼����ϵ�˵ĵ绰1\n");
                scanf("%s", p1->phone1);
                printf("������Ҫ¼����ϵ�˵ĵ绰2\n");
                scanf("%s", p1->phone2);
                printf("������Ҫ¼����ϵ�˵ĵ�������\n");
                scanf("%s", p1->email);
                p2->next = p1;
                p2 = p1;
                p1 = (phone*)malloc(len);
                p1->next = NULL;
                k++;
                printf("----------------------------------------------------------------------\n");


            }

            else {
                flag = 0;
                p1->next = NULL;
                free(p1);
                printf("-----------------����ɹ����˳�ʱ��������5������Ϣ��------------------\n");
                printf("----------------------------------------------------------------------\n");
            }
        }
    }
    return (head);
}

void readfile() {
    FILE *fp;
    phone *p1, *p2, *p4, *p5;
    p1 = p2 = (phone *)malloc(len);
    int flag = 1;
    head = NULL;
    if((fp = fopen("ͨѶ¼", "r")) == NULL) {
        printf("δ����ͨѶ¼��������1�½���ϵ�ˣ�\n");
    }
    else {
        if(p1 != NULL)head = p1;
        while(1) {
            if(!feof(fp)) {
                fscanf(fp, "%s%d%s%s%s%s", p1->name, &p1->sign, p1->home, p1->phone1, p1->phone2, p1->email);
                p2->next = p1;
                p5 = p2;
                p2 = p1;
                p1 = (phone *)malloc(len);
            }
            else {
                p5->next = NULL;

                break;
            }

        }

    }
    fclose(fp);
}

Seek(phone *p2) {
    char name[20];
    char ch1[5], ch2[5];
    memset(ch1, '\0', sizeof(ch1));
    memset(ch2, '\0', sizeof(ch2));
    int b;
    int n;
    printf("\n\t\t\t����������ݡ���\n");
    printf("----------------------------------------------------------------------\n");
    printf("---------------------------������������1:-----------------------------\n");
    printf("---------------------------������������2:-----------------------------\n");
    printf("����������ѡ��"); scanf("%d", &n);
    getchar();
    printf("��������Ҫ���ҵ�������");
    switch(n) {
        case 1:
        b = 0;
        scanf("%s", name);
        while(p2 != NULL) {
            if(strcmp(name, p2->name) == 0) {
                printf("��Ҫ�ҵ�������\n");
                printf("����:%s\t\t", p2->name);
                printf("���:%d\n", p2->sign);
                printf("����:%s\t", p2->home);
                printf("�绰����1:%s\t", p2->phone1);
                printf("�绰����2:%s\t", p2->phone2);
                printf("��������:%s\n", p2->email);
                printf("----------------------------------------------------------------------\n");
                b = 1;
            }
            p2 = p2->next;
        }
        if(b == 0) {
            printf("\n--------------------��Ҫ���ҵ��˲�����!--------------------------------\n");
        }
        break;
        case 2:
        b = 0;
        printf("�������գ�");
        scanf("%s", ch1);
        while(p2 != NULL) {
            strncpy(ch2, p2->name, 2);
            if(strcmp(ch1, ch2) == 0) {
                printf("��Ҫ�ҵ�������\n");
                printf("����:%s\t\t", p2->name);
                printf("���:%d\n", p2->sign);
                printf("����:%s\t", p2->home);
                printf("�绰����1:%s\t", p2->phone1);
                printf("�绰����2:%s\t", p2->phone2);
                printf("��������:%s\n", p2->email);
                printf("----------------------------------------------------------------------\n");
                b = 1;
            }
            p2 = p2->next;
        }
        if(b == 0) {
            printf("\n--------------------��Ҫ���ҵ��ղ�����!--------------------------------\n");
        }

    }

}
Keepdata(phone *p2) {
    FILE *fp;

    printf("\n\t\t\t��������ݡ���\n");
    printf("----------------------------------------------------------------------\n");
    if((fp = fopen("ͨѶ¼", "w")) == NULL) {
        printf("cannot open this file\n");
        exit(0);
    }
    while(p2 != NULL) {
        fprintf(fp, "%s\t", p2->name);
        fprintf(fp, "%d\t", p2->sign);
        fprintf(fp, "%s\t", p2->home);
        fprintf(fp, "%s\t", p2->phone1);
        fprintf(fp, "%s\t", p2->phone2);
        fprintf(fp, "%s\t", p2->email);
        p2 = p2->next;
        fputc('\n', fp);
    }
    printf("\n------------------------------����ɹ�!-----------------------------\n");
    printf("---------------------------------------------------------------------\n");
    fclose(fp);
}

Changedata(phone *p) {
    char name[20];
    int k, flag = 1;
    printf("\n\t\t\t�����޸����ݡ���\n");
    printf("----------------------------------------------------------------------\n");
    printf("---------------------��������Ҫ�޸ĵ���ϵ��������---------------------\n");
    scanf("%s", name);
    while(p != NULL) {
        if(strcmp(p->name, name) == 0) {
            show_one(p);
            flag = 0;
            printf("\n------------------��ѡ��Ҫ�޸ĵ���Ϣ:---------------------------\n");
            printf("+------------------------------------------------+\n");
            printf("|                                                |\n");
            printf("|          1.����              4.�ֻ�2           |\n");
            printf("|                                                |\n");
            printf("|          2.����              5.��������        |\n");
            printf("|                                                |\n");
            printf("|          3.�ֻ�1                               |\n");
            printf("|                                                |\n");
            printf("+------------------------------------------------+\n");
            scanf("%d", &k);
            switch(k) {
                case 1: printf("-------------------�����޸ĺ��������------------------\n");
                scanf("%s", p->name);
                break;

                case 2: printf("-------------------�����޸ĺ�Ļ�����------------------\n");
                scanf("%s", p->home);
                break;

                case 3: printf("-------------------�����޸ĺ���ֻ�1��-----------------\n");
                scanf("%s", p->phone1);
                break;

                case 4: printf("-------------------�����޸ĺ���ֻ�2��-----------------\n");
                scanf("%s", p->phone2);
                break;

                case 5: printf("--------------------�����޸ĺ�����䣺------------------\n");
                scanf("%s", p->email);
                break;

            }
            printf("-----------------------�޸ĳɹ���-------------------------------------\n");
            printf("----------------------------------------------------------------------\n");
            break;
        }
        else p = p->next;

    }
    if(flag)printf("------------------------���޴��ˣ�------------------------------------\n");
    printf("----------------------------------------------------------------------\n");

}

void deletedata() {
    phone *p1, *p2;
    phone *p3;
    char name[20];
    int n, k = 1;
    printf("\n\t\t\t����ɾ�����ݡ���\n");
    printf("----------------------------------------------------------------------\n");
    printf("��������ɾ������ϵ��������\n");
    scanf("%s", name);
    p1 = head;
    if(head == NULL) {
        printf("δ������ϵ����Ϣ��ͨѶ¼Ϊ��\n");
        return;
    }
    /*if(strcmp(p1->name,name)==0 ){
    head=p1->next ;
        printf("------------------------------ɾ���ɹ���------------------------------\n");
}
   else{ */
    printf("��ѡ����Ҫɾ�����ˣ�\n");
    printf("----------------------------------------------------------------------\n");
    p3 = head;
    while(p3 != NULL) {
        if(strcmp(name, p3->name) == 0) {

            printf("����:%s\t\t", p3->name);
            printf("���:%d\n", p3->sign);
            printf("����:%s\t", p3->home);
            printf("�绰����1:%s\t", p3->phone1);
            printf("�绰����2:%s\t", p3->phone2);
            printf("��������:%s\n", p3->email);
            printf("\n\n");
            k = 0;
            printf("----------------------------------------------------------------------\n");
        }
        p3 = p3->next;
    }
    if(k) {
        printf("���޴��ˣ�\n");
        return;
    }
    printf("��������Ҫɾ��������ţ�\n");
    scanf("%d", &n);
    while(p1 != NULL && (p1->sign != n || strcmp(p1->name, name) != 0)) {
        p2 = p1;
        p1 = p1->next;
    }
    if(p1 == NULL) {
        printf("���޴��ˣ�\n");
        return;
    }

    if(p1 != NULL) {
        p1 = p1->next;
        p2->next = p1;
        printf("------------------------------ɾ���ɹ���------------------------------\n");
        return;
    }


    printf("----------------------------------------------------------------------\n");
}
void input(phone *p1) {
    printf("����:");
    scanf("%s", &p1->name);
    printf("����:");
    scanf("%s", &p1->home);
    printf("�ֻ���1:");
    scanf("%s", &p1->phone1);
    printf("�ֻ���2:");
    scanf("%s", &p1->phone2);
    printf("����:");
    scanf("%s", &p1->email);
    p1->sign = 1;
}

void Insertdata() {
    char name2[20];
    int flag, max;
    phone *p1, *p2, *p3;
    phone *p4;
    p1 = head;
    p3 = (phone *)malloc(len);
    printf("\n\t\t\t���������ϵ�ˡ���\n");
    printf("----------------------------------------------------------------------\n");
    printf("-------------------------��������ص����ݣ�---------------------------\n");
    input(p3);
    p4 = head;


    max = 0;
    while(p4 != NULL) {
        if(strcmp(p3->name, p4->name) == 0) {
            if(p4->sign > max)max = p4->sign;
        }
        p4 = p4->next;
    }
    p3->sign=++max;


    printf("-------------------------����������λ�ã�---------------------------\n");
    printf("+---------------------------------------------------------+\n");
    printf("|                                                         |\n");
    printf("|                    1.��λ�ò���                         |\n");
    printf("|                                                         |\n");
    printf("|                    2.βλ�ò���                         |\n");
    printf("|                                                         |\n");
    printf("|                    3.ָ������ǰ����                     |\n");
    printf("+---------------------------------------------------------+\n");

    scanf("%d", &flag);
    switch(flag) {
        loop: case 1:
        p3->next = p1;
        head = p3;
        break;
        case 2:
        p2 = head;
        while(p2->next != NULL) {
            p2 = p2->next;
        }
        p2->next = p3;
        p3->next = NULL;
        break;
        case 3:
        printf("������������������ǰ�棺\n");
        scanf("%s", name2);
        while(p1->next != NULL && strcmp(p1->name, name2) != 0) {
            p2 = p1;
            p1 = p1->next;
        }
        if(p1 == head) {
            goto loop;
        }
        if(p1->next == NULL) {
            printf("------------------------------���޴��ˣ�---------------------------\n");
        }
        else {
            p3->next = p1;
            p2->next = p3;

        }
        break;
    }
    printf("------------------------------����ɹ���------------------------------\n");
    printf("----------------------------------------------------------------------\n");
    return;
}



int main() {
    int number;
    system("color e");
    mainmenuface();
    readfile();
    while(1) {

        loop: printf("-------------------��ѡ�����Ĳ�����----------------------\n");
        scanf("%d", &number);

        if(number >= 1 && number <= 9) {

            switch(number) {
                case 1:
                Inputdata();
                goto loop;
                break;
                case 2:
                Lookdata(head);
                break;
                case 3:
                Changedata(head);
                goto loop;
                break;
                case 4:
                Seek(head);
                break;
                case 5:
                Keepdata(head);
                break;
                case 6:
                Insertdata();
                break;
                case 7:
                deletedata();
                break;
                case 8:
                mainmenuface();
                break;
                case 9:
                exit(1);
                break;
            }
        }

        else {
            printf("---------------ѡ��Ĳ�������ȷ�����������룺------------------\n");
            goto loop;
        }

    }
    return 0;
}




