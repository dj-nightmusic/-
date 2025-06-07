#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1 //집 위치
#define BWL_POS (ROOM_WIDTH - 2) //냄비 위치
#define TWR_POS 3 //타워 위치
#define SCR_POS 6 //스크래쳐 위치

int main(void) {

    printf("***야옹이와 스프***\n");
    printf("  /\\_/\\ \n");
    printf(" ( o.o )\n");
    printf("<|  ^ <|\n");
    printf(" |     |\\  \n");
    printf("         \\/  \n");

    char name[20]; // 고양이 이름 저장

    printf("야옹이의 이름을 입력해주세요: ");
    scanf_s("%s", &name, 20);
    printf("야옹이의 이름은 %s입니다.", name);
    Sleep(1000); //1초 대기
    system("cls");



    int soup = 0; //수프 개수
    int relation = 2; //관계, 친밀도
    int leave = 2; //이전 위치, 즉 이미 떠나 자리, 3이상이면 이동
    int cat = 1; //고양이 위치
    int a = 0; //상호작용
    int CP = 0; //CP 포인트
    int feel = 3; //기분

    while (1) {
        printf("==========현재상태==========\n");
        printf("지금까지 만든 수프의 개수: %d개\n", soup);
        printf("CP: %d 포인트\n", CP);
        printf("고양이 기분(0~3): %d\n", feel);
        printf("집사와의 관계(0~4): %d\n", relation);

        if (feel == 0) {
            printf("기분이 매우 나쁩니다.\n");
            printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name);
        }
        if (feel == 1) {
            printf("심심해 합니다.\n");
        }
        if (feel == 2) {
            printf("식빵을 굽습니다.\n");
        }
        if (feel == 3) {
            printf("골골송을 부릅니다.\n");
        }

        if (relation == 0) {
            printf("곁에 오는 것조차 싫어합니다.\n");
        }
        else if (relation == 1) {
            printf("간식 자판기 취급입니다.\n");
        }
        else if (relation == 2) {
            printf("그럭저럭 쓸만한 집사입니다.\n");
        }
        else if (relation == 3) {
            printf("훌륭한 집사로 인정받고 있습니다.\n");
        }
        else if (relation == 4) {
            printf("집사 껌딱지입니다.\n");
        }
        else {
            printf("잘못된 친밀도 값입니다.\n");
        }
        printf("===============================\n\n");
        Sleep(500);

        srand((unsigned)time(NULL));

        printf("주사위의 눈이 6 - %d이하면 그냥 기분이 나빠집니다.\n 주사위를 굴립니다. 또르륵...\n", relation);
        int rrr; //“아무이유없이기분이나빠집니다. 고양이니까?”라는 이유로 걍 굴리는 주사위
		rrr = rand() % 6 + 1;
        printf("%d이(가) 나왔습니다!\n", rrr);
        if (rrr <= 6 - relation) { //주사위 눈 6 - relation이하 친밀도 하락
            printf("기분이 나빠집니다.\n");
            feel--;
            if (feel < 0) {
                feel = 0; //기분은 0아래로 내려가면 안됨
            }
            if (feel > 3) {
				feel = 3; //기분은 3을 넘어갈 수 없음
            }
        }
		else {
			printf("다행히 기분이 나빠지지 않았습니다.\n");
		}
        printf("현재 기분: %d\n", feel);


        srand((unsigned)time(NULL));

        printf("어떤상호작용을하시겠습니까?   0.아무것도하지않음 1.긁어주기>> ");
        scanf_s("%d", &a);

        while (a != 0 && a != 1) {

            printf("0과 1중 하나를 입력하세요.\n");
            printf("어떤상호작용을하시겠습니까?   0.아무것도하지않음 1.긁어주기>> ");
            scanf_s("%d", &a);
        }
        if (a == 0) {

            printf("아무것도 하지 않습니다.\n 4/6확룰로 친밀도가 떨어집니다.\n 주사위를 굴립니다. 또르륵...\n");
            int r; //주사위 수
            r = rand() % 6 + 1;
            printf("%d이(가) 나왔습니다!\n", r);
            if (r <= 4) { //주사위 눈 4이하 친밀도 하락
                printf("친밀도가 떨어집니다.\n");
                relation--;

                if (relation < 0) {
                    relation = 0; //친밀도는 0아래로 내려가면 안됨
                }
            }
            else {
                printf("다행히 친밀도가 떨어지지 않았습니다.\n");
            }
            printf("현재 친밀도: %d\n", relation);
        }
        else {
            printf("쫀덕의 턱을 긁어주었습니다.\n 2/6확률로 친밀도가 높아집니다.\n 주사위를 굴립니다. 또르륵...\n");
            int rr; //주사위 수
            rr = rand() % 6 + 1;
            printf("%d이(가) 나왔습니다!\n", rr);
            if (rr >= 5) { //주사위 눈 5이상 친밀도 상승
                printf("친밀도가 상승합니다.\n");
                relation++;
                if (relation > 4) {
                    relation = 4; //친밀도는 4를 넘어갈 수 없음
                }
            }
            else {
                printf("친밀도는 그대로 입니다.\n");
            }
            printf("현재 친밀도: %d\n", relation);
        }

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == HME_POS) {
                printf("H"); //집
            }
            else if (i == TWR_POS) {
                printf("T"); //타워
            }
            else if (i == SCR_POS) {
                printf("S"); //스크래쳐
            }
            else if (i == BWL_POS) { //냄비
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
                printf("C"); //고양이
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

       /* printf("쫀덕 이동: 집사와 친밀할 수록 냄비로 이동할 확률이 높아집니다.\n"); // ver. 1 좌우 이동 부분임
        int limit = 6 - relation;
        double probability = ((6 - limit + 1) / 6.0) * 100.0;
        printf("주사위 눈이 %d이상이면 냄비쪽으로 이동합니다.\n", limit);
        printf("→ 확률: 약 %.1f%%\n", probability);

        srand((unsigned)time(NULL));

        int dice = rand() % 6 + 1;
        printf("주사위를 굴립니다. 또르륵...\n");
        Sleep(1000);
        printf("%d이(가) 나왔습니다!\n", dice);

        if (dice >= limit) {
            printf("냄비 쪽으로 이동합니다.\n\n");
            if (cat < ROOM_WIDTH - 2) {
                cat++;
            }
            else {
                printf("하지만 벽에 막혀 움직일 수 없습니다.\n\n");
            }
        }
        else {
            printf("집 쪽으로 움직입니다.\n\n");
            if (cat > 1) {
                cat--;
            }
            else {
                printf("하지만 벽에 막혀 움직일 수 없습니다.\n\n");
            }
        }
        Sleep(1000);*/ // ver. 2에서는 좌우 이동 삭제

        if (feel == 0) {
            printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name);
            if (cat < HME_POS && cat < ROOM_WIDTH - 1) {
                cat++;
            }
            else if (cat > HME_POS && cat > 0) {
                cat--;
            }
        }
        if (feel == 1) {
            printf("%s은(는)심심해서 스크래처 쪽으로 이동합니다.\n", name);
            if (cat < SCR_POS && cat < TWR_POS && cat < ROOM_WIDTH - 2) {
                cat++;
            }
            else if (cat > SCR_POS && cat < TWR_POS && cat > 0) {
                cat--;
            }
            else (cat != SCR_POS && cat != TWR_POS); {
                printf("놀이기구가 없으면 기분 - 1: 놀거리가 없어서 기분이 매우 나빠집니다.\n");
            }
        }
		if (feel == 2) {
            printf("%s은(는) 기분좋게 식빵을 굽고 있습니다..\n", name);
		}
		if (feel == 3) {
			printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", name);
            if (cat < BWL_POS && cat < ROOM_WIDTH - 2) {
                cat++;
            }
            else if (cat > BWL_POS && cat > 0) {
                cat--;
            }
		}

        // 상태에 따른 이벤트
        if (cat == HME_POS) {
            printf("쫀떡은(는) 자신의 집에서 편안함을 느낍니다.\n\n");
        }
        else if (cat == BWL_POS) {
            const char* soups[] = { "감자수프", "양송이수프", "브로콜리수프" };
            int taste = rand() % 3;
            soup++;
            printf("쫀떡이(가) %s를 만들었습니다!\n", soups[taste]);
            printf("현재까지 만든 수프: %d개\n\n", soup);
        }
    }

    return 0;
}