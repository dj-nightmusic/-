#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1 //�� ��ġ
#define BWL_POS (ROOM_WIDTH - 2) //���� ��ġ
#define TWR_POS 3 //Ÿ�� ��ġ
#define SCR_POS 6 //��ũ���� ��ġ
#define PRICE_MOUSE 1 //�� �峭�� ����
#define PRICE_LASER     2 //������ ������ ����
#define PRICE_SCRATCHER 4 //��ũ���� ����
#define PRICE_TOWER 6 //Ÿ�� ����

int main(void) {

    printf("***�߿��̿� ����***\n");
    printf("  /\\_/\\ \n");
    printf(" ( o.o )\n");
    printf("<|  ^ <|\n");
    printf(" |     |\\  \n");
    printf("         \\/  \n");

    char name[100]; // ����� �̸� ����

    printf("�߿����� �̸��� �Է����ּ���(�ֱ����� ���� �ѱ���� �����ּ���).: ");
    scanf_s("%s", &name, 100);
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
	int scr = 0; //��ũ����
	int twr = 0; //Ÿ��
    int laser = 0; //������ ������
    int mouse = 0; //�� �峲��
    int toy; // �峭�� ��
    toy = laser + mouse; //�������� �� ���� �峭������ ����� ������
    CP += ((feel - 1) > 0 ? (feel - 1) : 0) + relation; //�����ϱ� ���� + ���̹�
    int choice;
	int turnCount = 0; //�� ī��Ʈ
    char userAnswer[100];

    while (1) {
        if (feel < 0) {
            feel = 0; //����� 0�Ʒ��� �������� �ȵ�
        }
        if (feel > 3) {
            feel = 3; //����� 3�� �Ѿ �� ����
        }
        printf("==========�������==========\n");
        printf("���ݱ��� ���� ������ ����: %d��\n", soup);
        printf("CP: %d ����Ʈ\n", CP);
        printf("����� ���(0~3): %d\n", feel);
        printf("������� ����(0~4): %d\n", relation);
        printf("%s�� ��а� ģ�е��� ���� CP�� %d����Ʈ ����Ǿ����ϴ�.\n", name, CP);
        printf("���� CP: %d ����Ʈ\n", CP);

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

        srand((unsigned)time(NULL));

        printf("�ֻ����� ���� 6 - %d���ϸ� �׳� ����� �������ϴ�.\n �ֻ����� �����ϴ�. �Ǹ���...\n", relation);
        int rrr; //���ƹ� ���� ���� ����� �������ϴ�. ����̴ϱ�?����� ������ �� ������ �ֻ���
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
            if (relation < 0) {
                relation = 0; //ģ�е��� 0�Ʒ��� �������� �ȵ�
            }
            if (relation > 4) {
                relation = 4; //ģ�е��� 4�� �Ѿ �� ����
            }
        }
        else {
            printf("������ ����� �������� �ʾҽ��ϴ�.\n");
        }
        printf("���� ���: %d\n", feel);


        srand((unsigned)time(NULL));

        if (toy == 0) {
            printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ�>> ");
            scanf_s("%d", &a);
            while (a != 0 && a != 1) {
                printf("0�� 1�� �ϳ��� �Է��ϼ���.\n");
                printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ�>> ");
                scanf_s("%d", &a);
            }
        }
        if (toy == 1) {
            if (laser == 1) {
                printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ� 2.������ �����ͷ� ����ֱ�>> ");
                scanf_s("%d", &a);
                while (a != 0 && a != 1 && a != 2) {
                    printf("0�� 1�� 2�� �ϳ��� �Է��ϼ���.\n");
                    printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ� 2.������ �����ͷ� ����ֱ�>> ");
                    scanf_s("%d", &a);
                }
            }
            if (mouse == 1) {
                printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ� 2.�峭�� ��� ����ֱ�>> ");
                scanf_s("%d", &a);
                while (a != 0 && a != 1 && a != 2) {
                    printf("0�� 1�� 2�� �ϳ��� �Է��ϼ���.\n");
                    printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ� 2.�峭�� ��� ����ֱ�>> ");
                    scanf_s("%d", &a);
                }
            }
        }
        if (toy == 2) {
            printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ� 2.������ �����ͷ� ����ֱ� 3.�峭�� ��� ����ֱ�>> ");
            scanf_s("%d", &a);
            while (a != 0 && a != 1 && a != 2 && a != 3) {
                printf("0�� 1�� 2�� 3�� �ϳ��� �Է��ϼ���.\n");
                printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0.�ƹ��͵� �������� 1.�ܾ��ֱ� 2.������ �����ͷ� ����ֱ� 3.�峭�� ��� ����ֱ�>> ");
                scanf_s("%d", &a);
            }
        }

        if (a == 0) {

            printf("�ƹ��͵� ���� �ʽ��ϴ�.\n %s�� ����� ���������ϴ�.\n 4/6Ȯ��� ģ�е��� �������ϴ�.\n �ֻ����� �����ϴ�. �Ǹ���...\n", name);
            feel--;
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
            printf("���� ���: %d\n", feel);
        }
        if (a == 1) {
            printf("%s�� ���� �ܾ��־����ϴ�.\n %s�� ����� �״���Դϴ�.\n 2/6Ȯ���� ģ�е��� �������ϴ�.\n �ֻ����� �����ϴ�. �Ǹ���...\n", name, name);
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
        if (a == 2) {
            printf("�峭�� ��� %s�� ����־����ϴ�.  %s�� ����� ���� ���������ϴ�.\n", name, name);
            feel++;
            int rrrr; //�ֻ��� ��
            rrrr = rand() % 6 + 1;
            printf("%d��(��) ���Խ��ϴ�!\n", rrrr);
            if (rrrr >= 4) { //�ֻ��� �� 4�̻� ģ�е� ���
                printf("ģ�е��� ����մϴ�.\n");
                relation++;
                if (relation > 4) {
                    relation = 4; //ģ�е��� 4�� �Ѿ �� ����
                }
            }
        }
        if (a == 3) {
            printf("������ �����ͷ� %s�� �ų��� ����־����ϴ�. %s�� ����� �� ���������ϴ�.\n", name, name);
            feel += 2;
            int rrrrr; //�ֻ��� ��
            rrrrr = rand() % 6 + 1;
            printf("%d��(��) ���Խ��ϴ�!\n", rrrrr);
			if (rrrrr >= 2) { //�ֻ��� �� 2�̻� ģ�е� ���
				printf("ģ�е��� ����մϴ�.\n");
				relation++;
				if (relation > 4) {
					relation = 4; //ģ�е��� 4�� �Ѿ �� ����
				}
			}
        }
        srand((unsigned)time(NULL));

        printf("\n�������� ������ �� �� �ֽ��ϴ�.\n"); //����

        printf("� ������ �����ұ��? (���� CP: %d)\n", CP);
        printf("0. �ƹ��͵� ���� �ʴ´�.\n");
        printf("1. �峭�� ��: %d CP\n", PRICE_MOUSE);
        printf("2. ������ ������: %d CP\n", PRICE_LASER);
        printf("3. ��ũ����: %d CP\n", PRICE_SCRATCHER);
        printf("4. Ĺ Ÿ��: %d CP\n", PRICE_TOWER);
        printf(">> ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("�ƹ��͵� ���� �ʰ� ������ �����ϴ�.\n");
        }
        if (choice == 1) {
            if (mouse == 1) {
                printf("ǰ���� ��ǰ�Դϴ�.\n �������� �ٽ� �̿����ּ���, �����մϴ�.\n");
            }
            else if (CP < PRICE_MOUSE) {
                printf("CP�� �����մϴ�.\n");
            }
            else {
                CP -= PRICE_MOUSE;
                mouse++;
                mouse = 1;
                printf("�峭�� �㸦 �����߽��ϴ�.\n");
                printf("���� CP %d ����Ʈ\n", CP);
            }
        }
        if (choice == 2) {
            if (laser == 1) {
                printf("ǰ���� ��ǰ�Դϴ�.\n �������� �ٽ� �̿����ּ���, �����մϴ�.\n");
            }
            else if (CP < PRICE_LASER) {
                printf("CP�� �����մϴ�.\n");
            }
            else {
                CP -= PRICE_LASER;
                laser++;
                laser = 1;
                printf("������ �����͸� �����߽��ϴ�.\n");
                printf("���� CP %d ����Ʈ\n", CP);
            }
        }
        if (choice == 3) {
            if (scr == 1) {
                printf("ǰ���� ��ǰ�Դϴ�.\n �������� �ٽ� �̿����ּ���, �����մϴ�.\n");
            }
            else if (CP < PRICE_SCRATCHER) {
                printf("CP�� �����մϴ�.\n");
            }
            else {
                CP -= PRICE_SCRATCHER;
                scr++;
                scr = 1;
                printf("��ũ���ĸ� �����߽��ϴ�.\n");
                printf("���� CP %d ����Ʈ\n", CP);

                int position = (rand() % 10) + 1;
                printf("��ũ���ĸ� ���� %d ��ġ�� ��ġ�߽��ϴ�.\n", position);
            }
        }
        if (choice == 4) {
            if (twr == 1) {
                printf("ǰ���� ��ǰ�Դϴ�.\n �������� �ٽ� �̿����ּ���, �����մϴ�.\n");
            }
            else if (CP < PRICE_TOWER) {
                printf("CP�� �����մϴ�.\n");
            }
            else {
                CP -= PRICE_TOWER;
                twr++;
                twr = 1;
                printf("Ĺ Ÿ���� �����߽��ϴ�.\n");
                printf("���� CP %d ����Ʈ\n", CP);
                int position = (rand() % 10) + 1;
                printf("Ĺ Ÿ���� ���� %d ��ġ�� ��ġ�߽��ϴ�.\n", position);
            }
        }
        else {
            printf("���� ���忡���� ����ϰ� ���� ���� ��ǰ�Դϴ�. �ٸ� �������� ���ּ���, �����մϴ�.\n");
        }
               
                /* printf("%s �̵�: ����� ģ���� ���� ����� �̵��� Ȯ���� �������ϴ�.\n", name); // ver. 1 �¿� �̵� �κ���
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
                    printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", name); //������ �̵�
                    if (cat < HME_POS && cat < ROOM_WIDTH - 1) {
                        cat++;
                    }
                    else (cat > HME_POS && cat > 0); {
                        cat--;
                    }
                }
                if (feel == 1) {
                    printf("%s��(��)�ɽ��ؼ� ���̱ⱸ ������ �̵��մϴ�.\n", name); //�� ����� ���̱ⱸ ������ �̵�
                    if (cat < SCR_POS && cat < TWR_POS && cat < ROOM_WIDTH - 1) {
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
                    printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�..\n", name); //���ڸ��� ���
                }
                if (feel == 3) {
                    printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", name); //���� ������ �̵�
                    if (cat < BWL_POS && cat < ROOM_WIDTH - 1) {
                        cat++;
                    }
                    else (cat > BWL_POS && cat > 0); {
                        cat--;
                    }
                }

                // ���¿� ���� �ൿ
                if (cat == HME_POS) { //���� ���� ��
                    printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n\n", name);
                    feel++;

                }
                else if (cat == BWL_POS) { //���� ���� ��
                    const char* soups[] = { "���ڼ���", "����̼���", "����ݸ�����" };
                    int taste = rand() % 3;
                    soup++;
                    printf("%s��(��) %s�� ��������ϴ�!\n", name, soups[taste]);
                    printf("������� ���� ����: %d��\n\n", soup);
                }
                else if (cat == SCR_POS) { //��ũ���Ŀ� ���� ��
                    printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�. ����� ���� ���������ϴ�.\n", name);
                    feel++;
                }
                else (cat == TWR_POS); { //Ÿ���� ���� ��
                    printf("%s��(��) ĹŸ���� �پ�ٴմϴ�. ����� ���� ���������ϴ�.\n", name);
                    feel += 2;
                }

                turnCount++; // ���� ���۵� ������ �� ī��Ʈ ����
                printf("\n--- ���� %d��° �� ---\n", turnCount);

                if (turnCount % 3 == 0) { // turnCount�� 3���� ���� �������� 0�̸� 3�� ���
                    char userAnswer[100]; //���� ����Ʈ�� ���� ����� �Է�
                    printf("\n*** ���� ����Ʈ �߻�! ***\n");
                    printf("%s���� �� ������ �����ϱ��?\n", name);
                    printf(">> ");
                    scanf_s("%s", userAnswer, 100);
                    printf("Ʋ�Ƚ��ϴ�. �̰����� �� ����̴� �������� �ʽ��ϴ�.\n ����� �� ���α׷��� ���� ����� ����� ���� �� ��� �� ������� ������ ���� �� �ΰ���?\n");
                    printf("����ִ� ���� �׾��� ���� �����ϴ�.\n ������ ����� �Ӹ��ӿ����� ����־��� ���� �־��ڳ׿�.\ ����̵� �̹� �˰� �־��� �� �Դϴ�.\n %s�� � ����̾�����?\n �����־�����?\n\n", name);
                    printf("*** ���� ����Ʈ ���� ***\n");
                    printf("\n");
                }
                Sleep(2000);
                system("cls");
            }

            return 0;
        }