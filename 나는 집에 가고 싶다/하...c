#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1 //�� ��ġ
#define BWL_POS (ROOM_WIDTH - 2) //���� ��ġ
#define TWR_POS 3 //Ÿ�� ��ġ
#define SCR_POS 6 //��ũ���� ��ġ

int main(void) {

    printf("***�߿��̿� ����***\n");
    printf("  /\\_/\\ \n");
    printf(" ( o.o )\n");
    printf("<|  ^ <|\n");
    printf(" |     |\\  \n");
    printf("         \\/  \n");

    char name[20]; // ����� �̸� ����

    printf("�߿����� �̸��� �Է����ּ���: ");
    scanf_s("%s", &name, 20);
    printf("�߿����� �̸��� %s�Դϴ�.", name);
    Sleep(1000); //1�� ���
    system("cls");



    int soup = 0; //���� ����
    int relation = 2; //����, ģ�е�
    int leave = 2; //���� ��ġ, �� �̹� ���� �ڸ�, 3�̻��̸� �̵�
    int cat = 1; //����� ��ġ
    int a = 0; //��ȣ�ۿ�
    int CP = 0; //CP ����Ʈ
    int feel = 3; //���

    while (1) {
        printf("==========�������==========\n");
        printf("���ݱ��� ���� ������ ����: %d��\n", soup);
        printf("CP: %d ����Ʈ\n", CP);
        printf("����� ���(0~3): %d\n", feel);
        printf("������� ����(0~4): %d\n", relation);

        if (feel == 0) {
            printf("����� �ſ� ���޴ϴ�.\n");
            printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", name);
        }
        if (feel == 1) {
            printf("�ɽ��� �մϴ�.\n");
        }
        if (feel == 2) {
            printf("�Ļ��� �����ϴ�.\n");
        }
        if (feel == 3) {
            printf("������ �θ��ϴ�.\n");
        }

        if (relation == 0) {
            printf("�翡 ���� ������ �Ⱦ��մϴ�.\n");
        }
        else if (relation == 1) {
            printf("���� ���Ǳ� ����Դϴ�.\n");
        }
        else if (relation == 2) {
            printf("�׷����� ������ �����Դϴ�.\n");
        }
        else if (relation == 3) {
            printf("�Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
        }
        else if (relation == 4) {
            printf("���� �������Դϴ�.\n");
        }
        else {
            printf("�߸��� ģ�е� ���Դϴ�.\n");
        }
        printf("===============================\n\n");
        Sleep(500);

        srand((unsigned)time(NULL));

        printf("�ֻ����� ���� 6 - %d���ϸ� �׳� ����� �������ϴ�.\n �ֻ����� �����ϴ�. �Ǹ���...\n", relation);
        int rrr; //���ƹ��������̱���̳������ϴ�. ����̴ϱ�?����� ������ �� ������ �ֻ���
		rrr = rand() % 6 + 1;
        printf("%d��(��) ���Խ��ϴ�!\n", rrr);
        if (rrr <= 6 - relation) { //�ֻ��� �� 6 - relation���� ģ�е� �϶�
            printf("����� �������ϴ�.\n");
            feel--;
            if (feel < 0) {
                feel = 0; //����� 0�Ʒ��� �������� �ȵ�
            }
            if (feel > 3) {
				feel = 3; //����� 3�� �Ѿ �� ����
            }
        }
		else {
			printf("������ ����� �������� �ʾҽ��ϴ�.\n");
		}
        printf("���� ���: %d\n", feel);


        srand((unsigned)time(NULL));

        printf("���ȣ�ۿ����Ͻðڽ��ϱ�?   0.�ƹ��͵��������� 1.�ܾ��ֱ�>> ");
        scanf_s("%d", &a);

        while (a != 0 && a != 1) {

            printf("0�� 1�� �ϳ��� �Է��ϼ���.\n");
            printf("���ȣ�ۿ����Ͻðڽ��ϱ�?   0.�ƹ��͵��������� 1.�ܾ��ֱ�>> ");
            scanf_s("%d", &a);
        }
        if (a == 0) {

            printf("�ƹ��͵� ���� �ʽ��ϴ�.\n 4/6Ȯ��� ģ�е��� �������ϴ�.\n �ֻ����� �����ϴ�. �Ǹ���...\n");
            int r; //�ֻ��� ��
            r = rand() % 6 + 1;
            printf("%d��(��) ���Խ��ϴ�!\n", r);
            if (r <= 4) { //�ֻ��� �� 4���� ģ�е� �϶�
                printf("ģ�е��� �������ϴ�.\n");
                relation--;

                if (relation < 0) {
                    relation = 0; //ģ�е��� 0�Ʒ��� �������� �ȵ�
                }
            }
            else {
                printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
            printf("���� ģ�е�: %d\n", relation);
        }
        else {
            printf("�˴��� ���� �ܾ��־����ϴ�.\n 2/6Ȯ���� ģ�е��� �������ϴ�.\n �ֻ����� �����ϴ�. �Ǹ���...\n");
            int rr; //�ֻ��� ��
            rr = rand() % 6 + 1;
            printf("%d��(��) ���Խ��ϴ�!\n", rr);
            if (rr >= 5) { //�ֻ��� �� 5�̻� ģ�е� ���
                printf("ģ�е��� ����մϴ�.\n");
                relation++;
                if (relation > 4) {
                    relation = 4; //ģ�е��� 4�� �Ѿ �� ����
                }
            }
            else {
                printf("ģ�е��� �״�� �Դϴ�.\n");
            }
            printf("���� ģ�е�: %d\n", relation);
        }

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == HME_POS) {
                printf("H"); //��
            }
            else if (i == TWR_POS) {
                printf("T"); //Ÿ��
            }
            else if (i == SCR_POS) {
                printf("S"); //��ũ����
            }
            else if (i == BWL_POS) { //����
                printf("B");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n");

        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == cat) {
                printf("C"); //�����
            }
            else if (i == leave && cat != leave) {
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

       /* printf("�˴� �̵�: ����� ģ���� ���� ����� �̵��� Ȯ���� �������ϴ�.\n"); // ver. 1 �¿� �̵� �κ���
        int limit = 6 - relation;
        double probability = ((6 - limit + 1) / 6.0) * 100.0;
        printf("�ֻ��� ���� %d�̻��̸� ���������� �̵��մϴ�.\n", limit);
        printf("�� Ȯ��: �� %.1f%%\n", probability);

        srand((unsigned)time(NULL));

        int dice = rand() % 6 + 1;
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
        Sleep(1000);
        printf("%d��(��) ���Խ��ϴ�!\n", dice);

        if (dice >= limit) {
            printf("���� ������ �̵��մϴ�.\n\n");
            if (cat < ROOM_WIDTH - 2) {
                cat++;
            }
            else {
                printf("������ ���� ���� ������ �� �����ϴ�.\n\n");
            }
        }
        else {
            printf("�� ������ �����Դϴ�.\n\n");
            if (cat > 1) {
                cat--;
            }
            else {
                printf("������ ���� ���� ������ �� �����ϴ�.\n\n");
            }
        }
        Sleep(1000);*/ // ver. 2������ �¿� �̵� ����

        if (feel == 0) {
            printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", name);
            if (cat < HME_POS && cat < ROOM_WIDTH - 1) {
                cat++;
            }
            else if (cat > HME_POS && cat > 0) {
                cat--;
            }
        }
        if (feel == 1) {
            printf("%s��(��)�ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n", name);
            if (cat < SCR_POS && cat < TWR_POS && cat < ROOM_WIDTH - 2) {
                cat++;
            }
            else if (cat > SCR_POS && cat < TWR_POS && cat > 0) {
                cat--;
            }
            else (cat != SCR_POS && cat != TWR_POS); {
                printf("���̱ⱸ�� ������ ��� - 1: ��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
            }
        }
		if (feel == 2) {
            printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�..\n", name);
		}
		if (feel == 3) {
			printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", name);
            if (cat < BWL_POS && cat < ROOM_WIDTH - 2) {
                cat++;
            }
            else if (cat > BWL_POS && cat > 0) {
                cat--;
            }
		}

        // ���¿� ���� �̺�Ʈ
        if (cat == HME_POS) {
            printf("�˶���(��) �ڽ��� ������ ������� �����ϴ�.\n\n");
        }
        else if (cat == BWL_POS) {
            const char* soups[] = { "���ڼ���", "����̼���", "����ݸ�����" };
            int taste = rand() % 3;
            soup++;
            printf("�˶���(��) %s�� ��������ϴ�!\n", soups[taste]);
            printf("������� ���� ����: %d��\n\n", soup);
        }
    }

    return 0;
}